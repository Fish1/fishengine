#include "Button.h"

#include "Label.h"

#include "ResourceManager.h"

fe::Button::Button() :
	m_shape(sf::Vector2f(100, 25)),
	m_isClicked(false)
{
	m_label = new Label();
	m_label->setColor(sf::Color::Black);
	m_label->setSize(12);

	addChild(m_label);

	m_label->centerX(m_shape.getLocalBounds());
	m_label->centerY(m_shape.getLocalBounds());
}

fe::Button::~Button()
{
	delete m_label;
}

void fe::Button::setFont(const sf::Font &font)
{
	m_label->setFont(font);
}

void fe::Button::setText(std::string text)
{
	m_label->setText(text);
	
	m_label->centerX(m_shape.getLocalBounds());
	m_label->centerY(m_shape.getLocalBounds());
}

void fe::Button::centerX(const sf::Rect<float> &space)
{
	float newX = space.left + (space.width * 0.5f);
	
	newX -= (m_shape.getLocalBounds().width * 0.5f);

	setPosition(newX, getPosition().y);	
}

void fe::Button::centerY(const sf::Rect<float> &space)
{
	float newY = space.top + (space.height * 0.5f);

	newY -= (m_shape.getLocalBounds().height * 0.5f);

	setPosition(getPosition().x, newY);
}

void fe::Button::onEvent(const sf::Event &event)
{
	m_isClicked = false;

	if(event.type == sf::Event::MouseButtonPressed)
	{	
		sf::Rect<float> rect(getPosition(), m_shape.getSize());

		if(event.mouseButton.button == sf::Mouse::Left)
		{
			if(rect.contains(
				event.mouseButton.x,
				event.mouseButton.y))
			{
				m_isClicked = true;
			}
		}
	}

	if(event.type == sf::Event::MouseMoved)
	{
		sf::Rect<float> rect(getPosition(), m_shape.getSize());

		if(rect.contains(event.mouseMove.x, event.mouseMove.y))
		{
			m_shape.setFillColor(sf::Color::Yellow);
		}
		else
		{
			m_shape.setFillColor(sf::Color::White);
		}
	}
}

void fe::Button::onDraw(sf::RenderTarget &target, const sf::RenderStates &parent) const
{
	target.draw(m_shape, parent);
}

bool fe::Button::isClicked()
{
	return m_isClicked;
}
