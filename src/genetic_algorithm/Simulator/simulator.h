#pragma once
#include "../specimen.h"
#include <vector>
class Simulator
{
    public:
    Simulator(size_t initial_population);
    
    bool simulate_next_wave();
    size_t run(size_t n_waves);


    private:
    std::vector<Specimen> m_specimens;
    size_t m_wave;
};