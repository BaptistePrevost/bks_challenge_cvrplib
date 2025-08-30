#pragma once

#include "population.hpp"
#include "solution.hpp"

class Selection {

    public:
    virtual ~Selection() = default;
    virtual const Solution& select(const Population& population) const = 0;
};