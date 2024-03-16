#include "Bidding.h"
#include <iostream>

using namespace std;

int bid_to_level(string player_bid) {
	char level_to_convert = player_bid[0];

	switch (level_to_convert) {
		case '1': case '2': case '3': case '4': case '5': case '6': case '7':
			return (level_to_convert - 48);
	}
}

int bid_to_trump(string player_bid) {
	char trump_to_convert = player_bid[1];

	switch (trump_to_convert) {
		case 'C':
			return 1;
		case 'D':
			return 2;
		case 'H':
			return 3;
		case 'S':
			return 4;
		case 'N':	//1'N'T, 2'N'T, ...
			return 5;
	}
}

int bid_to_id(string player_bid) {
	if (player_bid == "N/A") {
		return 0;
	}
	return ((bid_to_level(player_bid) - 1) * 5 + bid_to_trump(player_bid));
}