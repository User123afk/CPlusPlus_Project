#pragma once

#include <vector>
#include "Account.h"

using namespace std;

class BankDatabase {
public:
	BankDatabase(); 

	//determing whether account number and PIN match those of an Account
	bool authenticateUser(int, int);

	double getAvailableBalance(int); // get an available balance
	double getTotalBalance(int); // get an Account's total balance
	void credit(int, double); // add amount to Account balance
	void debit(int, double); // subtract amount from Account balance
private:
	vector<Account> accounts; // vector of the bank's Accounts to store
	// accounts
	
	// private utilitu function
	Account* getAccount(int); // get pointer to Account object
}; // end class
