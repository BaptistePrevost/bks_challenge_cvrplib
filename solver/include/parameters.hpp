#pragma once

class Parameters {

    public:
    Parameters(int populationSize, int maxPopulationSize, int maxNbRoutes);

    const int populationSize() const;
    const int maxPopulationSize() const;
    const int maxNbRoutes() const;

    private:
    int populationSize_;
    int maxPopulationSize_;
    int maxNbRoutes_;
};