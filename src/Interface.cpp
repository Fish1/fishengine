#include "Interface.h"

void fe::Interface::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform = states.transform * getTransform();

	onDraw(target, states);

	drawChildren(target, states);
}

void fe::Interface::drawChildren(sf::RenderTarget &target, const sf::RenderStates states) const
{
	auto iter = m_children.begin();

	while(iter != m_children.end())
	{
		(*iter)->draw(target, states);
	
		++iter;
	}
}

void fe::Interface::addChild(Interface *newChild)
{
	m_children.push_back(newChild);
}
