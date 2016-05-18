#include "GameState.h"

#include "Snake.h"

#include "Core.h"

#include <SFML/Graphics.hpp>

#include <iostream>

GameState::GameState()
{	

}

void GameState::enter(fe::Core &core)
{
	std::cout << "Enter Game State" << std::endl;

	m_Snake = new Snake();

	m_lastUpdate = 0;
}

void GameState::reactEvent(fe::Core &core)
{
	sf::Event event = core.getEvent();

	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Up)
		{
			m_Snake->setDirection(UP);
		}
		else if(event.key.code == sf::Keyboard::Down)
		{
			m_Snake->setDirection(DOWN);
		}
		else if(event.key.code == sf::Keyboard::Left)
		{
			m_Snake->setDirection(LEFT);	
		}
		else if(event.key.code == sf::Keyboard::Right)
		{
			m_Snake->setDirection(RIGHT);
		}
		else if(event.key.code == sf::Keyboard::Space)
		{
			//core.getStateMachine().setState(MenuState::instance());
		}
	}
}

void GameState::execute(fe::Core &core)
{
	m_lastUpdate += core.getDelta();

	if(m_lastUpdate >= 0.1f)
	{
		m_Snake->update(m_lastUpdate);

		core.getWindow().clear();

		m_Snake->draw(&core.getWindow());
	
		core.getWindow().display();
	
		m_lastUpdate = 0;
	}
	
	if(m_Snake->isDead())
	{
		std::cout << "YOU LOSE!" << std::endl;

		//game.getStateMachine().setState(GameOverState::instance(m_Snake->size() - 1));
	}
}

void GameState::exit(fe::Core &core)
{
	delete m_Snake;

	std::cout << "Exit Game State" << std::endl;
}
