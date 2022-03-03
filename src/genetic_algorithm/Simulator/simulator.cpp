#include "Simulator.h"
#include <random>

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) 
{
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) 
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

bool Simulator::simulate_next_wave()
{
    std::vector<Specimen> survivors = {};
    // Check if dead/alive.
    for( auto& specimen : m_specimens)
    {
        specimen.state.alive = true;
        if(specimen.genome.get_raw_genome().at(0) %2 == 0)
        {
            specimen.state.alive = false;
        }
        if(specimen.genome.get_raw_genome().at(1) %2 == 0)
        {
            specimen.state.alive = false;
        }
    }

    // Count survivors
    for( auto& specimen : m_specimens)
    {
        if(specimen.state.alive)
        {
            survivors.push_back(specimen);
        }
    }
    if( survivors.empty() )
    {
        return true;
    }
    const double survival_percentage = survivors.size()/(0.01 * m_specimens.size() );
    printf("Survival percentage %f \n", survival_percentage );

    std::vector<Specimen> children = {}; 
    for( int i = 0 ; i < m_specimens.size(); ++i)
    {
        auto father = *select_randomly(survivors.begin(), survivors.end());
        auto mother = *select_randomly(survivors.begin(), survivors.end());
        children.push_back(father.procreate(mother));
    }

    m_specimens = children;
    m_wave++;
    return false;

}


size_t Simulator::run(size_t n_waves) 
{
    for(int i = 0 ; i < n_waves; ++i)
    {
        bool extinction = simulate_next_wave();
        if(extinction)
            break;
    }
    return m_wave;
}

// Constructor
Simulator::Simulator(size_t initial_population) 
{
    m_specimens = std::vector<Specimen>(initial_population);
    m_wave = 0;
}
