#ifndef VUE_H
#define VUE_H

#include <iostream>
#include <vector>
#include <string>
#include "Magasin.h"

//Classe Vue
class Vue{
public:
	Vue();	
	void menu(Magasin magasin);
private:
	Magasin _magasin;
	
	//CLIENT
	std::string _prenom;
	std::string _nom;
	int _id;
	
	void clear();
	
	void affichageGestionProduit();
	void affichageComplexeProduit();
	void affichageSimpleProduit();
	void affichageAjoutProduit();
	void affichageAjoutQuantiteProduit();
	
	void affichageGestionClient();
	void affichageSimpleClient();
	void affichageClientNP();
	void affichageClientID();
	void affichageAjoutClient();
	
	void identificationClient();
	void affichageMenuClient();
	void affichageInfo();
	void affichageAjoutPdtPanier();
	void affichageSuppPdtPanier();
	void affichageModifQuantPanier();
	void affichageViderPanier();
	
	void affichageGestionCommande();
	void affichageMajStatutCommande();
	void affichageCommandesDemandees();
	void affichageCommandeClient();
};
#endif
