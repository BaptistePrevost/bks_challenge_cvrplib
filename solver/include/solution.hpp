#pragma once

#include <vector>
#include "instance.hpp"

class Solution {
    
    public:
    Solution(const Instance& instance);

    private:
    std::vector<int> tour_;
    std::vector<std::vector<int>> routes_;
};