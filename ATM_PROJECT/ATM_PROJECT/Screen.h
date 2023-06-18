#pragma once
#include <string>

using namespace std;

class Screen {
public:
	void displayMessage(string) const; // output a message
	void displayMessageLine(string) const; // output message with new line
	void displayDollarAmount(double) const;

}; // end class Screen