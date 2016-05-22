#include "MenuState.h"
#include "GameState.h"

#include <Core.h>
#include <ResourceManager.h>

#include <Button.h>
#include <Label.h>

#include <iostream>

MenuState::MenuState() :
	m_startButton(0)
{

}

void MenuState::enter(fe::Core &core)
{
	std::cout << "Enter Menu State" << std::endl;

	m_startButton = new fe::Button();	

	//m_startButton->setFont(fe::ResourceManager::instance().getFont("Font"));
	
	m_startButton->setText("Play");

	m_startButton->centerX(core.getWindowRectangle());

	m_startButton->centerY(core.getWindowRectangle());

	m_testButton = new fe::Button();

	m_title = new fe::Label();

	//m_title->setFont(fe::ResourceManager::instance().getFont("Font"));

	m_title->setText("Fish Engine");

	m_title->setPosition(sf::Vector2f(100, 50));

	m_title->centerX(core.getWindowRectangle());
}

void MenuState::reactEvent(fe::Core &core)
{
	const sf::Event &event = core.getEvent();

	m_startButton->onEvent(event);
	
	if(m_startButton->isClicked())
	{
		core.getStateMachine().setState(GameState::instance());
	}
}

void MenuState::execute(fe::Core &core)
{
	core.getWindow().clear();

	core.getWindow().draw(*m_startButton);

	core.getWindow().draw(*m_title);

	core.getWindow().display();
}

void MenuState::exit(fe::Core &core)
{
	delete m_startButton;

	delete m_title;

	std::cout << "Exit Menu State" << std::endl;
}
