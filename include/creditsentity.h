#ifndef __CREDITSENTITY_H
#define __CREDITSENTITY_H

#include "menuentity.h"

class CreditsEntity : virtual public MenuEntity
{
private:
    StateMachine<CreditsEntity>* m_pStateMachine;
public:
    ~CreditsEntity();

    CreditsEntity();
    virtual void Update(double elapsed);
    virtual StateMachine<CreditsEntity>* getStateMachine()
    {
        return m_pStateMachine;
    }

};

#endif