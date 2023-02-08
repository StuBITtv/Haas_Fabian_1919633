#ifndef EULERLIB_H_
#define EULERLIB_H_

#include <stdio.h>

typedef struct {
    FILE *position;
    FILE *velocity;
} Plot;

typedef struct {
    double position;
    double velocity;
} SimulationState;

typedef SimulationState(*SimulationCalculation)(SimulationState state, double duration);
typedef int (*StateToPlotWriter)(const Plot *plot, double x, SimulationState state);
typedef int (*GraphCalculator)(void *calculationData, const Plot *plot, StateToPlotWriter addValue);

typedef struct {
    SimulationState initialState;
    SimulationCalculation function;
    double stepSize;
    double duration;
} SimulationSettings;

SimulationState massSpringDamperCalculation(SimulationState state, double duration);

int calculateSimulation(void *data, const Plot *plot, StateToPlotWriter writeToPlot);

int plotSimulationGraphs(void *calculationData, GraphCalculator calculation);

SimulationSettings getHandle(SimulationCalculation simulationCalculation);

#endif
