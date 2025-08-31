#pragma once

#include "solution.hpp"

class Crossover {

    public:
    virtual ~Crossover() = default;
    virtual void cross(const Solution& left, const Solution& right, Solution& child) = 0;
};