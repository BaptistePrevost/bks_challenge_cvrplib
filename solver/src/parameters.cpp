#include "parameters.hpp"

Parameters::Parameters(int populationSize, int maxPopulationSize, int maxNbRoutes) : 
        populationSize_(populationSize), 
        maxPopulationSize_(maxPopulationSize), 
        maxNbRoutes_(maxNbRoutes) {}

const int Parameters::populationSize() const {
    return populationSize_;
}

const int Parameters::maxPopulationSize() const {
    return maxPopulationSize_;
}

const int Parameters::maxNbRoutes() const {
    return maxNbRoutes_;
}