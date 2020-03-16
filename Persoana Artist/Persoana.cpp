//Declararea constructorilor cu parametrii si fara parametrii
#include "Persoana.h"
using namespace std;

Persoana::Persoana():varsta(0)
{
}

Persoana::Persoana(string a, int b):nume(a),varsta(b)
{
}

void Persoana::afisare()
{
	cout<<endl;
	cout<<"Artist "<<nume;;
}

string Persoana::getNume()
{
	return nume;
}

int Persoana::getVarsta()
{
	return varsta;
}

