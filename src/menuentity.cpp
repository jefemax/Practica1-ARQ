#include "../include/menuentity.h"
#include "../include/state.h"
#include "../include/renderer.h"
#include "../include/resourcemanager.h"
#include "../include/font.h"


#define RN Renderer::Instance()

MenuEntity::MenuEntity()
{
}

void MenuEntity::Init()
{
    m_font = ResourceManager::Instance().LoadFont(String("data/arial16.png").ToCString());
}

void MenuEntity::Render()
{
    for (uint8 i = 0; i < m_items.Size(); i++)
    {

        switch (m_items[i]->m_textType)
        {
        case MenuElement::TextType::NORMAL:
            RN.SetColor(255, 255, 255, 255);
        break;
        case MenuElement::TextType::SELECTED:
            RN.SetColor(255, 0, 0, 255);
            break;
        default:
            break;
        }

        RN.DrawText(m_font, m_items[i]->m_text, m_items[i]->m_posx, m_items[i]->m_posy);
      //  RN.DrawText(m_font, String("Exit Level"), 400, 260);
    }

}

void MenuEntity::Update(double)
{


}

void MenuEntity::AddComponent(Component*)
{


}

void MenuEntity::AddItem(MenuElement* item)
{
    m_items.Add(item);
}

void MenuEntity::ReceiveMessage(Message *)
{

}