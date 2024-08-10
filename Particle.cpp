#include "Particle.h"

namespace project {
Particle::Particle(): m_x(0), m_y(0)
{
    init();
}

void Particle::init()
{
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_velocity = (0.02 * rand())/RAND_MAX;
    m_velocity *= m_velocity;
}

Particle::~Particle()
{

}

void Particle::update(int interval)
{
    m_direction += interval * 0.0005;

    double xVelocity = m_velocity * cos(m_direction);
    double yVelocity = m_velocity * sin(m_direction);

    m_x += xVelocity * interval;
    m_y += yVelocity * interval;

    if(m_x < -1 || m_x > 1 || m_y < -1 || m_x > 1)
        init();
    
    if(rand() < RAND_MAX/100)
        init();
}
}