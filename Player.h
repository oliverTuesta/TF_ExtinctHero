#pragma once
#include <vector>
#include <string>

using namespace std;

class Player {
private:
	string name;
	int pokemonRescued;
	int time;

public:
	Player(string x, int y, int z) {
		name = x;
		pokemonRescued = y;
		time = z;
	}

	~Player(){}

	string getName() { return name; }
	int getPokemonRescued() { return pokemonRescued; }
	int getTime() { return time; }

	void setName(string e) { name = e; }
	void setPokemonRescued(int e) { pokemonRescued = e; }
	void setTime(int e) { time = e; }

};