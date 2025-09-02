#pragma once

#include <vector>
#include "instance.hpp"
#include "parameters.hpp"

/**
 * Class for a solution of the CVRP.
 * The solution is always represented as a giant tour.
 * Eventually, 
 */
class Solution {
    
    public:
    Solution();
    Solution(const Solution& solution);
    Solution(const Instance& instance, const Parameters& parameters);

    /** Returns the solution giant tour */
    const std::vector<int>& tour() const;
    
    /** Returns the solution routes */
    const std::vector<std::vector<int>>& routes() const;
    
    /** Returns the solution number of routes */
    const int nbRoutes() const;
    
    /** Returns the routes total distance */
    const double totalDistance() const;
    
    /** Returns the solution fitness */
    const double fitness() const;
    
    /** Compares fitness of two solutions */
    const bool operator<(const Solution& other) const;

    /** Sets a value in the giant tour at the specified index */
    void addCustomer(int customer, int index);

    /** Resets the routes */
    void resetRoutes();

    /** Adds a route with size routeSize and distance routeDistance to the routes */
    void addRoute(const std::vector<int>& route, int routeSize, double routeDistance);
    
    /** Sets the fitness of the solution */
    void setFitness(double fitness);

    /** For debug purpose, checks the integrity of the solution */
    bool check(const Instance& instance) const;

    private:
    std::vector<int> tour_;                 //Giant tour
    std::vector<std::vector<int>> routes_;  //Routes
    int nbRoutes_;                          //Number of routes
    double totalDistance_;                  //Total distance
    double fitness_;                        //Fitness
};