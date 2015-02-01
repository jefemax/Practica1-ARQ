#ifndef __WORLDOWNERSTATES_H
#define __WORLDOWNERSTATES_H

#include "state.h"
class World;

class OnStartGameState :public State<World>
{
private:

    //Patron singleton
    OnStartGameState(){}
    OnStartGameState(const OnStartGameState&);
    OnStartGameState& operator=(const OnStartGameState&);
public:
    int stateType = StateTypeStruct::ON_START_GAME_STATE;
    static OnStartGameState* Instance();
    virtual void Enter(World* world);
    virtual void Execute(World* world);
    virtual void Exit(World* world);
};


class OnPlayingGameState :public State<World>
{
private:

    //Patron singleton
    OnPlayingGameState(){}
    OnPlayingGameState(const OnStartGameState&);
    OnPlayingGameState& operator=(const OnStartGameState&);
public:
    static OnPlayingGameState* Instance();
    virtual void Enter(World *e);
    virtual void Execute(World* e);
    virtual void Exit(World* e);
};

class GEOnPauseGameState :public State<World>
{
private:

    //Patron singleton
    GEOnPauseGameState(){}
    GEOnPauseGameState(const OnStartGameState&);
    GEOnPauseGameState& operator=(const OnStartGameState&);
public:
    static GEOnPauseGameState* Instance();
    virtual void Enter(World *e);
    virtual void Execute(World* e);
    virtual void Exit(World* e);
};

class GEOnEndGameState :public State<World>
{
private:

    //Patron singleton
    GEOnEndGameState(){}
    GEOnEndGameState(const OnStartGameState&);
    GEOnEndGameState& operator=(const OnStartGameState&);
public:
    static GEOnEndGameState* Instance();
    virtual void Enter(World *e);
    virtual void Execute(World* e);
    virtual void Exit(World* e);
};


class GEOnExitState :public State<World>
{
private:

    //Patron singleton
    GEOnExitState(){}
    GEOnExitState(const OnStartGameState&);
    GEOnExitState& operator=(const OnStartGameState&);
public:
    static GEOnExitState* Instance();
    virtual void Enter(World *e);
    virtual void Execute(World* e);
    virtual void Exit(World* e);
};
#endif