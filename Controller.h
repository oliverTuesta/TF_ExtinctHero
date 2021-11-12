#pragma once
#include "MainCharacter.h"
#include "OldMan.h"
#include "Cazador.h"
#include "PokemonIcons.h"
#include "Pokemon.h"

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
	Mensaje* mensaje;
	vector<Cazador*>cazadores;
	vector<Pokemon*>pokemones;
	vector<PokemonIcon*>pokemonIcons;
	vector<ObstaculosCasa*>casasMenu;
	vector<ObstaculosCasa*>casasNivel1;

public:
	Controller(Bitmap^ bmpMainCharacter, Bitmap^ bmpOldMan, Bitmap^ bmpCazador, Bitmap^ bmpmensaje) {
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

		for (int i = 0; i < 4; i++) {
			cazadores.push_back(new Cazador(bmpCazador));
		}
	}

	~Controller() {
		delete mainCharacter;
		delete oldman;
		delete mensaje;
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
	void drawEverythingNivle1(Graphics^ g, Bitmap^ bmpMainCharacter, Bitmap^ bmpCazador, Bitmap^ bmpmensaje, bool i) {
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


		/*g->DrawRectangle(gcnew Pen(Color::Red, 3), mainCharacter->getViewRectangle());*/

		mainCharacter->draw(g, bmpMainCharacter);

		if (i) {
			mensaje->draw(g, bmpmensaje);
		}
		
	}

	bool colisionNivel1(Graphics^ g, Bitmap^ bmpmensaje) {
		for (int i = 0; i < cazadores.size(); i++) {
			if (cazadores.at(i)->getRectangle().IntersectsWith(mainCharacter->getViewRectangle())) {
				cazadores.at(i)->setVisible(false);
				switch (pokemones.size())
				{
				case 0: pokemones.push_back(new Pokemon(cazadores[i]->getX(), cazadores[i]->getY(), 0.8, 0.8)); break;
				case 1: pokemones.push_back(new Pokemon(cazadores[i]->getX(), cazadores[i]->getY(), 0.1, 0.1)); break;
				case 2: pokemones.push_back(new Pokemon(cazadores[i]->getX(), cazadores[i]->getY(), 0.8, 0.8)); break;
				case 3: pokemones.push_back(new Pokemon(cazadores[i]->getX(), cazadores[i]->getY(), 0.5, 0.5, 1)); break;
				}
				mensaje = new Mensaje(g, 255, 44);
				pokemonIcons.push_back(new PokemonIcon(g, 30, 30, pokemonIcons.size()));
			}
		}
		for (int i = 0; i < cazadores.size(); i++) {
			if (!cazadores.at(i)->getVisible()) {
				cazadores.erase(cazadores.begin() + i);
				return true;
			}
		}
		return false;
	}

	MainCharacter* getMainCharacter() { return mainCharacter; }
	Mensaje* getMensaje() { return mensaje; }

	vector<ObstaculosCasa*> getObstaculosCasa() { return casasMenu; }
	vector<ObstaculosCasa*> getObstaculosNivel1() { return casasNivel1; }

	void drawPokemon(Graphics^ g, Bitmap^ bmp1, Bitmap^ bmp2, Bitmap^ bmp3, Bitmap^ bmp4, Bitmap^ bmp5) {
		for (int i = 0; i < pokemones.size(); i++) {
			switch (i)
			{
			case 0: pokemones.at(i)->draw(g, bmp1); break;
			case 1: pokemones.at(i)->draw(g, bmp2); break;
			case 2: pokemones.at(i)->draw(g, bmp3); break;
			case 3: pokemones.at(i)->draw(g, bmp4); break;
			case 4: pokemones.at(i)->draw(g, bmp5); break;
			}
			pokemones.at(i)->move();
		}
	}
	void drawPokemonIcon(Graphics^ g, Bitmap^ bmp1, Bitmap^ bmp2, Bitmap^ bmp3, Bitmap^ bmp4, Bitmap^ bmp5) {
		for (int i = 0; i < pokemonIcons.size(); i++) {
			switch (i)
			{
			case 0: pokemonIcons.at(i)->draw(g, bmp1); break;
			case 1: pokemonIcons.at(i)->draw(g, bmp2); break;
			case 2: pokemonIcons.at(i)->draw(g, bmp3); break;
			case 3: pokemonIcons.at(i)->draw(g, bmp4); break;
			case 4: pokemonIcons.at(i)->draw(g, bmp5); break;
			}
			pokemonIcons.at(i)->move(g);
		}
	}

};