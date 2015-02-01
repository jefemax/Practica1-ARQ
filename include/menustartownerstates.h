#ifndef __MENUSTARTOWNERSTATES_H
#define __MENUSTARTOWNERSTATES_H

//States for start menu
#include "state.h"
class MenuStartEntity;

class OnStartMenuState :public State<MenuStartEntity>
{
private:
    //Patron singleton
    bool keysArray[300];
    OnStartMenuState(){}
    OnStartMenuState(const OnStartMenuState&);
    OnStartMenuState& operator=(const OnStartMenuState&);
public:

    static OnStartMenuState* Instance();
    virtual void Enter(MenuStartEntity *e);
    virtual void Execute(MenuStartEntity* e);
    virtual void Exit(MenuStartEntity* e);
};

class OnEndMenuState :public State<MenuStartEntity>
{
private:
    //Patron singleton
    bool keysArray[300];
    OnEndMenuState(){}
    OnEndMenuState(const OnEndMenuState&);
    OnEndMenuState& operator=(const OnEndMenuState&);
public:

    static OnEndMenuState* Instance();
    virtual void Enter(MenuStartEntity *e);
    virtual void Execute(MenuStartEntity* e);
    virtual void Exit(MenuStartEntity* e);
};

#endif

