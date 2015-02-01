#ifndef __C_LIFE_H
#define __C_LIFE_H

#include "component.h"
#include "entity.h"

class Font;

class C_Life : public Component
{
private:
    int m_life;
    int m_damage;
    Font *m_font;
public:
    C_Life(Entity* owner, int damage) :Component(owner)
    {
        this->m_damage = damage;
        m_font = ResourceManager::Instance().LoadFont(String("data/arial16.png").ToCString());
    }
    ~C_Life();
    virtual void Update(double elapsed);
    virtual void ReceiveMessage(Message *msg);
    void setLife(int life)
    {
        m_life = life;
    }
    //virtual ProtaEntity* getOwner();

};

#endif