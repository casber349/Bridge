#include "Bridge.h"
#include <iostream>

using namespace std;

void POKER::set_id() {
	id = (suit - 1) * 13 + (rank - 2);
}

void POKER::swap() {
	if (this->id > (this + 1)->id) {
		string player_temp = this->player;
		int suit_temp = this->suit;
		int rank_temp = this->rank;
		int id_temp = this->id;

		this->player = (this + 1)->player;
		this->suit = (this + 1)->suit;
		this->rank = (this + 1)->rank;
		this->id = (this + 1)->id;

		(this + 1)->player = player_temp;
		(this + 1)->suit = suit_temp;
		(this + 1)->rank = rank_temp;
		(this + 1)->id = id_temp;
	}
}