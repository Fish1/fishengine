#ifndef LABEL 
#define LABEL

#include "Interface.h"

#include <string>

namespace fe
{
	class Label : public Interface
	{
	private:

		sf::Text *m_text;

	public:

		Label();

		~Label();

		void centerX(const sf::Rect<float> &space);

		void centerY(const sf::Rect<float> &space);

		void setTextString(std::string text);

		void setTextColor(sf::Color color);

		void setTextSize(unsigned int size);

		void onEvent(const sf::Event &event);
		
		void onDraw(sf::RenderTarget &target, const sf::RenderStates &states) const;	
	};
}

#endif
