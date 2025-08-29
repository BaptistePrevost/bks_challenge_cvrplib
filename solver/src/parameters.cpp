#include "parameters.hpp"

Parameters::Parameters(int populationSize) : populationSize_(populationSize) {}

const int Parameters::populationSize() const {
    return populationSize_;
}