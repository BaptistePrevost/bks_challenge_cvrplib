#pragma once

#include "instance.hpp"
#include "parameters.hpp"
#include "split.hpp"
#include "solution.hpp"

#include <vector>
#include <map>
#include <iostream>

/**
 * Class for a population of solution.
 * When the population reaches parameters_::maxPopulationSize(), it's reduced to parameters_.populationSize()
 * Note that it stores at most one solution per fitness value.
 */
class Population {

    public:
    Population(Instance& instance, Parameters& parameters, Split& split);

    /** Generate a random population of size parameters_.populationSize() */
    void generate();

    /** Returns a random solution in O(1) */
    const Solution& getRandomSolution() const;
    
    /** Inserts a solution in O(log n) */
    void addSolution(const Solution& solution);
    
    /** Returns the best solution in O(1) */
    const Solution& getBestSolution() const;

    /** Remove the worst solution in O(log n) */
    void removeWorstSolution();

    /** For debug purpose */
    void show() const {
        for (auto it = positions_.begin(); it != positions_.end(); it++)
            std::cout << it->first << " ";
        std::cout << std::endl;
        for (const Solution& sol : solutions_)
            std::cout << sol.fitness() << " ";
        std::cout << std::endl;
    }

    private:
    Instance& instance_;                //Reference to the instance object
    Parameters& parameters_;            //Reference to the parameters object
    Split& split_;                      //Reference to the split object
    int nbSolutions_;                   //Current number of solutions
    std::vector<Solution> solutions_;   //Vector of solution objects
    std::map<double, int> positions_;   //(Ordered) map of pairs {fitness, position}
};