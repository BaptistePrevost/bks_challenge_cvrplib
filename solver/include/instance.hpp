#include <string>
#include <vector>

struct Coordinate {
    int x;
    int y;
};

class Instance {

    public:
    Instance(std::string path);

    private:
    void parseName(std::ifstream& f);
    void parseComment(std::ifstream& f);
    void parseType(std::ifstream& f);
    void parseDimension(std::ifstream& f);
    void parseEdgeWeightType(std::ifstream& f);
    void parseCapacity(std::ifstream& f);
    void parseCoordinates(std::ifstream& f);
    void parseDemands(std::ifstream& f);

    std::string name_;
    std::string comment_;
    std::string type_;
    int dimension_;
    std::string edgeWeightType_;
    int capacity_;

    std::vector<Coordinate> coordinates_;
    std::vector<int> demands_;
};
