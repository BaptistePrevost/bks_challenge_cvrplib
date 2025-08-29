#include "parameters.hpp"

Parameters::Parameters(int populationSize, int maxNbRoutes) : 
        populationSize_(populationSize), maxNbRoutes_(maxNbRoutes) {}

const int Parameters::populationSize() const {
    return populationSize_;
}

const int Parameters::maxNbRoutes() const {
    return maxNbRoutes_;
}