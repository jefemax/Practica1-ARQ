#include "../include/u-gine.h"
#include "../include/menupauseownerstates.h"
#include "../include/menupause.h"
#include "../include/input.h"
#include "../include/menupause.h"
#include "../include/worldownerstate.h"
#include "../include/world.h"
#include "../include/protaentity.h"
#include "../include/menustartentity.h"
#include "../include/menuoptionsentity.h"

#define protaEntity dynamic_cast<ProtaEntity*>(World::Instance()->getProta())

OnStartPauseMenuState* OnStartPauseMenuState::Instance()
{
    static OnStartPauseMenuState instance;
    return &instance;
}

void OnStartPauseMenuState::Enter(PauseMenuEntity* entity)
{
    entity->Init();
    keysArray[GLFW_KEY_UP] = false;
    keysArray[GLFW_KEY_DOWN] = false;
    keysArray[GLFW_KEY_LEFT] = false;
    keysArray[GLFW_KEY_RIGHT] = false;
    keysArray[GLFW_KEY_M] = false;
    entity->AddItem(new MenuElement(String("Reestart game"), 400, 200, MenuElement::TextType::SELECTED));
    entity->AddItem(new MenuElement(String("Options"), 400, 220, MenuElement::TextType::NORMAL));
    entity->AddItem(new MenuElement(String("Exit Level"), 400, 240, MenuElement::TextType::NORMAL));

}

void OnStartPauseMenuState::Execute(PauseMenuEntity* entity)
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
                && (entity->getItems()[i]->m_text == String("Reestart game")))
            {
                if (entity->getStateMachine()->isInState(*OnStartPauseMenuState::Instance()))
                {
                    World::Instance()->getStateMachine()->GetCurrentState();
                    World::Instance()->getStateMachine()->ChangeState(OnPlayingGameState::Instance());
                    return;
                }
            }

            if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                && (entity->getItems()[i]->m_text == String("Options")))
            {
                if (entity->getStateMachine()->isInState(*OnStartPauseMenuState::Instance()))
                {
                    World::Instance()->addEntity(new MenuOptionsEntity());
                    entity->getStateMachine()->ChangeState(OnEndPauseMenuState::Instance());
                    return;
                }
            }
            /*

            */

            if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                && (entity->getItems()[i]->m_text == String("Exit Level")))
            {
                if (entity->getStateMachine()->isInState(*OnStartPauseMenuState::Instance()))
                {
                    protaEntity->getStateMachine()->ChangeState(ProtaDeadState::Instance());
                    World::Instance()->getStateMachine()->ChangeState(OnStartGameState::Instance());
                    World::Instance()->addEntity(new MenuStartEntity());
                    printf("");
                }
            }
            //printf("entity->getItems()[i]->m_textType %d \n", entity->getItems()[i]->m_textType);
        }
    }


}

void OnStartPauseMenuState::Exit(PauseMenuEntity* entity)
{
    for (uint32 i = 0; i < entity->getItemsPtr()->Size(); i++)
    {
        delete (*entity->getItemsPtr())[i];
    }

    entity->getItemsPtr()->Clear();
}

OnEndPauseMenuState* OnEndPauseMenuState::Instance()
{
    static OnEndPauseMenuState instance;
    return &instance;
}
void OnEndPauseMenuState::Enter(PauseMenuEntity *){}
void OnEndPauseMenuState::Execute(PauseMenuEntity*){}
void OnEndPauseMenuState::Exit(PauseMenuEntity*){}