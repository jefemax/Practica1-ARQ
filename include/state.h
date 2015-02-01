#ifndef __STATE_H
#define __STATE_H



struct StateTypeStruct
{
    enum StateType
    {
        ON_START_MENU_STATE,
        ON_START_GAME_STATE
    };
};

template <class entity_type>

class State
{
public:

    virtual ~State(){}
    virtual void Enter(entity_type* e) = 0;
    virtual void Execute(entity_type* e) = 0;
    virtual void Exit(entity_type* e) = 0;

    int m_stateType;

};

#endif