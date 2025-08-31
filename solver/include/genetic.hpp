#pragma once

#include "crossovers/crossover.hpp"
#include "population.hpp"
#include "solution.hpp"
#include "split.hpp"

class Genetic {

    public:
    Genetic(Instance& instance, Parameters& parameters, Crossover* crossover);

    void run();

    private:
    Instance& instance_;
    Parameters& parameters_;
    Crossover* crossover_;
    Split split_;
    Population population_;
    Solution child_;
};