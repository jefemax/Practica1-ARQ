#ifndef __ENEMYOWNERSTATES_H
#define __ENEMYOWNERSTATES_H

#include "state.h"
class EnemyEntity;

class OnPlayEnemyState :public State<EnemyEntity>
{
private:
    //Patron singleton
    OnPlayEnemyState(){}
    OnPlayEnemyState(const OnPlayEnemyState&);
    OnPlayEnemyState& operator=(const OnPlayEnemyState&);
public:

    static OnPlayEnemyState* Instance();
    virtual void Enter(EnemyEntity *e);
    virtual void Execute(EnemyEntity* e);
    virtual void Exit(EnemyEntity* e);
};

class OnDeathEnemyState :public State<EnemyEntity>
{
private:
    //Patron singleton
    OnDeathEnemyState(){}
    OnDeathEnemyState(const OnDeathEnemyState&);
    OnDeathEnemyState& operator=(const OnDeathEnemyState&);
public:

    static OnDeathEnemyState* Instance();
    virtual void Enter(EnemyEntity *e);
    virtual void Execute(EnemyEntity* e);
    virtual void Exit(EnemyEntity* e);
};

#endif