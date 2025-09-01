#include "bipartition.hpp"

Bipartition::Bipartition(int size) : size_(size), sizeIn_(0) {
    values_.resize(size);
    positions_.resize(size);
    for (int i = 0; i < size; i++) {
        positions_[i] = i;
        values_[i] = i;
    }
}

void Bipartition::setIn(int value) {
    if (isIn(value)) return;
    std::swap(values_[sizeIn_], values_[positions_[value]]);
    positions_[values_[positions_[value]]] = positions_[value];
    positions_[value] = sizeIn_;
    sizeIn_++;
}

[[ nodiscard ]]
const bool Bipartition::isIn(int value) const {
    return positions_[value] < sizeIn_;
}

[[ nodiscard ]]
const int Bipartition::sizeIn() const {
    return sizeIn_;
}

void Bipartition::clear() {
    sizeIn_ = 0;
}