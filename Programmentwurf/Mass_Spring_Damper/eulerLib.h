#ifndef EULERLIB_H_
#define EULERLIB_H_

#include <stdio.h>

/** 
    \STRUCT: SimulationSettings
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: definition of handle to simulate first order ode-system as struct

    \CONTAINS:  [void* function] rhs-function

                [double* stateVec] states-array for all timesteps (t_0 ... t_end)

                [double* stateVecInit] states-array with initial states (t = 0)

                [double* derivationStateVec] derivative-array for all timesteps (t_0 ... t_end)

                [int numOfStates]: number of states in ode-system (two for mass-spring-damper-system)

                [double stepSize]: timestepsize in seconds seconds for explicit euler method

                [double simTime]: duration in seconds for explicit euler method

*/

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

/** 
    \FUNCTION: massSpringDamperCalculation
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: right-hand-side of mass spring damper system
 
    \param[in]  reference to current state vector for 2D first oder ode

    \param[in]  reference to storage vector for derivatives [out]
*/
SimulationState massSpringDamperCalculation(SimulationState state, double duration);

/** 
    \FUNCTION: calculateSimulation
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: explicit euler function to solve first order ode-system
 
    \param[in]  reference to SimulationSettings

*/
int calculateSimulation(void *data, const Plot *plot, StateToPlotWriter writeToPlot);

/** 
    \FUNCTION: plotSimulationGraphs
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: visualize the results of given ode-system solved by given used sim method
 
    \param[in]  reference to SimulationSettings

*/

int plotSimulationGraphs(void *calculationData, GraphCalculator calculation);

/** 
    \FUNCTION: getSimulationSettings
 
    \AUTHOR: jannik wiessler

    \DATE: 2021-01-10

    \DESCRIPTION: initialize SimulationSettings by user defined specs
 
    \param[in]  reference to SimulationSettings

*/
SimulationSettings getSimulationSettings(SimulationCalculation simulationCalculation);

#endif
