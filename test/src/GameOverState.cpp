#include "GameOverState.h"
#include "MenuState.h"

#include <Core.h>
#include <Label.h>

#include <sstream>
#include <string>

#include <iostream>

GameOverState::GameOverState()
{
	m_score = 0;
}

void GameOverState::enter(fe::Core &core)
{
	std::cout << "Enter Game Over State" << std::endl;

	m_timeInState = 0.0f;

	m_scoreLabel = new fe::Label();
	
	std::ostringstream oss;

	oss << "Score: " << m_score;
	
	m_scoreLabel->setText(oss.str());
	
	m_scoreLabel->setPosition(sf::Vector2f(100, 100));

	m_scoreLabel->centerX(core.getWindowRectangle());

	m_loseLabel = new fe::Label();

	m_loseLabel->setText("Game Over");

	m_loseLabel->setPosition(sf::Vector2f(100, 50));

	m_loseLabel->centerX(core.getWindowRectangle());
}

void GameOverState::reactEvent(fe::Core &core)
{
	const sf::Event &event = core.getEvent();

	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Space)
		{
			core.getStateMachine().setState(MenuState::instance());	
		}
	}
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

	core.getWindow().draw(*m_scoreLabel);
	
	core.getWindow().display();
}

void GameOverState::exit(fe::Core &core)
{
	delete m_loseLabel;

	delete m_scoreLabel;

	std::cout << "Exit Game Over State" << std::endl;
}

void GameOverState::setScore(unsigned int score)
{
	m_score = score;
}
