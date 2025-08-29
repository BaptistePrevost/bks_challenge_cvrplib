#pragma once

class Parameters {

    public:
    Parameters(int populationSize);

    const int populationSize() const;

    private:
    int populationSize_;
};