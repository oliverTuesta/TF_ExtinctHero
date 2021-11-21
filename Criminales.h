#pragma once
#include"Character.h"
#include"MainCharacter.h"
#include"Cazador.h"
class Criminales : public Character
{
public:
	Criminales(Bitmap^ bmp, Cazador* C) : Character() {
		switch (rand() % (4 - 1 + 1) + 1) {
		case 1:
			x = C->getX() + 30;
			y = C->getY();
			break;
		case 2:
			x = C->getX() - 30;
			y = C->getY();
			break;
		case 3:
			x = C->getX();
			y = C->getY() + 30;
			break;
		case 4:
			x = C->getX();
			y = C->getY() - 30;
			break;
		}
		width = bmp->Width / 4;
		height = bmp->Height / 4;
		if (rand() % 11 > 5) dx = 6;
		else dx = -6;
		if (rand() % 11 > 5) dy = 6;
		else dy = -6;
		movement = true;
		zoomW = zoomH = 0.5;
	}
	void move(Graphics^ g, MainCharacter* hero) {
		if (this->getRectangle().IntersectsWith(hero->getDetectionRectangle())) {
			dx = dy = 3;
			if (x == hero->getX()) {
				x += 0;
			}
			else if (x > hero->getX()) {
				dx = -abs(dx);
				x += dx;
				idy = 1;
			}
			else if (x < hero->getX()) {
				dx = abs(dx);
				x += dx;
				idy = 2;
			}
			if (y == hero->getY()) {
				y += 0;
			}
			else if (y > hero->getY()) {
				dy = -abs(dy);
				y += dy;
				idy = 3;
			}
			else if (y < hero->getY()) {
				dy = abs(dy);
				y += dy;
				idy = 0;
			}
			dx *= 2;
			dy *= 2;
		}
		else {
			if (x + dx < 20) {
				dx = abs(dx);
			}
			if (x + width * zoomW + dx > 750) {
				dx = -abs(dx);
			}
			if (y + dy < 20) {
				dy = abs(dy);
			}
			if (y + height * zoomH + dy > 750) {
				dy = -abs(dy);
			}
			if (dx > 0) { idy = 2; }
			if (dx < 0) { idy = 1; }
			x += dx;
			y += dy;
		}
		idx++;
		if (idx > 3)idx = 0;
	}

	~Criminales();

private:
	
};



Criminales::~Criminales()
{
}