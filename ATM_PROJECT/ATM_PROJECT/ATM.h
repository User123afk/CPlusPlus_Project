#ifndef ATM_H
#define ATM_H

#include "Screen.h" // include definition of class Screen
#include "Keypad.h" // include definition of clas Keypad
#include "CashDispenser.h" // include definition of class CashDispenser
#include "BankDatabase.h" // include definition of class BankDataBase
#include "DepositSlot.h"

// foward declaration

class Transaction;

class ATM{
public:
	ATM(); // constructor intializes data member
	void run(); // loop which starts the ATM
private:
	bool userAuthenticated; // whether user is authenticated
	int currentAccountNumber; // current user account's number
	Screen screen; // ATM's screen
	Keypad keypad; // ATM 's keypad
	CashDispenser cashDispenser;
	DepositSlot depositSlot;
	BankDatabase bankDatabase;

	// private utility functions
	void authenticateUser(); // attempts to authenticate user
	void performTransaction(); // performs transactions
	int displayMainMenu() const; // display main menu
	// here we display menu as enum

	//return object of specified Transaction derived class using pointer
	Transaction* createTransaction(int);

};

#endif