#ifndef FE_LABEL 
#define FE_LABEL

#include "Interface.h"

#include <string>

namespace sf
{
	class Font;
}

namespace fe
{
	class Label : public Interface
	{
	private:

		static const sf::Font *sm_defaultFont;

		sf::Text *m_text;

	public:

		Label();

		~Label();

		void centerX(const sf::Rect<float> &space);

		void centerY(const sf::Rect<float> &space);

		void setText(std::string text);

		void setColor(sf::Color color);

		void setSize(unsigned int size);

		void setFont(const sf::Font &font);

		static void setDefaultFont(const sf::Font *font);

		void onEvent(const sf::Event &event);
		
		void onDraw(sf::RenderTarget &target, const sf::RenderStates &states) const;		};
}

#endif
