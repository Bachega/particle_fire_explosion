#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <SDL2/SDL.h>

using std::cout;
using std::endl;

namespace project {

class Screen
{
private:
    SDL_Window * m_pWindow;
    SDL_Renderer * m_pRenderer;
    SDL_Texture * m_pTexture;
    Uint32 * m_pBuffer;

public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

    Screen();
    ~Screen();
    bool init();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvents();
    void close();
    

};
};

#endif // SCREEN_H_