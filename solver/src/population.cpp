#include "population.hpp"
#include "parameters.hpp"

Population::Population(Instance& instance, Parameters& parameters, Split& split) : 
        instance_(instance), 
        parameters_(parameters),
        split_(split) {}

void Population::generate() {
    for (int i = 0; i < parameters_.populationSize(); i++) {
        Solution solution = Solution(instance_, parameters_);
        split_.process(solution);
        solutions_.insert(solution);
    }
}

[[ nodiscard ]]
std::set<Solution>& Population::solutions() {
    return solutions_;
}

[[ nodiscard ]]
const Solution& Population::getRandomSolution() const {
    int index = std::rand() % solutions_.size();
    return *(std::next(solutions_.begin(), index));
}

void Population::addSolution(Solution& solution) {
    solutions_.insert(Solution(solution));
    if (static_cast<int>(solutions_.size()) > parameters_.populationSize())
        solutions_.erase(std::prev(solutions_.end()));
}

const Solution& Population::getBestSolution() const {
    return *solutions_.begin();
}