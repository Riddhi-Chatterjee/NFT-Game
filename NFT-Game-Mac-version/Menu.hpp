#include "SDL2.framework/Headers/SDL.h"
#include "SDL2_image.framework/Headers/SDL_image.h"
#include <string>
#include <queue>
#include <fstream>
class Menu
{
private:
    SDL_Texture *background_texture;
    SDL_Renderer *renderer;
    class UITracker *uit;
    bool isRunning;


public:
    Menu(SDL_Window *window, SDL_Renderer *renderer);
    void Start();
    void render();
};