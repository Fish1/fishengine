#include "StateMachine.h"

#include "ExampleState.h"

#include "Core.h"

fe::StateMachine::StateMachine(Core &core) :
	m_state(0), m_core(core)
{
	m_state = &ExampleState::instance();	

	m_state->enter(core);
}

void fe::StateMachine::setState(State &state)
{
	m_state->exit(m_core);

	m_state = &state;

	m_state->enter(m_core);	
}

void fe::StateMachine::reactEvent()
{
	m_state->reactEvent(m_core);
}

void fe::StateMachine::execute()
{
	m_state->execute(m_core);
}
