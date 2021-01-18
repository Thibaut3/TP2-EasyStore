#include "client.h"

//Constructeur de la classe Client
Client::Client(int id, std::string prenom, std::string nom, std::vector<Produit> panier) : _id(id), _prenom(prenom), _nom(nom), _panier(panier) {}

//GETTER

int Client::getID() const{
	return _id;
}

std::string Client::getPrenom() const{
	return _prenom;
}

std::string Client::getNom() const{
	return _nom;
}

std::vector<Produit> Client::getPanier() const{
	return _panier;
}

//SETTER

void Client::setID(int id){
	_id = id;
}

void Client::setPrenom(std::string prenom){
	_prenom = prenom;
}

void Client::setNom(std::string nom){
	_nom = nom;
}

void Client::setPanier(std::vector<Produit> panier){
	_panier = panier;
}

//Ajoute le produit passé en paramètre dans le panier
void Client::addProduit(Produit pdt){
	_panier.push_back(pdt);
}

//Vide le panier du client
void Client::viderPanier(){
	getPanier().clear();
}

//Modifie la quantité du produit passé en paramètre
void Client::modifierQuant(Produit pdt, int nbQ){
	for(std::size_t i = 0; i < getPanier().size(); ++i) //Pour tout les produits dans le panier
	{
		if (getPanier().at(i).getID() == pdt.getID()){//Si le produit courant est égale au produit passé en paramètre
			_panier.at(i).setQuant(nbQ);
			std::cout << nbQ << std::endl;
			std::cout << _panier.at(i) << std::endl;
		}
	}
}

//Supprime le produit passé en paramètre dans le panier
void Client::delProduit(Produit pdt){
	for(int i=0; i < getPanier().size(); i++)
	{
		if(getPanier().at(i).getID() == pdt.getID()){//Si le produit courant est égale au produit passé en paramètre
			_panier.erase(_panier.begin() + i);
		}
	}
}

//surcharge de l'opérateur <<
std::ostream& operator << (std::ostream &out, const Client &c){
	out << "ID = " << c._id << std::endl;
	out << "Prenom = " << c._prenom << std::endl;
	out << "Nom = " << c._nom << std::endl;
	out << "Produits dans le panier :" << std::endl;
	out << "| ID Name          Description             Quantity     Price       |" << std::endl;
	for(std::size_t i=0; i < c.getPanier().size(); i++){
		out << c.getPanier().at(i).getID() << "   " << c.getPanier().at(i).getTitre() << "	" << c.getPanier().at(i).getDesc() << "		" << c.getPanier().at(i).getQuantD() << "		" << c.getPanier().at(i).getPrixU() << std::endl;
	}
	return out;
}
