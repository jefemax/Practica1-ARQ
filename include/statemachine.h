#ifndef __STATEMACHINE_H
#define __STATEMACHINE_H

#include "state.h"
#include "stdio.h"
#include "string.h"
#include <typeinfo>

template <class entity_type>

class StateMachine
{

private:
    entity_type*    m_pOwner;
    State<entity_type>*   m_pCurrentState;
    State<entity_type>*   m_pPreviousState;
    State<entity_type>*   m_pGlobalState;

public:
    StateMachine(entity_type* owner) :m_pOwner(owner), m_pCurrentState(NULL), m_pPreviousState(NULL), m_pGlobalState(NULL)
    {}

    virtual ~StateMachine(){}
    void SetCurrentState(State<entity_type>* s)
    {
        m_pCurrentState = s;
    }
    void SetGlobalState(State<entity_type>* s) { m_pGlobalState = s; }
    void SetPreviousState(State<entity_type>* s) { m_pPreviousState = s; }

    State<entity_type>*  GetCurrentState()  const{ return m_pCurrentState; }
    State<entity_type>*  GetGlobalState()   const{ return m_pGlobalState; }
    State<entity_type>*  GetPreviousState() const{ return m_pPreviousState; }

    void Update() const
    {
        if (m_pGlobalState)   m_pGlobalState->Execute(m_pOwner);
        if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
    }


    void ChangeState(State<entity_type>* pNewState)
    {
        m_pPreviousState = m_pCurrentState;

        m_pCurrentState->Exit(m_pOwner);

        m_pCurrentState = pNewState;

        m_pCurrentState->Enter(m_pOwner);
    }


    bool  isInState(const State<entity_type>& st)const
    {

        String s = typeid(*m_pCurrentState).name();
        String p = typeid(st).name();
        //return m_pCurrentState->m_stateType == otherState;
        return s == p;
    }

    bool previousStateIsInState(const State<entity_type>& st)const
    {

        String s = typeid(*m_pPreviousState).name();
        String p = typeid(st).name();
        //return m_pCurrentState->m_stateType == otherState;
        return s == p;
    }



};

#endif