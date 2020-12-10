#include "produit.h"

//constructeur de la classe Produit
Produit::Produit(int id, std::string titre, std::string desc, int quantite, double prix) : _ID(id), _titre(titre), _description(desc), _quantiteDisp(quantite), _prixUnit(prix) {}

int Produit::getID() const {
	return _ID;
}

std::string Produit::getTitre() const {
	return _titre;
}

std::string Produit::getDesc() const {
	return _description;
}

int Produit::getQuantD() const {
	return _quantiteDisp;
}

double Produit::getPrixU() const {
	return _prixUnit;
}

void Produit::setTitre(std::string titre){
	_titre = titre;
}

void Produit::setDesc(std::string desc){
	_description = desc;
}
void Produit::setQuant(int quantite){
	_quantiteDisp = quantite;
}
void Produit::setPrixU(double prix){
	_prixUnit = prix;
}
