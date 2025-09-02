#pragma once

#include "instance.hpp"
#include "parameters.hpp"
#include "split.hpp"
#include "solution.hpp"

#include <vector>
#include <map>
#include <iostream>

class Population {

    public:
    Population(Instance& instance, Parameters& parameters, Split& split);

    void generate();
    const Solution& getRandomSolution() const;
    void addSolution(const Solution& solution);
    const Solution& getBestSolution() const;
    void removeWorstSolution();

    void show() const {
        for (auto it = positions_.begin(); it != positions_.end(); it++)
            std::cout << it->first << " ";
        std::cout << std::endl;
        for (const Solution& sol : solutions_)
            std::cout << sol.fitness() << " ";
        std::cout << std::endl;
    }

    private:
    Instance& instance_;
    Parameters& parameters_;
    Split& split_;
    int nbSolutions_;
    std::vector<Solution> solutions_;
    std::map<double, int> positions_;
};