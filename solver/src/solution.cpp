#include "solution.hpp"
#include <algorithm>
#include <random>

Solution::Solution() {}

Solution::Solution(const Instance& instance, const Parameters& parameters) {
    tour_.resize(instance.nbCustomers());
    for (int c=0; c<instance.nbCustomers(); c++)
        tour_[c] = c;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tour_.begin(), tour_.end(), g);
    
    nbRoutes_ = 0;
    routes_.resize(parameters.maxNbRoutes());
}

[[ nodiscard ]]
const std::vector<int>& Solution::tour() const {
    return tour_;
}

[[ nodiscard ]]
const std::vector<std::vector<int>>& Solution::routes() const {
    return routes_;
}

[[ nodiscard ]]
const int Solution::nbRoutes() const {
    return nbRoutes_;
}

void Solution::resetRoutes() {
    nbRoutes_ = 0;
    totalDistance_ = 0;
}

void Solution::addRoute(const std::vector<int>& route, int routeSize, double routeDistance) {
    if (nbRoutes_ + 1 == static_cast<int>(routes_.size()))
        throw std::string("Maximum number of routes reached");
    routes_[nbRoutes_].resize(routeSize);
    for (int i=0; i<routeSize; i++)
        routes_[nbRoutes_][i] = route[i];
    totalDistance_ += routeDistance;
    nbRoutes_++;
}