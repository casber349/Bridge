#ifndef BRIDGE
#define BRIDGE
#include <iostream>

using namespace std;

enum Suit {
	club = 1, diamond, heart, spade
};

enum Rank {
	discard = 1,
	two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
	, trump_two, trump_three, trump_four, trump_five, trump_six, trump_seven, trump_eight
	, trump_nine, trump_ten, trump_jack, trump_queen, trump_king, trump_ace
};

class POKER {
	public:
		void card_initialize(int player_index, int card_id);

		void set_id();
		void swap();

		bool count_club();
		bool count_diamond();
		bool count_heart();
		bool count_spade();

		bool promote_trump(int trump);
		bool demote_discard(int trump, int suit_in_this_round);

		string print_player_name();
		void print_cards();

		bool find_the_card(string card_to_play);

		void remove_card();
	private:
		string player;
		int suit;
		int rank;
		int id;
};

int card_to_suit(string card_to_play);
int card_to_rank(string card_to_play);

int who_play_first(string lead_player);
#endif