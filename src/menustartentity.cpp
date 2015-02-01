#include "../include/menustartentity.h"
#include "../include/state.h"
#include "../include/renderer.h"
#include "../include/resourcemanager.h"
#include "../include/font.h"
#include "../include/menustartownerstates.h"


#define RN Renderer::Instance()

MenuStartEntity::MenuStartEntity()
{
    m_pStateMachine = new StateMachine<MenuStartEntity>(this);
    m_pStateMachine->SetCurrentState(OnStartMenuState::Instance());
    OnStartMenuState::Instance()->Enter(this);
    m_entityType = EntityTypeStruct::MENU_ENTITY;
}
MenuStartEntity::~MenuStartEntity()
{
    delete m_pStateMachine;
    for (unsigned int i = 0; i < m_items.Size(); i++)
        delete m_items[i];
    for (unsigned int i = 0; i < m_Components.Size(); i++)
        delete m_Components[i];
}
void MenuStartEntity::Update(double)
{
    OnStartMenuState::Instance()->Execute(this);
}


