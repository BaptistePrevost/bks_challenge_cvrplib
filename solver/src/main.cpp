#include <iostream>
#include "instance.hpp"
#include "population.hpp"
#include "parameters.hpp"
#include "split.hpp"

int main() {
    Instance instance("XLTEST/XLTEST-n1048-k139.vrp");
    Parameters parameters(10, 200);

    Population population(instance, parameters);
    population.generate();
    Split split(instance);

    for (Solution& solution : population.solutions()) {
        split.process(solution);
    }
}