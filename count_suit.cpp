#include "Bridge.h"
#include <iostream>

using namespace std;

bool POKER::count_club() {
	if (suit == club) {
		return true;
	}
	return false;
}

bool POKER::count_diamond() {
	if (suit == diamond) {
		return true;
	}
	return false;
}

bool POKER::count_heart() {
	if (suit == heart) {
		return true;
	}
	return false;
}

bool POKER::count_spade() {
	if (suit == spade) {
		return true;
	}
	return false;
}