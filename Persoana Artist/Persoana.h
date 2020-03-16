//crearea clasei de baza persoana unde sunt stocate numele si varsta si declarata functia afisare care este de tip void, deoarece vom avea nevoie de aceasta pentru functia care o va 
// mosteni
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Persoana{
	protected:
		string nume;
		int varsta;
	public:
		Persoana();
		Persoana(string ,int);
		virtual void afisare();
		string getNume();
		int getVarsta();
};
