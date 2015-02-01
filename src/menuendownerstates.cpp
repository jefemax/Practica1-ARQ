#include "../include/world.h"
#include "../include/u-gine.h"
#include "../include/menuendownerstates.h"
#include "../include/menuendentity.h"
#include "../include/input.h"

OnStartEndMenuState* OnStartEndMenuState::Instance()
{
    static OnStartEndMenuState instance;
    return &instance;
}

void OnStartEndMenuState::Enter(MenuEndEntity* entity)
{
    entity->Init();
    keysArray[GLFW_KEY_UP] = false;
    keysArray[GLFW_KEY_DOWN] = false;
    keysArray[GLFW_KEY_LEFT] = false;
    keysArray[GLFW_KEY_RIGHT] = false;
    keysArray[GLFW_KEY_M] = false;
    entity->AddItem(new MenuElement(String("Reestart game"), 400, 200, MenuElement::TextType::SELECTED));
    entity->AddItem(new MenuElement(String("Exit"), 400, 220, MenuElement::TextType::NORMAL));

}

void OnStartEndMenuState::Execute(MenuEndEntity* entity)
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
                if (entity->getStateMachine()->isInState(*OnStartEndMenuState::Instance()))
                {
                    World::Instance()->getStateMachine();
                    World::Instance()->getStateMachine()->ChangeState(OnPlayingGameState::Instance());
                    return;
                }
            }

            if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                && (entity->getItems()[i]->m_text == String("Exit")))
            {
                World::Instance()->getStateMachine()->ChangeState(GEOnExitState::Instance());
            }
            //printf("entity->getItems()[i]->m_textType %d \n", entity->getItems()[i]->m_textType);
        }
    }
    

}

void OnStartEndMenuState::Exit(MenuEndEntity* )
{

}