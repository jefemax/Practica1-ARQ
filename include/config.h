#ifndef __CONFIG_H
#define __CONFIG_H
#include "u-gine.h"

class Config{

private:
    Config(){};
    Config(const Config&);
    Config& operator=(const Config);
    uint32 m_numEnemigos;
    int32 m_enemySpeed;
    int32 m_maxlife;
    int32 m_score_per_hit;
public:
    ~Config();
    static Config* Instance();
    void setNumEnemigos(uint32 numEnemigos)
    {
        m_numEnemigos = numEnemigos;
    }
    uint32 getNumEnemigos()
    {
        return m_numEnemigos;
    }
    void setEnemySpeed(int32 enemySpeed)
    {
        m_enemySpeed = enemySpeed;
    }
    int32 getEnemySpeed()
    {
        return m_enemySpeed;
    }
    void setMaxLife(int32 maxLife)
    {
        m_maxlife = maxLife;
    }
    int32 getMaxLife()
    {
        return m_maxlife;
    }
    void setScorePerHit(int32 scorePerHit)
    {
        m_score_per_hit = scorePerHit;
    }
    int32 getScorePerHit()
    {
        return m_score_per_hit;
    }
};

#endif