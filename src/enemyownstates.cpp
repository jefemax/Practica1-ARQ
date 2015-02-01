#include "../include/enemyentity.h"
#include "../include/enemyownstates.h"
#include "../include/u-gine.h"

#define SC Screen::Instance()
const uint16 ANGLE_TO_ROTATE = 90;

OnPlayEnemyState* OnPlayEnemyState::Instance()
{
    static OnPlayEnemyState instance;
    return &instance;

}

void OnPlayEnemyState::Enter(EnemyEntity* entity)
{
    entity->Init();
}

void getAngle(EnemyEntity* e)
{
    //esta en la parte derecha
    if (e->getPosX() >= Screen::Instance().GetWidth())
    {
        e->setPosX(Screen::Instance().GetWidth() - 1);
        if (e->getAngle() < 90)
        {
            e->setAngle(e->getAngle() + ANGLE_TO_ROTATE);

        }
        if (e->getAngle() > 270)
        {
            e->setAngle(e->getAngle() - ANGLE_TO_ROTATE);
        }
    }
    if (e->getPosX() <= 0)
    {
        e->setPosX(1);
        if (e->getAngle() < 180)
        {
            e->setAngle(e->getAngle() - ANGLE_TO_ROTATE);
        }
        if (e->getAngle() > 180)
        {
            e->setAngle(e->getAngle() + ANGLE_TO_ROTATE);
        }
    }

    if (e->getPosY() >= Screen::Instance().GetHeight())
    {
        e->setPosY(Screen::Instance().GetHeight() - 1);

        if (e->getAngle() <= 90)
        {
            e->setAngle(e->getAngle() - ANGLE_TO_ROTATE);
            if (e->getAngle() < 0)   e->setAngle(e->getAngle() + 360);
        }
        else if (e->getAngle() <= 180)
        {
            e->setAngle(e->getAngle() + ANGLE_TO_ROTATE);
        }

    }
    if (e->getPosY() <= 0)
    {
        e->setPosY(1);

        if (e->getAngle() <= 270)
        {
            e->setAngle(e->getAngle() - ANGLE_TO_ROTATE);
        }
        else if (e->getAngle() <= 360)
        {
            e->setAngle(e->getAngle() + ANGLE_TO_ROTATE);
            if (e->getAngle() > 360)   e->setAngle(e->getAngle() -360);
        }

    }

}

void OnPlayEnemyState::Execute(EnemyEntity* entity)
{
    double velX = entity->getSpeed()*DegCos(entity->getAngle());
    double velY = entity->getSpeed()*DegSin(entity->getAngle());

    entity->setPosX(entity->getPosX() + SC.ElapsedTime()*velX);
    entity->setPosY(entity->getPosY() + SC.ElapsedTime()*velY);

    getAngle(entity);

}

void OnPlayEnemyState::Exit(EnemyEntity* )
{

}

OnDeathEnemyState* OnDeathEnemyState::Instance()
{
    static OnDeathEnemyState instance;
    return &instance;

}

void OnDeathEnemyState::Enter(EnemyEntity* )
{

}

void OnDeathEnemyState::Execute(EnemyEntity* )
{


}

void OnDeathEnemyState::Exit(EnemyEntity* )
{

}