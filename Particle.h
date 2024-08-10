#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>

using namespace std;

namespace project {
class Particle
{
private:
    
public:
    double m_x;
    double m_y;
    
    Particle();
    ~Particle();
    void update();
};
}


#endif // PARTICLE_H_