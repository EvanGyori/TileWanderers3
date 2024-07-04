#include "InputBindings.h"

#include <cstring>
#include <cassert>

InputBindings::InputBindings()
{
	setDefaultBindings();
}

void InputBindings::setBinding(BINDINGS binding, const char* input)
{
	assert(binding != BINDINGS::COUNT);
	bindings[static_cast<int>(binding)] = input;
}

bool InputBindings::checkInput(BINDINGS binding, const char* input) const
{
	assert(binding != BINDINGS::COUNT);
	return strcmp(bindings[static_cast<int>(binding)], input) == 0;
}

void InputBindings::setDefaultBindings()
{
	setBinding(BINDINGS::MOVE_UP, "w");
	setBinding(BINDINGS::MOVE_LEFT, "a");
	setBinding(BINDINGS::MOVE_DOWN, "s");
	setBinding(BINDINGS::MOVE_RIGHT, "d");
	
	setBinding(BINDINGS::OPEN_INVENTORY, "q");
	setBinding(BINDINGS::EXIT_INVENTORY, "q");
	setBinding(BINDINGS::ATTACK, "e");
	setBinding(BINDINGS::RETREAT, "r");
}
