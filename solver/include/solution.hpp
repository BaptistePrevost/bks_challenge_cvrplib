#pragma once

#include <vector>
#include "instance.hpp"
#include "parameters.hpp"

class Solution {
    
    public:
    Solution();
    Solution(const Solution& solution);
    Solution(const Instance& instance, const Parameters& parameters);

    const std::vector<int>& tour() const;
    const std::vector<std::vector<int>>& routes() const;
    const int nbRoutes() const;
    const double totalDistance() const;
    const double fitness() const;
    const bool operator<(const Solution& other) const;

    void addCustomer(int customer, int index);

    void resetRoutes();
    void addRoute(const std::vector<int>& route, int routeSize, double routeDistance);
    void setFitness(double fitness);

    bool check(const Instance& instance) const;

    private:
    std::vector<int> tour_;
    std::vector<std::vector<int>> routes_;
    int nbRoutes_;
    double totalDistance_;
    double fitness_;
};