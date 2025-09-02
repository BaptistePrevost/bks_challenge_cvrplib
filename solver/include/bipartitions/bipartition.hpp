#pragma once

class Bipartition {

    public:
    virtual ~Bipartition() = default;

    virtual void setIn(int value) = 0;

    virtual const bool isIn(int value) const = 0;

    virtual void clear() = 0;
    
};