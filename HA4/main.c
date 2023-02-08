#include "euler.h"

int main() {
    SimulationSettings settings = getHandle(massSpringDamperCalculation);
    return plotSimulationGraphs(&settings, calculateSimulation);
}
