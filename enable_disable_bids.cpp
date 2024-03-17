#include "Bidding.h"
#include <iostream>

using namespace std;

void BID::disable_bids(int bid_id) {
	if (id <= bid_id) {
		available = false;
	}
}

void BID::enable_doubles(bool can_you_double) {
	if (can_you_double) {
		available = true;
	}
}

void BID::disable_doubles() {
	available = false;
}