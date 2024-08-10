#include "Particle.h"

namespace project {
Particle::Particle(): m_x(0), m_y(0)
{
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_velocity = (0.001 * rand())/RAND_MAX;
}

Particle::~Particle()
{

}

void Particle::update()
{
    double xVelocity = m_velocity * cos(m_direction);
    double yVelocity = m_velocity * sin(m_direction);

    m_x += xVelocity;
    m_y += yVelocity;
}
}