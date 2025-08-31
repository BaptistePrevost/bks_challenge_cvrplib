#include "instance.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

[[ nodiscard ]]
double Coordinate::distTo(const Coordinate& other) const {
    return std::floor(std::sqrt((other.x - x)*(other.x - x) + (other.y - y)*(other.y - y)) + 0.5);
}

Instance::Instance(std::string path) {
    std::ifstream f(path);
    if (!f.is_open()) {
        std::cerr << "Error opening the file with path " << path << std::endl;
        return;
    }
    
    std::string s;
    parseName(f);
    parseComment(f);
    parseType(f);
    parseDimension(f);
    parseEdgeWeightType(f);
    parseCapacity(f);
    parseCoordinates(f);
    parseDemands(f);
    parseDepot(f);

    computeDistancesWithDepot();
    computeDistances();
}

[[ nodiscard ]]
const int Instance::dimension() const {
    return dimension_;
}

[[ nodiscard ]]
const int Instance::nbCustomers() const {
    return nbCustomers_;
}

[[ nodiscard ]]
const int Instance::capacity() const {
    return capacity_;
}

[[ nodiscard ]]
const std::vector<Coordinate>& Instance::coordinates() const {
    return coordinates_;
}

[[ nodiscard ]]
const std::vector<int>& Instance::demands() const {
    return demands_;
}

[[ nodiscard ]]
const int Instance::demand(int c) const {
    if (c < 0 || c >= nbCustomers_)
        throw std::string("Wrong customer index");
    return demands_[c+1];
}

[[ nodiscard ]]
const Coordinate& Instance::pointCoordinate(int i) const {
    if (i < 0 || i >= dimension_)
        throw std::string("Wrong point index");
    return coordinates_[i];
}

[[ nodiscard ]]
const Coordinate& Instance::depotCoordinate() const {
    return coordinates_[0];
}

[[ nodiscard ]]
const Coordinate& Instance::customerCoordinate(int c) const {
    if (c < 0 || c >= nbCustomers_)
        throw std::string("Wrong customer index");
    return coordinates_[c+1];
}

[[ nodiscard ]]
const double Instance::distanceWithDepot(int c) const {
    return distancesWithDepot_[c];
}


[[ nodiscard ]]
const double Instance::distance(int c, int d) const {
    return distances_[c][d];
}

void Instance::parseName(std::ifstream& f) {
    std::getline(f, name_);
    name_.erase(0, 7);
}

void Instance::parseComment(std::ifstream& f) {
    std::getline(f, comment_);
    comment_.erase(0, 10);
}

void Instance::parseType(std::ifstream& f) {
    std::getline(f, type_);
    type_.erase(0, 7);
}

void Instance::parseDimension(std::ifstream& f) {
    std::string s;
    std::getline(f, s);
    s.erase(0, 12);
    dimension_ = std::stoi(s);
    nbCustomers_ = dimension_-1;
}

void Instance::parseEdgeWeightType(std::ifstream& f) {
    std::getline(f, edgeWeightType_);
    edgeWeightType_.erase(0, 19);

}

void Instance::parseCapacity(std::ifstream& f) {
    std::string s;
    std::getline(f, s);
    s.erase(0, 11);
    capacity_ = std::stoi(s);
}

void Instance::parseCoordinates(std::ifstream& f) {
    std::string s;
    std::getline(f, s);
    for (int i=0; i<dimension_; i++) {
        std::getline(f, s);
        int valueStart = s.find(' ');
        while (s[valueStart] == ' ') valueStart++;
        s.erase(0, valueStart);
        valueStart = s.find(' ');
        while (s[valueStart] == ' ') valueStart++;
        s.erase(0, valueStart);
        int x = std::stoi(s);
        
        valueStart = s.find(' ');
        while (s[valueStart] == ' ') valueStart++;
        s.erase(0, valueStart);
        int y = std::stoi(s);
        
        coordinates_.push_back({x, y});
    }
}

void Instance::parseDemands(std::ifstream& f) {
    std::string s;
    std::getline(f, s);
    for (int i=0; i<dimension_; i++) {
        std::getline(f, s);
        int valueStart = s.find(' ');
        while (s[valueStart] == ' ') valueStart++;
        s.erase(0, valueStart);
        demands_.push_back(std::stoi(s));
    }
}

void Instance::parseDepot(std::ifstream& f) {
    std::string s;
    std::getline(f, s);
    std::getline(f, s);
    int depotIndex = std::stoi(s);
    if (depotIndex != 1)
        throw std::string("Error parsing the depot");
}

void Instance::computeDistancesWithDepot() {
    distancesWithDepot_.resize(nbCustomers_);
    for (int c=0; c<nbCustomers_; c++)
        distancesWithDepot_[c] = depotCoordinate().distTo(customerCoordinate(c));
}

void Instance::computeDistances() {
    distances_.resize(nbCustomers_);
    for (int c=0; c<nbCustomers_; c++) {
        distances_[c].resize(nbCustomers_);
        for (int d=0; d<nbCustomers_; d++) {
            distances_[c][d] = customerCoordinate(c).distTo(customerCoordinate(d));
        }
    }
}