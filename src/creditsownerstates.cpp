#include "../include/creditsownerstates.h"
#include "../include/creditsentity.h"
#include "../include/input.h"
#include "../include/world.h"
#include "../include/protaentity.h"
#include "../include/menustartentity.h"

#define protaEntity dynamic_cast<ProtaEntity*>(World::Instance()->getProta())

OnStartCreditsState* OnStartCreditsState::Instance()
{
    static OnStartCreditsState instance;
    return &instance;
}

void OnStartCreditsState::Enter(CreditsEntity* entity)
{
    entity->Init();
    keysArray[GLFW_KEY_UP] = false;
    keysArray[GLFW_KEY_DOWN] = false;
    keysArray[GLFW_KEY_LEFT] = false;
    keysArray[GLFW_KEY_RIGHT] = false;
    keysArray[GLFW_KEY_M] = false;
    entity->AddItem(new MenuElement(String("Credits:"), 100, 200, MenuElement::TextType::SELECTED));
    entity->AddItem(new MenuElement(String("Programmer: Antonio Fernandez del Castillo"), 100, 240, MenuElement::TextType::NORMAL));
    entity->AddItem(new MenuElement(String("Design : Jon Beltran Heredia"), 100, 280, MenuElement::TextType::NORMAL));
    entity->AddItem(new MenuElement(String("Press space bar to go back"), 100, 340, MenuElement::TextType::NORMAL));

}

void OnStartCreditsState::Execute(CreditsEntity* entity)
{

    if (keyOnce(GLFW_KEY_SPACE, keysArray))
    {
        /*World::Instance()->clean();
        World::Instance()->addEntity(new MenuStartEntity());*/
        entity->getStateMachine()->ChangeState(OnEndCreditsState::Instance());
    }
}

void OnStartCreditsState::Exit(CreditsEntity* )
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

OnEndCreditsState* OnEndCreditsState::Instance()
{
    static OnEndCreditsState instance;
    return &instance;
}
void OnEndCreditsState::Enter(CreditsEntity *){}
void OnEndCreditsState::Execute(CreditsEntity*){}
void OnEndCreditsState::Exit(CreditsEntity*){}