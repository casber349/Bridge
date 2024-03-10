#include "Bridge.h"
#include <iostream>

using namespace std;

//these functions are global functions

int card_to_suit(string card_to_play) {
	char suit_to_convert = card_to_play[0];
		
	switch (suit_to_convert) {
		case 'C':
			return 1;
		case 'D':
			return 2;
		case 'H':
			return 3;
		case 'S':
			return 4;
	}

}

int card_to_rank(string card_to_play) {
	char rank_to_convert = card_to_play[1];
	switch (rank_to_convert) {
		case 'A':
			return 14;
		case 'K':
			return 13;
		case 'Q':
			return 12;
		case 'J':
			return 11;
		case '1':	//for tens: (S'1'0, H'1'0, D'1'0, C'1'0)
			return 10;
		default:
			return (rank_to_convert - 48);
	}
}