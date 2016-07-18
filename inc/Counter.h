#ifndef FE_COUNTER
#define FE_COUNTER

#include "Label.h"

namespace fe
{
	class Counter : public Label
	{
	private:
		
		int m_count;
		
	public:

		Counter();

		void addCount(int value);	

		void setCount(int value);
		
		virtual void onDraw(sf::RenderTarget &target, const sf::RenderStates &states) const;
	};
}

#endif
