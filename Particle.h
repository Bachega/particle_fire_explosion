#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>

using namespace std;

namespace project {
class Particle
{
private:
    
public:
    double m_x;
    double m_y;
    double m_velocity;
    double m_direction;
    
    Particle();
    void init();
    ~Particle();
    void update(int interval);
};
}


#endif // PARTICLE_H_