#pragma once

#include "instance.hpp"
#include "parameters.hpp"
#include "solution.hpp"

class Population {

    public:
    Population(Instance& instance, Parameters& parameters);

    void generate();

    private:
    Instance& instance_;
    Parameters& parameters_;
    std::vector<Solution> individuals_;
};