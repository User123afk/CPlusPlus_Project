#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "CashDispenser.h"
#include "Withdrawal.h"

// global constant that corresponds to menu option to cancel
static const int CANCELED = 6;

Withdrawal::Withdrawal(int userAccountNumber, Screen& atmScreen,
	BankDatabase& atmBankDatabase, Keypad& atmKeyPad,
	CashDispenser& atmCashDispenser)
	:Transaction(userAccountNumber, atmScreen, atmBankDatabase),
	keypad(atmKeyPad), cashDispenser(atmCashDispenser) {

}

//perform Transaction, overrides Transaction's pure virtual function
void Withdrawal::execute() {
	bool cashDispensed = false; // cash was not dispensed yet
	bool transactionCanceled = false; // transaction was not canceled yet

	//get references to bank database and screen
	BankDatabase& bankDatabase = getBankDatabase();
	Screen& screen = getScreen();

	// loop until cash is dispensed or the user cancels the withdrawal
	do
	{
		// obtain the chosen withdrawal amount from the user
		int selection = displayMenuOfAmounts();

		// check whether the user chose a withdrawal amount or canceled
		if (selection != CANCELED)
		{
			amount = selection; // set amnount to the selected dollar amount

			// get available balance of account involved
			double availableBalance =
				bankDatabase.getAvailableBalance(getAccountNumber());

			// check if the user has enough money in the account
			if (amount <= availableBalance)
			{
				// check whether the cash dispenser has enough money
				if (cashDispenser.isSufficientCashAvailable(amount))
				{
					// update the account involved to reflect withdrawal
					bankDatabase.debit(getAccountNumber(), amount);

					cashDispenser.dispenseCash(amount); // dispense cash

					cashDispensed = true; // cash was dispensed

					// instruct user to take cash
					screen.displayMessageLine
					("\nPlease take cash from the ATM.");
				} // end if
				else // cash dispenser does not have enough cash
					screen.displayMessageLine
					("\nInsufficient cash in ATM. Please choose a smaller amount");

			} // end if
			else // user does not have enough money
				screen.displayMessageLine
				("\nInsufficient funds in  account. Please choose a smaller amount");

		} // end if
		else // user choose cancel option
		{
			screen.displayMessageLine("\nCanceling transaction...");
			transactionCanceled = true; // user cancel transaction
		} // end else
	} while (!cashDispensed && !transactionCanceled); // end do while
} // end function

// display a menu of withdrawal amounts and options to cancel
// return chosen amount or 0 if user cancel
int Withdrawal::displayMenuOfAmounts() const
{
	int userChoice = 0; // local variable to store return value

	Screen& screen = getScreen(); // get screen ref

	// arry of amounts to correspond to menu numbers
	int amounts[] = { 0, 20, 40, 60, 100, 200 };

	// loop while no valid choice has been made
	while (userChoice == 0)
	{
		//display the menu
		screen.displayMessageLine("\nWithdrawal options: ");
		screen.displayMessageLine("1 - $20");
		screen.displayMessageLine("2 - $40");
		screen.displayMessageLine("3 - $60");
		screen.displayMessageLine("4 - $100");
		screen.displayMessageLine("5 - $200");
		screen.displayMessageLine("6 - Cancel transaction");
		screen.displayMessage("\nChoose a withdrawal option (1 - 6): ");

		int input = keypad.getInput(); // get user input through keypad

		// determine how to proceed based on the input value
		switch (input)
		{
		case 1: // if user chose a withdrawal amount (1 - 5), return
		case 2: // the corresponding amount from amounts array
		case 3:
		case 4:
		case 5:
			userChoice = amounts[input]; // save user's choice
			break;
		case CANCELED: // user chose to cancel
			userChoice = CANCELED;// save user's choice
			break;
		default: // the user did not enter a value from 1 - 6
			screen.displayMessageLine
			("\nInvalid selection. Try again.");

		} // end switch
	} // end while

	return userChoice; // return withdrawal amount or CANCELED
} // end function
