#include "../include/C_score.h"
#include "../include/protaentity.h"
#include "../include/messages.h"

#define pEntity dynamic_cast<ProtaEntity*>(getOwner())
#define RN Renderer::Instance()

C_Score::~C_Score()
{

}

void C_Score::Update(double)
{

    RN.SetColor(255, 255, 255, 255);
    RN.DrawText(m_font, String().FromInt(m_score), 30, 30);

}

void C_Score::ReceiveMessage(Message *msg)
{
    if (dynamic_cast<AddScoreMessage*>(msg))
    {
        printf("entra en m_score %d \n", m_score);
        m_score += m_scorePerHit;
        RN.SetColor(255, 255, 255, 255);
        RN.DrawText(m_font, String().FromInt(m_score), 30, 30);
    }
}