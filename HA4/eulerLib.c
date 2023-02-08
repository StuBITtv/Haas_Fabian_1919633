#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "eulerLib.h"

SimulationState massSpringDamperCalculation(SimulationState state, double duration) {

    double m = 1.0;  // mass of object
    double c = 5;    // spring constant
    double d = 0.25; // damper constant

    double x = state.position;
    double v = state.velocity;

    double acceleration = -1 * (d / m * v + c / m * x);

    return (SimulationState) {
            state.position + state.velocity * duration,
            state.velocity + acceleration * duration,
    };
}

static double numberInput(const char *prompt) {
    while (1) {
        printf("%s", prompt);

        double input;
        if (scanf("%lf", &input) == 1) {     // NOLINT(cert-err34-c)
            return input;
        }

        printf("Please enter a valid number. ");

        while (getchar() != '\n');  // free stdin till a new line starts
    }
}

SimulationSettings getSimulationSettings(SimulationCalculation simulationCalculation) {
    SimulationSettings settings;
    settings.function = simulationCalculation;

    /*get user defined simulation time*/
    settings.duration = numberInput("Simulation duration (in s):\n");

    /*get user defined step size*/
    settings.stepSize = numberInput("Step size (in s):\n");

    /*get init state position*/
    settings.initialState.position = numberInput("position(t = 0):\n");

    /*get init state speed*/
    settings.initialState.velocity = numberInput("speed(t = 0):\n");

    return settings;
}

int calculateSimulation(void *data, const Plot *plot, StateToPlotWriter writeToPlot) {
    SimulationSettings *settings = data;
    int timeStepCount = (int) ceil(settings->duration / settings->stepSize);

    SimulationState currentState = settings->initialState;

    for (int i = 0; i < timeStepCount; ++i) {
        int dataWritten = writeToPlot(plot, i * settings->stepSize, currentState);
        if (dataWritten < 0) return dataWritten;

        currentState = massSpringDamperCalculation(currentState, settings->stepSize);
    }

    return 0;
}

static int writeToPlot(const Plot *plot, double x, SimulationState state) {
    const int positionWritten = fprintf(plot->position, "%lf %lf\n", x, state.position);
    if (positionWritten < 0) return positionWritten;

    const int velocityWritten = fprintf(plot->velocity, "%lf %lf\n", x, state.velocity);

    return velocityWritten < 0 ? velocityWritten : velocityWritten + positionWritten;
}

static void closePlotFile(FILE **file) {
    if (file && *file) {
        fclose(*file);
        *file = NULL;
    }
}

static void closePlot(Plot *plot) {
    closePlotFile(&plot->position);
    closePlotFile(&plot->velocity);
}

static int submitPlotToPlotter(FILE *plotter, FILE *data) {
    while (1) {
        int character = fgetc(data);

        if (feof(data)) {
            return 0;
        }

        if (fputc(character, plotter) != character) return -1;
    }
}

static int submitPlot(FILE *plotter, const Plot *plot) {
    rewind(plot->position);
    rewind(plot->velocity);

    if (submitPlotToPlotter(plotter, plot->position) < 0) {
        fprintf(stderr, "Could not submit all position states to plotter.");
        return -1;
    }

    fprintf(plotter, "e\n");

    if (submitPlotToPlotter(plotter, plot->velocity) < 0) {
        fprintf(stderr, "Could not submit all velocity states to plotter.");
        return -1;
    }

    fprintf(plotter, "e\n");

    return 0;
}

static int errorExit(FILE *plotter, Plot *plot, const char *message) {
    fprintf(stderr, "%s", message);

    if (plotter) pclose(plotter);
    if (plot) closePlot(plot);

    return EXIT_FAILURE;
}

int plotSimulationGraphs(void *calculationData, GraphCalculator calculation) {
    Plot plot = {tmpfile(), tmpfile()};

    if (!plot.position || !plot.velocity) {
        return errorExit(NULL, &plot, "Could not create temporary files necessary. Check your permissions.");
    }

    if (calculation) {
        if ((*calculation)(calculationData, &plot, writeToPlot) < 0) {
            fprintf(stderr, "Could not calculate whole simulation, result might be truncated.");
        }
    }

    FILE *plotter = popen(
            "gnuplot -p -e \""
            "plot '-' using 1:2 w l title 'Position', "
            "     ''  using 1:2 w l title 'Velocity';"
            "\"",
            "w"
    );

    if (!plotter) {
        return errorExit(plotter, &plot, "Could not start plotter (gnuplot).");
    }

    int plottingExitCode = submitPlot(plotter, &plot);

    pclose(plotter);
    closePlot(&plot);

    return plottingExitCode;
}
