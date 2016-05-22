#include "GameState.h"
#include "MenuState.h"

#include "Snake.h"

#include <Core.h>

#include <SFML/Graphics.hpp>

#include <iostream>

GameState::GameState()
{	

}

void GameState::enter(fe::Core &core)
{
	std::cout << "Enter Game State" << std::endl;

	m_snake = new Snake();

	m_lastUpdate = 0;
}

void GameState::reactEvent(fe::Core &core)
{
	const sf::Event &event = core.getEvent();

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
		m_snake->update(m_lastUpdate);

		core.getWindow().clear();

		m_snake->draw(core.getWindow());
	
		core.getWindow().display();
	
		m_lastUpdate = 0;
	}
	
	if(m_snake->isDead())
	{
		core.getStateMachine().setState(MenuState::instance());
	}
}

void GameState::exit(fe::Core &core)
{
	delete m_snake;

	std::cout << "Exit Game State" << std::endl;
}
