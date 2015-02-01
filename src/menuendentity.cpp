#include "../include/menuendentity.h"
#include "../include/state.h"
#include "../include/renderer.h"
#include "../include/resourcemanager.h"
#include "../include/font.h"
#include "../include/menuendownerstates.h"


#define RN Renderer::Instance()

MenuEndEntity::MenuEndEntity()
{
    m_pStateMachine = new StateMachine<MenuEndEntity>(this);
    m_pStateMachine->SetCurrentState(OnStartEndMenuState::Instance());
    OnStartEndMenuState::Instance()->Enter(this);
    m_entityType = EntityTypeStruct::MENU_DEAD_ENTIY;
}

MenuEndEntity::~MenuEndEntity()
{
    delete m_pStateMachine;
    for (unsigned int i = 0; i < m_items.Size(); i++)
        delete m_items[i];
    for (unsigned int i = 0; i < m_Components.Size(); i++)
        delete m_Components[i];
}

void MenuEndEntity::Update(double)
{
    OnStartEndMenuState::Instance()->Execute(this);
}


