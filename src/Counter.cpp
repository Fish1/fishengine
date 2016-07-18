#include "Counter.h"

#include <string>

fe::Counter::Counter() :
	m_count(0)
{

}

void fe::Counter::addCount(int value)
{
	m_count += value;
	
	fe::Label::setText(std::to_string(m_count));
}

void fe::Counter::setCount(int value)
{
	m_count = value;

	fe::Label::setText(std::to_string(m_count));
}

void fe::Counter::onDraw(sf::RenderTarget &target, const sf::RenderStates &states) const
{
	fe::Label::onDraw(target, states);
}
