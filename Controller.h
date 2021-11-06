#pragma once
#include "MainCharacter.h"
#include "OldMan.h"
#include "Cazador.h"

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
	vector<Cazador*>cazadores;
	vector<ObstaculosCasa*>casasMenu;
	vector<ObstaculosCasa*>casasNivel1;

public:
	Controller(Bitmap^ bmpMainCharacter, Bitmap^ bmpOldMan, Bitmap^ bmpCazador) {
		//---------- Constructor del Menu/Inicio ----------
		mainCharacter = new MainCharacter(bmpMainCharacter);
		oldman = new OldMan(bmpOldMan);
		casasMenu.push_back(new ObstaculosCasa(205, 80, 75, 60));
		casasMenu.push_back(new ObstaculosCasa(355, 60, 75, 60));
		casasMenu.push_back(new ObstaculosCasa(60, 260, 125, 80));
		casasMenu.push_back(new ObstaculosCasa(280, 285, 175, 60));

		//---------- Constructor del Menu/Inicio ----------
		// Limites: W = 780  H = 755
		casasNivel1.push_back(new ObstaculosCasa(0, 0, 75, 210));	   //
		casasNivel1.push_back(new ObstaculosCasa(75, 130, 30, 80));	   //
		casasNivel1.push_back(new ObstaculosCasa(75, 0, 705, 60));	   // Obstaculos
		casasNivel1.push_back(new ObstaculosCasa(710, 60, 70, 450));   // del costado
		casasNivel1.push_back(new ObstaculosCasa(710, 580, 70, 175));  //
		casasNivel1.push_back(new ObstaculosCasa(500, 680, 210, 75));  // Faltan algunas
		casasNivel1.push_back(new ObstaculosCasa(0, 670, 300, 85));	   // imperfecciones
		casasNivel1.push_back(new ObstaculosCasa(0, 265, 80, 405));	   //

		casasNivel1.push_back(new ObstaculosCasa(155, 140, 65, 50));
		casasNivel1.push_back(new ObstaculosCasa(250, 60, 55, 70));
		casasNivel1.push_back(new ObstaculosCasa(350, 60, 360, 70));
		casasNivel1.push_back(new ObstaculosCasa(290, 190, 100, 70));
		casasNivel1.push_back(new ObstaculosCasa(480, 185, 30, 15));
		casasNivel1.push_back(new ObstaculosCasa(460, 200, 70, 40));
		casasNivel1.push_back(new ObstaculosCasa(440, 240, 110, 40));
		casasNivel1.push_back(new ObstaculosCasa(290, 380, 60, 45));
		casasNivel1.push_back(new ObstaculosCasa(450, 390, 110, 40));
		casasNivel1.push_back(new ObstaculosCasa(205, 490, 60, 70));
		casasNivel1.push_back(new ObstaculosCasa(360, 505, 70, 55));
		casasNivel1.push_back(new ObstaculosCasa(470, 505, 60, 55));

		cazadores.push_back(new Cazador(bmpCazador));
	}

	~Controller() {
		delete mainCharacter;
	}

	//------------------ INICIO/MENU -----------------------
	void drawEverythingMenu(Graphics^ g, Bitmap^ bmpMainCharacter, Bitmap^ bmpOldMan) {
		/*for (int i = 0; i < casasMenu.size(); i++)	{
			casasMenu.at(i)->draw(g);
		}*/
		// codigo para mostrar el hitbox de las casas
		
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

	void changetoNivel1() {
		casasMenu.clear();
	}

	//------------------ INICIO/MENU -----------------------
	void drawEverythingNivle1(Graphics^ g, Bitmap^ bmpMainCharacter, Bitmap^ bmpCazador) {
		/*for (int i = 0; i < casasNivel1.size(); i++)	{
			casasNivel1.at(i)->draw(g);
		}*/
		for (int i = 0; i < cazadores.size(); i++) {
			cazadores.at(i)->move(g, this->getMainCharacter());
		}
		for (int i = 0; i < cazadores.size(); i++) {
			cazadores.at(i)->draw(g, bmpCazador);
		}
		g->DrawEllipse(gcnew Pen(Color::DodgerBlue, 3), 
			this->getMainCharacter()->getX()-60, 
			this->getMainCharacter()->getY()-60, 150, 150);
		mainCharacter->draw(g, bmpMainCharacter);
	}

	MainCharacter* getMainCharacter() { return mainCharacter; }

	vector<ObstaculosCasa*> getObstaculosCasa() { return casasMenu; }
	vector<ObstaculosCasa*> getObstaculosNivel1() { return casasNivel1; }

};