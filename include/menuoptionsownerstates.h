#ifndef __MENUOPTIONSOWNERSTATES_H
#define __MENUOPTIONSOWNERSTATES_H
//--------- States for End Menu
#include "state.h"

class MenuOptionsEntity;
class OnStartOptionsMenuState : public State < MenuOptionsEntity >
{
private:
    //Patron singleton
    bool keysArray[300];
    OnStartOptionsMenuState(){}
    OnStartOptionsMenuState(const OnStartOptionsMenuState&);
    OnStartOptionsMenuState& operator=(const OnStartOptionsMenuState&);
public:

    static OnStartOptionsMenuState* Instance();
    virtual void Enter(MenuOptionsEntity *e);
    virtual void Execute(MenuOptionsEntity* e);
    virtual void Exit(MenuOptionsEntity* e);
};
class OnEndOptionsMenuState : public State < MenuOptionsEntity >
{
private:
    //Patron singleton
    bool keysArray[300];
    OnEndOptionsMenuState(){}
    OnEndOptionsMenuState(const OnEndOptionsMenuState&);
    OnEndOptionsMenuState& operator=(const OnEndOptionsMenuState&);
public:

    static OnEndOptionsMenuState* Instance();
    virtual void Enter(MenuOptionsEntity *e);
    virtual void Execute(MenuOptionsEntity* e);
    virtual void Exit(MenuOptionsEntity* e);
};
#endif
