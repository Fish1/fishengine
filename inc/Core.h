#ifndef FE_CORE
#define FE_CORE

#include <SFML/Graphics.hpp>

#include "StateMachine.h"

namespace fe
{
	class Core
	{
		private:

			sf::RenderWindow m_window;

			sf::Clock m_clock;

			sf::Event m_event;

			bool m_running;

			float m_delta;

			StateMachine *m_stateMachine;

		public:

			Core(int width, int height);

			~Core();

			void setWindowTitle(std::string title);

			void go();

			void stop();

			float getDelta() const;

			const sf::Event& getEvent() const;

			StateMachine& getStateMachine();

			sf::RenderWindow& getWindow();

			sf::Rect<float> getWindowRectangle() const;
	};
}

#endif
