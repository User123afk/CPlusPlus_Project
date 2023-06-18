#include "Account.h"

// Account constructor initializes attributes
Account::Account(int theAccountNumber, int thePIN, 
	double theAvailableBalance, double theTotalBalance) {
	this->accountNumber = theAccountNumber;
	this->pin = thePIN;
	this->availableBalance = theAvailableBalance;
	this->totalBalance = theTotalBalance;
}

//determines whether a user - specified PIN matches PIN in Account
bool Account::validatePIN(int userPIN) const {
	if (pin == userPIN)
		return true;
	else return false;
} 

// returns available balance
double Account::getAvailableBalance() const {
	return totalBalance;
}
// returns the total balance
double Account::getTotalBalance() const {
	return totalBalance;
} 

// credits an amount to the account
void Account::credit(double amount) {
	totalBalance += amount; // add to total balance
	// we do not count this amount to availableBalance just yet since
	// this amount still needs to be verified by the bank before it can 
	// be used by the user
}

// debits an amount from the account
void Account::debit(double amount) {
	availableBalance -= amount; 
	totalBalance -= amount;
}

// returns account number
int Account::getAccountNumber() const {
	return accountNumber;
}