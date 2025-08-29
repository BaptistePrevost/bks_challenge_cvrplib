#include "split.hpp"

Split::Split(Instance& instance) : instance_(instance), route_(instance.nbCustomers()) {}

void Split::process(Solution& solution) {
    solution.resetRoutes();
    int index = 0;
    int routeSize, cumulatedDemand;
    double routeDistance;
    while (index < instance_.nbCustomers()) {
        routeSize = 0;
        cumulatedDemand = 0;
        routeDistance = 0;
        while (index < instance_.nbCustomers()) {
            int customerIndex = solution.tour()[index];
            int customerDemand = instance_.demand(customerIndex);
            if (cumulatedDemand + customerDemand > instance_.capacity())
                break;
            cumulatedDemand += customerDemand;
            route_[routeSize] = customerIndex;
            if (routeSize > 0)
                routeDistance += instance_.distance(route_[routeSize-1], route_[routeSize]);
            routeSize++;
            index++;
        }
        routeDistance += instance_.distanceWithDepot(route_[0]) + (routeSize > 1 ? instance_.distanceWithDepot(route_[routeSize-1]) : 0);
        solution.addRoute(route_, routeSize, routeDistance);
    }
}