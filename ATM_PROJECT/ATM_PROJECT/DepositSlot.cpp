#include "DepositSlot.h"

// indicates whether envelope was received (always return true because
// this is only a software simulation

bool DepositSlot::isEnvelopeReceived() const {
	return true; // deposit envelope was received
}

