#include "ShootingEnemy.h"

ShootingEnemy::ShootingEnemy(Vec2D Epos, Object *Target)
	: shEnemyR("shEnemyRight.bmp", 1, 1), shEnemyL("shEnemyLeft.bmp", 1 ,1), Enemy(Epos, 1, 53, 85, 1, 4)
{
	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.w = getLength();
	m_Position.h = getBredth();
    shEnemyR.selectSprite(0,0);
    shEnemyL.selectSprite(0,0);
    health = 4;
    target = Target;
    shootingDir.x = (target->pos.x) - (this->pos.x);
    shootingDir.y = (target->pos.y) - (this->pos.y);
    timepassed = 0.0;
    selectSprite = 0;
}


void ShootingEnemy::update(double delta_time)
{
    int i;
    int weaponNum = 2;
    srand(time(0));
    for(i=0;i<fires.size();i++)
    {
        if(fires[i])
        {
            int result;
            int weapon = fires[i]->getWeaponType();
            if(weapon == CANNON_FIRE)
            {
                if(dynamic_cast<CannonFire *> (fires[i]))
                {
                    result = dynamic_cast<CannonFire *> (fires[i])->fire(delta_time);
                }
            }
            else if(weapon == FIRE_BALL)
            {
                if(dynamic_cast<Fireball *> (fires[i]))
                {
                    result = dynamic_cast<Fireball *> (fires[i])->fire(delta_time);
                }
            }
            if(result == 0)
            {
                delete(fires[i]);
                fires[i] = NULL;
            }
        }
    }
	shootingDir.x = (target->pos.x) - (this->pos.x);
    shootingDir.y = (target->pos.y) - (this->pos.y);
    timepassed += delta_time;
    fireReady(this->pos, target->pos);
    if(timepassed >= 15)
    {
        timepassed = 0.0;
        double mag = sqrt((shootingDir.x * shootingDir.x)+(shootingDir.y * shootingDir.y));
        if(mag <= 300)
        {
            int randNum = rand()%weaponNum;
            if(randNum == 0)
            {
                Object *o = (Object *)new CannonFire(this->pos, {(shootingDir.x/mag)*30, (shootingDir.y/mag)*30});
                o->setWeaponType(CANNON_FIRE);
                fires.push_back(o);
            }
            else if(randNum == 1)
            {
                Object *o = (Object *)new Fireball(this->pos, {(shootingDir.x/mag)*30, (shootingDir.y/mag)*30});
                o->setWeaponType(FIRE_BALL);
                fires.push_back(o);
            }
        }
    }
}

void ShootingEnemy::draw(SDL_Surface* surface, int x, int y)
{
	m_Position.x = pos.x - getLength() / 2;
	m_Position.y = pos.y - getBredth() / 2;
    int i;
    for(i=0;i<fires.size();i++)
    {
        if(fires[i])
        {
            fires[i]->draw(surface, 0, 0);
        }
    }
    if(selectSprite == 0)
    {
        shEnemyL.drawSelectedSprite(surface, &m_Position);
    }
    else if(selectSprite == 1)
    {
        shEnemyR.drawSelectedSprite(surface, &m_Position);
    }
}

int ShootingEnemy::reduceHealth() //If health becomes zero then destroy this enemy object
{
    if(health > 0)
    {
        health--;
    }
    return health;
}

void ShootingEnemy::fireReady(Vec2D myPos, Vec2D tPos)
{
    if(tPos.x < myPos.x)
    {
        selectSprite = 0;
    }
    else
    {
        selectSprite = 1;
    }
}

void ShootingEnemy::collideFireBalls(HollowKnight* hk, Physics& p, std::vector<Object*> ledges) {
    for (auto it = fires.begin(); it != fires.end(); it++) {
        if (*it) {
            if (p.detectCollision(*hk, **it)) {
                if(*it)
                {
                    (*it)->informCollision();
                }
                hk->reduceHealth();
                break;
            }

        }
    }
}

ShootingEnemy::~ShootingEnemy()
{
}