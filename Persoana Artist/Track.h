#pragma once
#include<iostream>
#include<string>
using namespace std;

class Track{
	int pozitie;
	int secunde;
	string nume;
	public:
		Track();
		Track(int, int, string);
		friend ostream& operator<<(ostream &, Track &);
		bool operator<(const Track& ) const;
		int getPozitie();
		int getSecunde();
		string getNume2();
		bool operator==(const Track&) const;
		Track &operator=(const Track&);
};
