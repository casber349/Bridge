#include "Bridge.h"
#include <iostream>

using namespace std;

int who_play_first(string lead_player) {
	if (lead_player == "S") {
		return 0;
	}
	else if (lead_player == "N") {
		return 2;
	}
	else if (lead_player == "E") {
		return 3;
	}
	else if (lead_player == "W") {
		return 1;
	}
}