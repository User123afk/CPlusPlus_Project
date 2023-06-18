#pragma once

class Screen; // forward declaration
class BankDatabase;

class Transaction {
public:
	Transaction(int, Screen&, BankDatabase&);

	virtual ~Transaction() {} // virtual destructor with empty body
	int getAccountNumber() const; // return account number
	Screen& getScreen() const; // return reference to the screen
	BankDatabase& getBankDatabase() const;

	// pure virtual function to perform transaction
	virtual void execute() = 0; // overidden in derived class
private:
	int accountNumber; // indicates account involved
	Screen& screen; // ref to screen of ATM
	BankDatabase& bankDatabase; // ref to account info database
}; // end class