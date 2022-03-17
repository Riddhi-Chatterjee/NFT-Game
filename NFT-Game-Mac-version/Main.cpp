
#include "Core.h"
#include "Application.h"
#include "Menu.hpp"


int main(int argc, char* argv[])
{

    int error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code)
    {
        std::cout << "Init Failed\nERROR CODE: " << error_code << "\n";
        return 1;
    };
    int width, height;
    SDL_Window *window = SDL_CreateWindow("NFT Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (!window)
    {
        std::cout << "Window Creation Failed\n";
        return 2;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        std::cout << "Renderer Creation Failed\n";
        return 3;
    }

    Menu *menu = new Menu(window, renderer);
    menu->Start();

    return 0;

    return 0;
}