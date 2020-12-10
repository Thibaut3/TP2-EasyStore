#pragma once
#include <vector>
#include <iostream>
#include "produit.h"
#include "client.h"
#include "commande.h"

class Magasin
{
public:
	Magasin();

	void AjoutProduit(std::string titre, std::string description, int quantite, double prix);
	void AffichageProduits() const;
	void AffichageProduit(std::string titre) const;
	void AjoutQuantiteProduit(std::string titre, int quantité); //à n'utiliser que si vous êtes sûr que le produit existe
	
	void AjoutClient(std::string prenom, std::string nom, std::vector<Produit> panier);
	void AffichageClients() const;
	void AffichageClient( std::string prenom, std::string nom) const;
	void AffichageClient(int id);

	void AjoutProduit(Produit produit, int Id);
	void SuppProduit(Produit produit, int Id);
	void ModifQuantProd(Produit produit, int Id, int quantite);



private:
	
	std::vector<Produit*> m_products;
	std::vector<Client*> m_clients;
	std::vector<Commande*> m_orders;

	std::string Creationmenu(int typeLigne) const;


};

