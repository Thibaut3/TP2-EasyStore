#ifndef ENREGISTREMENT_H
#define ENREGISTREMENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "produit.h"
#include "client.h"
#include "commande.h"

//Classe Enregistrement de données
class Enregistrement{
public:
	Enregistrement(std::string nomFichier);
	void writeF(std::vector<Produit> pdts,std::vector<Client> clients,std::vector<Commande> commandes);
	void openF();
private:
	std::string _nFichier;
};
#endif
