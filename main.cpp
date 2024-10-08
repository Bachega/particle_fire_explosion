#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>

#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"

using namespace std;

using project::Screen;
using project::Particle;
using project::Swarm;

int main(int argc, char ** argv)
{
    srand(time(0));

    Screen screen;
    screen.init();

    Swarm swarm;

    unsigned char red, green, blue;
    unsigned int elapsed;
    for(;;)
    {
        // Update particles

        // Clear the screen
        // screen.clear();

        // Draw particles
        swarm.update(elapsed);
        
        elapsed = SDL_GetTicks();
        red = (unsigned char)((1 + sin(elapsed * 0.0007)) * 128);
        green = (unsigned char)((1 + sin(elapsed * 0.0008)) * 128);
        blue = (unsigned char)((1 + sin(elapsed * 0.0009)) * 128);

        double halfScreenWidth = Screen::SCREEN_WIDTH/2;
        double halfScreenHeight = Screen::SCREEN_HEIGHT/2;

        const Particle * const pParticles = swarm.getParticles();
        for (int i = 0; i < Swarm::N_PARTICLES; i++)
        {
            Particle particle = pParticles[i];
            
            // MAYBE DECLARE BEFORE THE FOR LOOP?
            halfScreenWidth = Screen::SCREEN_WIDTH/2;
            halfScreenHeight = Screen::SCREEN_HEIGHT/2;

            unsigned int x = (particle.m_x + 1) * halfScreenWidth;
            unsigned int y = particle.m_y * halfScreenWidth + halfScreenHeight;

            screen.setPixel(x, y, red, green, blue);
        }

        screen.boxBlur();

        // Draw the screen
        screen.update();

        // Check for messages/events
        if(!screen.processEvents())
            break;
    }
    screen.close();

    return 0;
}