#pragma once

class CashDispenser {
public:
	CashDispenser(); // constructor initializes bill count to 500

	// simulates the dispensing of specified amount of cash
	void dispenseCash(int);

	// indicates whether cash dispenser can dispense desired amount
	bool isSufficientCashAvailable(int) const;
private:
	static const int INITIAL_COUNT = 500;
	int count; // number of $20 bills remaining
}; // end class 