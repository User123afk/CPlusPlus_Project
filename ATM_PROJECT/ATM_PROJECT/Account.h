#pragma once

class Account {
public:
	Account(int, int, double, double); // constructor 
	bool validatePIN(int) const; // is user - specified PIN correct ?
	double getAvailableBalance()const; // returns available balance
	double getTotalBalance() const; // return total balance
	void credit(double); // adds an amount to the Account balance
	void debit(double); // subtracts an amount from the account balance
	int getAccountNumber() const;
private:
	int accountNumber; // account number
	int pin; // PIN for authentication
	double availableBalance; // funds available for withdrawal
	double totalBalance; // funds available + funds waiting to clear
}; // end class Account

