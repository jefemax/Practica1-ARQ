#include "../include/creditsentity.h"
#include "../include/creditsownerstates.h"


CreditsEntity::CreditsEntity()
{
    m_pStateMachine = new StateMachine<CreditsEntity>(this);
    m_pStateMachine->SetCurrentState(OnStartCreditsState::Instance());
    OnStartCreditsState::Instance()->Enter(this);
    m_entityType = EntityTypeStruct::CREDITS_ENTITY;
}

CreditsEntity::~CreditsEntity()
{
    delete m_pStateMachine;
    delete m_font;
    for (unsigned int i = 0; i < m_items.Size(); i++)
        delete m_items[i];
    for (unsigned int i = 0; i < m_Components.Size(); i++)
        delete m_Components[i];
}

void CreditsEntity::Update(double)
{
    OnStartCreditsState::Instance()->Execute(this);
}