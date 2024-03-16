#include "Bridge.h"
#include "Bidding.h"
#include <iostream>

using namespace std;

void POKER::card_initialize(int player_index, int card_id) {
	switch(player_index) {
		case 0:
			player = "South";
			break;
		case 1:
			player = "West";
			break;
		case 2:
			player = "North";
			break;
		case 3:
			player = "East";
			break;
	}

	suit = (card_id / 13 + 1);	//range: 1~4 (C, D, H, S)
	rank = (card_id % 13 + 2);	//range: 2~14 (2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A)
}

void BID::bidding_initialize(int level_temp, int trump_temp, bool special) {
	if (special) {
		available = false;
	}
	else {
		level = level_temp;
		trump = trump_temp;
		id = (level_temp - 1) * 5 + trump_temp;
		available = true;
	}
}