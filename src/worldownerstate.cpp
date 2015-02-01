#include "../include/worldownerstate.h"
#include "../include/world.h"
#include "../include/menuentity.h"
#include "../include/menuendentity.h"
#include "../include/protaentity.h"
#include "../include/C_Collision.h"
#include "../include/config.h"
#include "../include/enemyentity.h"
#include "../include/menupause.h"

OnStartGameState* OnStartGameState::Instance()
{
    static OnStartGameState instance;
    //instance.m_stateType = StateTypeStruct::ON_START_GAME_STATE;
    return &instance;

}

void OnStartGameState::Enter(World* )
{

}

void OnStartGameState::Execute(World* )
{

}

void OnStartGameState::Exit(World* )
{

}


OnPlayingGameState* OnPlayingGameState::Instance()
{
    static OnPlayingGameState instance;
    //instance.m_stateType = StateTypeStruct::ON_START_GAME_STATE;
    return &instance;

}

void OnPlayingGameState::Enter(World* world)
{
    world->cleanForPlay();
    world->getEntityArray()->Add(world->getProta());
    for (uint32 x = 0; x < Config::Instance()->getNumEnemigos(); x++)
    {
        EnemyEntity* enemyEntity = new EnemyEntity();
        enemyEntity->setEnemyType(rand() % 2);
        enemyEntity->setActive(true);
        enemyEntity->setSpeed(Config::Instance()->getEnemySpeed());
        world->getEntityArray()->Add(enemyEntity);
    }
    world->setCollisionComp(new C_collision());
    (dynamic_cast<ProtaEntity*>(world->getProta()))->getStateMachine()->ChangeState(OnPlayState::Instance());
}

void OnPlayingGameState::Execute(World* )
{

}

void OnPlayingGameState::Exit(World* )
{

}


GEOnEndGameState* GEOnEndGameState::Instance()
{
    static GEOnEndGameState instance;
    return &instance;

}

void GEOnEndGameState::Enter(World* entity)
{
    MenuEndEntity *menuEndEntity = new MenuEndEntity();
    entity->addEntity(menuEndEntity);
    /*MenuEntity *exitEntity = new MenuEntity();
    exitEntity->AddItem(new String());
    entity->addEntity(exitEntity);*/
}

void GEOnEndGameState::Execute(World* )
{

}

void GEOnEndGameState::Exit(World* )
{

}

//_-----    Game pause state
GEOnPauseGameState* GEOnPauseGameState::Instance()
{
    static GEOnPauseGameState instance;
    return &instance;

}

void GEOnPauseGameState::Enter(World* world)
{
    world->getEntityArray()->Add(new PauseMenuEntity());
}

void GEOnPauseGameState::Execute(World* )
{

}

void GEOnPauseGameState::Exit(World* )
{

}

//-------------


GEOnExitState* GEOnExitState::Instance()
{
    static GEOnExitState instance;
    return &instance;

}

void GEOnExitState::Enter(World* )
{

}

void GEOnExitState::Execute(World* )
{

}

void GEOnExitState::Exit(World* )
{

}