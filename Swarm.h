#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace project
{
class Swarm
{
private:
    Particle * m_pParticles;
    int m_lastElapsed;

public:
    const static unsigned int N_PARTICLES = 5000;

    Swarm();
    ~Swarm();

    void update(int elapsed);

    const Particle * const getParticles();
};
}

#endif // SWARM_H_