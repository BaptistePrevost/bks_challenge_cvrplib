#pragma once

#include "bipartitions/bipartition.hpp"
#include <vector>

class SwitchBipartition : public Bipartition {

    public:
    SwitchBipartition(int size);

    void setIn(int value) override final;

    const bool isIn(int value) const override final;

    void clear() override final;

    private:
    int size_;
    bool stateIn_;
    std::vector<bool> states_;

};