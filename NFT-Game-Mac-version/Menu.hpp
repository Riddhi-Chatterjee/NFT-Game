#include "SDL2.framework/Headers/SDL.h"
#include "SDL2_image.framework/Headers/SDL_image.h"
#include <string>
#include <queue>
#include <fstream>
#include <thread>
#include <fstream>
#include <iostream>
class Menu
{
private:
    SDL_Texture *background_texture;
    SDL_Renderer *renderer;
    class UITracker *uit;
    bool isRunning;
    int count;
    int sword;


public:
    Menu(SDL_Window *window, SDL_Renderer *renderer);
    int Start();
    void render();
    void addButton(const char *path, int pos_x, int pos_y, int width, int height, char mouseResponse);
    int getSword();
};