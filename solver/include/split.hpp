#pragma once

#include "solution.hpp"
#include <vector>

class Split {
    
    public:
    Split(Instance& instance);

    void process(Solution& solution);

    private:
    Instance& instance_;
    std::vector<int> route_;
    
};