#pragma once
#include "Character.h"
#include "ObstaculosCasas.h"
#include <vector>

using namespace std;

class MainCharacter : public Character {
private:
	bool finishLvl1;
public:
	MainCharacter(Bitmap^ bmp) : Character() {
		x = 220;
		y = 200;
		width = bmp->Width / 4;
		height = bmp->Height / 4;
		dx = dy = 10;
		zoomW = zoomH = 0.8;
		movement = true;
		finishLvl1 = false;
	}

	~MainCharacter() {}

	void moveLeft(Graphics^ g, vector<ObstaculosCasa*> casas) {
		idy = 1;
		for (int i = 0; i < casas.size(); i++) {
			if (this->getFutureRectangle(-10, 0).IntersectsWith(casas.at(i)->getRectangle())) {
				movement = false;
			}
		}
		if (x > 0 && movement) {
			x -= dx;
		}

		idx++;
		if (idx > 3)idx = 0;
		movement = true;
	}

	void moveRight(Graphics^ g, vector<ObstaculosCasa*> casas) {
		idy = 2;
		for (int i = 0; i < casas.size(); i++) {
			if (this->getFutureRectangle(10, 0).IntersectsWith(casas.at(i)->getRectangle())) {
				movement = false;
			}
		}
		if (x + (width * zoomW) < g->VisibleClipBounds.Width && movement) {
			x += dx;
		}

		idx++;
		if (idx > 3)idx = 0;
		movement = true;
	}

	void moveUp(Graphics^ g, vector<ObstaculosCasa*> casas) {
		idy = 3;
		for (int i = 0; i < casas.size(); i++) {
			if (this->getFutureRectangle(0, -10).IntersectsWith(casas.at(i)->getRectangle())) {
				movement = false;
			}
		}
		if (y > 0 && movement) {
			y -= dy;
		}

		idx++;
		if (idx > 3)idx = 0;
		movement = true;
	}

	void moveDown(Graphics^ g, vector<ObstaculosCasa*> casas) {
		idy = 0;
		for (int i = 0; i < casas.size(); i++) {
			if (this->getFutureRectangle(0, 10).IntersectsWith(casas.at(i)->getRectangle())) {
				movement = false;
			}
		}
		if (y + (height * zoomH) < g->VisibleClipBounds.Height && movement) {
			y += dy;
		}

		idx++;
		if (idx > 3)idx = 0;
		movement = true;
	}

	void setNivel1() {
		x = 30;
		y = 220;
		dx = dy = 25;
		zoomW = zoomH = 0.5;
	}

	void setNivel2() {
		x = 30;
		y = 350;
		dx = dy = 15;
		zoomW = zoomH = 0.5;
	}

	Rectangle getFutureRectangle(int xd, int yd) {
		return Rectangle(x + xd + 5, y + yd + 5, width * zoomW - 10, height * zoomH - 10);
	}

	Rectangle getViewRectangle() {
		return Rectangle(x + dx - 50, y + dy - 50, width * zoomW + 90, height * zoomH + 90);
	}

	Rectangle getDetectionRectangle() {
		return Rectangle(x + dx - 75, y + dy - 75, width * zoomW + 140, height * zoomH + 140);
	}

	Rectangle getCaptureRectangle() {
		return Rectangle(x + 10, y + dy + 10, width * zoomW - 20, height * zoomH - 20);
	}

	void setFinsishLvl1(bool i) { finishLvl1 = i; }
	bool getFinsishLvl1() { return finishLvl1; }

};