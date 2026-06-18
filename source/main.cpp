#include <iostream >
#include <vector > 
#include <algorithm>
#include <string> 
#include "fifo.h"
#include "lru.h"

using namespace std;

int main ()
{
	int choix,nbpages,nbcadres,b;
	int rep,nb,tverif;
	vector<int> ref;
	vector<int> verif;
	
	do 
	{
		rep=0;
		tverif=0;
		ref.clear(); // REMISE A ZERO DES DIFFERENTE VARIABLES
		verif.clear();
		
		
		cout<<" \t\t---Menu---\n" ;
	
		cout<<" 1. FIFO \n 2. LRU \n  Entrer votre choix \n ";
		
		cin>>choix ;
		
			while(choix<1 || choix>2)
		{
			cout<<"*****CHOISISSEZ VOTRE ALGORITHME***\n ***ENTRER UN CHOIX CORRECTE*** \n ";
			cin>>choix	;
		}
	
		cout<<"Entrer le nombre de Pages \n ";
					cin>>nbpages;
		cout<<"Entrer le nombre de Cadres \n ";
					cin>>nbcadres;
	 	cout<<" Taper votre liste de references \t \t Apres avoir fini de saisir taper un nombre negatif pour continuer \n ";
					cin>>b;
	
	
		// ENTRER DES REFERENCES  
		 
	 	while (b>-1)
		 	{	
		 		ref.push_back(b);
		 		
		 		// DECOMPTES DES PAGES UNIQUES 
				nb=count(verif.begin(),verif.end(),b);
				
		 		if(nb<1)
				 	{
		 				verif.push_back(b);
		 			}
				cin>>b;
			}
				
		rep=ref.size();
		tverif=verif.size();	
			
		cout<<"\n les elements de votre reference : \n"; // Affichages des reference de l'utilisateur
		nb=0;
		
			for(int i=0;i<rep;i++)
				{
					cout<<"-"<<ref[i]<<"-";	
				}

		cout<<"\n";
					
		cout<<"\nLe nombre de pages uniques ***"<<verif.size()<<"*** \n";		
		cout<<"\n votre reference de pages uniques est : ";
			for(int i=0;i<tverif;i++)
				{
					cout<<"-"<<verif[i]<<"-";	
				}

		cout<<"\n";
		
			// Verification des infortions si elles sont correctes sinon l'utilisateur ressaisie les information depuis le depart
				
			while(tverif!=nbpages)
			{
				rep=0;
				tverif=0;
				ref.clear();
				verif.clear();
					cout<<"\nEntrer Des informations correctes , Vos nombres de pages uniques ne sont pas egales  au nombres de pages saisies \n ";
					
					cout<<"Retaper le nombre de Pages \n ";
					cin>>nbpages;
					
					cout<<" Retaper votre liste de references \t \t Apres avoir fini de saisir taper un nombre negatif pour continuer \n ";
					cin>>b;
	
					//		entrer des reference 
		 
	 				while (b>-1)
		 			{	
		 				ref.push_back(b);
		 		
		 			// DECOMPTES DES PAGES UNIQUES 
						nb=count(verif.begin(),verif.end(),b);
				
		 				if(nb<1)
				 		{
		 					verif.push_back(b);
		 				}
						cin>>b;
					}
				
					rep=ref.size();
					tverif=verif.size();	
			
					cout<<"\n les elements de votre reference "; // Affichages des reference de l'utilisateur
					nb=0;
		
					for(int i=0;i<rep;i++)
					{
					cout<<"-"<<ref[i]<<"-";
					
					}
					
					cout<<"\n \n Le nombre de pages uniques ***"<<verif.size()<<"*** \n";		
					cout<<"\n votre reference de pages uniques est : ";
					for(int i=0;i<tverif;i++)
					{
						cout<<"-"<<verif[i]<<"-";		
					}
					cout<<"\n";	
			}
			
	switch(choix)
	 {
		case 1 : 
		cout<<"\n Algorihme FIFO : First In First Out \n\n" ;
		cout<<fifo(nbcadres,ref);
		break;
						  			  
		case 2 :
		cout<<"\n Algorihme LRU : Least Recently Used \n\n" ;
		cout<<lru(nbcadres,ref);
		break ;
		 
		default : cout<<" Erreur ";
		break;
	}
	
	cout<<"\n";
  } while (choix==1 || choix==2);
 
}
