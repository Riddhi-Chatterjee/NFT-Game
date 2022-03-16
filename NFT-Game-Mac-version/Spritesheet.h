#pragma once
#include "SDL2.framework/Headers/SDL.h"
#include "SDL2_image.framework/Headers/SDL_image.h"

class Spritesheet
{
private:
	SDL_Rect m_clip;
	SDL_Surface* m_spritesheet;
	double m_clipx;
	double m_clipy;

public:
	Spritesheet(const char* path, int row, int column);
	~Spritesheet();

	void selectSprite(int x, int y);
	void drawSelectedSprite(SDL_Surface* surface, SDL_Rect* position);

};

