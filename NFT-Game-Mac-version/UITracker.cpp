#include "UIElement.hpp"
#include "UITracker.hpp"
#include "Label.hpp"
UITracker::UITracker(SDL_Renderer *renderer)
{
    this->renderer = renderer;
    Update();
}
void UITracker::addLabel(int pos_x, int pos_y, int width, int height, SDL_Renderer *renderer, std::string str, int fill[], Uint8 font_colour[], int font_size)
{
    inElementArr.push_back(false);
    UIList.push_back(new Label(pos_x, pos_y, width, height, renderer, fill, font_colour, str, font_size));
}
void UITracker::addLabel(int pos_x, int pos_y, int width, int height, SDL_Renderer *renderer, SDL_Texture *texture)
{
    inElementArr.push_back(false);
    UIList.push_back(new Label(pos_x, pos_y, width, height, renderer, texture));
}
void UITracker::setMouseResponse(int i, std::string response)
{
    UIList[i]->setMouseResponse(response);
}
void UITracker::render()
{
    for (int i = 0; i < UIList.size(); i++)
    {
        UIList[i]->render();
    }
}
void UITracker::Update()
{
    buttonState = SDL_GetMouseState(&x, &y);
    for (int i = 0; i < UIList.size(); i++)
    {
        inElementArr[i] = UIList[i]->inElement(x, y);
    }
}
std::string UITracker::processInput(SDL_Event event)
{
    Update();
    std::string output = "";
    for (int i = 0; i < UIList.size(); i++)
    {
        output += UIList[i]->processEvent(x, y, buttonState);
        output += "~ ";
        output += UIList[i]->processEvent(event);
        output += "~ ";
    }
    return output;
}
void UITracker::addUIElement(class UIElement *uie)
{
    inElementArr.push_back(false);
    UIList.push_back(uie);
}
std::vector<bool> UITracker::getInElementArr()
{
    return inElementArr;
}
Uint8 UITracker::getButtonState()
{
    return buttonState;
}
UITracker::~UITracker()
{
}