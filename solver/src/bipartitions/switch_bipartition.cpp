#include "bipartitions/switch_bipartition.hpp"

SwitchBipartition::SwitchBipartition(int size) : size_(size), stateIn_(true) {
    states_.resize(size);
    for (int i = 0; i < size; i++) states_[i] = !stateIn_;
}

void SwitchBipartition::setIn(int value) {
    states_[value] = stateIn_;
}

[[ nodiscard ]]
const bool SwitchBipartition::isIn(int value) const {
    return states_[value] == stateIn_;
}

void SwitchBipartition::clear() {
    stateIn_ = !stateIn_;
}