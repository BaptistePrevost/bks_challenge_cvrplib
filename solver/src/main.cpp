#include <iostream>
#include "instance.hpp"
#include "population.hpp"
#include "parameters.hpp"
#include "split.hpp"
#include "crossovers/ordered_crossover.hpp"

int main() {
    Instance instance("data/A/A-n32-k5.vrp");
    Parameters parameters(10, 200);

    Population population(instance, parameters);

    Split split(instance);
    OrderedCrossover crossover(instance);

}