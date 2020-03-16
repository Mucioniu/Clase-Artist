#include "Track.h"
using namespace std;

Track::Track():pozitie(0),secunde(0){
}

Track::Track(int a, int b, string c):pozitie(a),secunde(b),nume(c)
{
}

ostream& operator<<(ostream& d, Track &a)
{
	d<<" "<<a.nume<<" ("<<a.secunde<<")";
	return d;
}

bool Track::operator<(const Track &a) const
{
	return pozitie<a.pozitie;
}

int Track::getPozitie()
{
	return pozitie;
}

int Track::getSecunde()
{
	return secunde;
}

string Track::getNume2()
{
	return nume;
}

bool Track::operator==(const Track&a) const
{
	return (pozitie==a.pozitie && secunde==a.secunde && nume==a.nume);
}

Track& Track::operator=(const Track&a)
{
	if(this!=&a)
	{
		pozitie=a.pozitie;
		secunde=a.secunde;
		nume=a.nume;
	}
	return *this;
}
