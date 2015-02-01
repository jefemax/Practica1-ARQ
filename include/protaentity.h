#ifndef __PROTA_ENTITY_H
#define __PROTA_ENTITY_H

#include "entity.h"
#include "string.h"
#include "statemachine.h"
#include "protaownstate.h"
#include "math.h"

class C_Life;
class C_Score;

class ProtaEntity : public Entity
{
private:

    //an instance of the state machine class
    StateMachine<ProtaEntity>* m_pStateMachine;

    signed int m_speed;
    signed int m_speedX;
    signed int m_speedY;
    unsigned int m_width;
    unsigned int m_height;
    double m_angle;
    double m_posX;
    double m_posY;
    double m_radX;
    double m_radY;
    bool m_isActive;
    uint32 m_life;
    int m_max_life;
    int m_collisions;
    C_Life* m_c_life;
    C_Score* m_c_score;

public:
    
    ProtaEntity(signed int speed = 10, signed int speedX = 0, signed int speedY = 0,
        unsigned int width = 20, unsigned int height = 20, double angle = 20, double posX = 100,
        double posY = 100, double radX = 20, double radY = 20);
    ~ProtaEntity();
    virtual void Init();
    virtual void Render();
    virtual void Clean();
    virtual void Update(double elapsed);
    virtual void AddComponent(Component*);
    virtual void ReceiveMessage(Message *msg);

    double getRadRes()
    {
        return Hipotenuse(m_radX, m_radY);
    }
    double getSpeed()
    {
        return Hipotenuse(m_speedX, m_speedY);
    }
    double getSpeedX()
    {
        return m_speed*DegCos(m_angle);
    }
    double getSpeedY()
    {
        return m_speed*DegSin(m_angle);
    }

    void setPosX(double posX)
    {
        this->m_posX = posX;
    }
    void setPosY(double posY)
    {
        this->m_posY = posY;
    }

    double getPosX()
    {
        return this->m_posX;
    }
    double getPosY()
    {
        return this->m_posY;
    }

    void setLife(uint32 life)
    {
        this->m_life = life;
    }

    int getLife()
    {
        return this->m_life;
    }

    int getMaxLife()
    {
        return this->m_max_life;
    }
    StateMachine<ProtaEntity>* getStateMachine()
    {
        return m_pStateMachine;
    }

    int getCollisions()
    {
        return this->m_collisions;
    }

    void setCollisions(int collisions)
    {
        this->m_collisions = collisions;
    }
};

#endif