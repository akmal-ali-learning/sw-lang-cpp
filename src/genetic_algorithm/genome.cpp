#include "genome.h"
#include <random>
#include <functional>

Genome Genome::mix(const Genome& other) const
{
    std::vector<uint32_t> out_genome = {};
    auto this_genome = get_raw_genome();
    auto other_genome = other.get_raw_genome();
    auto random_bool_gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    for(int i = 0; i< this_genome.size(); ++i )
    {
        bool from_other = random_bool_gen();
        if(from_other)
        {
            out_genome.push_back(other_genome[i]);
        }
        else
        {
            out_genome.push_back(this_genome[i]);
        }
    }
    return Genome(out_genome);
}

Genome::Genome(std::vector<uint32_t> raw_genome)
    : m_genome(raw_genome) 
{
}
