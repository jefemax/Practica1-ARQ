#include "../include/C_Collision.h"
#include "../include/world.h"
#include "../include/protaentity.h"
#include "../include/enemyentity.h"
#include "../include/enemyownstates.h"
#include "../include/messages.h"
#include "../include/enemyentity.h"
//#include "../include/math.h"

#define wEntity World::Instance()
#define pEntity wEntity->getProta()
#define eEntity dynamic_cast<EnemyEntity*>(b)

C_collision::~C_collision()
{

}
void C_collision::Update(double)
{
        if (cirlceToCircledetection(enemyInTurn))
        {
            m_msg = new ReduceLifeMessage(1);
            pEntity->ReceiveMessage(m_msg);
        }
}

void C_collision::ReceiveMessage(Message*)
{
    
}

bool C_collision::cirlceToCircledetection(Entity *b)
{

    if (b->getEntitytype()==EntityTypeStruct::ENEMY_ENTITY){
        double distance = Distance(pEntity->getPosX(), pEntity->getPosY(), eEntity->getPosX(), eEntity->getPosY());
        int f_diff = abs(static_cast<int>(pEntity->getRadRes())) + abs(static_cast<int>(eEntity->getRadRes()));
        if (distance <= f_diff)
        {
            if (eEntity->getEnemyType() == EnemyType::FOOD)
            {
                if (!eEntity->getStateMachine()->isInState(*OnDeathEnemyState::Instance()))
                {
                    eEntity->getStateMachine()->ChangeState(OnDeathEnemyState::Instance());
                     AddLifeMessage *rlfmsg = new AddLifeMessage(20);
                    printf("genero mensaje de agregar vida \n");
                    pEntity->ReceiveMessage(rlfmsg);
                    wEntity->getEntityArray()->Remove(b);
                    delete b;
                    int countFood = 0;
                    #define item (*wEntity->getEntityArray())[x]
                    for (uint32 x = 0; x < wEntity->getEntityArray()->Size(); x++)
                    {
                        if (item->getEntitytype() == EntityTypeStruct::ENEMY_ENTITY
                            && dynamic_cast<EnemyEntity*>(item)->getEnemyType() == EnemyType::FOOD)
                        {
                            countFood++;
                        }
                    }
                    if (countFood == 0)
                    {
                        pEntity->getStateMachine()->ChangeState(ProtaDeadState::Instance());
                        wEntity->getStateMachine()->ChangeState(GEOnEndGameState::Instance());
                    }
                }
               /* AddLifeMessage *rlfmsg = new AddLifeMessage(20);
                printf("genero mensaje de agregar vida \n");
                pEntity->ReceiveMessage(rlfmsg);*/
                return false;
            }
            else
                return true;
        }
        return false;
    }
    return false;
}