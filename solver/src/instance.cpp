#include "instance.hpp"
#include <fstream>
#include <iostream>

Instance::Instance(std::string path) {
    std::ifstream f(path);
    if (!f.is_open()) {
        std::cerr << "Error opening the file with path " << path;
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