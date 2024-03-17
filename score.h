#ifndef SCORE
#define SCORE
#include <iostream>

using namespace std;


bool check_dealer(string dealer);
bool check_vulnerable(string who_is_vulnerable);

bool is_NS_vulnerable(string who_is_vulnerable);
bool is_EW_vulnerable(string who_is_vulnerable);

int win(int trick_required, int trick, int suit, int level, bool vulnerable, bool Doubled, bool Redoubled);
int lose(int trick_required, int trick, bool vulnerable, bool Doubled, bool Redoubled);

#endif