#ifndef INTERFACE
#define INTERFACE

#include <SFML/Graphics.hpp>

#include <list>

namespace fe
{
	class Interface : public sf::Drawable, public sf::Transformable
	{
	private:

		sf::Vector2f m_position;

		std::list<Interface*> m_children;

	public:

		virtual void onEvent(const sf::Event &event) = 0;

		virtual void onDraw(sf::RenderTarget &target, const sf::RenderStates &parent) const = 0;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
		void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

		void addChild(Interface *newChild);
	};
}

#endif
