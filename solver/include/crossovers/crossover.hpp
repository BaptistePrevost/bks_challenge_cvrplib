#pragma once

#include "solution.hpp"

class Crossover {

    public:
    virtual ~Crossover() = default;
    virtual void cross(Solution& left, Solution& right, Solution& child) = 0;
};