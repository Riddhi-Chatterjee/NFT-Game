#pragma once
#include <vector>
#include "SDL2.framework/Headers/SDL.h"
class UIElement;
class UITracker
{
private:
    int x, y;
    Uint8 buttonState;
    std::vector<class UIElement *> UIList;
    SDL_Renderer *renderer;
    std::vector<bool> inElementArr;

public:
    UITracker(SDL_Renderer *renderer);
    void addLabel(int pos_x, int pos_y, int width, int height, SDL_Renderer *renderer, std::string str, int fill[], Uint8 font_colour[], int font_size);
    void addLabel(int pos_x, int pos_y, int width, int height, SDL_Renderer *renderer, SDL_Texture *texture);
    void setMouseResponse(int i, std::string response);
    void addUIElement(class UIElement *uie);
    void render();
    void Update();
    std::string processInput(SDL_Event event);
    ~UITracker();
    std::vector<bool> getInElementArr();
    Uint8 getButtonState();
};
