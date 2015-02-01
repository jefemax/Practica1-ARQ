#ifndef __MENUENDOWNERSTATES_H
#define __MENUENDOWNERSTATES_H
//--------- States for End Menu
#include "state.h"

class MenuEndEntity;
class OnStartEndMenuState : public State < MenuEndEntity >
{
private:
    //Patron singleton
    bool keysArray[300];
    OnStartEndMenuState(){}
    OnStartEndMenuState(const OnStartEndMenuState&);
    OnStartEndMenuState& operator=(const OnStartEndMenuState&);
public:

    static OnStartEndMenuState* Instance();
    virtual void Enter(MenuEndEntity *e);
    virtual void Execute(MenuEndEntity* e);
    virtual void Exit(MenuEndEntity* e);
};
#endif
