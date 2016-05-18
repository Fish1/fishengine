#include "Core.h" 

#include "StateMachine.h"

#include "ResourceManager.h"

#include <iostream>

fe::Core::Core() :
	m_running(true), m_delta(0.0f),
	m_window(sf::VideoMode(400, 400), "My Game!")
{
	loadResources();

	m_stateMachine = new StateMachine(*this);
}

fe::Core::~Core()
{
	delete m_stateMachine;
}

void fe::Core::loadResources()
{
	ResourceManager& rm = ResourceManager::instance();

	sf::Font *font = new sf::Font();

	font->loadFromFile("unispace.ttf");

	//font->loadFromFile("Resources/Fonts/unispace.ttf");

	rm.put("Font", font);
}

void fe::Core::go()
{
	while(m_running)
	{
		m_delta = m_clock.restart().asSeconds();
	
		while(m_window.pollEvent(m_event))
		{
			if(m_event.type == sf::Event::Closed)
			{
				m_window.close();

				stop();
			}

			m_stateMachine->reactEvent();
		}

		m_stateMachine->execute();
	}
}

void fe::Core::stop()
{
	m_running = false;
}

float fe::Core::getDelta() const
{
	return m_delta;
}

const sf::Event& fe::Core::getEvent() const
{
	return m_event;
}

fe::StateMachine& fe::Core::getStateMachine()
{
	return *m_stateMachine;
}

sf::RenderWindow& fe::Core::getWindow()
{
	return m_window;
}

sf::Rect<float> fe::Core::getWindowRectangle() const
{
	sf::Vector2f size(m_window.getSize());

	sf::Rect<float> rect(sf::Vector2f(0.0f, 0.0f), size);

	return rect;
}
