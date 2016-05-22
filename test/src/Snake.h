#ifndef SNAKE
#define SNAKE

namespace sf
{
	class RenderWindow;
}

enum DIRECTION
{
	UP, DOWN, LEFT, RIGHT
};

class Snake
{
private:

class Node
{
public:
	int x;
	int y;

	Node() :
		next(0)
	{

	}

	Node *next;
};

private:

	Node *head;
	
	DIRECTION direction;

	DIRECTION deltaDirection;

	bool m_dead;

private:

	bool nodeAtCoord(int x, int y);

	void move();

	Node* getEndNode();

	void moveFood();

public:

	Snake();

	~Snake();
	
	void draw(sf::RenderWindow &window);

	void update(float delta);

	bool setDirection(DIRECTION set);

	void expand();

	int size();

	bool isDead();
};

#endif
