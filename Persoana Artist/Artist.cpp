#include"Artist.h"

Artist::Artist():Persoana()
{
}

Artist::Artist(string a, int b, multimap<int,Album> c):Persoana(a,b),alb(c)
{
}

void Artist::afisare()
{
	Persoana::afisare();
	multimap<int,Album>::iterator it;
	for(it=alb.begin();it!=alb.end();it++)
	{
		cout<<it->second;
		cout<<endl;
	}
}

void Artist::afisareNumeAlbum(ostream &d)
{
	multimap<int,Album>::iterator it;
	for(it=alb.begin();it!=alb.end();it++)
	{
		d<<it->second.getNume1();
		d<<endl;
	}
}

ostream& operator<<(ostream &d,Artist &a)
{
	d<<" Nume "<<a.getNume()<<" varsta "<<a.getVarsta();
	multimap<int,Album>::iterator it;
	for(it=a.alb.begin();it!=a.alb.end();it++)
	{
		d<<it->second;
		d<<endl;
	}
	return d;
}

void Artist::afisare_intre_ani(int an1, int an2)
{
	multimap<int,Album>::iterator it;
	for(it=alb.begin();it!=alb.end();it++)
	{
		if(it->second.getAn()>an1 && it->second.getAn()<an2)
		cout<<it->second.getNume1();
		cout<<endl;
	}
}
