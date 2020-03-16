//Clasa artist mostenita din clasa persoana are declarata ca atribut cointainerul multimap de albume pe care o sa le sorteze in functie de anul aparitiei. 
//Este mostenita functia afisare din clasa persoana
#include<map>
#include"Persoana.h"
#include"Album.h"

class Artist:public Persoana
{
	multimap<int, Album> alb;
	public:
		Artist();
		Artist(string, int, multimap<int, Album> );
		void afisare();
		friend ostream& operator<<(ostream &,Artist &);
		void afisareNumeAlbum(ostream &);
		void afisare_intre_ani(int, int);
};
