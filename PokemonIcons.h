#pragma once
#include "Mensaje.h"

class PokemonIcon : public Mensaje {
private:
	int dx;
	int nivel;
	bool moving;

public:
	PokemonIcon(int j, Graphics^ g, int w, int h, int i, float zW = 1.0, float zH = 1.0) : Mensaje(g, w, h, zW, zH) {
		dx = 5;
		y = 50 + (height * zoomH + 10) * i;
		x = g->VisibleClipBounds.Width - 100;
		if (j == 1) {
			nivel = 850;
			x = 900;
		}
		else {
			nivel = 750;
		}
		moving = true;
	}

	void move(Graphics^ g) {
		if (moving) {
			x -= dx;
		}
		if (x < nivel) {
			moving = false;
		}
	}

	void setNivel(int i) { nivel = i; }

};