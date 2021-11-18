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
	bool firstTime; //Ya habia jugado antes_como para mostrar o no el menu
	int playersPlayed; //Numero de jugadores que han jugado
	vector<Player*>players;
	/*int hp;
	int myTime;*/

public:
	File() {}
	~File() {}

	void readData() {
		fileRead.open("configuration.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();

			fileWrite.open("configuration.txt", ios::out); //Creates the new txt
			fileWrite << "10" << endl;
			fileWrite << "90" << endl;
			fileWrite.close();

			fileRead.open("configuration.txt", ios::in);
		}

		getline(fileRead, text);
		hp = atoi(text.c_str());
		getline(fileRead, text);
		myTime = atoi(text.c_str());

		fileRead.close();
	}

	int getHp() { return hp; }
	int getMyTime() { return myTime; }
	

};