#include "Bridge.h"
#include <iostream>

using namespace std;

int main() {
	//initializing
	POKER cards[4][13];		//1st dimension: player name, 2nd dimension: cards no. for each players

	srand(time(NULL));		//shuffling
	int available_id[52];
	for (int i = 0; i < 52; i++) {
		available_id[i] = i;
	}
	for (int player_idx = 0; player_idx < 4; player_idx++) {
		for (int cards_idx = 0; cards_idx < 13; cards_idx++) {
			int r = rand() % 52;
			while (available_id[r] < 0) {	//avoid repeat cards
				r = rand() % 52;
			}
			cards[player_idx][cards_idx].card_initialize(player_idx, r);
			available_id[r] = -1;
		}
	}

	//sorting-1
	for (int player_idx = 0; player_idx < 4; player_idx++) {
		for (int cards_idx = 0; cards_idx < 13; cards_idx++) {
			cards[player_idx][cards_idx].set_id();
		}
	}

	for (int player_idx = 0; player_idx < 4; player_idx++) {
		for (int j = 0; j < (13 - 1); j++) {
			for (int cards_idx = 0; cards_idx < (13 - 1 - j); cards_idx++) {
				cards[player_idx][cards_idx].swap();
			}
		}
	}

	//game start
	int trump;
	cout << "Which suit do you want to choose to be trump?";
	cout << "(1: Club, 2: Diamond, 3:Heart, 4:Spade, 5:No trump)" << endl;
	cin >> trump;

	string lead_player;
	cout << "Which player lead in first round?";
	cout << "(S:south, N:north, E:east, W:west)" << endl;
	cin >> lead_player;

	int NS_trick = 0, EW_trick = 0;

	int round = 1;
	for (round; round <= 13; round++) {
		//counting cards
		int player_suit_table[4][4] = { {0} };	// S{c, d, h, s}, W{c, d, h, s}, N{c, d, h, s}, E{c, d, h, s}
		for (int player_idx = 0; player_idx < 4; player_idx++) {
			for (int cards_idx = 0; cards_idx < 13; cards_idx++) {
				if (cards[player_idx][cards_idx].count_club()) {
					player_suit_table[player_idx][0]++;
				}
				if (cards[player_idx][cards_idx].count_diamond()) {
					player_suit_table[player_idx][1]++;
				}
				if (cards[player_idx][cards_idx].count_heart()) {
					player_suit_table[player_idx][2]++;
				}
				if (cards[player_idx][cards_idx].count_spade()) {
					player_suit_table[player_idx][3]++;
				}

			}
		}
		int south_rank = 0, north_rank = 0, east_rank = 0, west_rank = 0;
		cout << "NS_trick:" << NS_trick << endl;
		cout << "EW_trick:" << EW_trick << endl;
		cout << endl;

		for (int player_idx = who_play_first(lead_player); player_idx < (who_play_first(lead_player) + 4); player_idx++) {
			cout << cards[player_idx % 4][0].print_player_name() << ":" << endl;
			for (int cards_idx = 0; cards_idx < 13; cards_idx++) {
				cards[player_idx % 4][cards_idx].print_cards();
			}
			cout << endl;

			string card_to_play;
			cout << "Enter the card to play:";
			cin >> card_to_play;
			cout << endl;

			static int suit_in_this_round = 0;
			if (player_idx == who_play_first(lead_player)) {
				suit_in_this_round = card_to_suit(card_to_play);
			}

			while (!((card_to_suit(card_to_play) == suit_in_this_round) || !(player_suit_table[player_idx % 4][suit_in_this_round - 1]))) {
				cout << "You must follow suit if possible!" << endl;
				cout << "Enter the card to play:";
				cin >> card_to_play;
				cout << endl;
			}

			switch (player_idx % 4) {
			case 0:
				for (int card_id = 0; card_id < 13; card_id++) {
					if (cards[0][card_id].find_the_card(card_to_play)) {
						south_rank = card_to_rank(card_to_play);
						if (cards[0][card_id].promote_trump(trump)) {
							south_rank += 13;
						};
						if (cards[0][card_id].demote_discard(trump, suit_in_this_round)) {
							south_rank = 1;
						}
						cards[0][card_id].remove_card();
						cards[0][card_id].set_id();
					}
				}
				break;
			case 1:
				for (int card_id = 0; card_id < 13; card_id++) {
					if (cards[1][card_id].find_the_card(card_to_play)) {
						west_rank = card_to_rank(card_to_play);
						if (cards[1][card_id].promote_trump(trump)) {
							west_rank += 13;
						};
						if (cards[1][card_id].demote_discard(trump, suit_in_this_round)) {
							west_rank = 1;
						}
						cards[1][card_id].remove_card();
						cards[1][card_id].set_id();
					}
				}
				break;
			case 2:
				for (int card_id = 0; card_id < 13; card_id++) {
					if (cards[2][card_id].find_the_card(card_to_play)) {
						north_rank = card_to_rank(card_to_play);
						if (cards[2][card_id].promote_trump(trump)) {
							north_rank += 13;
						};
						if (cards[2][card_id].demote_discard(trump, suit_in_this_round)) {
							north_rank = 1;
						}
						cards[2][card_id].remove_card();
						cards[2][card_id].set_id();
					}
				}
				break;
			case 3:
				for (int card_id = 0; card_id < 13; card_id++) {
					if (cards[3][card_id].find_the_card(card_to_play)) {
						east_rank = card_to_rank(card_to_play);
						if (cards[3][card_id].promote_trump(trump)) {
							east_rank += 13;
						};
						if (cards[3][card_id].demote_discard(trump, suit_in_this_round)) {
							east_rank = 1;
						}
						cards[3][card_id].remove_card();
						cards[3][card_id].set_id();
					}
				}
				break;
			}



		}

		//compare the rank
		int highest_rank = 0;
		if (south_rank > highest_rank) {
			highest_rank = south_rank;
		}
		if (north_rank > highest_rank) {
			highest_rank = north_rank;
		}
		if (east_rank > highest_rank) {
			highest_rank = east_rank;
		}
		if (west_rank > highest_rank) {
			highest_rank = west_rank;
		}

		if (highest_rank == south_rank) {
			NS_trick++;
			lead_player = "S";
		}
		if (highest_rank == north_rank) {
			NS_trick++;
			lead_player = "N";
		}
		if (highest_rank == east_rank) {
			EW_trick++;
			lead_player = "E";
		}
		if (highest_rank == west_rank) {
			EW_trick++;
			lead_player = "W";
		}

		for (int player_idx = 0; player_idx < 4; player_idx++) {
			for (int j = 0; j < (13 - 1); j++) {
				for (int cards_idx = 0; cards_idx < (13 - 1 - j); cards_idx++) {
					cards[player_idx][cards_idx].swap();
				}
			}
		}
	}

	cout << "NS_trick:" << NS_trick << endl;
	cout << "EW_trick:" << EW_trick << endl;

	return 0;
}