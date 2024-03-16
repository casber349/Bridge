#include "Bridge.h"
#include "Bidding.h"
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

void BID::print_bids(bool special, int Doubles) {
	if (special) {
		if (available) {
			switch (Doubles) {
				case 1:
					cout << "Double";
					break;
				case 2:
					cout << "Redouble";
					break;
			}
		}
		return;
	}
	else {
		if (available) {
			cout << level;
			switch (trump) {
			case 1:
				cout << "C";
				break;
			case 2:
				cout << "D";
				break;
			case 3:
				cout << "H";
				break;
			case 4:
				cout << "S";
				break;
			case 5:
				cout << "NT";
				break;
			}

			cout << " ";
		}
		else {
			cout << "   ";
		}
	}
}