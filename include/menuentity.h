#ifndef __MENU_ENTITY_H
#define __MENU_ENTITY_H

#include "entity.h"
#include "string.h"
#include "menustartownerstates.h"
#include "statemachine.h"

class Font;

struct MenuElement 
{
    enum TextType 
    {
        SELECTED,
        NORMAL
    };

    MenuElement(String s, uint16 posx, uint16 posy, uint8 textType)
    {
        m_text = s;
        m_posx = posx;
        m_posy = posy;
        m_textType = textType;

    }
    
    String m_text;
    uint16 m_posx;
    uint16 m_posy;
    uint8  m_textType;

};

class MenuEntity: public Entity
{
protected:
    Array<MenuElement*> m_items;
    Font *m_font;

    //an instance of the state machine class


public:

    MenuEntity();
    virtual ~MenuEntity(){}

    virtual void Init();
    virtual void Update(double elapsed);
    virtual void Render();
    virtual void ReceiveMessage(Message *msg);

    virtual void AddComponent(Component*);
    virtual void AddItem(MenuElement* obj);
    virtual Array<MenuElement*> getItems()
    {
        return m_items;
    }
    virtual Array<MenuElement*>* getItemsPtr()
    {
        return &m_items;
    }
    virtual Font* getFont()
    {
        return m_font;
    }


};

#endif
