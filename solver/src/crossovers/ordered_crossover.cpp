#include "crossovers/ordered_crossover.hpp"
#include <random>

OrderedCrossover::OrderedCrossover(Instance& instance) :
        instance_(instance), inserted_(instance.nbCustomers(), false) {}

void OrderedCrossover::cross(Solution& left, Solution& right, Solution& child) {
    std::fill(inserted_.begin(), inserted_.end(), false);

    int index = std::rand() % instance_.nbCustomers();
    int end = std::rand() % instance_.nbCustomers();
    while (index != end) {
        int customer = left.tour()[index];
        child.addCustomer(customer, index);
        inserted_[customer] = true;
        index++;
        if(index == instance_.nbCustomers()) index = 0;
    }
    int customerIndex = end;
    do {
        int customer = right.tour()[index];
        if (!inserted_[customer]) {
            child.addCustomer(customer, customerIndex);
            customerIndex++;
            if(customerIndex == instance_.nbCustomers()) customerIndex = 0;
        }
        inserted_[customer] = true;
        index++;
        if(index == instance_.nbCustomers()) index = 0;
    } while (index != end);
    
}