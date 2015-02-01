#ifndef __MENUSTARTENTITY_H
#define __MENUSTARTENTITY_H

#include "menuentity.h"

class MenuStartEntity : virtual public MenuEntity
{
private:
    StateMachine<MenuStartEntity>* m_pStateMachine;
public:
    MenuStartEntity();
    ~MenuStartEntity();
    virtual void Update(double elapsed);

    virtual StateMachine<MenuStartEntity>* getStateMachine()
    {
        return m_pStateMachine;
    }

};

#endif