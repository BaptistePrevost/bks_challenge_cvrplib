#include "genetic.hpp"
#include <iostream>

Genetic::Genetic(Instance& instance, Parameters& parameters, Crossover* crossover) : 
        instance_(instance),
        parameters_(parameters),
        crossover_(crossover),
        split_(instance),
        population_(instance, parameters, split_),
        child_(instance, parameters) {
    population_.generate();
}

void Genetic::run() {
    for (int iter = 0; iter < 1e5; iter++) {
        crossover_->cross(population_.getRandomSolution(), population_.getRandomSolution(), child_);
        split_.process(child_);
        population_.addSolution(child_);
        if (iter % 1000 == 0) {
            std::cout << "Iter " << iter << " --- " << population_.getBestSolution().fitness() << " - " << population_.getBestSolution().nbRoutes() << std::endl;
        }
    }
    for (const std::vector<int>& route : population_.getBestSolution().routes()) {
        if (route.size() == 0) continue;
        for (int customer : route) {
            std::cout << customer << " ";
        }
        std::cout << std::endl;
    }
}