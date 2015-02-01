#include "../include/protaentity.h"
#include "../include/state.h"
#include "../include/renderer.h"
#include "../include/resourcemanager.h"
#include "../include/C_life.h"
#include "../include/C_score.h"
#include "../include/messages.h"
#include "../include/u-gine.h"
#include "../include/world.h"
#include "../include/config.h"

#define RN Renderer::Instance()

ProtaEntity::ProtaEntity(signed int, signed int, signed int,
    unsigned int, unsigned int, double, double,
    double, double, double)
{
   // m_life = max_life;
    m_pStateMachine = new StateMachine<ProtaEntity>(this);
    m_pStateMachine->SetCurrentState(OnPlayState::Instance());
    m_entityType = EntityTypeStruct::PROTA_ENTITY;
    OnPlayState::Instance()->Enter(this);
}

void ProtaEntity::Init()
{
    m_speed = 10; m_speedX = 0; m_speedY = 0; m_width = 20; m_height = 20;  m_angle = 20;
    m_posX = 100; m_posY = 100; m_radX = 20; m_radY = 20; m_life = 100, m_collisions = 0;

    m_c_life = new C_Life(this, 1);
    AddComponent(m_c_life);
    m_c_score = new C_Score(this);
    printf("scoreperhit %d \n", Config::Instance()->getScorePerHit());
    m_c_score->setScorePerHit(Config::Instance()->getScorePerHit());
    AddComponent(m_c_score);

    m_life = Config::Instance()->getMaxLife();


    m_msg = NULL;

}


void ProtaEntity::Update(double)
{
   /* for (int i = 0; i < m_Components.Size(); i++)
    {
        m_Components[i]->Update(elapsed);
    }*/
    getStateMachine()->GetCurrentState()->Execute(this);
}


void ProtaEntity::Render()
{
    RN.SetColor(0, 255, 0, 255);
    RN.DrawEllipse(m_posX, m_posY, m_radX, m_radY);

}

void ProtaEntity::AddComponent(Component* c)
{
    m_Components.Add(c);

}

void ProtaEntity::ReceiveMessage(Message *msg)
{
    printf("ReceiveMessage %d \n", rand() % 2);
    for (uint32 i = 0; i < m_Components.Size(); i++)
    {
        m_Components[i]->ReceiveMessage(msg);
    }
    delete msg;
    msg = NULL;

}

ProtaEntity::~ProtaEntity()
{
    delete m_pStateMachine;
    for (unsigned int i = 0; i < m_Components.Size(); i++)
        delete m_Components[i];
}

void ProtaEntity::Clean()
{
    for (uint32 x = 0; x < m_Components.Size(); x++)
    {
        delete(m_Components[x]);
    }
    m_Components.Clear();
}

