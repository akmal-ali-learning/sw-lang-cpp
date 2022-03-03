#include "specimen.h"
#include <random>

Specimen Specimen::procreate(const Specimen& other) const 
{
    return Specimen(genome.mix(other.genome) );
}

uint32_t random_gene()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> distrib(0, UINT32_MAX);
    return distrib(gen);
}

Specimen::Specimen()
{
    state.alive = true;
    state.r = 0.0f;
    state.g = 0.0f;
    state.b = 0.0f;

    std::vector<uint32_t> genes = {random_gene(), random_gene() };
    genome = Genome(genes);
}

Specimen::Specimen(Genome in_genome) 
{
    state.alive = true;
    state.r = 0.0f;
    state.g = 0.0f;
    state.b = 0.0f;
    genome = in_genome;
}
