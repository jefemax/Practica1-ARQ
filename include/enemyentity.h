#ifndef __ENEMY_ENTITY_H
#define __ENEMY_ENTITY_H

#include "entity.h"
#include "string.h"
#include "statemachine.h"
#include "math.h"
#include "u-gine.h"

enum EnemyType {
    FOOD, MORTAL
};

class EnemyEntity : public Entity
{
private:
    signed int m_speed;
    unsigned int m_width;
    unsigned int m_height;
    double m_angle;
    double m_increment;
    bool m_direction;
    double m_posX;
    double m_posY;
    double m_radX;
    double m_radY;
    bool m_isActive;
    int m_enemyType;
    //an instance of the state machine class
    StateMachine<EnemyEntity>* m_pStateMachine;

public:
    ~EnemyEntity();
    enum EnemyType {
        FOOD, MORTAL
    };

    EnemyEntity(signed int speed = 20,
        unsigned int width = 20, unsigned int height = 20, double angle = 290, double increment = 0.0,
        bool direction = true, double posX = 400,
        double posY = 300, double radX = 10, double radY = 10, bool isActive = true, int enemyType = EnemyType::FOOD);
    virtual void Init();
    virtual void Render();
    virtual void Update(double elapsed);
    virtual void AddComponent(Component*);
    virtual void ReceiveMessage(Message *msg);

    double getRadRes()
    {
        return Hipotenuse(m_radX, m_radY);
    }
    double getSpeed()
    {
        return m_speed;
    }

    void setSpeed(signed int speed)
    {
        this->m_speed = speed;
    }

    double getAngle()
    {
        return m_angle;
    }

    void setAngle(double angle)
    {
        this->m_angle = angle;
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
        return m_posX;
    }

    double getPosY()
    {
        return m_posY;
    }

    void setEnemyType(int type)
    {
        this->m_enemyType = type;
    }

    int getEnemyType()
    {
        return m_enemyType;
    }


    StateMachine<EnemyEntity>* getStateMachine()
    {
        return m_pStateMachine;
    }
};

#endif