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
	//----- Atributos del Menu/Inicio -----
	MainCharacter* mainCharacter;
	OldMan* oldman;
	vector<ObstaculosCasa*>casasMenu;

public:
	Controller(Bitmap^ bmpMainCharacter, Bitmap^ bmpOldMan) {
		//---------- Constructor del Menu/Inicio ----------
		mainCharacter = new MainCharacter(bmpMainCharacter);
		oldman = new OldMan(bmpOldMan);
		casasMenu.push_back(new ObstaculosCasa(205, 80, 75, 60));
		casasMenu.push_back(new ObstaculosCasa(355, 60, 75, 60));
		casasMenu.push_back(new ObstaculosCasa(60, 260, 125, 80));
		casasMenu.push_back(new ObstaculosCasa(280, 285, 175, 60));
	}

	~Controller() {
		delete mainCharacter;
	}

	//------------------ INICIO/MENU -----------------------
	void drawEverythingMenu(Graphics^ g, Bitmap^ bmpMainCharacter, Bitmap^ bmpOldMan) {
		/*for (int i = 0; i < casasMenu.size(); i++)	{
			casasMenu.at(i)->draw(g);
		}*/
		// ^ codigo para mostrar el hitbox de las casas
		
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

	vector<ObstaculosCasa*> getObstaculosCasa() { return casasMenu; }

};