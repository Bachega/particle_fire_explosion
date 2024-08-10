#include "Swarm.h"

namespace project {
Swarm::Swarm()
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

void Swarm::update()
{
    for (int i = 0; i < Swarm::N_PARTICLES; i++)
            m_pParticles[i].update();
}

}