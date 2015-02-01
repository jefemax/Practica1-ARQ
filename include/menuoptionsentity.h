#ifndef __MENUOPTIONS_H
#define __MENUOPTIONS_H

#include "menuentity.h"

class MenuOptionsEntity : virtual public MenuEntity
{
private:
    StateMachine<MenuOptionsEntity>* m_pStateMachine;
public:
    ~MenuOptionsEntity();
    MenuOptionsEntity();
    virtual void Update(double elapsed);

    virtual StateMachine<MenuOptionsEntity>* getStateMachine()
    {
        return m_pStateMachine;
    }

};

#endif