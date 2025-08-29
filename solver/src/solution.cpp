#include "solution.hpp"
#include <algorithm>
#include <random>

Solution::Solution(const Instance& instance) {
    tour_.clear();
    for (int c=0; c<instance.nbCustomers(); c++)
        tour_.push_back(c);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tour_.begin(), tour_.end(), g);
}