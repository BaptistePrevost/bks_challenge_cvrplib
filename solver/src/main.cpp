#include <iostream>
#include <chrono>
#include "instance.hpp"
#include "parameters.hpp"
#include "crossovers/ordered_crossover.hpp"
#include "genetic.hpp"

int main() {
    auto now = std::chrono::system_clock::now();
    
    Instance instance("data/A/A-n32-k5.vrp");
    Parameters parameters(1000, 200);
    OrderedCrossover crossover(instance);
    
    Genetic genetic(instance, parameters, &crossover);
    genetic.run();

    std::cout << "Elapsed time : " << (std::chrono::system_clock::now() - now).count() / 1000000.0 << " milliseconds." << std::endl;
}