#ifndef __C_SCORE_H
#define __C_SCORE_H

#include "component.h"


class Entity;
class Font;

class C_Score : public Component
{
private:

    int m_score;
    int m_lifeCount;
    int m_scorePerHit;
    Font *m_font;
public:
    C_Score(Entity* owner) :Component(owner)
    {
        m_score = 0;
        m_font = ResourceManager::Instance().LoadFont(String("data/arial16.png").ToCString());
        m_lifeCount = 0;
    }
    ~C_Score();
    virtual void Update(double elapsed);
    virtual void ReceiveMessage(Message *msg);
    int getScore()
    {
        return m_score;
    }
    int getScorePerHit()
    {
        return m_scorePerHit;
    }

    void setScorePerHit(int scorePerHit)
    {
         m_scorePerHit = scorePerHit;
    }
    //virtual ProtaEntity* getOwner();

};

#endif