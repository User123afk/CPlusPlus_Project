#include "BalanceInquiry.h"
#include "Screen.h"
#include "BankDatabase.h"

BalanceInquiry::BalanceInquiry(int userAccountNumber, Screen& atmScreen,
	BankDatabase& atmBankDatabase) : Transaction(userAccountNumber,
		atmScreen, atmBankDatabase) {

}

// performs transaction
void BalanceInquiry::execute() {
	// get references to bank databse and screen
	BankDatabase& bankDatabase = getBankDatabase();
	Screen& screen = getScreen();

	// get the total balance for the current user's Account
	double availableBalance = bankDatabase.getAvailableBalance
	(getAccountNumber());

	// get the total balance for the current user's Account
	double totalBalance = bankDatabase.getTotalBalance
	(getAccountNumber());

	// display the balance info on the screen
	screen.displayMessageLine("\nBalance Information:");
	screen.displayMessage(" - Available balance: ");
	screen.displayDollarAmount(availableBalance);
	screen.displayMessage(" - Total balance: ");
	screen.displayDollarAmount(totalBalance);
	screen.displayMessageLine("");
}