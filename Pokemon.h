#pragma once
#include "Character.h"

class Pokemon : public Character {
private:
	int pokemonType;
	int direccion;
public:
	Pokemon(int _x, int _y, float w, float h, int type = 0) : Character () {
		x = _x;
		y = _y;
		pokemonType = type;
		direccion = rand() % 4;
		zoomW = w;
		zoomH = h;
		dx = dy = 5;
	}

	void draw(Graphics^ g, Bitmap^ bmp) {
		if (pokemonType == 0) {
			width = bmp->Width / 4;
			height = bmp->Height / 4;
		}
		else if (pokemonType == 1) {
			width = bmp->Width / 3;
			height = bmp->Height / 4;
		}
		else if (pokemonType == 2){
			width = bmp->Width / 5;
			height = bmp->Height;
		}
		if (visible) {
			Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
			Rectangle zoom = Rectangle(x, y, width * zoomW, height * zoomH);
			g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
		}
	}

	void move() {
		switch (pokemonType)
		{
		case 0: case 1:
			switch (direccion)
			{
			case 0:
				idy = 0;
				y += dy;
				break;
			case 1:
				idy = 1;
				x -= dx;
				break;
			case 2:
				idy = 2;
				x += dx;
				break;
			case 3:
				idy = 3;
				y -= dy;
				break;
			}
			idx++;
			if (pokemonType == 0 && idx > 3 || pokemonType == 1 && idx > 2) {
				idx = 0;
			}
			if (idx > 3)idx = 0;
			break;
		case 2: //Psyduck
			idx++;
			if (idx > 4)idx = 0;
			break;
		}
	}

};