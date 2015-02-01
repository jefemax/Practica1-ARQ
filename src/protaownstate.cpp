#include "../include/protaownstate.h"
#include "../include/protaentity.h"
#include "../include/u-gine.h"
#include "../include/messages.h"
#include "../include/world.h"
#include "../include/worldownerstate.h"

#define SC Screen::Instance()
OnPlayState* OnPlayState::Instance()
{
    static OnPlayState instance;
    return &instance;

}

void OnPlayState::Enter(ProtaEntity* entity)
{
    entity->setLife(100);
    entity->Init();
}

void OnPlayState::Execute(ProtaEntity* entity)
{
    if (Screen::Instance().KeyPressed(GLFW_KEY_UP))
    {
        entity->setPosY(entity->getPosY()-entity->getSpeedY());
    }
    if (Screen::Instance().KeyPressed(GLFW_KEY_DOWN))
    {
        entity->setPosY(entity->getPosY() + entity->getSpeedY());
    }
    if (Screen::Instance().KeyPressed(GLFW_KEY_LEFT))
    {
        entity->setPosX(entity->getPosX() - entity->getSpeedX());
    }
    if (Screen::Instance().KeyPressed(GLFW_KEY_RIGHT))
    {
        entity->setPosX(entity->getPosX() + entity->getSpeedX());
    }

    if (Screen::Instance().KeyPressed(GLFW_KEY_SPACE))
    {
        World::Instance()->getStateMachine()->ChangeState(GEOnPauseGameState::Instance());
    }
   /* if (msg != NULL && dynamic_cast<ReduceLifeMessage*>(msg)->dead){
        printf("mensaje vivo");
        //        ReduceLifeMessage *rlmsg = dynamic_cast<ReduceLifeMessage*>(msg);
        m_pStateMachine->ChangeState(ProtaDeadState::Instance());
        delete msg;
    }*/

   /* if (entity->getMessage() != NULL && dynamic_cast<ReduceLifeMessage*>(entity->getMessage())->dead){
        printf("mensaje vivo");
        //        ReduceLifeMessage *rlmsg = dynamic_cast<ReduceLifeMessage*>(msg);
        entity->getStateMachine()->ChangeState(ProtaDeadState::Instance());
        delete entity->getMessage();
    }*/

    for (uint32 i = 0; i < entity->m_Components.Size(); i++)
    {
        entity->m_Components[i]->Update(SC.ElapsedTime());
    }
    
}

void OnPlayState::Exit(ProtaEntity* entity)
{
    entity->Clean();
}

ProtaDeadState* ProtaDeadState::Instance()
{
    static ProtaDeadState instance;
    return &instance;

}

void ProtaDeadState::Enter(ProtaEntity* )
{

}

void ProtaDeadState::Execute(ProtaEntity* )
{

}
void ProtaDeadState::Exit(ProtaEntity* )
{

}
