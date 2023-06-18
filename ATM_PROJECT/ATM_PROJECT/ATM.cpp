#include "ATM.h" 
#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "Deposit.h"

// enumeration constants represent main menu options
enum MenuOption {BALANCE_INQUIRY = 1, WITHDRAWAL, DEPOSIT, EXIT};

// ATM constructor initializes data members
ATM::ATM()
	: userAuthenticated(false), // user is not authenticated to start
	currentAccountNumber(0) // no current account number to start
{
	// empty body => default constructor
}

// start the ATM by a loop
void ATM::run() {
	// displays welcome message and authenticate user
	// performs transactions;
	while (true)
	{
		// loop while user is not yet authenticated
		while (!userAuthenticated)
		{
			screen.displayMessageLine("\nWelcome!");
			authenticateUser();
		} // end while

		performTransaction(); // user is now authenticated
		userAuthenticated = false; // reset before next session
		currentAccountNumber = 0; // reset before next session
		screen.displayMessageLine("\nThank you and goodbye!");
	} // end while
} // end run

// attempts to authenticate user against database
void ATM::authenticateUser() {
	screen.displayMessage("\nPlease enter your account number: ");
	int accountNumber = keypad.getInput(); // input account number
	// prompt for PIN if account number exists
	screen.displayMessage("\nEnter your PIN: "); 
	int pin = keypad.getInput(); // input PIN

	// set userAuthenticated to bool value returned by database
	userAuthenticated = bankDatabase.authenticateUser(accountNumber, pin);

	// check whether authentication suceeded
	if (userAuthenticated)
	{
		currentAccountNumber = accountNumber; // save user's account
	}
	else screen.displayMessageLine
	("Invalid account number or PIN. Please try again.");

}// end function authenticate

// display the menu and perform transactions
void ATM::performTransaction() {
	// local pointer to store transcation currently being processed
	Transaction* currentTransactionPtr;

	bool userExited = false; // user has not chosen to exit

	// loop while user has not chosen option exit system
	while (!userExited)
	{
		//show main menu and get user selection
		int mainMenuSelection = displayMainMenu();

		//decide how to proceed based on user's menu selection
		switch (mainMenuSelection)
		{
			// user chose to perform one of the three transaction types
		case BALANCE_INQUIRY:
		case WITHDRAWAL:
		case DEPOSIT:
			// inititialize as new object of the chosen type
			currentTransactionPtr = createTransaction(mainMenuSelection);
			currentTransactionPtr->execute();

			//free the space for the dynamically allocated Transaction
			delete currentTransactionPtr;
			break;
		case EXIT:
			screen.displayMessageLine("\nExiting the system...");
			userExited = true; // this ATM session should end
			break;
		default: // user did not enter an integer from 1 - 4
			screen.displayMessageLine
			("\nYou did not enter a valid selection. Pls try again.");
			break;
		} // end switch
	} // end while
} // end function performTransactions

// display the main menu and return an input selection
int ATM::displayMainMenu() const {
	screen.displayMessageLine("\nMain menu:");
	screen.displayMessageLine("1 - View my balance:");
	screen.displayMessageLine("2 - Withdraw cash:");
	screen.displayMessageLine("3 - Deposit funds:");
	screen.displayMessageLine("4 - Exit\n");
	screen.displayMessageLine("Please enter a choice:");
	return keypad.getInput(); // return user selection
} // end function displayMainMenu

//return object of specified Transaction derived class
Transaction* ATM::createTransaction(int type) {
	Transaction* tempPtr = nullptr; // temporary Transaction pointer

	// determine which tyep of Transaction to create
	switch (type)
	{
	case BALANCE_INQUIRY: // create a new Balance Inquiry transaction
		tempPtr = new BalanceInquiry(currentAccountNumber, screen, bankDatabase);
		break;
	case WITHDRAWAL: // create new Withdrawal transaction
		tempPtr = new Withdrawal(currentAccountNumber, screen, bankDatabase,
				keypad, cashDispenser);
		break;
	case DEPOSIT: // create a new Deposit transaction
		tempPtr = new Deposit(currentAccountNumber, screen, bankDatabase,
			keypad, depositSlot);
		break;
	} // end switch

	return tempPtr;
} // end function createTransaction

