#include "population.hpp"
#include "parameters.hpp"

Population::Population(Instance& instance, Parameters& parameters, Split& split) : 
        instance_(instance), 
        parameters_(parameters),
        split_(split),
        solutions_(parameters.maxPopulationSize() + 1) {}

void Population::generate() {
    for (int i = 0; i < parameters_.populationSize(); i++) {
        solutions_[i] = Solution(instance_, parameters_);
        split_.process(solutions_[i]);
        positions_[solutions_[i].fitness()] = i;
    }
    nbSolutions_ = parameters_.populationSize();
}

[[ nodiscard ]]
const Solution& Population::getRandomSolution() const {
    int index = std::rand() % nbSolutions_;
    return solutions_[index];
}

void Population::addSolution(const Solution& solution) {
    if (positions_.find(solution.fitness()) != positions_.end()) return;
    if (std::prev(positions_.end())->first <= solution.fitness()) return;
    if (nbSolutions_ >= parameters_.maxPopulationSize()) {
        while (nbSolutions_ >= parameters_.populationSize()) {
            removeWorstSolution();
        }
    }
    solutions_[nbSolutions_] = Solution(solution);
    positions_[solution.fitness()] = nbSolutions_;
    nbSolutions_++;
}

const Solution& Population::getBestSolution() const {
    return solutions_[positions_.begin()->second];
}

void Population::removeWorstSolution() {
    nbSolutions_--;
    int worstPosition = std::prev(positions_.end())->second;
    positions_[solutions_[nbSolutions_].fitness()] = worstPosition;
    std::swap(solutions_[worstPosition], solutions_[nbSolutions_]);
    positions_.erase(solutions_[nbSolutions_].fitness());
}