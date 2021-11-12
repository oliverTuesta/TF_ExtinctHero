#pragma once
#include <cmath>

using namespace System::Drawing;

class Mensaje {
private:
	int x, y, dy; //solo se movera hacia arriba y hacia abajo
	int width, height;
	float zoomW, zoomH;
	bool moving;

public:
	Mensaje(Graphics^ g, Bitmap^ bmp, float zW = 1.0, float zH = 1.0) {
		dy = -5;
		width = bmp->Width;
		height = bmp->Height;
		zoomW = zW;
		zoomH = zH;
		moving = true;
		x = (g->VisibleClipBounds.Width / 2) - (width * zoomW / 2);
		y = g->VisibleClipBounds.Height;
	}

	~Mensaje() {}

	void draw(Graphics^ g, Bitmap^ bmp = gcnew Bitmap("archivos/mensajePositivo")) {
		Rectangle sectionShown = Rectangle(width, height, width, height);
		Rectangle zoom = Rectangle(x, y, width * zoomW, height * zoomH);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Graphics^ g) {
		if (moving) {
			y += dy;
		}
		if (y + height + 10 < g->VisibleClipBounds.Height) {
			moving = false;
			dy = abs(dy);
		}
	}

	bool getMoving() { return moving; }
	void setMoving(bool i) { moving = i; }

};