#pragma once

#include <string>
#include <vector>

struct Coordinate {
    int x;
    int y;

    double distTo(const Coordinate& other) const;
};

class Instance {

    public:
    Instance(std::string path);

    const int dimension() const;
    const int nbCustomers() const;
    const int capacity() const;

    const int demand(int c) const;

    const Coordinate& pointCoordinate(int i) const;
    const Coordinate& depotCoordinate() const;
    const Coordinate& customerCoordinate(int c) const;

    const double distanceWithDepot(int c) const;
    const double distance(int c, int d) const;
    
    private:
    const std::vector<Coordinate>& coordinates() const;
    const std::vector<int>& demands() const;

    void parseName(std::ifstream& f);
    void parseComment(std::ifstream& f);
    void parseType(std::ifstream& f);
    void parseDimension(std::ifstream& f);
    void parseEdgeWeightType(std::ifstream& f);
    void parseCapacity(std::ifstream& f);
    void parseCoordinates(std::ifstream& f);
    void parseDemands(std::ifstream& f);
    void parseDepot(std::ifstream& f);

    void computeDistancesWithDepot();
    void computeDistances();

    std::string name_;
    std::string comment_;
    std::string type_;
    int dimension_;
    int nbCustomers_;
    std::string edgeWeightType_;
    int capacity_;

    std::vector<Coordinate> coordinates_;
    std::vector<int> demands_;

    std::vector<double> distancesWithDepot_;
    std::vector<std::vector<double>> distances_;
};
