#ifndef VUE_H
#define VUE_H

#include <iostream>
#include <vector>
#include <string>
#include "Magasin.h"

//Classe Vue
class Vue{
public:
	Vue(std::string nomMagasin);	
	void menu();
private:
	Magasin _magasin;
	
	//CLIENT
	std::string _prenom;
	std::string _nom;
	int _id;
	
	void clear();
	
	void _2_affichageGestionProduit();
	void _21_affichageSimpleProduit();
	void _22_affichageComplexeProduit();
	void _23_affichageAjoutProduit();
	void _24_affichageAjoutQuantiteProduit();
	
	void _3_affichageGestionClient();
	void _31_affichageSimpleClient();
	void _32_affichageClientNP();
	void _33_affichageClientID();
	void _34_affichageAjoutClient();
	
	void _4_affichageGestionCommande();
	void _41_affichageCommandesDemandees();
	void _411_affichageCommandeDetails();
	void _42_affichageCommandeClient();
	void _43_affichageMajStatutCommande();

	void _50_identificationClient();
	void _5_affichageMenuClient();
	void _51_affichageInfo();
	void _52_affichageAjoutPdtPanier();
	void _53_affichageSuppPdtPanier();
	void _54_affichageModifQuantPanier();
	void _55_affichageViderPanier();
	
	
};
#endif
