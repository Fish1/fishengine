#ifndef GAMEOVERSTATE
#define GAMEOVERSTATE

#include <State.h>

namespace fe
{
	class Label;
}

class GameOverState : public fe::State
{
private:
	
	GameOverState();

	fe::Label *m_loseLabel;
	
	float m_timeInState;

public:

	static GameOverState &instance()
	{
		static GameOverState instance;

		return instance;
	}

	void enter(fe::Core &core);

	void reactEvent(fe::Core &core);
	
	void execute(fe::Core &core);

	void exit(fe::Core &core);
}; 

#endif
