#include "GameOverState.h"
#include "MenuState.h"

#include <Core.h>
#include <Label.h>

#include <iostream>

GameOverState::GameOverState()
{

}

void GameOverState::enter(fe::Core &core)
{
	std::cout << "Enter Game Over State" << std::endl;

	m_timeInState = 0.0f;

	m_loseLabel = new fe::Label();

	m_loseLabel->setText("Game Over");

	m_loseLabel->setPosition(sf::Vector2f(100, 50));

	m_loseLabel->centerX(core.getWindowRectangle());
}

void GameOverState::reactEvent(fe::Core &core)
{
	const sf::Event &event = core.getEvent();
}

void GameOverState::execute(fe::Core &core)
{
	m_timeInState += core.getDelta();

	if(m_timeInState >= 4.0f)
	{
		core.getStateMachine().setState(MenuState::instance());
	}

	core.getWindow().clear();

	core.getWindow().draw(*m_loseLabel);

	core.getWindow().display();
}

void GameOverState::exit(fe::Core &core)
{
	delete m_loseLabel;

	std::cout << "Exit Game Over State" << std::endl;
}
