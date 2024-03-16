#include "Bidding.h"
#include <iostream>

using namespace std;

void BID::disable_bids(int bid_id) {
	if (id <= bid_id) {
		available = false;
	}
}