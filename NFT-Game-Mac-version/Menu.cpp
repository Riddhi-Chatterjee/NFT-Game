#include "Menu.hpp"
#include "Application.h"
#include "UITracker.hpp"
#include "Label.hpp"
#include <fstream>
Menu::Menu(SDL_Window *window, SDL_Renderer *renderer)
{
    count = 0;
    this->renderer = renderer;
    SDL_Surface *temp_sur = SDL_LoadBMP("gamemenu.bmp");
    background_texture = SDL_CreateTextureFromSurface(renderer, temp_sur);
    uit = new UITracker(renderer);
    SDL_FreeSurface(temp_sur);
    isRunning = true;
}
int Menu::Start()
{
    addButton("Start.bmp", 420, 450, 240, 125, '!');
    
    while (isRunning)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        uit->processInput(event);
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            return 1;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
                return 1;
            }
            break;
        }
        if(uit->isPressedStatus(0))
        {
            isRunning = false;
        }
        render();
    }
    return 0;
}
void Menu::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background_texture, NULL, NULL);
    uit->render();
    SDL_RenderPresent(renderer);
}

void Menu::addButton(const char *path, int pos_x, int pos_y, int width, int height, char mouseResponse)
{
    std::string mResp = "";
    mResp += mouseResponse;
    SDL_Surface *temp_sur = SDL_LoadBMP(path);
    SDL_Texture *temp_tex = SDL_CreateTextureFromSurface(renderer, temp_sur);
    uit->addLabel(pos_x, pos_y, width, height, renderer, temp_tex);
    SDL_FreeSurface(temp_sur);
    uit->setMouseResponse(count, mResp);
    count++;
}