#include "crossovers/ordered_crossover.hpp"
#include <random>

OrderedCrossover::OrderedCrossover(Instance& instance) :
        instance_(instance), inserted_(instance.nbCustomers()) {}

void OrderedCrossover::cross(const Solution& left, const Solution& right, Solution& child) {
    inserted_.clear();
    int index = std::rand() % instance_.nbCustomers();
    int end = std::rand() % instance_.nbCustomers();
    while (index != end) {
        int customer = left.tour()[index];
        child.addCustomer(customer, index);
        inserted_.setIn(customer);
        index++;
        if(index == instance_.nbCustomers()) index = 0;
    }
    int customerIndex = end;
    do {
        int customer = right.tour()[index];
        if (!inserted_.isIn(customer)) {
            child.addCustomer(customer, customerIndex);
            customerIndex++;
            if(customerIndex == instance_.nbCustomers()) customerIndex = 0;
        }
        inserted_.setIn(customer);
        index++;
        if(index == instance_.nbCustomers()) index = 0;
    } while (index != end);
    
}