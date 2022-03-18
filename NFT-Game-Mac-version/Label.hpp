#ifndef LABEL
#define LABEL
#include <iostream>
#include <string>
#include "UIElement.hpp"
class Label : public UIElement
{
private:
    SDL_Renderer *renderer;
    std::string str;
    int fillR, fillG, fillB;
    SDL_Rect destRect;
    bool isVisible;
    std::string mouseResponse;
    SDL_Texture *Message;
    SDL_Texture *Image;

public:
    Label(int pos_x, int pos_y, int width, int height, SDL_Renderer *renderer, int fill[], Uint8 font_colour[], std::string str, int font_size);
    Label(int pos_x, int pos_y, int width, int height, SDL_Renderer *renderer, SDL_Texture *texture);
    bool inElement(int x, int y) override;
    void render() override;
    std::string processEvent(int x, int y, int buttonState) override;
    std::string processEvent(SDL_Event event) override { return ""; };
    void makeInvisible();
    void makeVisible();
    void setMouseResponse(std::string mouseResponse) override;
    std::string getMouseResponse();
};
#endif