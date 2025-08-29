#pragma once

class Parameters {

    public:
    Parameters(int populationSize, int maxNbRoutes);

    const int populationSize() const;
    const int maxNbRoutes() const;

    private:
    int populationSize_;
    int maxNbRoutes_;
};