#include "Screen.h"

namespace project {
Screen::Screen()
{
    m_pWindow = NULL, m_pRenderer = NULL, m_pTexture = NULL, m_pBuffer = NULL;
}

Screen::~Screen()
{}

bool Screen::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL INIT failed." << endl;
        return 1;
    }

    m_pWindow = SDL_CreateWindow("Particle Fire Explosion",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH, SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN);

    if(!m_pWindow)
    {
        SDL_Quit();
        return 2;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);

    m_pTexture = SDL_CreateTexture(m_pRenderer, SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if(!m_pRenderer)
    {
        cout << "Could not create renderer" << endl;
        close();
        return false;
    }

    if(!m_pTexture)
    {
        cout << "Could not create texture" << endl;
        close();
        return false;
    }

    m_pBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    memset(m_pBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    update();

    return true;
}

bool Screen::processEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
            return false;
    }
    return true;
}

void Screen::close()
{
    if(m_pBuffer)
        delete [] m_pBuffer;
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyTexture(m_pTexture);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Screen::update()
{
    SDL_UpdateTexture(m_pTexture, NULL, m_pBuffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, NULL);
    SDL_RenderPresent(m_pRenderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
    if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
        return;

    Uint32 pixelColor = 0;

    pixelColor += red;
    pixelColor <<= 8;
    pixelColor += green;
    pixelColor <<= 8;
    pixelColor += blue;
    pixelColor <<= 8;
    pixelColor += 0xff;

    m_pBuffer[(y * SCREEN_WIDTH) + x] = pixelColor;
}

}
    
