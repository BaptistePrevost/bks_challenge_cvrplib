#pragma once

#include <vector>
#include "instance.hpp"
#include "parameters.hpp"

class Solution {
    
    public:
    Solution();
    Solution(const Instance& instance, const Parameters& parameters);

    const std::vector<int>& tour() const;
    const std::vector<std::vector<int>>& routes() const;
    const int nbRoutes() const;

    void resetRoutes();
    void addRoute(const std::vector<int>& route, int routeSize, double routeDistance);

    private:
    std::vector<int> tour_;
    std::vector<std::vector<int>> routes_;
    int nbRoutes_;
    double totalDistance_;
};