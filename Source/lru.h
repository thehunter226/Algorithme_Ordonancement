#ifndef FIFOAAA_H
#define FIFOAAA_H
#include <iostream >
#include <vector > 
#include <algorithm>
#include <string> 

using namespace std;

// FONCTION FIFO
 
string fifo (int nbcadre, vector<int> page)
 {
 	int b,c=0,dp=0;
 	vector<int> cadre(nbcadre);
 	
	b=page.size();
		
	cout<<"Page";	
		//INITIALISATION DES VECTEURS ET AFFICHAGES DES CADRES
	for(int i=0;i<nbcadre;i++) { cadre[i]=(-1);cout<<"\tC"<<i; }
	
		cout<<"\n";
		
	for(int i=0;i<b;i++)
	{
		
		if(count(cadre.begin(),cadre.end(),page[i])>0)
		{
			cout<<" "<<page[i]<<" ";
		}
		// SI IL N'Y A PAGES DE NOUVELLE PAGES ON NE CHARGE PAS DE PAGES
		if(count(cadre.begin(),cadre.end(),page[i])<1)
		{
			cout<<"("<<page[i]<<") ";
			cadre[c]=page[i];
			c=c+1;
			dp=dp+1;
		} 
		if(c==nbcadre){c=0;}

	// A CHAQUE TOUR DE ON AFFICHE LE CONTENU DES CADRES
		for(int j=0;j<cadre.size();j++){ if (cadre[j]!=-1) {cout<<"\t"<<cadre[j];} }
		
		cout<<"\n";
	}
	 
 	cout<<"\n Le nombre de defaut de pages est "<<dp<<"\n";

	return " ";
 };

#endif
