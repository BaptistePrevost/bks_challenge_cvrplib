#pragma once

#include "crossovers/crossover.hpp"
#include "instance.hpp"

class OrderedCrossover : public Crossover {

    public:
    OrderedCrossover(Instance& instance);

    void cross(const Solution& left, const Solution& right, Solution& child) override final;

    private:
    Instance& instance_;
    std::vector<bool> inserted_;
    /** 
     * TODO : Benchmark with a bitset
     * One could also use a vector of timestamps : 
     * - to reset, increase the current timestamp by one
     * - when updating, set to current timestamp
     * - then, compare each stored timestamp with the current to know if recent update
     */
};