#pragma once

#include "instance.hpp"
#include "parameters.hpp"
#include "solution.hpp"

class Population {

    public:
    Population(Instance& instance, Parameters& parameters);

    void generate();
    std::vector<Solution>& solutions();
    const Solution& getRandomSolution() const;

    private:
    Instance& instance_;
    Parameters& parameters_;
    std::vector<Solution> solutions_;
};