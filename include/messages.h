 #ifndef __MESSAGES_H
#define __MESSAGES_H

#include "message.h"
#include "u-gine.h"

struct ReduceLifeMessage : public Message
{
    uint32 m_amount;
    bool m_dead;
    ReduceLifeMessage(uint32 amount)
    {
        this->m_amount = amount;
        this->m_dead = false;
    }
    virtual void foo(){}
};

struct AddLifeMessage : public Message
{
    uint32 amount;
    AddLifeMessage(uint32 amount)
    {
        this->amount = amount;
    }
};

struct AddScoreMessage : public Message
{
    AddScoreMessage() :Message(){}
    virtual void foo(){}
};

#endif
