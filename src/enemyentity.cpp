#include "../include/enemyentity.h"
#include "../include/state.h"
#include "../include/renderer.h"
#include "../include/resourcemanager.h"
#include "../include/enemyownstates.h"

#define RN Renderer::Instance()

EnemyEntity::EnemyEntity(signed int speed,
    unsigned int width, unsigned int height, double angle, double increment,
    bool direction, double posX,
    double posY, double radX, double radY, bool isActive, int enemyType) :m_speed(speed), m_width(width), m_height(height),
    m_angle(angle), m_increment(increment), m_direction(direction), m_posX(posX), m_posY(posY), m_radX(radX), m_radY(radY), m_isActive(isActive),
    m_enemyType(enemyType)
{
    m_pStateMachine = new StateMachine<EnemyEntity>(this);
    m_pStateMachine->SetCurrentState(OnPlayEnemyState::Instance());
    m_entityType = EntityTypeStruct::ENEMY_ENTITY;
    OnPlayEnemyState::Instance()->Enter(this);
}

EnemyEntity::~EnemyEntity()
{
    delete m_pStateMachine;
    for (unsigned int i = 0; i < m_Components.Size(); i++)
        delete m_Components[i];
}

void EnemyEntity::Init()
{
    m_speed = (rand() % 200);
    m_angle = (rand() % 360);
    m_enemyType = rand() % 2;
}

void EnemyEntity::Render()
{
    if (m_enemyType == EnemyType::FOOD)
    {
        Renderer::Instance().SetColor(0, 0, 255, 255);
    }
    else
        Renderer::Instance().SetColor(255, 0, 0, 255);

    Renderer::Instance().DrawEllipse(m_posX, m_posY, 10, 10);
}

void EnemyEntity::Update(double)
{
    OnPlayEnemyState::Instance()->Execute(this);
}

void EnemyEntity::AddComponent(Component*)
{


}

void EnemyEntity::ReceiveMessage(Message *)
{

}
