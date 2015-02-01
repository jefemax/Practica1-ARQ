#ifndef __ENTITY_H
#define __ENTITY_H

#include "array.h"
#include "component.h"
#include "state.h"
#include "message.h"

struct EntityTypeStruct
{
    enum EntityType
    {
        MENU_ENTITY = 0,
        MENU_DEAD_ENTIY = 1,
        MENU_PAUSE_ENTITY = 2,
        MENU_OPTIONS_ENTITY = 3,
        CREDITS_ENTITY = 4,
        WORLD_ENTITY = 5,
        PROTA_ENTITY = 6,
        ENEMY_ENTITY = 7
    };
};

class Entity
{
protected:
    int m_entityType;
    bool m_isActive = true;
    Message* m_msg;

public:
    virtual ~Entity(){}
    Array<Component*> m_Components;
    virtual void Init();
    virtual void Update(double elapsed);
    virtual void Render();
    virtual void Clean();
    virtual void ReceiveMessage(Message *msg);
    int getEntitytype()
    {
        return m_entityType;
    }
    void AddComponent(Component*);

    void setActive(bool isActive)
    {
        this->m_isActive = isActive;
    }
    bool getActive()
    {
        return m_isActive;
    }

    Message* getMessage()
    {
        return m_msg;
    }

};

#endif