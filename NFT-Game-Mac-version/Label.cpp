#include "Label.hpp"
#include <iostream>
#include <vector>
Label::Label(int pos_x, int pos_y, int width, int height, SDL_Renderer *renderer, int fill[], Uint8 font_colour[], std::string str, int font_size = 0)
{
    destRect.x = pos_x;
    destRect.y = pos_y;
    destRect.w = width;
    destRect.h = height;
    this->renderer = renderer;
    this->fillR = (int)fill[0];
    this->fillG = (int)fill[1];
    this->fillB = (int)fill[2];
    this->str = str;
    this->isVisible = true;
    Image = NULL;
}
Label::Label(int pos_x, int pos_y, int width, int height, SDL_Renderer *renderer, SDL_Texture *texture)
{
    destRect.x = pos_x;
    destRect.y = pos_y;
    destRect.w = width;
    destRect.h = height;
    this->renderer = renderer;
    this->str = str;
    this->isVisible = true;
    this->Image = texture;
    Message = NULL;
}
bool Label::inElement(int x, int y)
{
    return (x > destRect.x && y > destRect.y && y < destRect.y + destRect.h && x < destRect.x + destRect.w);
}
void Label::render()
{
    if (isVisible)
    {
        if (Image == NULL)
        {
            SDL_SetRenderDrawColor(renderer, fillR, fillG, fillB, 0);
            SDL_RenderFillRect(renderer, &destRect);
            SDL_RenderCopy(renderer, this->Message, NULL, &destRect);
        }
        else
        {
            SDL_RenderCopy(renderer, this->Image, NULL, &destRect);
        }
    }
}
std::string Label::processEvent(int x, int y, int buttonState)
{
    if (buttonState & SDL_BUTTON_LMASK)
    {
        return mouseResponse;
    }
    return "";
}
void Label::makeInvisible()
{
    isVisible = false;
}
void Label::makeVisible()
{
    isVisible = true;
}
void Label::setMouseResponse(std::string mouseResponse)
{
    this->mouseResponse = mouseResponse;
}
std::string Label::getMouseResponse()
{
    return mouseResponse;
}