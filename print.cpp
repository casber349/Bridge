#include "Bridge.h"
#include <iostream>

using namespace std;

string POKER::print_player_name() {
	return player;
}

void POKER::print_cards() {
	switch (suit) {
		case club:
			cout << "C";
			break;
		case diamond:
			cout << "D";
			break;
		case heart:
			cout << "H";
			break;
		case spade:
			cout << "S";
			break;
		default:
			break;
	}

	switch (rank) {
		case ace: case trump_ace:
			cout << "A";
			break;
		case king: case trump_king:
			cout << "K";
			break;
		case queen: case trump_queen:
			cout << "Q";
			break;
		case jack: case trump_jack:
			cout << "J";
			break;
		case 10: case 9: case 8: case 7: case 6: case 5: case 4: case 3: case 2:
			cout << (rank % 13);
			break;
		default:
			return;
	}

	cout << " ";
}