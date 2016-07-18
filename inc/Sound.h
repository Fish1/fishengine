#ifndef FE_SOUND
#define FE_SOUND

namespace sf
{
	class SoundBuffer;
	
	class Sound;
}

namespace fe 
{
	class Sound
	{
	private:

		sf::Sound *m_sound;
	
	public:

		Sound(sf::SoundBuffer&);

		void play();
	};
}

#endif
