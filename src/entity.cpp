#include "../include/entity.h"
#define RN Renderer::Instance()

void Entity::Init()
{

}

void Entity::Render()
{

}

void Entity::Update(double)
{


}

void Entity::AddComponent(Component* )
{


}

void Entity::ReceiveMessage(Message *msg)
{
    for (uint32 i = 0; i < m_Components.Size(); i++)
    {
        m_Components[i]->ReceiveMessage(msg);
    }
}

void Entity::Clean()
{
    for (uint32 x = 0; x < m_Components.Size(); x++)
    {
        delete(m_Components[x]);
    }
    m_Components.Clear();
}