#include "ResourceManager.h"

#include <SFML/Graphics.hpp>

#include <iostream>

fe::ResourceManager::ResourceManager()
{
	m_resources = new std::map<std::string, std::shared_ptr<void>>; 
}

fe::ResourceManager::~ResourceManager()
{
	delete m_resources;
}

std::shared_ptr<void> fe::ResourceManager::get(std::string key)
{
	return m_resources->at(key);
}

void fe::ResourceManager::put(std::string key, std::shared_ptr<void> object)
{
	m_resources->emplace(key, object);
}

void fe::ResourceManager::loadFont(std::string key, std::string fileName)
{
	std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();

	font->loadFromFile(fileName);

	put(key, font);
}

sf::Font& fe::ResourceManager::getFont(std::string key)
{
	return *std::static_pointer_cast<sf::Font>(get(key));
}

void fe::ResourceManager::free(std::string key)
{

}

void fe::ResourceManager::freeAll()
{
	/*
	std::map<std::string, void*>::iterator it = m_resources->begin();

	while(it != m_resources->end())
	{
		#ifdef DEBUG	
			std::cout << "Resource Manager: delete " + it->first << std::endl;
		#endif

		delete it->second;

		++it;
	}

	m_resources->clear();
	*/
}
