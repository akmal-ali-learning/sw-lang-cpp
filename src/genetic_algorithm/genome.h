#pragma once
#include <stdint.h>
#include <vector>
class Genome
{
    public:
    Genome(){};
    Genome(std::vector<uint32_t> raw_genome);
    Genome mix(const Genome& other)const ;
    std::vector<uint32_t> get_raw_genome() const { return m_genome; };
    private:
    std::vector<uint32_t> m_genome;
};