#include <math.h>
#include "eulerLib.h"

SimulationState massSpringDamperCalculation(SimulationState state, double duration)
{ // mass spring damper

    double m = 1.0;  // mass of object
    double c = 5;    // spring constant
    double d = 0.25; // damper constant

    double x = state.position;
    double v = state.velocity;

    /*calc derivatives and store in state*/

    /* YOUR CODE HERE */
    /* ---------------*/

    return state;
}

SimulationSettings getSimulationSettings(SimulationCalculation simulationCalculation)
{
    /*get user defined simulation time*/
    printf("Simulation time (in s): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get user defined step size*/
    printf("Step size (in s): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get init state position*/
    printf("position(t = 0): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get init state speed*/
    printf("speed(t = 0): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    return (SimulationSettings){};
}

int calculateSimulation(void *data, const Plot *plot, StateToPlotWriter writeToPlot)
{ // this is called only once
    SimulationSettings *settings = data;
    int timeStepCount = (int)ceil(settings->duration / settings->stepSize);

    SimulationState currentState = settings->initialState;

    for (int i = 0; i < timeStepCount; ++i)
    {
        int dataWritten = writeToPlot(plot, i * settings->stepSize, currentState);
        if(dataWritten < 0) return dataWritten;

        /*calculate currentState*/

        /* YOUR CODE HERE */
        /* ---------------*/

    }

    return 0;
}

static int writeToPlot(const Plot *plot, double x, SimulationState state) {
    const int positionWritten = fprintf(plot->position, "%lf %lf\n", x, state.position);
    if(positionWritten < 0) return positionWritten;

    const int velocityWritten = fprintf(plot->velocity, "%lf %lf\n", x, state.velocity);

    return velocityWritten < 0 ? velocityWritten : velocityWritten + positionWritten;
}

static void closePlotFile(FILE **file) {
    if(file && *file) {
        fclose(*file);
        *file = NULL;
    }
}

static void closePlot(Plot *plot) {
    closePlotFile(&plot->position);
    closePlotFile(&plot->velocity);
}

int plotSimulationGraphs(void *calculationData, GraphCalculator calculation)
{
    Plot plot = {tmpfile(), tmpfile()};

    if(!plot.position || !plot.velocity) {
        fprintf(stderr, "Could not create temporary files necessary");
        closePlot(&plot);
        return -1;
    }

    if(calculation) {
        if((*calculation)(calculationData, &plot, writeToPlot) < 0) {
            fprintf(stderr, "Could not calculate whole simulation, result might be truncated");
        }
    }

    /*call gnuplot*/

    /* YOUR CODE HERE */
    /* ---------------*/

    closePlot(&plot);

    return 0;
}
