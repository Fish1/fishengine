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

	fe::Label *m_scoreLabel;

	int m_score;

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

	void setScore(unsigned int score);
}; 

#endif
