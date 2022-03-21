#include "Menu.hpp"
#include "Application.h"
#include "UITracker.hpp"
#include "Label.hpp"

void MenuWebsite(std::string price)
{
    std::ofstream fout;
    fout.open("sword_price.txt");
    fout<<price;
    fout.close();

    system("node server.js");
    system("open -a 'google chrome' http://localhost:3300");
}

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
    bool flag = false;
    bool isSelected = false;

    addButton("SelectSword.bmp", 50, 50, 300, 150, '!');
    
    
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
        if(uit->isPressedStatus(0) && !flag)
        {   
            flag = true;
            addButton("TiltedSwords (1).bmp", 50, 250, 73, 100, '!');
            addButton("TiltedSwords (2).bmp", 143, 250, 73, 100, '!');
            addButton("TiltedSwords (3).bmp", 236, 250, 73, 100, '!');
            addButton("TiltedSwords (4).bmp", 329, 250, 73, 100, '!');
            // addButton("TiltedSwords (13).bmp", 422, 250, 73, 100, '!');
            // addButton("TiltedSwords (14).bmp", 495, 250, 73, 100, '!');
            addButton("TiltedSwords (5).bmp", 50, 400, 73, 100, '!');
            addButton("TiltedSwords (6).bmp", 150, 400, 73, 100, '!');
            addButton("TiltedSwords (7).bmp", 250, 400, 73, 100, '!');
            addButton("TiltedSwords (8).bmp", 350, 400, 73, 100, '!');
            addButton("TiltedSwords (9).bmp", 50, 550, 73, 100, '!');
            addButton("TiltedSwords (10).bmp", 150, 550, 73, 100, '!');
            addButton("TiltedSwords (11).bmp", 250, 550, 73, 100, '!');
            addButton("TiltedSwords (12).bmp", 350, 550, 73, 100, '!');
            addButton("Start.bmp", 430, 580, 240, 125, '!');

        }
        if(flag == true){

            if(uit ->isPressedStatus(1)){
                isSelected = true;
                std::cout << "button one" << std::endl;
                sword = 1;
                std::thread thread_obj1(MenuWebsite, "0.01");
                thread_obj1.join();
            }
            else if(uit ->isPressedStatus(2)){
                isSelected = true;
                std::cout << "button two" << std::endl;
                sword = 2;
                std::thread thread_obj2(MenuWebsite, "0.015");
                thread_obj2.join();
            }
            else if(uit ->isPressedStatus(3)){
                isSelected = true;
                std::cout << "button three" << std::endl;
                sword = 3;
                std::thread thread_obj3(MenuWebsite, "0.02");
                thread_obj3.join();
            }
            else if(uit ->isPressedStatus(4)){
                isSelected = true;
                std::cout << "button four" << std::endl;
                sword = 4;
                std::thread thread_obj4(MenuWebsite, "0.025");
                thread_obj4.join();
            }
            else if(uit ->isPressedStatus(5)){
                isSelected = true;
                std::cout << "button five" << std::endl;
                sword = 5;
                std::thread thread_obj5(MenuWebsite, "0.03");
                thread_obj5.join();
            }
            else if(uit ->isPressedStatus(6)){
                isSelected = true;
                std::cout << "button six" << std::endl;
                sword = 6;
                std::thread thread_obj6(MenuWebsite, "0.035");
                thread_obj6.join();
            }
            else if(uit ->isPressedStatus(7)){
                isSelected = true;
                std::cout << "button seven" << std::endl;
                sword = 7;
                std::thread thread_obj7(MenuWebsite, "0.04");
                thread_obj7.join();
            }
            else if(uit ->isPressedStatus(8)){
                isSelected = true;
                std::cout << "button eight" << std::endl;
                sword = 8;
                std::thread thread_obj8(MenuWebsite, "0.045");
                thread_obj8.join();
            }
            else if(uit ->isPressedStatus(9)){
                isSelected = true;
                std::cout << "button nine" << std::endl;
                sword = 9;
                std::thread thread_obj9(MenuWebsite, "0.05");
                thread_obj9.join();
            }
            else if(uit ->isPressedStatus(10)){
                isSelected = true;
                std::cout << "button ten" << std::endl;
                sword = 10;
                std::thread thread_obj10(MenuWebsite, "0.055");
                thread_obj10.join();
            }
            else if(uit ->isPressedStatus(11)){
                isSelected = true;
                std::cout << "button eleven" << std::endl;
                sword = 11;
                std::thread thread_obj11(MenuWebsite, "0.06");
                thread_obj11.join();
            }
            else if(uit ->isPressedStatus(12)){
                isSelected = true;
                std::cout << "button twelve" << std::endl;
                sword = 12;
                std::thread thread_obj12(MenuWebsite, "0.065");
                thread_obj12.join();
            }

            else if(isSelected == true){
                if(uit ->isPressedStatus(13)){
                    std::cout<<"button thirteen"<<std::endl;
                    isRunning = false;
                }
            }
        
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

int Menu::getSword()
{
    return sword;
}