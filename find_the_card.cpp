#include "Bridge.h"
#include <iostream>

using namespace std;

bool POKER::find_the_card(string card_to_play) {
	if ((suit == card_to_suit(card_to_play)) && (rank == card_to_rank(card_to_play))) {
		return true;
	}
	return false;
}