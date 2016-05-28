#include "EmptyState.h"

#include "Core.h"

#include "Button.h"
#include "Label.h"

#include <iostream>

fe::EmptyState::EmptyState()
{

}

void fe::EmptyState::enter(fe::Core &core)
{
	std::cout << "Enter Empty State" << std::endl;

	core.getWindow().clear();

	core.getWindow().display();
}

void fe::EmptyState::reactEvent(fe::Core &core)
{

}

void fe::EmptyState::execute(fe::Core &core)
{

}

void fe::EmptyState::exit(fe::Core &core)
{
	std::cout << "Exit Empty State" << std::endl;
}
