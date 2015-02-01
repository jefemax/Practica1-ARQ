#include "../include/menustartownerstates.h"
#include "../include/menustartentity.h"
#include "../include/world.h"
#include "../include/u-gine.h"
#include "../include/input.h"
#include "../include/creditsentity.h"
#include "../include/menuoptionsentity.h"

#define RN Renderer::Instance()

OnStartMenuState* OnStartMenuState::Instance()
{
    static OnStartMenuState instance;
    return &instance;
}

void OnStartMenuState::Enter(MenuStartEntity* entity)
{
    entity->Init();
    keysArray[GLFW_KEY_UP] = false;
    keysArray[GLFW_KEY_DOWN] = false;
    keysArray[GLFW_KEY_LEFT] = false;
    keysArray[GLFW_KEY_RIGHT] = false;
    keysArray[GLFW_KEY_M] = false;
    entity->AddItem(new MenuElement(String("New Game"), 400, 200, MenuElement::TextType::SELECTED));
    entity->AddItem(new MenuElement(String("Options"), 400, 220, MenuElement::TextType::NORMAL));
    entity->AddItem(new MenuElement(String("Credits"), 400, 240, MenuElement::TextType::NORMAL));
    entity->AddItem(new MenuElement(String("Exit Game"), 400, 260, MenuElement::TextType::NORMAL));

}

void OnStartMenuState::Execute(MenuStartEntity* entity)
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
                && (entity->getItems()[i]->m_text == String("New Game")))
            {
                if (entity->getStateMachine()->isInState(*OnStartMenuState::Instance()))
                {
                    World::Instance()->getStateMachine()->ChangeState(OnPlayingGameState::Instance());
                    return;
                }
            }

            if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                && (entity->getItems()[i]->m_text == String("Options")))
            {
                // World::Instance()->clean();
                World::Instance()->addEntity(new MenuOptionsEntity());
                entity->getStateMachine()->ChangeState(OnEndMenuState::Instance());
                return;
            }

            if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                && (entity->getItems()[i]->m_text == String("Credits")))
            {
               // World::Instance()->clean();
                World::Instance()->addEntity(new CreditsEntity());
                entity->getStateMachine()->ChangeState(OnEndMenuState::Instance());
                return;
            }

            if (entity->getItems()[i]->m_textType == MenuElement::TextType::SELECTED
                && (entity->getItems()[i]->m_text == String("Exit Game")))
            {
                World::Instance()->getStateMachine()->ChangeState(GEOnExitState::Instance());
            }
            //printf("entity->getItems()[i]->m_textType %d \n", entity->getItems()[i]->m_textType);
        }
    }

    RN.SetColor(150, 255, 0, 255);
    RN.DrawText(entity->getFont(), String("Instructions:"), 200, 350);
    RN.DrawText(entity->getFont(), String("Use arrows and press enter to move over Menus"), 200, 370);
    RN.DrawText(entity->getFont(), String("Choose new Game to start a Game"), 200, 390);
    RN.DrawText(entity->getFont(), String("During the game use Arrows to move and space bar to pause game"), 200, 410);
    RN.DrawText(entity->getFont(), String("You have to  eat all blue balls to win"), 200, 430);
    RN.DrawText(entity->getFont(), String("Every blue ball eated add life and score"), 200, 450);
    RN.DrawText(entity->getFont(), String("Every red ball collided reduce your life until death"), 200, 470);

}

void OnStartMenuState::Exit(MenuStartEntity* entity)
{
    for (uint32 i = 0; i < entity->getItemsPtr()->Size(); i++)
    {
        delete (*entity->getItemsPtr())[i];
    }

    entity->getItemsPtr()->Clear();
}

OnEndMenuState* OnEndMenuState::Instance()
{
    static OnEndMenuState instance;
    return &instance;
}

void OnEndMenuState::Enter(MenuStartEntity *)
{

}
void OnEndMenuState::Execute(MenuStartEntity*)
{

}
void OnEndMenuState::Exit(MenuStartEntity*)
{

}