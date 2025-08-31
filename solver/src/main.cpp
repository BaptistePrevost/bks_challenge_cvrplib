#include <iostream>
#include "instance.hpp"
#include "parameters.hpp"
#include "crossovers/ordered_crossover.hpp"
#include "genetic.hpp"

int main() {
    Instance instance("data/A/A-n32-k5.vrp");
    Parameters parameters(10, 200);
    OrderedCrossover crossover(instance);
    
    Genetic genetic(instance, parameters, &crossover);
    genetic.run();
}