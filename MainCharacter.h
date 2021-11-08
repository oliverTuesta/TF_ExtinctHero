#pragma once
#include "Character.h"
#include "ObstaculosCasas.h"
#include <vector>

using namespace std;

class MainCharacter : public Character {
public:
	MainCharacter(Bitmap^ bmp) : Character() {
		x = 220;
		y = 200;
		width = bmp->Width / 4;
		height = bmp->Height / 4;
		dx = dy = 10;
		zoomW = zoomH = 0.8;
		movement = true;
	}

	~MainCharacter() {}
	
	void move(Graphics^ g, char i, vector<ObstaculosCasa*> casas) {
		switch (i)
		{
		case 'A':
			idy = 1;
			for (int i = 0; i < casas.size(); i++)	{
				if (this->getFutureRectangle(-10, 0).IntersectsWith(casas.at(i)->getRectangle())) {
					movement = false;
				}
			}
			if (x > 0 && movement) {
				x -= dx;
			}
			break;
		case 'D':
			idy = 2;
			for (int i = 0; i < casas.size(); i++) {
				if (this->getFutureRectangle(10, 0).IntersectsWith(casas.at(i)->getRectangle())) {
					movement = false;
				}
			}
			if (x + (width * zoomW) < g->VisibleClipBounds.Width && movement) {
				x += dx;
			}
			break;
		case 'W':
			idy = 3;
			for (int i = 0; i < casas.size(); i++) {
				if (this->getFutureRectangle(0, -10).IntersectsWith(casas.at(i)->getRectangle())) {
					movement = false;
				}
			}
			if (y > 0 && movement) {
				y -= dy;
			}
			break;
		case 'S':
			idy = 0;
			for (int i = 0; i < casas.size(); i++) {
				if (this->getFutureRectangle(0, 10).IntersectsWith(casas.at(i)->getRectangle())) {
					movement = false;
				}
			}
			if (y + (height * zoomH) < g->VisibleClipBounds.Height && movement) {
				y += dy;
			}
			break;
		}

		idx++;
		if (idx > 3)idx = 0;
		movement = true;

	}

	void setNivel1() {
		x = 30;
		y = 220;
		dx = dy = 5;
		zoomW = zoomH = 0.5;
	}

	Rectangle getFutureRectangle(int xd, int yd) {
		return Rectangle(x + xd + 5, y + yd + 5, width * zoomW - 10, height * zoomH - 10);
	}

	Rectangle getViewRectangle() {
		return Rectangle(x + dx - 50, y + dy - 50, width * zoomW + 90, height * zoomH + 90);
	}

};