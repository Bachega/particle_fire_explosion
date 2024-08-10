#include "Particle.h"

namespace project {
Particle::Particle()
{
    m_x = ((2.0 * rand()) / RAND_MAX) - 1;
    m_y = ((2.0 * rand()) / RAND_MAX) - 1;

    m_xVelocity = 0.001 * (((2.0 * rand())/RAND_MAX) - 1);
    m_yVelocity = 0.001 * (((2.0 * rand())/RAND_MAX) - 1);
}

Particle::~Particle()
{

}

void Particle::update()
{
    m_x += m_xVelocity;
    m_y += m_yVelocity;
}
}