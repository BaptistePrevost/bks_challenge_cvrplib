#include "solution.hpp"
#include <algorithm>
#include <random>

Solution::Solution() {}

Solution::Solution(const Instance& instance, const Parameters& parameters) {
    tour_.resize(instance.nbCustomers());
    for (int c=0; c<instance.nbCustomers(); c++)
        tour_[c] = c;
    std::random_shuffle(tour_.begin(), tour_.end());
    
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

[[ nodiscard ]]
const double Solution::totalDistance() const {
    return totalDistance_;
}

[[ nodiscard ]]
const double Solution::fitness() const {
    return totalDistance_;
}

void Solution::addCustomer(int customer, int index) {
    tour_[index] = customer;
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

[[ nodiscard ]]
bool Solution::check(const Instance& instance) const {
    std::vector<bool> seen(instance.nbCustomers(), false);
    int nbSeens = 0;
    for (int c : tour_) {
        if (!seen[c]) nbSeens++;
        else return false;
        seen[c] = true;
    }
    if (nbSeens != instance.nbCustomers()) 
        return false;
    
    nbSeens = 0;
    std::fill(seen.begin(), seen.end(), false);
    for (const std::vector<int>& route : routes_) {
        for (int c : route) {
            if (!seen[c]) nbSeens++;
            else return false;
            seen[c] = true;
        }
    }
    if (nbSeens != instance.nbCustomers())
        return false;
    return true;
}