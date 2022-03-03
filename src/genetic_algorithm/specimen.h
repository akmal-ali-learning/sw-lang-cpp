#pragma once
#include <stdint.h>
#include "physicalstate.h"
#include "genome.h"

class Specimen
{
    public:
    Specimen();
    Specimen(Genome genome);

    PhysicalState state;
    Genome   genome;

    Specimen procreate(const Specimen& other) const;
};
