#pragma once
#include "MainCharacter.h"
#include "OldMan.h"
#include "Cazador.h"
#include "PokemonIcons.h"
#include "Pokemon.h"
#include "Criminales.h"
#include "CPotenciador.h"

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
	vector<Criminales*>criminales;
	vector<Pokemon*>pokemones;
	vector<Potenciador*>potenciadores;
	vector<PokemonIcon*>pokemonIcons;
	vector<ObstaculosCasa*>casasMenu;
	vector<ObstaculosCasa*>casasNivel1;
	vector<ObstaculosCasa*>casasNivel2;

public:
	Controller(Bitmap^ bmpMainCharacter, Bitmap^ bmpOldMan, Bitmap^ bmpCazador, Bitmap^ bmpCriminal, Bitmap^ bmpPotenciador, Bitmap^ bmpmensaje) {
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


		//---------- Constructor del Nivel 1 ----------
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

		//---------- Constructor del Nivel 2 ----------// Size dimensions: 885 width 760 heigth
		casasNivel2.push_back(new ObstaculosCasa(0, 0, 885, 145));//tierra superior	
		casasNivel2.push_back(new ObstaculosCasa(0, 0, 75, 320));//arboles superior izquierda
		casasNivel2.push_back(new ObstaculosCasa(330, 145, 110, 160));//tierra peque;a 2
		casasNivel2.push_back(new ObstaculosCasa(530, 145, 75, 100));//tierra peque;a 3
		casasNivel2.push_back(new ObstaculosCasa(790, 145, 95, 105));//tierra peque;a 4


		casasNivel2.push_back(new ObstaculosCasa(155, 140, 65, 50));//arbolito superior 2
		casasNivel2.push_back(new ObstaculosCasa(75, 145, 70, 155));//casita superior 1
		casasNivel2.push_back(new ObstaculosCasa(250, 170, 80, 50));//casita superior 2
		casasNivel2.push_back(new ObstaculosCasa(625, 170, 130, 70));//casita superior 3


		casasNivel2.push_back(new ObstaculosCasa(0, 400, 180, 360));//tierra inferior grande
		casasNivel2.push_back(new ObstaculosCasa(180, 640, 240, 120));//tierra inferior peque;a
		casasNivel2.push_back(new ObstaculosCasa(500, 680, 160, 80));//tierra inferior peque;a 2
		casasNivel2.push_back(new ObstaculosCasa(665, 710, 220, 50));//arboles inferior derecha 
		casasNivel2.push_back(new ObstaculosCasa(845, 450, 40, 310));//arboles inferior derecha 2

		casasNivel2.push_back(new ObstaculosCasa(170, 490, 85, 75));//casita inferior 1
		casasNivel2.push_back(new ObstaculosCasa(405, 420, 90, 90));//casita inferior 2
		casasNivel2.push_back(new ObstaculosCasa(645, 535, 125, 80));//casita inferior 3





		for (int i = 0; i < 3; i++) {
			potenciadores.push_back(new Potenciador(bmpPotenciador->Width / 10, bmpPotenciador->Height / 3));
		}

	}

	~Controller() {
		delete mainCharacter;
		delete oldman;
		delete mensaje;
	}

	//------------------ INICIO/MENU -----------------------
	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////
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

	//-------------------- NIVEL 1 -------------------------
	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////
	void drawEverythingNivle1(Graphics^ g, Bitmap^ bmpMainCharacter, Bitmap^ bmpCazador, Bitmap^ bmpCriminal, Bitmap^ bmpmensaje, bool i) {
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

		if (i) {
			mensaje->draw(g, bmpmensaje);
		}
		
		if (mainCharacter->getFinsishLvl1()) {
			g->DrawString("Continue ->",
				gcnew Drawing::Font("MV Boli", 10, FontStyle::Bold),
				Brushes::Black, 690, 535);
		}

		//g->DrawRectangle(gcnew Pen(Color::Red, 3), Rectangle(700, 530, 70, 30));
	}

	bool colisionNivel1(Graphics^ g, Bitmap^ bmpmensaje) {
		for (int i = 0; i < cazadores.size(); i++) {
			if (cazadores.at(i)->getRectangle().IntersectsWith(mainCharacter->getViewRectangle())) {
				cazadores.at(i)->setVisible(false);
				switch (pokemones.size())
				{
				case 0: pokemones.push_back(new Pokemon(cazadores[i]->getX(), cazadores[i]->getY(), 0.8, 0.8)); break;
				case 1: pokemones.push_back(new Pokemon(cazadores[i]->getX(), cazadores[i]->getY(), 0.5, 0.5)); break;
				case 2: pokemones.push_back(new Pokemon(cazadores[i]->getX(), cazadores[i]->getY(), 0.8, 0.8)); break;
				case 3: pokemones.push_back(new Pokemon(cazadores[i]->getX(), cazadores[i]->getY(), 0.5, 0.5, 1));
					mainCharacter->setFinsishLvl1(true);
					break;
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

	bool colisionNivel1Terminado() {
		if (mainCharacter->getRectangle().IntersectsWith(Rectangle(700, 530, 70, 30))) {
			return true;
		}
		return false;
	}

	void changetoNivel2(Bitmap^ bmpCazador, Bitmap^ bmpCriminal) {
		casasNivel1.clear();
		cazadores.clear();
		pokemones.clear();
		criminales.clear();
		for (int i = 0; i < 4; i++) {
			cazadores.push_back(new Cazador(bmpCazador));
			criminales.push_back(new Criminales(bmpCriminal, cazadores.at(i)));
		}
		mainCharacter->setNivel2();
	}

	//-------------------- Nivel 2 -------------------------
	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////
	void drawEverythingNivle2(Graphics^ g, Bitmap^ bmpMainCharacter, Bitmap^ bmpCazador, Bitmap^ bmpCriminal, Bitmap^ bmpPotenciador, Bitmap^ bmpmensaje, bool i) {
		for (int i = 0; i < cazadores.size(); i++) {
			cazadores.at(i)->move(g, this->getMainCharacter());
		}
		for (int i = 0; i < cazadores.size(); i++) {
			cazadores.at(i)->draw(g, bmpCazador);
		}
		for (int i = 0; i < criminales.size(); i++)
		{
			criminales.at(i)->move(g, this->getMainCharacter());
		}
		for (int i = 0; i < criminales.size(); i++)
		{
			criminales.at(i)->draw(g, bmpCriminal);
		}
		g->DrawEllipse(gcnew Pen(Color::DodgerBlue, 3),
			this->getMainCharacter()->getX() - 60,
			this->getMainCharacter()->getY() - 60, 150, 150);
		mainCharacter->draw(g, bmpMainCharacter);

		if (i) {
			mensaje->draw(g, bmpmensaje);
		}

		for (int i = 0; i < potenciadores.size(); i++) {
			potenciadores.at(i)->draw(g, bmpPotenciador);
			potenciadores.at(i)->move();
		}

		for (int i = 0; i < casasNivel2.size(); i++)	{
			casasNivel2.at(i)->draw(g);
		}

	}

	int colisionNivel2(bool tmr) {
		//Returns
		// 0 = no pasa nda
		// 1 = colision con un powerup -> activa un timer en form.h
		// 
		for (int i = 0; i < criminales.size(); i++) {
			if (!tmr) {
				criminales.at(i)->setSpeed(0);
			}
		}
		//Colision
		for (int i = 0; i < potenciadores.size(); i++) {
			if (!tmr && mainCharacter->getViewRectangle().IntersectsWith(potenciadores.at(i)->getRectangle())) {
				if (potenciadores.at(i)->getIDY() == 0) {
					for (int i = 0; i < criminales.size(); i++)	{
						criminales.at(i)->setSpeed(1);
					}
				}
				else if (potenciadores.at(i)->getIDY() == 1) {
					for (int i = 0; i < criminales.size(); i++) {
						criminales.at(i)->setSpeed(2);
					}
				}
				else {
					for (int i = 0; i < criminales.size(); i++) {
						criminales.at(i)->setSpeed(3);
					}
				}
				potenciadores.at(i)->setVisible(false);
			}
		}
		
		//Verificacion
		for (int i = 0; i < potenciadores.size(); i++) {
			if (!potenciadores.at(i)->getVisible()) {
				potenciadores.erase(potenciadores.begin() + i);
				return 1;
			}
		}
		return 0;
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

	int getPokemonSize() { return pokemones.size(); }

};