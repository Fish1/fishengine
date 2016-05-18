#ifndef MENUSTATE
#define MENUSTATE

#include "State.h"

namespace fe
{
	class Label;
	class Button;
}

class ExampleState : public fe::State 
{
private:
	
	ExampleState();

	fe::Button *m_startButton;

	fe::Button *m_testButton;

	fe::Label *m_title;

public:

	static ExampleState &instance()
	{
		static ExampleState instance;

		return instance;	
	}

	void enter(fe::Core &core);

	void reactEvent(fe::Core &core);

	void execute(fe::Core &core);
	
	void exit(fe::Core &core);
};

#endif
