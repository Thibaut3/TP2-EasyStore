#include <iostream>
#include "Magasin.h"


int main()
{
	Magasin micromania;

	micromania.AjoutProduit("PS5", "Tout nouveau !", 50, 599.99);
	micromania.AjoutProduit("Xbox One", "Incontournable", 40, 199.99);
	micromania.AjoutProduit("Switch", "Pour tous le monde", 60, 299.99);

	micromania.AffichageProduits();

	micromania.AffichageProduit("PS5");

	std::vector<Produit> panier;
	micromania.AjoutClient("Hubert", "Roche", panier );
	micromania.AffichageClient(0);
	micromania.AffichageClient("Hubert", "Roche");
	micromania.AffichageClients();


}