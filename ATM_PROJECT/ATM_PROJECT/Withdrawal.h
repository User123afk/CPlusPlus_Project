#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "Transaction.h"

// forward declaration of class
class Keypad;
class CashDispenser;

class Withdrawal:public Transaction {
public:
	Withdrawal(int, Screen&, BankDatabase&, Keypad&, CashDispenser&);
	// member function overidding virtual function execute in base class
	// Transaction
	virtual void execute();
private:
	int amount; // amount to withdraw
	Keypad& keypad; // reference to ATM's keyboard
	CashDispenser& cashDispenser; // ref to ATM's cash dispenser
	int displayMenuOfAmounts() const; // display the withdrawal menu

}; // end class

#endif