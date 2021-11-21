#pragma once
#include <cmath>

using namespace System::Drawing;

class Mensaje {
protected:
	int x, y;
	int width, height;
	float zoomW, zoomH;

public:
	Mensaje(Graphics^ g, int w, int h, float zW = 1.0, float zH = 1.0) {
		width = w;
		height = h;
		zoomW = zW;
		zoomH = zH;
		x = g->VisibleClipBounds.Width - width * 1.4;
		y = 0;
	}

	~Mensaje() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle zoom = Rectangle(x, y, width * zoomW, height * zoomH);
		g->DrawImage(bmp, zoom);
	}

	void setX(int i) { x = i; }

};