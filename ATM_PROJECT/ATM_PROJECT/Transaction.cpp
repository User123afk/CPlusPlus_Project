#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"

Transaction::Transaction(int userAccountNumber, Screen& atmScreen,
	BankDatabase& atmBankDatabase)
	: accountNumber(userAccountNumber), 
	screen(atmScreen), bankDatabase(atmBankDatabase)
{
 // reference member have to be intitialized on creation
}

// return account number

int Transaction::getAccountNumber() const {
	return accountNumber;
}

// return a ref to the screen
Screen& Transaction::getScreen() const {
	return screen;
}

// return reference to bank database
BankDatabase& Transaction::getBankDatabase() const
{
	return bankDatabase;
}


