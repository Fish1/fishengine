#include "ExampleState.h"

#include "Core.h"

#include "Button.h"
#include "Label.h"

#include <iostream>

ExampleState::ExampleState() :
	m_startButton(0)
{

}

void ExampleState::enter(fe::Core &core)
{
	std::cout << "Enter Example State" << std::endl;

	m_startButton = new fe::Button();	

	m_startButton->setText("Play");

	m_startButton->centerX(core.getWindowRectangle());

	m_startButton->centerY(core.getWindowRectangle());

	m_testButton = new fe::Button();

	m_title = new fe::Label();

	m_title->setTextString("Fish Engine");

	m_title->setPosition(sf::Vector2f(100, 50));

	m_title->centerX(core.getWindowRectangle());
}

void ExampleState::reactEvent(fe::Core &core)
{
	const sf::Event &event = core.getEvent();

	m_startButton->onEvent(event);
	
	if(m_startButton->isClicked())
	{
		std::cout << "You Clicked Play!" << std::endl;

		//core.getStateMachine().setState(GameState::instance());
	}
}

void ExampleState::execute(fe::Core &core)
{
	core.getWindow().clear();

	core.getWindow().draw(*m_startButton);

	core.getWindow().draw(*m_title);

	core.getWindow().display();
}

void ExampleState::exit(fe::Core &core)
{
	delete m_startButton;

	delete m_title;

	std::cout << "Exit Example State" << std::endl;
}
