#include "Menu.hpp"
#include "Application.h"
#include "UITracker.hpp"
#include "Label.hpp"
#include <fstream>
Menu::Menu(SDL_Window *window, SDL_Renderer *renderer)
{
    this->renderer = renderer;
    SDL_Surface *temp_sur = SDL_LoadBMP("gamemenu.bmp");
    background_texture = SDL_CreateTextureFromSurface(renderer, temp_sur);
    uit = new UITracker(renderer);
    SDL_FreeSurface(temp_sur);
    isRunning = true;
}
void Menu::Start()
{
    SDL_Surface *temp_sur = SDL_LoadBMP("Start.bmp");
    SDL_Texture *temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
    uit->addLabel(420, 450, 240, 125, renderer, temp_tex);
    SDL_FreeSurface(temp_sur);
    uit->setMouseResponse(0, "!");
    while (isRunning)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        uit->processInput(event);
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isRunning = false;
            break;
        }
        if(uit->isPressedStatus(0))
        {
            isRunning = false;
        }
        render();
    }
}
void Menu::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background_texture, NULL, NULL);
    uit->render();
    SDL_RenderPresent(renderer);
}