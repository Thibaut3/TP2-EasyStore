#ifndef COMMANDE_H
#define COMMANDE_H

#include <iostream>
#include <vector>
#include "client.h"
#include "produit.h"

/**
Classe commande
**/
class Commande{
public:
	Commande(Client client,std::vector<Produit> pdts,bool statut);
	bool getStatut() const;
	void setStatut(bool statut);
	
	//surcharge de l'opérateur <<
	friend std::ostream& operator << (std::ostream &out, const Commande &com);
private:
	Client _client; //Client de la commande
	std::vector<Produit> _pdtCommand; //Produit que le clien a commandé
	bool _statut; // statut de la commande (true = livrée, false = pas livrée)
};
#endif
