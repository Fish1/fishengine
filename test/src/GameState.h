#ifndef GAMESTATE
#define GAMESTATE

#include <State.h>

#include <Counter.h>

#include <Sound.h>

class Snake;

class GameState : public fe::State
{
private:
	
	GameState();

	Snake *m_snake;

	float m_lastUpdate;

	fe::Counter *m_counter;

public:

	static GameState &instance()
	{
		static GameState instance;
	
		return instance;
	}

	void enter(fe::Core &core);

	void reactEvent(fe::Core &core);
	
	void execute(fe::Core &core);
	
	void exit(fe::Core &core);
};

#endif
