#include "Album.h"
using namespace std;

Album::Album()
{
}

Album::Album(int a, string b):an(a),nume(b)
{
}

Album::Album(int a, string b,multimap<int,Track> c):an(a),nume(b),track(c)
{
}

bool Album::operator<(const Album &a) const
{
	return (an<a.an);
}

ostream& operator<<(ostream &d, Album &b)
{
	d<<"- "<<b.an<<" "<<b.nume;
	multimap<int,Track>::iterator it;
	for(it=b.track.begin();it!=b.track.end();it++)
	{
		d<<it->second;
		d<<endl;
	}
	return d;
}

int Album::getAn()
{
	return an;
}

string Album::getNume1()
{
	return nume;
}

void Album::afisare()
{
	cout<<"Numele albumului "<<nume<<endl;
}

int Album::are_secunde()
{
	int sec=0;
	multimap<int,Track>::iterator it;
	for(it=track.begin();it!=track.end();it++)
	{
		sec=sec+it->second.getSecunde();
	}
	return sec;
}

void Album::mai_lung(int xx)
{
	int contor=0;
	multimap<int,Track>::iterator it;
	for(it=track.begin();it!=track.end();it++)
	{
		if(it->second.getSecunde()>xx)
		{
			cout<<it->second.getNume2()<<endl;
			contor++;
		}
	}
	if(contor==0)
		cout<<" Nu este niciun track mai lung fata de valoarea data\n " ;
	cout<<endl;
}

bool Album::operator==(const Album&a) const
{
	return (an==a.an && nume==a.nume && track==a.track);
}

Album& Album::operator=(const Album&a)
{
	if(this!=&a)
	{
		an=a.an;
		nume=a.nume;
		track=a.track;		
	}
	return *this;
}
