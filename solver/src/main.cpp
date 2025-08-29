#include <iostream>
#include "instance.hpp"
#include "population.hpp"
#include "parameters.hpp"

int main() {
    Instance instance("XLTEST/XLTEST-n1048-k139.vrp");
    Parameters parameters(500);

    Population population(instance, parameters);
}