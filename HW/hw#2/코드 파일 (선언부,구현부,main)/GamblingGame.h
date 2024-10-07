#ifndef GAMBLINGGAME_H
#define GAMBLINGGAME_H
#include "Player.h"

class GamblingGame {
	Player player[2];
public:
	void gamestart();
	bool turn(string name);
	~GamblingGame();
};

#endif
