#pragma once

#include "selections/selection.hpp"

class BinaryTournament : public Selection {

    public:
    BinaryTournament();

    const Solution& select(const Population& population) const override final;

};