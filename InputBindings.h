/*
 The InputBindings class manages what console input is needed for each action.
 
 The class instantiates with the default bindings. To check if an input matches
 the binding for an action, use the checkInput method.
 
 To change a binding, use the setBinding method.
*/

#pragma once

enum class BINDINGS
{
	MOVE_UP,
	MOVE_LEFT,
	MOVE_DOWN,
	MOVE_RIGHT,
	COUNT // Do not use
};

class InputBindings
{
public:
	// Sets bindings to default
	InputBindings();
	
	/*
	 Sets which input is needed for a binding.
	 Using BINDINGS::COUNT is invalid.
	*/
	void setBinding(BINDINGS binding, const char* input);
	
	/*
	 Returns true if the input matches the input required for the specified binding.
	 Using BINDINGS::COUNT is invalid.
	*/
	bool checkInput(BINDINGS binding, const char* input) const;
	
private:
	const char* bindings[static_cast<int>(BINDINGS::COUNT)];
	
	void setDefaultBindings();
};
