#include "population.hpp"
#include "parameters.hpp"

Population::Population(Instance& instance, Parameters& parameters) : instance_(instance), parameters_(parameters) {}

void Population::generate() {
    individuals_.clear();
    for (int i=0; i<parameters_.populationSize(); i++) {
        individuals_.emplace_back(instance_);
    }
}