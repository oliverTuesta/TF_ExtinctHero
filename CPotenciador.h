#pragma once
#include "Character.h"

class Potenciador : public Character {
public:
	Potenciador(int w, int h) : Character() {
		x = rand() % (600 - 300 + 1) + 300;
		y = rand() % (600 - 150 + 1) + 150;
		width = w;
		height = h;
		dx = dy = 0;
		idy = rand() % 3;
		zoomW = zoomH = 0.3;
	}

	~Potenciador(){}

	void move() {

		idx++;
		if (idx > 9)idx = 0;

	}

	int getIDY() { return idy; }

};