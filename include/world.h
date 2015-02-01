#ifndef __WORLD_H
#define __WORLD_H
#include "u-gine.h"
#include "worldownerstate.h"
#include "component.h"

class Entity;
class ProtaEntity;
template <class entity_type>
class StateMachine;

class World{

private:

    World(){};
    World(const World&);
    World& operator=(const World);

    Component* m_collisionComp;
    Array<Entity*> m_entityArray;
    StateMachine<World>* m_pStateMachine;
    ProtaEntity *m_prota;

public:
    ~World();
    static World* Instance();
    void init();
    void execute();
    void update();
    void draw();
    void cleanForPlay();
    StateMachine<World>* getStateMachine()
    {
        return m_pStateMachine;
    }
    void addEntity(Entity* entity)
    {
        m_entityArray.Add(entity);
    }

    ProtaEntity* getProta()
    {
        return m_prota;
    }

    Array<Entity*>* getEntityArray()
    {
        return &m_entityArray;
    }
    void setCollisionComp(Component *c)
    {
        this->m_collisionComp = c;
    }
    Component* getCollisionComp()
    {
        return m_collisionComp;
    }
};

#endif