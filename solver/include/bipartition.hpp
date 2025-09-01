#pragma once

#include <vector>

class Bipartition {
    
    public:
    Bipartition(int size);

    void setIn(int value);

    const bool isIn(int value) const;

    const int sizeIn() const;

    void clear();

    private:
    int size_;
    int sizeIn_;
	std::vector<int> values_;
	std::vector<int> positions_;
};