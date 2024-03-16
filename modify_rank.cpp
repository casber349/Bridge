#include "Bridge.h"
#include <iostream>

using namespace std;

bool POKER::promote_trump(int trump) {
	if (trump == 5) {
		return false;
	}
	if (suit == trump) {
		return true;
	}
	return false;
}

bool POKER::demote_discard(int trump, int suit_in_this_round) {
	if (suit == trump) {
		return false;
	}
	if (suit != suit_in_this_round) {
		return true;
	}
	return false;
}