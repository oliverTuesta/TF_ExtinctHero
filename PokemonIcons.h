#pragma once
#include "Mensaje.h"

class PokemonIcon : public Mensaje {
private:
	int dx;
	bool moving;

public:
	PokemonIcon(Graphics^ g, int w, int h, int i, float zW = 1.0, float zH = 1.0) :Mensaje(g, w, h, zW, zH) {
		dx = 5;
		/*y = 0 - height * zoomH;
		x = 270 + (width * zoomW + 10) * i;*/
		y = 50 + (height * zoomH + 10) * i;
		x = g->VisibleClipBounds.Width - 100;
		moving = true;
	}

	void move(Graphics^ g) {
		if (moving) {
			x -= dx;
		}
		if (x + width + 10 < g->VisibleClipBounds.Width) {
			moving = false;
		}
	}
};