/*	In acest progran avem doua persoane care fac parte din clasa artist, un artist are mai multe clase albume, iar un album are mai multe clase track-uri. Foloseste elemente de stl cum
ar fi map, multimap, vector si priorityqueue.
 
*/
#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<utility>
#include<fstream>
#include "Artist.h"
#include "Album.h"
using namespace std;

int main(){
	
	//Declararea Track-urilor
	Track t1(1, 180, "Sweet Home Alabama");                         
	Track t2(2, 150, "Love of my life");
	Track t3(3, 210, "I had that dream a thousand times");
	Track t4(1, 450, "Bohemian Rhapsody");
	Track t5(3, 250, "Kill for me");
	Track t6(2, 160, "Cheek to cheek");
	Track t7(2, 260, "Saint James Infirmery");
	
	//Introducerea track-urilor in container-ul multimap care sunt sortate in functie de pozitie
	multimap<int,Track> alb1;
	alb1.insert(pair<int,Track>(t1.getPozitie(),t1));
	alb1.insert(pair<int,Track>(t2.getPozitie(),t2));
	alb1.insert(pair<int,Track>(t3.getPozitie(),t3));
	multimap<int,Track> alb2;
	alb2.insert(pair<int,Track>(t4.getPozitie(),t4));
	alb2.insert(pair<int,Track>(t7.getPozitie(),t7));
	multimap<int,Track> alb3;
	alb3.insert(pair<int,Track>(t5.getPozitie(),t5));
	alb3.insert(pair<int,Track>(t6.getPozitie(),t6));
	
	//Declararea albumelor
	Album a1(1990,"Autumn",alb1);
	Album a2(1978,"Killer Queen",alb2);
	Album a3(2015,"The Pale Emperor");
	Album a4(1980,"Hihgway yo gell");
	Album a5(1978,"Killer King",alb3);
	Album a6(2013,"No woman no cry");
	
	//Introducerea track-urilor in container-ul multimap care sunt sortate in functie de an
	multimap<int,Album> mp;
	mp.insert(pair<int,Album>(a1.getAn(),a1));
	mp.insert(pair<int,Album>(a2.getAn(),a2));
	mp.insert(pair<int,Album>(a3.getAn(),a3));
	multimap<int,Album> mp1;
	mp1.insert(pair<int,Album>(a4.getAn(),a4));
	mp1.insert(pair<int,Album>(a5.getAn(),a5));
	mp1.insert(pair<int,Album>(a6.getAn(),a6));
	
	//Introducerea track-urilor in container-ul vector
	vector<Artist> pers;
	pers.push_back(Artist("John",30,mp));
	pers.push_back(Artist("Mihai",50,mp1));
	
	//Afisarea elementelor din vector
	vector<Artist>::iterator x;
	x=pers.begin();
	while(x!=pers.end())
	{
		(*x).afisare();
		x++;
	}
	//Afisarea in fisier a primului artist cu albumele sale 
	ofstream fis_1("Artist.txt", ios::app);
	if(!fis_1) cout<<"Eroare la deschidere"<<endl;
	fis_1<<"Artistul "<<pers[0].getNume()<<" ";
	fis_1<<"Cu albumele: "<<endl;
	pers[0].afisareNumeAlbum(fis_1);
	fis_1.close();
	
	//Introducem doua valori de la tastatura care reprezinta anul1 si anul 2, pentru a afisa toate albumele care se afla intre anii introdusi
	int an1,an2;
	cout<<endl;
	cout<<"Dati intre ce ani sa se gaseasca albumele?\n";
	cin>>an1>>an2;
	multimap<int, Album> albume;
	albume.insert(pair<int,Album>(a1.getAn(),a1));
	albume.insert(pair<int,Album>(a2.getAn(),a2));
	albume.insert(pair<int,Album>(a3.getAn(),a3));
	albume.insert(pair<int,Album>(a4.getAn(),a4));
	albume.insert(pair<int,Album>(a5.getAn(),a5));
	albume.insert(pair<int,Album>(a6.getAn(),a6));
	multimap<int, Album>::iterator it=albume.begin();
	//Afisarea albumelor care se afla intre cele doua valori
	while(it!=albume.end())
	{
		if(it->second.getAn()>an1 && it->second.getAn()<an2)
			it->second.afisare();
		it++;
	}
	cout<<endl;
	
	//Afisarea albumelor unui artist care se afla intre cele doua  valori
	cout<<"Albumele artistului care are albumele intre "<<an1<<" si "<<an2<<endl;
	pers[0].afisare_intre_ani(an1,an2);
	
	//Introducem toate albumele intr-un priority queue in functie de numarul de secunde pentru a le avea deja sortate 
	priority_queue<int> Q;
	it=albume.begin();
	while(it!=albume.end())
	{
		Q.push(it->second.are_secunde());
		it++;
	}
	cout<<"Cel mai lung album are "<<Q.top()<<" secunde "<<endl;
	//Introducerea de la tastatura a valorii xx pentru a afisa toate track-urile dintr-un album dat de noi, care sunt mai lungi decat valoarea data.
	int xx;
	cout<<"Dati secundele: ";
	cin>>xx;
	cout<<"Track-urile cu mai multe secunde decat "<<xx<<" sunt: ";
	a1.mai_lung(xx);
	return 0;
}
