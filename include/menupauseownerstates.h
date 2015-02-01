#ifndef __MENUPAUSEOWNERSTATES_H
#define __MENUPAUSEOWNERSTATES_H
//--------- States for End Menu
#include "state.h"

class PauseMenuEntity;
class OnStartPauseMenuState : public State < PauseMenuEntity >
{
private:
    //Patron singleton
    bool keysArray[300];
    OnStartPauseMenuState(){}
    OnStartPauseMenuState(const OnStartPauseMenuState&);
    OnStartPauseMenuState& operator=(const OnStartPauseMenuState&);
public:

    static OnStartPauseMenuState* Instance();
    virtual void Enter(PauseMenuEntity *e);
    virtual void Execute(PauseMenuEntity* e);
    virtual void Exit(PauseMenuEntity* e);
};

class OnEndPauseMenuState : public State < PauseMenuEntity >
{
private:
    //Patron singleton
    bool keysArray[300];
    OnEndPauseMenuState(){}
    OnEndPauseMenuState(const OnEndPauseMenuState&);
    OnEndPauseMenuState& operator=(const OnEndPauseMenuState&);
public:

    static OnEndPauseMenuState* Instance();
    virtual void Enter(PauseMenuEntity *e);
    virtual void Execute(PauseMenuEntity* e);
    virtual void Exit(PauseMenuEntity* e);
};
#endif