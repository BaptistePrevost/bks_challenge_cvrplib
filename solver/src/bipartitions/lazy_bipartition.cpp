#include "bipartitions/lazy_bipartition.hpp"

LazyBipartition::LazyBipartition(int size) : size_(size), currentGeneration_(1) {
    generations_.resize(size);
    std::fill(generations_.begin(), generations_.end(), 0);
}


void LazyBipartition::setIn(int value) {
    generations_[value] = currentGeneration_;
}

[[ nodiscard ]]
const bool LazyBipartition::isIn(int value) const {
    return generations_[value] == currentGeneration_;
}

void LazyBipartition::clear() {
    currentGeneration_++;
    if (currentGeneration_ == 0) {
        std::fill(generations_.begin(), generations_.end(), 0);
        currentGeneration_ = 1;
    }
}