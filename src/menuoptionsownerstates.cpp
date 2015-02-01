#include "../include/menuoptionsownerstates.h"
#include "../include/input.h"
#include "../include/menuoptionsentity.h"
#include "../include/World.h"
#include "../include/worldownerstate.h"
#include "../include/menustartentity.h"
#include "../include/menupause.h"
#include "../include/menupauseownerstates.h"

#define MUSIC_ON "Music ON"
#define MUSIC_OFF "Music OFF"

#define SOUND_ON "Sound ON"
#define SOUND_OFF "Sound OFF"
#define EA World::Instance()->getEntityArray()

OnStartOptionsMenuState* OnStartOptionsMenuState::Instance()
{
    static OnStartOptionsMenuState instance;
    return &instance;
}

void OnStartOptionsMenuState::Enter(MenuOptionsEntity* entity)
{
    entity->Init();
    keysArray[GLFW_KEY_UP] = false;
    keysArray[GLFW_KEY_DOWN] = false;
    keysArray[GLFW_KEY_LEFT] = false;
    keysArray[GLFW_KEY_RIGHT] = false;
    keysArray[GLFW_KEY_M] = false;
    entity->AddItem(new MenuElement(String(MUSIC_ON), 400, 200, MenuElement::TextType::SELECTED));
    entity->AddItem(new MenuElement(String(SOUND_ON), 400, 220, MenuElement::TextType::NORMAL));
    entity->AddItem(new MenuElement(String("Exit Options"), 400, 240, MenuElement::TextType::NORMAL));

}

void OnStartOptionsMenuState::Execute(MenuOptionsEntity* entity)
{
    
        if (keyOnce(GLFW_KEY_DOWN, keysArray))
        {
            printf("entra");
            for (uint32 i = 0; i < (entity->getItems()).Size(); i++)
            {
                //Si el elemento esta seleccionado entonces selecciona el de abajo

                if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED)
                {
                    if ((i + 1) < entity->getItems().Size())
                    {
                        entity->getItems()[i]->m_textType = MenuElement::TextType::NORMAL;
                        entity->getItems()[i + 1]->m_textType = MenuElement::TextType::SELECTED;
                        break;
                    }
                }
                //printf("entity->getItems()[i]->m_textType %d \n", entity->getItems()[i]->m_textType);
            }

        }
        if (keyOnce(GLFW_KEY_UP, keysArray))
        {
            printf("entra");
            for (uint8 i = 0; i < (entity->getItems()).Size(); i++)
            {
                //Si el elemento esta seleccionado entonces selecciona el de abajo

                if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED)
                {
                    if ((i - 1) >= 0)
                    {
                        entity->getItems()[i]->m_textType = MenuElement::TextType::NORMAL;
                        entity->getItems()[i - 1]->m_textType = MenuElement::TextType::SELECTED;
                        break;
                    }
                }
                //printf("entity->getItems()[i]->m_textType %d \n", entity->getItems()[i]->m_textType);
            }

        }
        if (keyOnce(GLFW_KEY_ENTER, keysArray))
        {
            for (uint8 i = 0; i < (entity->getItems()).Size(); i++)
            {
                //Si el elemento esta seleccionado entonces selecciona el de abajo

                if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                    && (entity->getItems()[i]->m_text == String(MUSIC_ON)))
                {
                    entity->getItems()[i]->m_text = String(MUSIC_OFF);
                }
                else if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                    && (entity->getItems()[i]->m_text == String(MUSIC_OFF)))
                {
                    entity->getItems()[i]->m_text = String(MUSIC_ON);
                }
                if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                    && (entity->getItems()[i]->m_text == String(SOUND_ON)))
                {
                    entity->getItems()[i]->m_text = String(SOUND_OFF);
                }
                else if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                    && (entity->getItems()[i]->m_text == String(SOUND_OFF)))
                {
                    entity->getItems()[i]->m_text = String(SOUND_ON);
                }

                if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                    && (entity->getItems()[i]->m_text == String("Exit Options")))
                {
                    entity->getStateMachine()->ChangeState(OnEndOptionsMenuState::Instance());
                }

               /* if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                    && (entity->getItems()[i]->m_text == "Exit"))
                {
                    World::Instance()->getStateMachine()->ChangeState(GEOnExitState::Instance());
                }*/
                //printf("entity->getItems()[i]->m_textType %d \n", entity->getItems()[i]->m_textType);
            }
        }
}

void OnStartOptionsMenuState::Exit(MenuOptionsEntity* )
{
    if (World::Instance()->getStateMachine()->isInState(*OnStartGameState::Instance()))
    {
        for (uint32 x = 0; x < World::Instance()->getEntityArray()->Size(); x++)
        {
            Entity *entity = (*World::Instance()->getEntityArray())[x];

            if (entity->getEntitytype() == EntityTypeStruct::MENU_ENTITY &&
                dynamic_cast<MenuStartEntity*>(entity)->getStateMachine()->isInState(*OnEndMenuState::Instance()))
            {
                dynamic_cast<MenuStartEntity*>(entity)->getStateMachine()->ChangeState(OnStartMenuState::Instance());
            }
        }
    }
    else if (World::Instance()->getStateMachine()->isInState(*GEOnPauseGameState::Instance()))
    {
        for (uint32 x = 0; x < World::Instance()->getEntityArray()->Size(); x++)
        {
            Entity *entity = (*World::Instance()->getEntityArray())[x];

            if (entity->getEntitytype() == EntityTypeStruct::MENU_PAUSE_ENTITY &&
                dynamic_cast<PauseMenuEntity*>(entity)->getStateMachine()->isInState(*OnEndPauseMenuState::Instance()))
            {
                dynamic_cast<PauseMenuEntity*>(entity)->getStateMachine()->ChangeState(OnStartPauseMenuState::Instance());
            }
        }
    }
}

OnEndOptionsMenuState* OnEndOptionsMenuState::Instance()
{
    static OnEndOptionsMenuState instance;
    return &instance;
}

void OnEndOptionsMenuState::Enter(MenuOptionsEntity *)
{

}
void OnEndOptionsMenuState::Execute(MenuOptionsEntity*)
{

}
void OnEndOptionsMenuState::Exit(MenuOptionsEntity*)
{

}
