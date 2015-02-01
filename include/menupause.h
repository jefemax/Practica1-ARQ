#ifndef __MENUPAUSE_H
#define __MENUPAUSE_H

#include "menuentity.h"

class PauseMenuEntity : virtual public MenuEntity
{
private:
    StateMachine<PauseMenuEntity>* m_pStateMachine;
public:
    PauseMenuEntity();
    ~PauseMenuEntity();
    virtual void Update(double elapsed);
    virtual StateMachine<PauseMenuEntity>* getStateMachine()
    {
        return m_pStateMachine;
    }

};

#endif