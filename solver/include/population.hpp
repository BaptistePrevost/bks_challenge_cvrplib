#pragma once

#include "instance.hpp"
#include "parameters.hpp"
#include "split.hpp"
#include "solution.hpp"
#include <set>

class Population {

    public:
    Population(Instance& instance, Parameters& parameters, Split& split);

    void generate();
    std::set<Solution>& solutions();
    const Solution& getRandomSolution() const;
    void addSolution(Solution& solution);
    const Solution& getBestSolution() const;

    private:
    Instance& instance_;
    Parameters& parameters_;
    Split& split_;
    std::set<Solution> solutions_;
};