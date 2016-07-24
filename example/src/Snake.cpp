#include "Snake.h"

#include <ResourceManager.h>

#include <SFML/Graphics.hpp>

#include <iostream>

Snake::Snake() :
	m_sound(fe::ResourceManager::instance().getSoundBuffer("Score")), 
	head(0), direction(DOWN), deltaDirection(DOWN), m_dead(false), m_score(0)
{
	head = new Node();
	head->x = 3;
	head->y = 3;

	head->next = new Node();
	head->next->x = 5;
	head->next->y = 5;

	for(int index = 0; index < 2; ++index)
		expand();
}

Snake::~Snake()
{
	Node *ptr = head;

	while(ptr != 0)
	{
		Node *next = ptr->next;
		
		delete ptr;
		
		ptr = next;
	}
}

bool Snake::nodeAtCoord(int x, int y)
{
	Node *ptr = head;

	while(ptr != 0)
	{
		if(ptr->x == x && ptr->y == y)
		{
			return true;
		}

		ptr = ptr->next;
	}

	return false;
}

void Snake::move()
{
	Node *ptr = head->next;

	while(ptr->next != 0)
	{
		ptr->x = ptr->next->x;
		ptr->y = ptr->next->y;

		ptr = ptr->next;	
	}

	int newX = ptr->x;
	int newY = ptr->y;

	direction = deltaDirection;

	switch(direction)
	{
		case UP:
			newY = ptr->y - 1;
		break;
		case DOWN:
			newY = ptr->y + 1;	
		break; 
		case LEFT:
			newX = ptr->x - 1;	
		break;
		case RIGHT:
			newX = ptr->x + 1;
		break;	
	}
	
	if(head->x == newX && head->y == newY)
	{
		expand();
		
		moveFood();

		++m_score;

		m_sound.play();
	}
	else if(nodeAtCoord(newX, newY))
	{
		m_dead = true;
	}

	ptr->x = newX;
	ptr->y = newY;
}

void Snake::moveFood()
{
	int x;
	int y;

	do
	{
		x = rand() % 25;
		y = rand() % 25;
	}
	while(nodeAtCoord(x, y));

	head->x = x;
	head->y = y;
}

Snake::Node* Snake::getEndNode()
{
	Node *result = head;

	while(result->next != 0)
	{
		result = result->next;
	}

	return result;
}

void Snake::draw(sf::RenderWindow &window)
{
	Node *ptr = head;

	sf::RectangleShape rect;

	rect.setSize(sf::Vector2f(10, 10));

	rect.setFillColor(sf::Color::Yellow);

	rect.setPosition(ptr->x * 10 + 2 * ptr->x, ptr->y * 10 + 2 * ptr->y);

	window.draw(rect);

	rect.setFillColor(sf::Color::White);
	
	ptr = ptr->next;

	while(ptr != 0)
	{
		rect.setPosition(ptr->x * 10 + 2 * ptr->x, ptr->y * 10 + 2 * ptr->y);
	
		window.draw(rect);	
		
		ptr = ptr->next;
	}
}

void Snake::update(float delta)
{
	move();
}

bool Snake::setDirection(DIRECTION set)
{
	Node *end = getEndNode();

	if(set == UP && direction == DOWN)
	{
		return false;
	}

	if(set == DOWN && direction == UP)
	{
		return false;
	}

	if(set == LEFT && direction == RIGHT)
	{
		return false;
	}

	if(set == RIGHT && direction == LEFT)
	{
		return false;
	}

	deltaDirection = set;
	
	return true;

}

void Snake::expand()
{
	Node *tmp = new Node();

	tmp->next = head->next;
	head->next = tmp;
	tmp->x = tmp->next->x;
	tmp->y = tmp->next->y;	
}

int Snake::positionX()
{
	Node *node = getEndNode();

	return node->x;
}

int Snake::positionY()
{
	Node *node = getEndNode();

	return node->y;
}

int Snake::size()
{
	int result = 0;
	
	Node *ptr = head;

	while(ptr != 0)
	{
		ptr = ptr->next;
		
		++result;
	}

	return result;
}

int Snake::score()
{
	return m_score;
}

bool Snake::isDead()
{
	return m_dead;
}
