#include <Core.h>

#include <ResourceManager.h>

#include <Label.h>

#include "MenuState.h"

int main(void)
{
	srand(time(NULL));

	fe::ResourceManager &rm = fe::ResourceManager::instance();

	rm.loadFont("Font", "resources/fonts/unispace.ttf");

	rm.loadSoundBuffer("Score", "resources/sounds/score.wav");

	fe::Label::setDefaultFont(&rm.getFont("Font"));

	fe::Core *core = new fe::Core(300, 300);

	core->getStateMachine().setState(MenuState::instance());	

	core->go();

	delete core;

	rm.freeAll();
}
