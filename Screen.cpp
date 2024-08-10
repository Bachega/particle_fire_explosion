#include "Screen.h"

namespace project {
Screen::Screen()
{
    m_pWindow = NULL, m_pRenderer = NULL, m_pTexture = NULL, m_pBuffer = NULL, m_pBufferBlurred = NULL;
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

    m_pBufferBlurred = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    memset(m_pBufferBlurred, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

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
    
    if(m_pBufferBlurred)
        delete [] m_pBufferBlurred;

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

void Screen::clear()
{
    memset(m_pBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(m_pBufferBlurred, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::boxBlur()
{
    // Swap the buffers
    Uint32 * auxBuffer = m_pBuffer;
    m_pBuffer = m_pBufferBlurred;
    m_pBufferBlurred = auxBuffer;

    for(int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for(int x = 0; x < SCREEN_WIDTH; x++)
        {
            
            int redTotal = 0, greenTotal = 0, blueTotal = 0;
            
            for(int row = -1; row <= 1; row++)
            {
                for(int col = -1; col <= 1; col++)
                {
                    int gridX = x + col;
                    int gridY = y + row;
                    
                    // IF THE GRID PIXELS ARE INSIDE THE SCREEN
                    if(gridX >= 0 && gridX < SCREEN_WIDTH && gridY >=0 && gridY < SCREEN_HEIGHT)
                    {
                        Uint32 color = m_pBufferBlurred[gridY * SCREEN_WIDTH + gridX];

                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;
                        
                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                    }
                }
            }

            Uint8 red = redTotal/9;
            Uint8 green = greenTotal/9;
            Uint8 blue = blueTotal/9;

            setPixel(x, y, red, green, blue);
        }
    }
}
}
