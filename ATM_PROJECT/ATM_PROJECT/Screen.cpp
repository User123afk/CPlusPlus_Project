#pragma once
#include <iostream>
#include "Screen.h"
#include <iomanip>

using namespace std;

// output message without a line
void Screen::displayMessage(string message) const {
	cout << message;
}

// output message with a new line
void Screen::displayMessageLine(string message) const {
	cout << message << endl;
}

// output dollar amount
void Screen::displayDollarAmount(double amount) const {
	cout << fixed << setprecision(2) << "$" << amount;
}

