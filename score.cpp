#include "score.h"
#include <iostream>

using namespace std;

bool is_NS_vulnerable(string who_is_vulnerable) {
	if ((who_is_vulnerable == "NS") || (who_is_vulnerable == "Both")) {
		return true;
	}
	else {
		return false;
	}
}
bool is_EW_vulnerable(string who_is_vulnerable) {
	if ((who_is_vulnerable == "EW") || (who_is_vulnerable == "Both")) {
		return true;
	}
	else {
		return false;
	}
}

int win(int trick_required, int trick, int suit, int level, bool vulnerable, bool Doubled, bool Redoubled) {
	int score = 0;
	if (!Doubled) {
		if (!Redoubled) {
			switch (suit) {	//Basic score
				case 1: case 2:		//minor(C, D)
					score = level * 20;
					break;
				case 3: case 4:		//Major(H, S)
					score = level * 30;
					break;
				case 5:					//NT
					score = level * 30 + 10;
					break;
			}

			if (score >= 100) {	//Game
				if (vulnerable) {
					score += 500;
				}
				else {
					score += 300;
				}
			}
			else {
				score += 50;	//Partscore Bonus
			}			

			if (level == 6) {		//Slam
				if (vulnerable) {
					score += 750;
				}
				else {
					score += 500;
				}
			}
			if (level == 7) {		//Grand Slam
				if (vulnerable) {
					score += 1500;
				}
				else {
					score += 1000;
				}
			}
			
			switch (suit) {	//Overtrick score
			case 1: case 2:		//minor(C, D)
				score += (trick - trick_required) * 20;
				break;
			case 3: case 4: case 5:		//Major(H, S), NT
				score += (trick - trick_required) * 30;
				break;
			}
		}
		else {	//Redoubled
			switch (suit) {	//Basic score
			case 1: case 2:		//minor(C, D)
				score = level * 20;
				break;
			case 3: case 4:		//Major(H, S)
				score = level * 30;
				break;
			case 5:					//NT
				score = level * 30 + 10;
				break;
			}

			score *= 4;	//Redouble: Basic score * 4

			if (score >= 100) {	//Game
				if (vulnerable) {
					score += 500;
				}
				else {
					score += 300;
				}
			}
			else {
				score += 50;	//Partscore Bonus
			}

			if (level == 6) {		//Slam
				if (vulnerable) {
					score += 750;
				}
				else {
					score += 500;
				}
			}
			if (level == 7) {		//Grand Slam
				if (vulnerable) {
					score += 1500;
				}
				else {
					score += 1000;
				}
			}

			score += 100;	//Redouble Bonus

			if (vulnerable) {	//Overtrick Bonus (Redouble)
				score += (trick - trick_required) * 400;
			}
			else {
				score += (trick - trick_required) * 200;
			}
		}
	}
	else {	//Doubled
		switch (suit) {	//Basic score
		case 1: case 2:		//minor(C, D)
			score = level * 20;
			break;
		case 3: case 4:		//Major(H, S)
			score = level * 30;
			break;
		case 5:					//NT
			score = level * 30 + 10;
			break;
		}

		score *= 2;	//Double: Basic score * 2

		if (score >= 100) {	//Game
			if (vulnerable) {
				score += 500;
			}
			else {
				score += 300;
			}
		}
		else {
			score += 50;	//Partscore Bonus
		}

		if (level == 6) {		//Slam
			if (vulnerable) {
				score += 750;
			}
			else {
				score += 500;
			}
		}
		if (level == 7) {		//Grand Slam
			if (vulnerable) {
				score += 1500;
			}
			else {
				score += 1000;
			}
		}

		score += 50;	//Double Bonus

		if (vulnerable) {	//Overtrick Bonus (Double)
			score += (trick - trick_required) * 200;
		}
		else {
			score += (trick - trick_required) * 100;
		}
	}
	return score;
}

int lose(int trick_required, int trick, bool vulnerable, bool Doubled, bool Redoubled) {
	int score = 0;
	if (!Doubled) {
		if (!Redoubled) {
			if (vulnerable) {
				score = (trick_required - trick) * (-100);
			}
			else {	//non_vulnerable
				score = (trick_required - trick) * (-50);
			}
		}
		else {	//Redoubled
			if (vulnerable) {	//(Redouble)
				if ((trick_required - trick) == 1) {	//down 1 trick: -400
					score = -400;
				}
				else {	//down 2 trick or more : -1000, -1600
					score = -400;
					score -= ((trick_required - trick) - 1) * 600;
				}
			}
			else {	//non_vulnerable (Redouble)
				if ((trick_required - trick) == 1) {	//down 1 trick: -200
					score = -200;
				}
				else if (((trick_required - trick) == 2) || ((trick_required - trick) == 3)) {	//down 2~ 3 trick: -600, -1000
					score = -200;
					score -= ((trick_required - trick) - 1) * 400;
				}
				else {	//down 4 trick or more : -1600, -2200
					score = -1000;
					score -= ((trick_required - trick) - 3) * 600;
				}
			}
		}
	}
	else {	//Doubled
		if (vulnerable) {	//(Double)
			if ((trick_required - trick) == 1) {	//down 1 trick: -200
				score = -200;
			}
			else {	//down 2 trick or more : -500, -800
				score = -200;
				score -= ((trick_required - trick) - 1) * 300;
			}
		}
		else {	//non_vulnerable (Double)
			if ((trick_required - trick) == 1) {	//down 1 trick: -100
				score = -100;
			}
			else if(((trick_required - trick) == 2) || ((trick_required - trick) == 3)){	//down 2~ 3 trick: -300, -500
				score = -100;
				score -= ((trick_required - trick) - 1) * 200;
			}
			else {	//down 4 trick or more : -800, -1100
				score = -500;
				score -= ((trick_required - trick) - 3) * 300;
			}
		}
	}

	return score;
}