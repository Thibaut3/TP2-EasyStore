#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include "produit.h"

//Classe Client
class Client{
public:
	//Constructeur de la classe client
	Client(int id, std::string prenom, std::string nom, std::vector<Produit> panier);
	//Getter de la classe Client
	int getID() const;
	std::string getPrenom() const;
	std::string getNom() const;
	std::vector<Produit> getPanier() const;
	//Setter de la classe Client
	void setID(int id);
	void setPrenom(std::string prenom);
	void setNom(std::string nom);
	void setPanier(std::vector<Produit> panier);
	
	void addProduit(Produit pdt);
	void viderPanier();
	void modifierQuant(Produit pdt, int nbQ);
	void delProduit(Produit pdt);
	
	//surcharge de l'opérateur <<
	friend std::ostream& operator << (std::ostream &out, const Client &c);
private:
	int _id;
	std::string _prenom;
	std::string _nom;
	std::vector<Produit> _panier;
};
#endif
