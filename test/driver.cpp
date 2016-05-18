#include "Core.h"

#include "GameState.h"

int main(void)
{
	srand(time(NULL));

	fe::Core *core = new fe::Core();

	//core->getStateMachine().setState(GameState::instance());	

	core->go();

	delete core;
}
