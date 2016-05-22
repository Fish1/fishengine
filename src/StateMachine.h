#ifndef FE_STATEMACHINE
#define FE_STATEMACHINE

namespace fe
{
	class Core;

	class State;

	class StateMachine
	{
	private:

		State * m_state;

		Core &m_core;

	public:
		StateMachine(Core &core);

		void setState(State &state);

		void reactEvent();

		void execute();
	};
}

#endif
