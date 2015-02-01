#include "../include/menuoptionsentity.h"
#include "../include/menuoptionsownerstates.h"

MenuOptionsEntity::MenuOptionsEntity()
{
    m_pStateMachine = new StateMachine<MenuOptionsEntity>(this);
    m_pStateMachine->SetCurrentState(OnStartOptionsMenuState::Instance());
    OnStartOptionsMenuState::Instance()->Enter(this);
    m_entityType = EntityTypeStruct::MENU_OPTIONS_ENTITY;
}
MenuOptionsEntity::~MenuOptionsEntity()
{
    delete m_pStateMachine;
    for (unsigned int i = 0; i < m_items.Size(); i++)
        delete m_items[i];
    for (unsigned int i = 0; i < m_Components.Size(); i++)
        delete m_Components[i];
}
void MenuOptionsEntity::Update(double)
{
    OnStartOptionsMenuState::Instance()->Execute(this);
}