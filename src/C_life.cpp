#include "../include/C_life.h"
#include "../include/messages.h"
#include "../include/protaentity.h"
#include "../include/string.h"
#include "../include/world.h"


#define pEntity dynamic_cast<ProtaEntity*>(getOwner())
#define RN Renderer::Instance()


C_Life::~C_Life()
{

}

void C_Life::Update(double)
{

        RN.SetColor(255, 255, 255, 255);
        RN.DrawText(m_font, String().FromInt(pEntity->getLife()), 700, 500);
    
}

void C_Life::ReceiveMessage(Message *msg)
{
    //AddLifeMessage *almsg = dynamic_cast<AddLifeMessage*>(msg);
    if (dynamic_cast<AddLifeMessage*>(msg))
    {
        pEntity->setLife(pEntity->getLife() + dynamic_cast<AddLifeMessage*>(msg)->amount);
        printf("Genero Score Message \n");
        pEntity->ReceiveMessage(new AddScoreMessage());
    }

    if (dynamic_cast<ReduceLifeMessage*>(msg))
    {
        pEntity->setLife(pEntity->getLife() - dynamic_cast<ReduceLifeMessage*>(msg)->m_amount);
        if (pEntity->getLife() <= 0)
        {
            pEntity->getStateMachine()->ChangeState(ProtaDeadState::Instance());
            World::Instance()->getStateMachine()->ChangeState(GEOnEndGameState::Instance());
        }
        //printf("Te queda %d de vida \n", m_life);
    }
}

