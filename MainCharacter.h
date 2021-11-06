#pragma once
#include "Character.h"

class MainCharacter : public Character {
public:
	MainCharacter(Bitmap^ bmp) : Character() {
		x = 225;
		y = 220;
		width = bmp->Width / 4;
		height = bmp->Height / 4;
		dx = dy = 10;
		zoomW = zoomH = 0.8;
	}

	~MainCharacter() {}

	void move(Graphics^ g, char i) {
		switch (i)
		{
		case 'A':
			idy = 1;
			if (x > 0) {
				x -= dx;
			}
			break;
		case 'D':
			idy = 2;
			if (x + (width * zoomW) + dx < g->VisibleClipBounds.Width) {
				x += dx;
			}
			break;
		case 'W':
			idy = 3;
			if (y > 0) {
				y -= dy;
			}
			break;
		case 'S':
			idy = 0;
			if (y + (height * zoomH) + dy < g->VisibleClipBounds.Height) {
				y += dy;
			}
			break;
		}

		idx++;
		if (idx > 3)idx = 0;

	}
};