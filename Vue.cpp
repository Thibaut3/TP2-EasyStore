#include "vue.h"

Vue::Vue(std::string nomMagasin)
 :_magasin(Magasin(nomMagasin))
{
}

void Vue::clear() {
	std::cout << "\x1B[2J\x1B[H";
}

void Vue::menu() {
	clear();
	std::cout << "Sélectionner votre choix : " << std::endl;
	std::cout << "1- Gestion Produit" << std::endl;
	std::cout << "2- Gestion Client" << std::endl;
	std::cout << "3- Gestion Commande" << std::endl;
	std::cout << "\n0- Quitter" << std::endl;
	int c;
	std::cin >> c;
	while (!_magasin.VerificationMenu(c,3))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> c;
	}
	switch (c) {
	case 1: _2_affichageGestionProduit();break;
	case 2: _3_affichageGestionClient();break;
	case 3: _4_affichageGestionCommande();break;
	case 0:std::cout << "\nAu revoir\n";_magasin.~Magasin();break;
	}
}

void Vue::_2_affichageGestionProduit() {
	clear();
	std::cout << "Sélectionner votre choix : " << std::endl;
	std::cout << "1- Affichage des Produits" << std::endl;
	std::cout << "2- Affichage du Produit par son nom" << std::endl;
	std::cout << "3- Ajout du Produit" << std::endl;
	std::cout << "4- Ajout de la quantité du Produit" << std::endl;
	std::cout << "\n0- Retour" << std::endl;
	int choix;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 4))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch (choix) {
	case 1: _21_affichageSimpleProduit();break;
	case 2: _22_affichageComplexeProduit();break;
	case 3: _23_affichageAjoutProduit();break;
	case 4: _24_affichageAjoutQuantiteProduit();break;
	case 0:menu();break;
	}
}

void Vue::_3_affichageGestionClient() {
	clear();
	std::cout << "Sélectionner votre choix : " << std::endl;
	std::cout << "1- Affichage des Clients" << std::endl;
	std::cout << "2- Affichage du Client par son nom et son prénom" << std::endl;
	std::cout << "3- Affichage du Client par son ID" << std::endl;
	std::cout << "4- Ajout d'un Client" << std::endl;
	std::cout << "5- Menu Client" << std::endl;
	std::cout << "\n0- Retour" << std::endl;
	int choix;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 5))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch (choix) {
	case 1: _31_affichageSimpleClient();break;
	case 2: _32_affichageClientNP();break;
	case 3: _33_affichageClientID();break;
	case 4: _34_affichageAjoutClient();break;
	case 5: _50_identificationClient();break;
	case 0:menu();break;
	}
}

void Vue::_4_affichageGestionCommande() {
	clear();
	std::cout << "Sélectionner votre choix : " << std::endl;
	std::cout << "1- Affichage des Commandes demandées" << std::endl;
	std::cout << "2- Affichage des Commandes d'un client" << std::endl;
	std::cout << "3- Mise à jour d'un status de commande" << std::endl;
	std::cout << "\n0- Retour" << std::endl;
	int choix;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 3))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch (choix) {
	case 1: _41_affichageCommandesDemandees();break;
	case 2: _42_affichageCommandeClient();break;
	case 3: _43_affichageMajStatutCommande();break;
	case 0:menu();break;
	}
}







void Vue::_21_affichageSimpleProduit(){
	clear();
	std::string retour;
	_magasin.AffichageProduits();
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	_2_affichageGestionProduit();
}

void Vue::_22_affichageComplexeProduit(){
	clear();
	std::string nomP;
	std::string retour;
	std::cout << "Rentrer le nom de produit" << std::endl;
	std::cin >> nomP;
	
	if (_magasin.VerificationNomProduitExistant(nomP))
	{
		_magasin.AffichageProduit(nomP);
	}
	else
	{
		do
		{
			std::cout << "Rentrer un nom de produit valide" << std::endl;
			std::cin >> nomP;
		} while (!_magasin.VerificationNomProduitExistant(nomP));
		_magasin.AffichageProduit(nomP);
	}

	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	_2_affichageGestionProduit();
}

void Vue::_23_affichageAjoutProduit() {
	clear();
	std::string titre = "";
	std::string description = "";
	int quantite;
	double prix;
	int choix;
	int choix2;

	std::cout << "1- Ajouter un produit" << std::endl;
	std::cout << "0- Retour" << std::endl;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 1))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch (choix) {
	case 1:
		std::cout << "Rentrer les informations du produit" << std::endl;
		std::getline(std::cin, titre);
		std::cout << "Rentrer le titre" << std::endl;
		std::getline(std::cin, titre);
		std::cout << "Rentrer la description" << std::endl;
		std::getline(std::cin, description);
		std::cout << "Rentrer la quantité" << std::endl;
		std::cin >> quantite;
		std::cout << "Rentrer le prix" << std::endl;
		std::cin >> prix;

		std::cout << "\n1- Confirmer" << std::endl;
		std::cout << "0- Annuler" << std::endl;
		std::cin >> choix2;
		switch (choix2) {
		case 1:_magasin.AjoutProduit(titre, description, quantite, prix);
			_23_affichageAjoutProduit();break;
		case 0:_23_affichageAjoutProduit();break;
		}
		break;
	case 0:_2_affichageGestionProduit();break;
	}
}

void Vue::_24_affichageAjoutQuantiteProduit(){
	clear();
	_magasin.AffichageProduits();
	int choix;
	int choix2;
	int id;
	int quantite;
	
	std::cout<<"1- Modifier la quantité d'un produit"<<std::endl;
	std::cout<<"0- Retour"<<std::endl;
	std::cin >> choix;
	
	switch(choix){
	case 1:
		std::cout<<"Rentrer l'ID du produit"<<std::endl;
		std::cin >> id;
		while (!_magasin.VerificationIdProduitExistant(id))
		{
			std::cout << "Rentrer un id de produit valide" << std::endl;
			std::cin >> id;
		}
		std::cout <<"Rentrer la quantité du produit"<<std::endl;
		std::cin >> quantite;
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.AjoutQuantiteProduit(id,quantite);
			_24_affichageAjoutQuantiteProduit();break;
		case 0:_24_affichageAjoutQuantiteProduit();break;	
		}break;
	case 0:_2_affichageGestionProduit();break;
	}
}



void Vue::_31_affichageSimpleClient(){
	clear();
	std::string retour;
	_magasin.AffichageClients();
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	_3_affichageGestionClient();
}

void Vue::_32_affichageClientNP(){
	clear();
	std::string nomC;
	std::string prenomC;
	std::string retour;
	std::cout << "Rentrer le nom du Client" << std::endl;
	std::cin >> nomC;
	std::cout << "Rentrer le prénom du Client" << std::endl;
	std::cin >> prenomC;
	while (!_magasin.VerificationNomPrenomClientExistant(nomC,prenomC))
	{
		std::cout << "Rentrer un nom du Client valide" << std::endl;
		std::cin >> nomC;
		std::cout << "Rentrer un prénom du Client valide" << std::endl;
		std::cin >> prenomC;
	}
	_magasin.AffichageClient(prenomC,nomC);
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	_3_affichageGestionClient();
}

void Vue::_33_affichageClientID(){
	clear();
	int idC;
	std::string retour;
	std::cout << "Rentrer l'ID du Client" << std::endl;
	std::cin >> idC;
	if (_magasin.VerificationIdClientExistant(idC))
	{
		_magasin.AffichageCommandeClient(idC);
		std::cout << "0- Retour" << std::endl;
	}
	else
	{
		do
		{
			std::cout << "Rentrer un ID du client valide" << std::endl;
			std::cin >> idC;
		} while (!_magasin.VerificationIdClientExistant(idC));
		_magasin.AffichageCommandeClient(idC);
		std::cout << "0- Retour" << std::endl;
	}
	std::cin >> retour;
	_3_affichageGestionClient();
}

void Vue::_34_affichageAjoutClient(){
	clear();
	std::string prenom="";
	std::string nom="";
	std::vector<Produit> panier;
	int choix;
	int choix2;
	
	std::cout << "1- Ajouter un Client" << std::endl;
	std::cout << "0- Retour" << std::endl;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 1))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch(choix){
	case 1:
		std::cout<<"Rentrer les informations du Client"<<std::endl;
		std::getline(std::cin,prenom);
		std::cout<<"Rentrer le prenom"<<std::endl;
		std::getline(std::cin,prenom);
		std::cout<<"Rentrer le Nom"<<std::endl;
		std::getline(std::cin,nom);
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.AjoutClient(prenom,nom,panier);
			_34_affichageAjoutClient();break;
		case 0:_34_affichageAjoutClient();break;	
		}
	break;
	case 0:_3_affichageGestionClient();break;
	}
}




void Vue::_41_affichageCommandesDemandees() {
	clear();
	std::string retour;
	int choix;
	_magasin.AffichageCommandesDemandees();
	std::cout << "1- Détails d'une commande" << std::endl;
	std::cout << "0- Retour" << std::endl;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 1))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch (choix)
	{
	case 1:
		_411_affichageCommandeDetails();
		break;

	case 0:_4_affichageGestionCommande();break;
	}
	_4_affichageGestionCommande();
}

void Vue::_411_affichageCommandeDetails()
{
	std::string retour;
	int id;
	std::cout << "Rentrer l'ID de la commande" << std::endl;
	std::cin >> id;
	while (!_magasin.VerificationIdCommandeExistant(id))
	{
		std::cout << "Rentrer un ID de commande valide" << std::endl;
		std::cin >> id;
	}
	_magasin.AffichageCommandeDetail(id);
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	_41_affichageCommandesDemandees();
}

void Vue::_42_affichageCommandeClient() {
	clear();
	std::string retour;
	int id;
	std::cout << "Rentrer l'ID du client" << std::endl;
	std::cin >> id;

	if (_magasin.VerificationIdClientExistant(id))
	{
		_magasin.AffichageCommandeClient(id);
		std::cout << "0- Retour" << std::endl;
	}
	else
	{
		do
		{
			std::cout << "Rentrer un ID du client valide" << std::endl;
			std::cin >> id;
		} while (!_magasin.VerificationIdClientExistant(id));
		_magasin.AffichageCommandeClient(id);
		std::cout << "0- Retour" << std::endl;
	}
	std::cin >> retour;
	_4_affichageGestionCommande();
}

void Vue::_43_affichageMajStatutCommande() {
	clear();
	_magasin.AffichageCommandesDemandees();
	int choix;
	int choix2;
	int id;
	bool status;
	std::string s;

	std::cout << "1- Mise a jour d'un status de commande" << std::endl;
	std::cout << "0- Retour" << std::endl;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 1))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch (choix) {
	case 1:
		std::cout << "Selectionner l'ID de la Commande" << std::endl;
		std::cin >> id;
		while (!_magasin.VerificationIdCommandeExistant(id))
		{
			std::cout << "Rentrer un ID de commande valide" << std::endl;
			std::cin >> id;
		}
		std::cout << "Selectionner le statut (true = livrée /false = non livrée )" << std::endl;
		std::cin >> s;

		if (s == "true") {
			status = true;
		}
		else {
			status = false;
		}

		std::cout << "\n1- Confirmer" << std::endl;
		std::cout << "0- Annuler" << std::endl;
		std::cin >> choix2;
		while (!_magasin.VerificationMenu(choix2, 1))
		{
			std::cout << "Sélectionner un choix valide " << std::endl;
			std::cin >> choix;
		}
		switch (choix2) {
		case 1:_magasin.MajStatutCommande(id, status);
			_43_affichageMajStatutCommande();break;
		case 0:_43_affichageMajStatutCommande();break;
		}break;
	case 0:_4_affichageGestionCommande();break;
	}
}




void Vue::_50_identificationClient(){
	clear();
	std::string prenom;
	std::string nom;
	int id;
	std::cout << "Identification Client" << std::endl;
	std::cout << "Rentrer le prénom" << std::endl;
	std::cin >> prenom;
	std::cout << "Rentrer le nom" << std::endl;
	std::cin >> nom;
	std::cout << "Rentrer l'ID" << std::endl;
	std::cin >> id;
	
	while (_magasin.VerificationIdentificationClientExistant(id,nom,prenom) < 5)
	{
		switch (_magasin.VerificationIdentificationClientExistant(id, nom, prenom))
		{
		case 0 : 
			std::cout << "Rentrer un ID du client valide" << std::endl;
			std::cin >> id;
			std::cout << " Rentrer un nom puis un prénom valide" << std::endl;
			std::cin >> nom;
			std::cin >> prenom;
			break;
		case 1 :
			std::cout << " Rentrer un nom puis un prénom valide" << std::endl;
			std::cin >> nom;
			std::cin >> prenom;
			break;
		case 2 :
			std::cout << "Rentrer un ID du client valide" << std::endl;
			std::cin >> id;
			break;
		case 3 :
			std::cout << "L'id et les noms ne correspondent pas" << std::endl;
			std::cout << "Rentrer l'ID du client " << std::endl;
			std::cin >> id;
			std::cout << " Rentrer le nom puis le prénom " << std::endl;
			std::cin >> nom;
			std::cin >> prenom;
			break;
		default : 
			break;
		}
	}
	_id = id;		
	_prenom = prenom;
	_nom = nom;
	
	_5_affichageMenuClient();
}

void Vue::_5_affichageMenuClient() {
	clear();
	std::cout << "Sélectionner votre choix : " << std::endl;
	std::cout << "1- Afficher Info" << std::endl;
	std::cout << "2- Ajout d'un produit dans le panier" << std::endl;
	std::cout << "3- Suppression d'un produit du panier" << std::endl;
	std::cout << "4- Modifier la quantité d'un produit du panier" << std::endl;
	std::cout << "5- Vider le panier" << std::endl;
	std::cout << "\n0- Retour" << std::endl;
	int choix;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 5))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch (choix) {
	case 1: _51_affichageInfo();break;
	case 2: _52_affichageAjoutPdtPanier();break;
	case 3: _53_affichageSuppPdtPanier();break;
	case 4: _54_affichageModifQuantPanier();break;
	case 5: _55_affichageViderPanier();break;
	case 0: _3_affichageGestionClient();break;
	}
}

void Vue::_51_affichageInfo(){
	clear();
	std::string retour;
	_magasin.AffichageClient(_id);
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	_5_affichageMenuClient();
}

void Vue::_52_affichageAjoutPdtPanier(){
	clear();
	_magasin.AffichageProduits();
	int choix;
	int choix2;
	int id;
	int quantite;
	
	std::cout<<"1- Ajouter un produit au panier"<<std::endl;
	std::cout<<"0- Retour"<<std::endl;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 1))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch(choix){
	case 1:
		std::cout<<"Rentrer l'ID du produit"<<std::endl;
		std::cin >> id;
		while (!_magasin.VerificationIdProduitExistant(id))
		{
			std::cout << "Rentrer un id de produit valide" << std::endl;
			std::cin >> id;
		}
		std::cout <<"Rentrer la quantité du produit"<<std::endl;
		std::cin >> quantite;
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.AjoutProduitPanier(id,_id,quantite);
			_52_affichageAjoutPdtPanier();break;
		case 0:_52_affichageAjoutPdtPanier();break;	
		}break;
	case 0:_5_affichageMenuClient();break;
	}
}

void Vue::_53_affichageSuppPdtPanier(){
	clear();
	_magasin.AffichageClient(_id);
	int choix;
	int choix2;
	int id;
	
	std::cout<<"1- Supprimer un produit du panier"<<std::endl;
	std::cout<<"0- Retour"<<std::endl;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 1))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch(choix){
	case 1:
		std::cout<<"Rentrer l'ID du produit"<<std::endl;
		std::cin >> id;
		while (!_magasin.VerificationIdProduitExistant(id))
		{
			std::cout << "Rentrer un id de produit valide" << std::endl;
			std::cin >> id;
		}
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.SuppProduitPanier(id,_id);
			_53_affichageSuppPdtPanier();break;
		case 0:_53_affichageSuppPdtPanier();break;	
		}break;
	case 0:_5_affichageMenuClient();break;
	}
}

void Vue::_54_affichageModifQuantPanier(){
	clear();
	_magasin.AffichageClient(_id);
	int choix;
	int choix2;
	int id;
	int quantite;
	
	std::cout<<"1- Modifier la quantité d'un produit du panier"<<std::endl;
	std::cout<<"0- Retour"<<std::endl;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 1))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch(choix){
	case 1:
		std::cout<<"Rentrer l'ID du produit"<<std::endl;
		std::cin >> id;
		while (!_magasin.VerificationIdProduitExistant(id))
		{
			std::cout << "Rentrer un id de produit valide" << std::endl;
			std::cin >> id;
		}
		std::cout<<"Rentrer la quantité"<<std::endl;
		std::cin >> quantite;
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.ModifQuantProdPanier(id,_id,quantite);
			_54_affichageModifQuantPanier();break;
		case 0:_54_affichageModifQuantPanier();break;	
		}break;
	case 0:_5_affichageMenuClient();break;
	}
}

void Vue::_55_affichageViderPanier(){
	clear();
	int choix;
	std::cout << "Vider le panier"<< std::endl;
	std::cout << "1- Confirmer"<<std::endl;
	std::cout << "0- Retour" <<std::endl;
	std::cin >> choix;
	while (!_magasin.VerificationMenu(choix, 1))
	{
		std::cout << "Sélectionner un choix valide " << std::endl;
		std::cin >> choix;
	}
	switch(choix){
	case 1:_magasin.ViderPanier(_id);
		_5_affichageMenuClient();
		break;
	case 0:_5_affichageMenuClient();break;
	}
}








