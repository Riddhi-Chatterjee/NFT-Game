#include "FlameFire.h"

FlameFire::FlameFire(Vec2D p, Vec2D v)
	: propagation("bullets.bmp", 1, 4), burst("white_burst.bmp", 1, 3), Enemy(p, 0.15, 71, 57, 1, 4)
{
    count = 0;
    timepassed = 0.0;
    destroyed = false;
	propagation.selectSprite(count%3,count/3);
    burst.selectSprite(0,0);
    currentSpriteSheet = 0;
    vel.x = v.x;
    vel.y = v.y;
    initialVel = {v.x, v.y};
    collided = false;

	m_position.x = 0;
	m_position.y = 0;
	m_position.w = getLength();
	m_position.h = getBredth();
}


int FlameFire::fire(double delta_time)
{
    pos.x = pos.x + (delta_time*vel.x);
    pos.y = pos.y + (delta_time*vel.y);
    if(!destroyed)
    {
	    timepassed += delta_time;
        if(((initialVel.x != this->vel.x) || (initialVel.y != this->vel.y) || collided) && currentSpriteSheet == 0)
        {
            currentSpriteSheet = 1;
            timepassed = 0.0;
            count = 0;
            burst.selectSprite(count,0);
        }
        if(currentSpriteSheet == 0)
        {
	        if(timepassed >= 0.5)
            {
                timepassed = 0.0;
                count = (count + 1)%4;
                propagation.selectSprite(count,0);
            }
        }
        else if(currentSpriteSheet == 1)
        {
            if(timepassed >= 0.5)
            {
                timepassed = 0.0;
                count = (count + 1);
                if(count == 3)
                {
                    destroyed = true;
                    return 0;
                }
                else
                {
                    burst.selectSprite(count%3,count/3);
                }
            }   
        }
    }
    return 1;
}


void FlameFire::draw(SDL_Surface* surface, int x, int y)
{
	m_position.x = pos.x - getLength();
	m_position.y = pos.y - getBredth();
	if(currentSpriteSheet == 0)
    {
        propagation.drawSelectedSprite(surface, &m_position);
    }
    else if(currentSpriteSheet == 1)
    {
        burst.drawSelectedSprite(surface, &m_position);
    }
}

FlameFire::~FlameFire()
{
}