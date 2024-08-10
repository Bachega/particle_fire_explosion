#include "Swarm.h"

namespace project {
Swarm::Swarm(): m_lastElapsed(0)
{
    m_pParticles = new Particle[N_PARTICLES];
}

Swarm::~Swarm()
{
    delete [] m_pParticles;
}

const Particle * const Swarm::getParticles()
{
    return m_pParticles;
}

void Swarm::update(int elapsed)
{
    int interval = elapsed - m_lastElapsed;
    for (int i = 0; i < Swarm::N_PARTICLES; i++)
            m_pParticles[i].update(interval);
    
    m_lastElapsed = elapsed;
}
}