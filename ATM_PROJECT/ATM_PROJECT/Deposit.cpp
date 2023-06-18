#include "Deposit.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "DepositSlot.h"

static const int CANCELED = 0; // constant representing cancel option

Deposit::Deposit(int userAccountNumber, Screen& atmScreen,
	BankDatabase& atmBankDatabase, Keypad& atmKeypad,
	DepositSlot& atmDepositSlot)
	:Transaction(userAccountNumber, atmScreen, atmBankDatabase),
	keypad(atmKeypad), depositSlot(atmDepositSlot) {

}

void Deposit::execute()
{
	BankDatabase& bankDatabase = getBankDatabase(); // get ref
	Screen& screen = getScreen(); 

	amount = promptForDepositAmount(); 

	// check whether user entered a deposit amount or canceled
	if (amount != CANCELED)
	{
		// request deposit envelope containing specified amount
		screen.displayMessage
		("\nPlease insert a deposit envelope containing ");
		screen.displayDollarAmount(amount);
		screen.displayMessageLine(" in the deposit slot.");

		// receive deposit envelope
		bool envelopeReceived = depositSlot.isEnvelopeReceived();

		// check whether deposit envelope was received
		if (envelopeReceived)
		{
			screen.displayMessageLine
			("\nYour envelope has been received."
			"\nNote: The money deposited will not be available till "
			"\nwe verify the amount of cash.");
			
			// credit account to reflect the deposit
			bankDatabase.credit(getAccountNumber(), amount);
		} // end if
		else // deposit envelope not received
		{
			screen.displayMessageLine
			("\nEnvelope not received. Transaction is canceled");
		} // end else
	} // end if
	else // user canceled instead of entering amount
	{
		screen.displayMessageLine("\nCanceling transaction...");
	} // end else
} // end function

// prompt user to enter a deposit amount in cents

double Deposit::promptForDepositAmount() const
{
	Screen& screen = getScreen(); // get ref to screen

	// dislay the prompt and receive input
	screen.displayMessage
	("\nPlease enter a deposit amount in CENTS (or 0 to cancel): ");

	int input = keypad.getInput(); // receive input of deposit amount

	// check whether the user canceled or entered a valid amount
	if (input == CANCELED)
		return CANCELED;
	else 
		return static_cast<double>(input) / 100; // return dollar amount
} 
