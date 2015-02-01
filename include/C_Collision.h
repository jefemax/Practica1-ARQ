#ifndef __C_COLLISION_H
#define __C_COLLISION_H

#include "component.h"
#include "entity.h"


class C_collision : public  Component
{
    Entity* enemyInTurn;
public:
    C_collision() :Component(NULL){}
    ~C_collision();
    virtual void Update(double elapsed);
    virtual void ReceiveMessage(Message *msg);
    bool cirlceToCircledetection(Entity *b);
    Message * getMesssage(){
        return m_msg;
    }
    void setEnemyInturn(Entity* e){
        enemyInTurn = e;
    }
};

#endif