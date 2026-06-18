#ifndef LRUAAA_H
#define LRUAAA_H
#include <iostream >
#include <vector > 
#include <algorithm>
#include <string> 

using namespace std;

  // Fonction LRU
string lru(int nbcadre,vector<int> page )
  	{
		int b,c=0,dp=0,min,z=0;
		int p;
 		vector<int> cadre(nbcadre);
 		vector<int> position(nbcadre);
 		
 		cout<<"Page";
 		//INITIALISATION DES VECTEURS ET AFFICHAGES DES CADRES
 		
 		for(int i=0;i<nbcadre;i++) { cadre[i]=(-1); cout<<"\tC"<<i;position[i]=(-1); }
	
		cout<<"\n";
 		
		b=page.size();
		
	 		for(int i=0;i<b;i++)
			{
			
				if(count(cadre.begin(),cadre.end(),page[i])>0)
				{
					cout<<" "<<page[i]<<" ";
				}
				// SI IL N'Y A PAGES DE NOUVELLE PAGES ON NE CHARGE PAS DE PAGES
		
				if(count(cadre.begin(),cadre.end(),page[i])<1 && c<nbcadre)
				{
					cout<<"("<<page[i]<<")";
					cadre[c]=page[i];
					c=c+1;
					dp=dp+1;
				}
			
				// GESTION DES CADRES
				// SI UNE PAGE ETAIT DANS LE CADRE ET EST OCCURENCE ON LE MET A LA DERNIERE POSITION
			
				if(count(position.begin(),position.end(),page[i])>0 && z==nbcadre)
					{ 
			  		int d=0,e=0;
			  		
			  		while(position[d]!=page[i]){d++;}
					  			  		
			  		for(e=d;e<(position.size()-1);e++)
			  			{	
			  				position[e]=position[e+1];
						}
					
			  		 position[e]=page[i];
					
					}
				if(count(position.begin(),position.end(),page[i])<1 && z<nbcadre)
					{					
					   if(z<nbcadre){
						position[z]=page[i];z=z+1;}
					}	
		
			// SI UNE NOUVELLE PAGE ARRIVE ON LE MET A LA PLACE DU DERNIER CADRE UTILISE CE QUI CORRESPONT ICI AU CADRE DU PREMIER ELEMENT DU VECTEUR
			// ET ENSUITE ON LE MET A LA DERNIERE POSITION DES OCCURENCES DES PAGES
			
				if( c==nbcadre && count(cadre.begin(),cadre.end(),page[i])<1 )
				{
					int f=0;
					while(cadre[f]!=position.front()){f++;}
					
					cadre[f]=page[i];	
					dp=dp+1;
					
					for(p=0;p<(cadre.size()-1);p++){ position[p]=position[p+1]; }
					position[nbcadre-1]=page[i];
					cout<<"("<<page[i]<<")";
					
				}
			
				for(int j=0;j<cadre.size();j++){ if (cadre[j]!=-1) {cout<<"\t"<<cadre[j];} }
				cout<<"\n";
			}
	        
		cout<<"\n Le nombre de defaut de pages est "<<dp<<"\n";
		return 	" ";
	 }
#endif
