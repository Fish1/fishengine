#ifndef MENUSTATE
#define MENUSTATE

#include <State.h>

namespace fe
{
	class Label;
	class Button;
}

class MenuState: public fe::State 
{
private:
	
	MenuState();

	fe::Button *m_startButton;

	fe::Button *m_testButton;

	fe::Label *m_title;

public:

	static MenuState &instance()
	{
		static MenuState instance;

		return instance;	
	}

	void enter(fe::Core &core);

	void reactEvent(fe::Core &core);

	void execute(fe::Core &core);
	
	void exit(fe::Core &core);
};

#endif
