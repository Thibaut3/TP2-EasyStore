#include <iostream>
#include "vue.h"
#include <locale>


int main(int argc, wchar_t* argv[])
{
	/*setlocale(LC_CTYPE, "fra");
	Magasin micromania = Magasin("micromania");

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

	micromania.AjoutProduitPanier(0, 0, 5);
	micromania.AjoutProduitPanier(1, 0, 5);
	micromania.AffichageClient(0);
	micromania.SuppProduitPanier(1, 0);
	micromania.AffichageClient(0);
	micromania.ModifQuantProdPanier(0, 0, 2);
	micromania.AffichageClient(0);
	micromania.AffichageProduits();
	
	micromania.ValidationCommande(0);
	micromania.AffichageProduits();
	micromania.AffichageCommandesDemandees();
	micromania.AffichageCommandeDetail(0);
	micromania.AffichageCommandeClient(0);
	micromania.MajStatutCommande(0, true);

	micromania.~Magasin();
	*/
	Vue vue = Vue("micromania");
	vue.menu();
	
}