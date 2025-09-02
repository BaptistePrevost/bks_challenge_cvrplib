#pragma once

#include "bipartitions/bipartition.hpp"
#include <vector>

class LazyBipartition : public Bipartition {
    
    public:
    LazyBipartition(int size);

    void setIn(int value) override final;

    const bool isIn(int value) const override final;

    void clear() override final;

    private:
    int size_;
    unsigned int currentGeneration_;
	std::vector<unsigned int> generations_;
};