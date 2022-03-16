#pragma once
#include "SDL2.framework/Headers/SDL.h"
#include "SDL2_image.framework/Headers/SDL_image.h"

class Map
{

private:
	SDL_Rect m_clip;
	SDL_Surface* m_map;
	double m_curOffsetX;
	double m_curOffsetY;

public:
	Map(const char* path, int length, int height);
	~Map();

	void moveMap(int x, int y);
	void drawMap(SDL_Surface* surface);


};

