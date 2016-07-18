#include "StateMachine.h"

#include "EmptyState.h"

#include "Core.h"

fe::StateMachine::StateMachine(Core &core) :
	m_state(nullptr), m_nextState(nullptr), m_core(core)
{
	m_state = &EmptyState::instance();	

	m_state->enter(core);
}

void fe::StateMachine::setState(State &state)
{
	m_nextState = &state;

	/*
	m_state->exit(m_core);

	m_state = &state;

	m_state->enter(m_core);	
	*/
}

void fe::StateMachine::reactEvent()
{
	m_state->reactEvent(m_core);
}

void fe::StateMachine::execute()
{
	if(m_nextState != nullptr)
	{
		m_state->exit(m_core);

		m_state = m_nextState;

		m_state->enter(m_core);

		m_nextState = nullptr;
	}
m_state->execute(m_core); }
