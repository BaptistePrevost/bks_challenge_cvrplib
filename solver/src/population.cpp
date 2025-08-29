#include "population.hpp"
#include "parameters.hpp"

Population::Population(Instance& instance, Parameters& parameters) : instance_(instance), parameters_(parameters) {}

void Population::generate() {
    solutions_.resize(parameters_.populationSize());
    for (int i=0; i<parameters_.populationSize(); i++) {
        solutions_[i] = Solution(instance_, parameters_);
    }
}

[[ nodiscard ]]
std::vector<Solution>& Population::solutions() {
    return solutions_;
}