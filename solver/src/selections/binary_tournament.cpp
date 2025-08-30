#include "selections/binary_tournament.hpp"

BinaryTournament::BinaryTournament() {}

const Solution& BinaryTournament::select(const Population& population) const {
    const Solution& left = population.getRandomSolution();
    const Solution& right = population.getRandomSolution();
    if (left.fitness() < right.fitness()) return left;
    return right;
}