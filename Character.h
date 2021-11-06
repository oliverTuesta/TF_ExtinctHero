#pragma once
#include <iostream>

using namespace System::Drawing;

class Character {
protected:
	int x, y;
	int dx, dy;
	int width, height;
	int idx, idy;
	float zoomW, zoomH;
	bool visible; 
	bool movement;

public:
	Character() {
		//En las clases hijos se asignaran las variables restantes
		zoomW = zoomH = 1.0;
		idx = idy = 0;
		visible = true;
	}

	~Character() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * zoomW, height * zoomH);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	virtual void move() {}

	int getX() { return x; }
	int getY() { return y; }
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
	bool getMovement() { return movement; }
	void setMovement(bool v) { movement = v; }

	Rectangle getRectangle() {
		return Rectangle(x + 5, y + 5, width * zoomW - 10, height * zoomH - 10);
	}
};