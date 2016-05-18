#include "Label.h"

#include "Core.h"

#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

fe::Label::Label()
{
	m_text = new sf::Text("a", *((sf::Font*)ResourceManager::instance().get("Font")));
}

fe::Label::~Label()
{
	delete m_text;
}

void fe::Label::centerX(const sf::Rect<float> &space)
{
	float newX = space.left + (space.width * 0.5f);

	newX -= (m_text->getLocalBounds().width * 0.5f);

	setPosition(newX, getPosition().y);	
}

void fe::Label::centerY(const sf::Rect<float> &space)
{
	float newY = space.top + (space.height * 0.5f);

	newY -= (m_text->getLocalBounds().height * 0.5f);

	setPosition(getPosition().x, newY);
}

void fe::Label::setTextString(std::string text)
{
	m_text->setString(text);
}

void fe::Label::setTextColor(sf::Color color)
{
	m_text->setColor(color);
}

void fe::Label::setTextSize(unsigned int size)
{
	m_text->setCharacterSize(size);
}

void fe::Label::onEvent(const sf::Event &event)
{

}

void fe::Label::onDraw(sf::RenderTarget &target,const sf::RenderStates &parent) const
{
	target.draw(*m_text, parent);
}
