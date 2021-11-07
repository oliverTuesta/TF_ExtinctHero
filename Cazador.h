#pragma once
#include "MainCharacter.h"
#include <cmath>

class Cazador : public Character {
private:
	//Aun no se si necesita alguna variable extra

public:
	Cazador(Bitmap^ bmp) :Character() {
		x = rand() % (700 - 40 + 1) + 40;
		y = rand() % (700 - 40 + 1) + 40;
		width = bmp->Width / 4;
		height = bmp->Height / 4;
		if (rand() % 11 > 5) dx = 5;
		else dx = -5;
		if (rand() % 11 > 5) dy = 5;
		else dy = -5;
		zoomW = zoomH = 0.5;
		movement = true;
	}

	~Cazador() {}

	void move(Graphics^ g, MainCharacter* hero) {

		if (this->getRectangle().IntersectsWith(hero->getViewRectangle())) {
			dx = dy = 1;
			if (x == hero->getX()) {
				x += dx;
			}
			else if (x > hero->getX()) {
				dx = abs(dx);
				x += dx;
				idy = 1;
			}
			else if (x < hero->getX()) {
				dx = -abs(dx);
				x += dx;
				idy = 2;
			}

			if (y == hero->getY()) {
				y += dy;
			}
			else if (y > hero->getY()) {
				dy = abs(dy);
				y += dy;
				idy = 0;
			}
			else if (y < hero->getY()) {
				dy = -abs(dy);
				y += dy;
				idy = 3;
			}
			dx *= 5;
			dy *= 5;
		}
		else {
			if (x + dx < 20 || x + width * zoomW + dx > 750) {
				dx = -dx;
			}
			if (y + dy < 20 || y + height * zoomH + dy > 750) {
				dy = -dy;
			}
			if (dx > 0) { idy = 2; }
			if (dx < 0) { idy = 1; }
			x += dx;
			y += dy;
		}
		
		idx++;
		if (idx > 3)idx = 0;

	}

	Rectangle getFutureRectangle() {
		return Rectangle(x + dx, y + dy, width * zoomW - 10, height * zoomH - 10);
	}
};