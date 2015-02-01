#ifndef __PROTAOWNERSTATES_H
#define __PROTAOWNERSTATES_H

#include "state.h"
class ProtaEntity;

class OnPlayState :public State<ProtaEntity>
{
private:
    //Patron singleton
    OnPlayState(){}
    OnPlayState(const OnPlayState&);
    OnPlayState& operator=(const OnPlayState&);
public:

    static OnPlayState* Instance();
    virtual void Enter(ProtaEntity *e);
    virtual void Execute(ProtaEntity* e);
    virtual void Exit(ProtaEntity* e);
};

class ProtaDeadState :public State<ProtaEntity>
{
private:
    //Patron singleton
    ProtaDeadState(){}
    ProtaDeadState(const ProtaDeadState&);
    ProtaDeadState& operator=(const ProtaDeadState&);
public:

    static ProtaDeadState* Instance();
    virtual void Enter(ProtaEntity *e);
    virtual void Execute(ProtaEntity* e);
    virtual void Exit(ProtaEntity* e);
};
#endif