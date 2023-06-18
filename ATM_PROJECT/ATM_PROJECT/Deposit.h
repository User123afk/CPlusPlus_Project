#pragma once
#include "Transaction.h"

// forward declaration
class Keypad;
class DepositSlot;

class Deposit : public Transaction {
public:
	Deposit(int, Screen&, BankDatabase&, Keypad&, DepositSlot&);
	virtual void execute();
private:
	double amount; // amount to deposit
	Keypad& keypad; // reference to ATM's keypad
	DepositSlot& depositSlot; // reference to ATM's deposit slot
	double promptForDepositAmount() const; // get deposit amount from user
}; // end class