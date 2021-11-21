#pragma once
#include <vector>
#include <string>
#include"String.h"

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
	//void MarshalString(String^ s, string& os) {
	//	using namespace Runtime::InteropServices;
	//	const char* chars =
	//		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	//	os = chars;
	//	Marshal::FreeHGlobal(IntPtr((void*)chars));
	//}
	//
	//void MarshalString(String^ s, wstring& os) {
	//	using namespace Runtime::InteropServices;
	//	const wchar_t* chars =
	//		(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
	//	os = chars;
	//	Marshal::FreeHGlobal(IntPtr((void*)chars));
	//}

	~Player(){}

	string getName() { return name; }
	int getPokemonRescued() { return pokemonRescued; }
	int getTime() { return time; }
	void what(){  }
	void setName(String^ e) {
		name = "";
		for (int i = 0; i < e->Length; i++) {
			name.append(" ");
			name[i] = e[i];
		}
		//MarshalString(e, name);
	}
	void setPokemonRescued(int e) { pokemonRescued = e; }
	void setTime(int e) { time = e; }

};