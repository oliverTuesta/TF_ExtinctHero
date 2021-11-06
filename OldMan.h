#pragma once
#include "Character.h"

class OldMan : public Character {
private:
	bool visitado;

public:
	OldMan(Bitmap^ bmp) : Character() {
		x = 275;
		y = 355;
		width = bmp->Width;
		height = bmp->Height;
		dx = dy = 0;
		zoomW = zoomH = 1.7;
		visitado = false;
	}
	
	~OldMan(){}

	bool getVisitado() { return visitado; }
	void setVisitado(bool i) { visitado = i; }
};