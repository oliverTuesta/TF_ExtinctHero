#pragma once
#include "MainCharacter.h"
#include "OldMan.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


class Controller {
private:
	MainCharacter* mainCharacter;
	OldMan* oldman;

public:
	Controller(Bitmap^ bmpMainCharacter, Bitmap^ bmpOldMan) {
		mainCharacter = new MainCharacter(bmpMainCharacter);
		oldman = new OldMan(bmpOldMan);
	}

	~Controller() {
		delete mainCharacter;
	}

	//------------------ INICIO/MENU -----------------------
	void drawEverythingMenu(Graphics^ g, Bitmap^ bmpMainCharacter, Bitmap^ bmpOldMan) {
		oldman->draw(g, bmpOldMan);

		if (oldman->getVisitado()) {
			g->DrawString("Continue ->", 
				gcnew Drawing::Font("MV Boli", 10, FontStyle::Bold),
				Brushes::Black, 390, 225);
		}

		mainCharacter->draw(g, bmpMainCharacter);

	}

	int colisionMenu() {
		if (mainCharacter->getRectangle().IntersectsWith(oldman->getRectangle())
			&& !oldman->getVisitado()) {
			oldman->setVisitado(true);
			return 1;
		}
		if (mainCharacter->getRectangle().IntersectsWith(Rectangle(465, 215, 15, 40))
			&& oldman->getVisitado()) {
			return 2;
		}
		return 0;
	}

	MainCharacter* getMainCharacter() { return mainCharacter; }

};