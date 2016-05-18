#ifndef BUTTON 
#define BUTTON

#include "Interface.h"

namespace fe
{
	class Label;

	class Button : public Interface
	{
	private:

		mutable sf::RectangleShape m_shape;

		Label *m_label;

		bool m_isClicked;

	public:

		Button();

		~Button();

		void setText(std::string text);

		void centerX(const sf::Rect<float> &space);

		void centerY(const sf::Rect<float> &space);

		void onEvent(const sf::Event &event);

		void onDraw(sf::RenderTarget &target, const sf::RenderStates &states) const;	

		bool isClicked();
	};
}

#endif
