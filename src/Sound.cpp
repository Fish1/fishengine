#include "Sound.h"

#include <SFML/Audio.hpp>

fe::Sound::Sound(sf::SoundBuffer& buffer)
{
	m_sound = new sf::Sound();

	m_sound->setBuffer(buffer);
}

void fe::Sound::play()
{
	m_sound->play();
}
