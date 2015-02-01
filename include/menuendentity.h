#ifndef __MENUENDENTITY_H
#define __MENUENDENTITY_H

#include "menuentity.h"

class MenuEndEntity : virtual public MenuEntity
{
private:
    StateMachine<MenuEndEntity>* m_pStateMachine;
public:
    MenuEndEntity();
    ~MenuEndEntity();
    virtual void Update(double elapsed);
    virtual StateMachine<MenuEndEntity>* getStateMachine()
    {
        return m_pStateMachine;
    }

};

#endif