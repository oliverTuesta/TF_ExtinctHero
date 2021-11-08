#pragma once

using namespace System::Drawing;

class ObstaculosCasa {
private:
	int x, y;
	/*int dx, dy;*/
	int width, height;

public:
	ObstaculosCasa(int _x, int _y, int w, int h) {
		x = _x;
		y = _y;
		width = w;
		height = h;
	}

	~ObstaculosCasa(){}

	void draw(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::Red, 3);
		g->DrawRectangle(p, x, y, width, height);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}

};