#pragma once
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;

	//Lista de variables
	bool firstTime; //Ya habia jugado antes_como para mostrar o no el menu // 0 significa que aun no juega
	int playersPlayed; //Numero de jugadores que han jugado
	int aux;
	string name;
	int pokemonRescued;
	int time;
	vector<Player*>players;

public:
	File() {}
	~File() {}

	void readData() {
		fileRead.open("configuration.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();

			fileWrite.open("configuration.txt", ios::out); //Creates the new txt
			fileWrite << "0" << endl;
			fileWrite << "0" << endl; //numero de jugadores anteriores
			fileWrite.close();

			fileRead.open("configuration.txt", ios::in);
		}

		//Ya habia jugado?
		getline(fileRead, text);
		aux = atoi(text.c_str());
		if (aux == 0) { firstTime = true; }
		else { firstTime = false; }
		//Cuantos jugadores hay
		getline(fileRead, text);
		playersPlayed = atoi(text.c_str());
		for (int i = 0; i < playersPlayed; i++) {
			getline(fileRead, text);
			name = text.c_str();
			getline(fileRead, text);
			pokemonRescued = atoi(text.c_str());
			getline(fileRead, text);
			time = atoi(text.c_str());
			players.push_back(new Player(name, pokemonRescued, time));
		}

		fileRead.close();
	}

	void agregarJugador(Player* newPlayer) {
		players.push_back(newPlayer);
		fileWrite.open("configuration.txt", ios::out);
		fileWrite << "1" << endl;
		fileWrite << players.size() << endl;
		for (int i = 0; i < players.size(); i++) {
			fileWrite << players.at(i)->getName() << endl;
			fileWrite << players.at(i)->getPokemonRescued() << endl;
			fileWrite << players.at(i)->getTime() << endl;
		}
		fileWrite.close();
		playersPlayed = players.size();
	}

	vector<Player*> getPlayers() { return players; }

};