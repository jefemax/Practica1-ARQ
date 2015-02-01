#ifndef __COMPONENT_H
#define __COMPONENT_H

#include "../include/u-gine.h"
#include "../include/message.h"

class Entity;
//class Message;

class Component
{
protected:
    Message *m_msg;
    Entity* m_Owner;
public:
    Component(){}
    Component(Entity* owner)
    {
        this->m_Owner = owner;
        m_msg = NULL;
    }
    virtual ~Component(){}
    virtual void Update(double elapsed) = 0;
    virtual void ReceiveMessage(Message *msg) = 0;
    virtual Entity* getOwner()
    {
        return m_Owner;
    }
   /* void setOwner(Entity* m_Owner)
    {
        this->m_Owner = m_Owner;
    }*/
    
};

#endif