#ifndef __CREDITSOWNERSTATES_H
#define __CREDITSOWNERSTATES_H
#include "creditsentity.h"

class CreditsEntity;
class OnStartCreditsState : public State < CreditsEntity >
{
private:
    //Patron singleton
    bool keysArray[300];
    OnStartCreditsState(){}
    OnStartCreditsState(const OnStartCreditsState&);
    OnStartCreditsState& operator=(const OnStartCreditsState&);
public:

    static OnStartCreditsState* Instance();
    virtual void Enter(CreditsEntity *e);
    virtual void Execute(CreditsEntity* e);
    virtual void Exit(CreditsEntity* e);
};

class OnEndCreditsState : public State < CreditsEntity >
{
private:
    //Patron singleton
    OnEndCreditsState(){}
    OnEndCreditsState(const OnEndCreditsState&);
    OnEndCreditsState& operator=(const OnEndCreditsState&);
public:

    static OnEndCreditsState* Instance();
    virtual void Enter(CreditsEntity *e);
    virtual void Execute(CreditsEntity* e);
    virtual void Exit(CreditsEntity* e);
};
#endif