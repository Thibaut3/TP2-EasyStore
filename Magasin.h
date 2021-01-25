#pragma once
#include <vector>
#include <iostream>
#include "produit.h"
#include "client.h"
#include "commande.h"
#include "enregistrement.h"

class Magasin
{
public:
	Magasin(std::string nomMagasin);

	void AjoutProduit(std::string titre, std::string description, int quantite, double prix);
	void AffichageProduits() const;
	void AffichageProduit(std::string titre) const;
	void AjoutQuantiteProduit(std::string titre, int quantité); //à n'utiliser que si vous êtes sûr que le produit existe 
	void AjoutQuantiteProduit(int IdProduit, int quantité);
	
	void AjoutClient(std::string prenom, std::string nom, std::vector<Produit> panier);
	void AffichageClients() const;
	void AffichageClient( std::string prenom, std::string nom) const;
	void AffichageClient(int IdClient);

	void AjoutProduitPanier(int IdProduit, int IdClient, int quantite);
	void SuppProduitPanier(int IdProduit, int IdClient);
	void ModifQuantProdPanier(int IdProduit, int IdClient, int quantite);
	void ViderPanier(int IdClient);

	void ValidationCommande(int Idclient);
	void MajStatutCommande(int IdCommande, bool statusSouhaite);
	void AffichageCommandesDemandees();
	void AffichageCommandeDetail(int idCommande);
	void AffichageCommandeClient(int idClient);

	bool VerificationIdProduitExistant(int idAVerifier);
	bool VerificationNomProduitExistant(std::string nomP);
	bool VerificationIdClientExistant(int idAVerifier);
	bool VerificationIdCommandeExistant(int idAVerifier);
	bool VerificationNomPrenomClientExistant(std::string nom, std::string prenom);
	int VerificationIdentificationClientExistant(int id ,std::string nom, std::string prenom);
	bool VerificationMenu(int choix, int max);

	~Magasin();

private:
	std::string m_nomMagasin;

	std::vector<Produit*> m_products;
	std::vector<Client*> m_clients;
	std::vector<Commande*> m_orders;

	std::string Creationmenu(int typeLigne) const;
	Enregistrement m_enregistrement;

};

