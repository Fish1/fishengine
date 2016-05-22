#include "Label.h"

#include "Core.h"

#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

const sf::Font *fe::Label::sm_defaultFont = 0;

fe::Label::Label()
{
	m_text = new sf::Text();

	if(sm_defaultFont != 0)
	{
		m_text->setFont(*fe::Label::sm_defaultFont);
	}
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

void fe::Label::setText(std::string text)
{
	m_text->setString(text);
}

void fe::Label::setColor(sf::Color color)
{
	m_text->setColor(color);
}

void fe::Label::setSize(unsigned int size)
{
	m_text->setCharacterSize(size);
}

void fe::Label::setFont(const sf::Font &font)
{
	m_text->setFont(font);
}

void fe::Label::setDefaultFont(const sf::Font *font)
{
	sm_defaultFont = font;
}

void fe::Label::onEvent(const sf::Event &event)
{

}

void fe::Label::onDraw(sf::RenderTarget &target,const sf::RenderStates &parent) const
{
	target.draw(*m_text, parent);
}
