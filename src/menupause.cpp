#include "../include/menupause.h"
#include "../include/menupauseownerstates.h"

PauseMenuEntity::PauseMenuEntity()
{
    m_pStateMachine = new StateMachine<PauseMenuEntity>(this);
    m_pStateMachine->SetCurrentState(OnStartPauseMenuState::Instance());
    OnStartPauseMenuState::Instance()->Enter(this);
    m_entityType = EntityTypeStruct::MENU_PAUSE_ENTITY;
}
PauseMenuEntity::~PauseMenuEntity()
{
    delete m_pStateMachine;
    for (unsigned int i = 0; i < m_items.Size(); i++)
        delete m_items[i];
    for (unsigned int i = 0; i < m_Components.Size(); i++)
        delete m_Components[i];
}
void PauseMenuEntity::Update(double)
{
    OnStartPauseMenuState::Instance()->Execute(this);
}