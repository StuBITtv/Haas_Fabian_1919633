#include "eulerLib.h"

int main() {
    SimulationSettings settings = getSimulationSettings(massSpringDamperCalculation);
    return plotSimulationGraphs(&settings, calculateSimulation);
}
