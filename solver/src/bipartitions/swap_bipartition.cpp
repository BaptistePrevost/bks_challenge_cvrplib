#include "bipartitions/swap_bipartition.hpp"

SwapBipartition::SwapBipartition(int size) : size_(size), sizeIn_(0) {
    values_.resize(size);
    positions_.resize(size);
    for (int i = 0; i < size; i++) {
        positions_[i] = i;
        values_[i] = i;
    }
}

void SwapBipartition::setIn(int value) {
    if (isIn(value)) return;
    std::swap(values_[sizeIn_], values_[positions_[value]]);
    positions_[values_[positions_[value]]] = positions_[value];
    positions_[value] = sizeIn_;
    sizeIn_++;
}

[[ nodiscard ]]
const bool SwapBipartition::isIn(int value) const {
    return positions_[value] < sizeIn_;
}

[[ nodiscard ]]
const int SwapBipartition::sizeIn() const {
    return sizeIn_;
}

void SwapBipartition::clear() {
    sizeIn_ = 0;
}