#include <iostream>
#include "Keypad.h"

//return an integer value entered by user
int Keypad::getInput() const {
	int input; // variable to store the input
	std::cin >> input;
	return input; // return the value entered by user
}