#pragma once

#include "bipartitions/bipartition.hpp"
#include <vector>

class SwapBipartition : public Bipartition {
    
    public:
    SwapBipartition(int size);

    void setIn(int value) override final;

    const bool isIn(int value) const override final;

    void clear() override final;
    
    const int sizeIn() const;

    private:
    int size_;
    int sizeIn_;
	std::vector<int> values_;
	std::vector<int> positions_;
};