#include "GameState.h"
#include "MenuState.h"
#include "GameOverState.h"

#include "Snake.h"

#include <Core.h>

#include <ResourceManager.h>

#include <SFML/Graphics.hpp>

#include <iostream>

GameState::GameState()
{	

}

void GameState::enter(fe::Core &core)
{
	std::cout << "Enter Game State" << std::endl;

	m_snake = new Snake();

	m_counter = new fe::Counter();

	m_counter->setPosition(sf::Vector2f(9.0f, 9.0f));

	m_lastUpdate = 0;
}

void GameState::reactEvent(fe::Core &core)
{
	const sf::Event &event = core.getEvent();

	m_counter->onEvent(event);

	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Up)
		{
			m_snake->setDirection(UP);
		}
		else if(event.key.code == sf::Keyboard::Down)
		{
			m_snake->setDirection(DOWN);
		}
		else if(event.key.code == sf::Keyboard::Left)
		{
			m_snake->setDirection(LEFT);	
		}
		else if(event.key.code == sf::Keyboard::Right)
		{
			m_snake->setDirection(RIGHT);
		}
		else if(event.key.code == sf::Keyboard::Escape)
		{
			core.getStateMachine().setState(MenuState::instance());
		}
	}
}

void GameState::execute(fe::Core &core)
{
	m_lastUpdate += core.getDelta();

	if(m_lastUpdate >= 0.1f)
	{
		m_counter->setCount(m_snake->score());

		m_snake->update(m_lastUpdate);

		core.getWindow().clear();

		m_snake->draw(core.getWindow());

		core.getWindow().draw(*m_counter);

		core.getWindow().display();
	
		m_lastUpdate = 0;
	}
	
	if(m_snake->isDead())
	{
		GameOverState::instance().setScore(m_snake->score());

		//core.getStateMachine().setState(MenuState::instance());
		core.getStateMachine().setState(GameOverState::instance());
	}

	int x = m_snake->positionX();

	int y = m_snake->positionY();

	if(x == -1 || y == -1 || x == 25 || y == 25)
	{
		GameOverState::instance().setScore(m_snake->score());
	
		//core.getStateMachine().setState(MenuState::instance());
		core.getStateMachine().setState(GameOverState::instance());
	}
}

void GameState::exit(fe::Core &core)
{
	delete m_snake;

	delete m_counter;

	std::cout << "Exit Game State" << std::endl;
}
