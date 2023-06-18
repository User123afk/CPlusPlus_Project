

#include "CashDispenser.h"

CashDispenser::CashDispenser()
{
	count = INITIAL_COUNT; // set count attribute to default
}

// simulates dispensing of specified amount of cash
// assumes there is enough cash in the ATM
void CashDispenser::dispenseCash(int amount) {
	int billsRequired = amount / 20; // number of $20 bills required
	count -= billsRequired; // update the count of bills
}// end function dispenseCash

// indicates whether cash dispenser can dispense desired amount
bool CashDispenser::isSufficientCashAvailable(int amount) const {
	int billsRequired = amount / 20; // number of $20 bills required

	if (count >= billsRequired)
		return true;
	else return false;
}