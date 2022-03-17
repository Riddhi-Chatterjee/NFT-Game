#pragma once
#include "SDL2.framework/Headers/SDL.h"
#include "SDL2_image.framework/Headers/SDL_image.h"
#include "Spritesheet.h"
#include <iostream>
#include <time.h>
#include "Physics.h"
#include "Health.h"
#include "CannonFire.h"
#include "Fireball.h"
#include "FlameFire.h"
#include "Enemy.h"
#define CANNON_FIRE 0
#define FIRE_BALL 1
#define FLAME_FIRE 2

class ShootingEnemy : public Enemy
{
private:
	Spritesheet shEnemyR, shEnemyL;
	SDL_Rect m_Position;
    Vec2D shootingDir;
    Object *target;
    int health;
    double timepassed;
    int selectSprite;
	std::vector<Object *> fires;


public:
	ShootingEnemy(Vec2D pos, Object *Target);
	~ShootingEnemy();

	void update(double delta_time) override;
	void draw(SDL_Surface* surface, int x, int y) override;
	void handle_events(SDL_Event const& event) {};
	bool isGravity() override { return true; }
	bool isCollideable() const { return true; }
	int reduceHealth();
    void fireReady(Vec2D myPos, Vec2D tPos);
	void collideFireBalls(HollowKnight* hk, Physics& p, std::vector<Object*> ledges);

};

