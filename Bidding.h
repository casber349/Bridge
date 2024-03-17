#ifndef BIDDING
#define BIDDING
#include <iostream>

using namespace std;

class BID {
	public:
		void bidding_initialize(int level_temp, int trump_temp, bool special);
		void print_bids(bool special, int doubles);
		void enable_doubles(bool can_you_double);
		void disable_doubles();
		void disable_bids(int bid_id);
		bool bid_to_level(string player_bid);
	private:
		int level;
		int trump;

		int id;
		bool available;
};

int bid_to_level(string player_bid);
int bid_to_trump(string player_bid);
int bid_to_id(string player_bid);

#endif