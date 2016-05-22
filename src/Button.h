#ifndef FE_BUTTON 
#define FE_BUTTON

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

		void setFont(const sf::Font &font);

		void setText(std::string text);

		void centerX(const sf::Rect<float> &space);

		void centerY(const sf::Rect<float> &space);

		void onEvent(const sf::Event &event);

		void onDraw(sf::RenderTarget &target, const sf::RenderStates &states) const;	
	
		bool isClicked();
	};
}

#endif
