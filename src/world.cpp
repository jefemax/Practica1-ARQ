#include "../include/messages.h"
#include "../include/menustartentity.h"
#include "../include/protaentity.h"
#include "../include/enemyentity.h"
#include "../include/enemyownstates.h"
#include "../include/world.h"
#include "../include/statemachine.h"
#include "../include/config.h"
#include "../include/C_Collision.h"
#include "../include/readdata.h"
#include "../include/creditsentity.h"
#include "../include/menuoptionsentity.h"
#include "../include/creditsownerstates.h"
#include "../include/menuoptionsownerstates.h"
#include "../include/menupause.h"
#include "../include/menupauseownerstates.h"

#define RN Renderer::Instance()
#define SC Screen::Instance()
#define pEntity dynamic_cast<ProtaEntity*>(prota)
#define eEntity dynamic_cast<EnemyEntity*>(b)

const int WIDTH = 800;
const int HEIGHT = 600;
const uint16 NUM_OF_ENEM = 20;

World* World::Instance()
{
    static World instance;
    if (!instance.m_pStateMachine)
    {
        instance.m_pStateMachine = new StateMachine<World>(&instance);
        instance.m_pStateMachine->SetCurrentState(OnStartGameState::Instance());
    }
    return &instance;
}

World::~World()
{
}

void World::execute()
{
    Screen::Instance().Open(WIDTH, HEIGHT, false);
    init();

    RN.SetBlendMode(Renderer::BlendMode::ALPHA);
    while (Screen::Instance().IsOpened() && !m_pStateMachine->isInState(*GEOnExitState::Instance()))
    {
        RN.Clear();
        update();
        draw();
        Screen::Instance().Refresh();
    }
    ResourceManager::Instance().FreeFonts();
}

void World::init()
{
    ReadData(String("Data/config.xml"));
    MenuStartEntity *mainMenuEntity = new MenuStartEntity();
    m_entityArray.Add(mainMenuEntity);
    m_prota = new ProtaEntity();
}

void World::update()
{
    for (uint32 i = 0; i < m_entityArray.Size(); i++)
    {
        Entity *entity = m_entityArray[i];

        if (m_pStateMachine->isInState(*OnStartGameState::Instance()))
        {
            if (entity->getEntitytype() == EntityTypeStruct::MENU_ENTITY &&
                dynamic_cast<MenuStartEntity*>(entity)->getStateMachine()->isInState(*OnStartMenuState::Instance()))
            {
                entity->Update(SC.ElapsedTime());
            }

            if (entity->getEntitytype() == EntityTypeStruct::CREDITS_ENTITY &&
                dynamic_cast<CreditsEntity*>(entity)->getStateMachine()->isInState(*OnStartCreditsState::Instance()))
            {
                entity->Update(SC.ElapsedTime());
            }

            if (entity->getEntitytype() == EntityTypeStruct::MENU_OPTIONS_ENTITY &&
                dynamic_cast<MenuOptionsEntity*>(entity)->getStateMachine()->isInState(*OnStartOptionsMenuState::Instance()))
            {
                entity->Update(SC.ElapsedTime());
            }
        }

        if (m_pStateMachine->isInState(*OnPlayingGameState::Instance()))
        {
            if (m_collisionComp)
            {
                dynamic_cast<C_collision*>(m_collisionComp)->setEnemyInturn(entity);
                m_collisionComp->Update(SC.ElapsedTime());
            }

            if (entity->getEntitytype() == EntityTypeStruct::PROTA_ENTITY)
            {
                entity->Update(SC.ElapsedTime());
            }
            if (entity->getEntitytype() == EntityTypeStruct::ENEMY_ENTITY
                && dynamic_cast<EnemyEntity*>(entity)->getStateMachine()->isInState(*OnPlayEnemyState::Instance()))
            {

                entity->Update(SC.ElapsedTime());
            }
        }
        if (m_pStateMachine->isInState(*GEOnEndGameState::Instance()))
        {
            if (entity->getEntitytype() == EntityTypeStruct::MENU_DEAD_ENTIY)
            {
                entity->Update(SC.ElapsedTime());
            }
        }

        if (m_pStateMachine->isInState(*GEOnPauseGameState::Instance()))
        {
            if (entity->getEntitytype() == EntityTypeStruct::MENU_PAUSE_ENTITY &&
                dynamic_cast<PauseMenuEntity*>(entity)->getStateMachine()->isInState(*OnStartPauseMenuState::Instance()))
                
            {
                entity->Update(SC.ElapsedTime());
            }
            if (entity->getEntitytype() == EntityTypeStruct::MENU_OPTIONS_ENTITY &&
                dynamic_cast<MenuOptionsEntity*>(entity)->getStateMachine()->isInState(*OnStartOptionsMenuState::Instance()))
            {
                entity->Update(SC.ElapsedTime());
            }
        }
    }
    m_pStateMachine->GetCurrentState()->Execute(this);
}

void World::draw()
{
    for (uint32 i = 0; i < m_entityArray.Size(); i++)
    {
        Entity *entity = m_entityArray[i];

        if (m_pStateMachine->isInState(*OnStartGameState::Instance()))
        {
            if (entity->getEntitytype() == EntityTypeStruct::MENU_ENTITY &&
                dynamic_cast<MenuStartEntity*>(entity)->getStateMachine()->isInState(*OnStartMenuState::Instance()))
            {
                entity->Render();
            }
            if (entity->getEntitytype() == EntityTypeStruct::CREDITS_ENTITY &&
                dynamic_cast<CreditsEntity*>(entity)->getStateMachine()->isInState(*OnStartCreditsState::Instance()))
            {
                entity->Render();
            }
            if (entity->getEntitytype() == EntityTypeStruct::MENU_OPTIONS_ENTITY &&
                dynamic_cast<MenuOptionsEntity*>(entity)->getStateMachine()->isInState(*OnStartOptionsMenuState::Instance()))
            {
                entity->Render();
            }
            
        }

        if (m_pStateMachine->isInState(*OnPlayingGameState::Instance()))
        {
            if (entity->getEntitytype() == EntityTypeStruct::PROTA_ENTITY)
            {
                entity->Render();
            }

            if (entity->getEntitytype() == EntityTypeStruct::ENEMY_ENTITY && entity->getActive()
                && dynamic_cast<EnemyEntity*>(entity)->getStateMachine()->isInState(*OnPlayEnemyState::Instance()))
            {
                entity->Render();
            }
        }

        if (m_pStateMachine->isInState(*GEOnEndGameState::Instance()))
        {
            if (entity->getEntitytype() == EntityTypeStruct::MENU_DEAD_ENTIY)
            {
                entity->Render();
            }
        }
        if (m_pStateMachine->isInState(*GEOnPauseGameState::Instance()))
        {
            if (entity->getEntitytype() == EntityTypeStruct::MENU_PAUSE_ENTITY &&
                dynamic_cast<PauseMenuEntity*>(entity)->getStateMachine()->isInState(*OnStartPauseMenuState::Instance()))

            {
                entity->Render();
            }
            if (entity->getEntitytype() == EntityTypeStruct::MENU_OPTIONS_ENTITY &&
                dynamic_cast<MenuOptionsEntity*>(entity)->getStateMachine()->isInState(*OnStartOptionsMenuState::Instance()))
            {
                entity->Render();
            }
        }
    }
}

void World::cleanForPlay()
{
    delete getCollisionComp();
    for (uint32 x = 0; x < m_entityArray.Size(); x++)
    {
        printf("tipos entidades %d %d \n", x, m_entityArray[x]->getEntitytype());

        if (m_entityArray[x]->getEntitytype() != EntityTypeStruct::PROTA_ENTITY){
            delete m_entityArray[x];
        }
    }
    m_entityArray.Clear();
    printf("");
}


/*
#define RN Renderer::Instance()

const int WIDTH = 800;
const int HEIGHT = 600;
const int SIZEARRAY = 1;
const int ANGLE_TO_ROTATE = 90;


const int DERECHA = 1;
const int IZQUIERDA = 0;

const int NUM_OF_ENEMYS = 20;

const unsigned int RADIUS = 50;

const int width = 800;
const int height = 600;

const int distanciaAlcirculo = 30;
const int velocidad = 40;





void init(Array<Entity*> entityArray);

void init(Array<Entity*> entityArray)
{
MenuEntity *mainMenuEntity = new MenuEntity();
mainMenuEntity->AddItem(new MenuElement(String("New Game"), 400, 200, MenuElement::TextType::SELECTED));
mainMenuEntity->AddItem(new MenuElement(String("Options"), 400, 220, MenuElement::TextType::NORMAL));
mainMenuEntity->AddItem(new MenuElement(String("Credits"), 400, 240, MenuElement::TextType::NORMAL));
mainMenuEntity->AddItem(new MenuElement(String("Exit Game"), 400, 260, MenuElement::TextType::NORMAL));

entityArray.Add(mainMenuEntity);

for (uint32 i = 0; i < entityArray.Size(); i++)
{
Entity *e = entityArray[i];

}


}*/