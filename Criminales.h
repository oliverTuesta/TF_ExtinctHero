#pragma once
#include"Character.h"
#include"MainCharacter.h"
#include"Cazador.h"

class Criminales : public Character {
private:
	int potenciador;
	int velocidad;
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
		if (rand() % 11 > 5) dx = 1;
		else dx = -1;
		if (rand() % 11 > 5) dy = 1;
		else dy = -1;
		movement = true;
		zoomW = zoomH = 0.5;
		potenciador = 0;
	}

	~Criminales() {}

	void move(Graphics^ g, MainCharacter* hero) {
		if (this->getRectangle().IntersectsWith(hero->getDetectionRectangle())) {
			switch (potenciador)
			{
			case 0: velocidad = 3; break;
			case 1: velocidad = 0; break;
			case 2: velocidad = 1; break;
			case 3: velocidad = 2; break;
			}
			if (x == hero->getX()) {
				x += 0;
			}
			else if (x > hero->getX()) {
				dx = -abs(dx);
				x += dx * velocidad;
				idy = 1;
			}
			else if (x < hero->getX()) {
				dx = abs(dx);
				x += dx * velocidad;
				idy = 2;
			}
			if (y == hero->getY()) {
				y += 0;
			}
			else if (y > hero->getY()) {
				dy = -abs(dy);
				y += dy * velocidad;
				idy = 3;
			}
			else if (y < hero->getY()) {
				dy = abs(dy);
				y += dy * velocidad;
				idy = 0;
			}
		}
		else {
			switch (potenciador)
			{
			case 0: velocidad = 6; break;
			case 1: velocidad = 0; break;
			case 2: velocidad = 1; break;
			case 3: velocidad = 2; break;
			}
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
			x += dx * velocidad;
			y += dy * velocidad;
		}
		idx++;
		if (idx > 3)idx = 0;
	}

	void setSpeed(int i) { potenciador = i; }
	
};