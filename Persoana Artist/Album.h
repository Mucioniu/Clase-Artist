#pragma once 
#include<iostream>
#include<string>
#include<map>
#include "Track.h"
using namespace std;

class Album{
	int an;
	string nume;
	multimap<int,Track> track;
	public:
		Album();
		Album(int, string);
		Album(int, string, multimap<int,Track> );
		bool operator<(const Album&) const;
		friend ostream& operator<<(ostream &,Album &);
		int getAn();
		string getNume1();
		void afisare();
		int are_secunde();
		void mai_lung(int );
		bool operator==(const Album&) const;
		Album &operator=(const Album&);
};
