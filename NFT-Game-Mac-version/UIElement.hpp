#ifndef UIELEMENT
#define UIELEMENT
#include <string>
#include "SDL2.framework/Headers/SDL.h"
class UIElement
{
public:
    virtual bool inElement(int x, int y) = 0;
    virtual void render() = 0;
    virtual std::string processEvent(int x, int y, int buttonState) = 0;
    virtual std::string processEvent(SDL_Event event) = 0;
    virtual void setMouseResponse(std::string mouseResponse) = 0;
};
#endif