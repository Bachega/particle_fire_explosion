#include "Particle.h"

namespace project {
Particle::Particle()
{
    m_x = ((2.0 * rand()) / RAND_MAX) - 1;
    m_y = ((2.0 * rand()) / RAND_MAX) - 1;
}

Particle::~Particle()
{

}

void Particle::update()
{
    const double velocity = 0.01;

    m_x += velocity;
    m_y += velocity;
}
}