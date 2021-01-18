#include "vue.h"

Vue::Vue(){}

void Vue::clear(){
	std::cout << "\x1B[2J\x1B[H";
}

void Vue::affichageAjoutProduit(){
	clear();
	std::string titre="";
	std::string description="";
	int quantite;
	double prix;
	int choix;
	int choix2;
	
	std::cout << "1- Ajouter un produit" << std::endl;
	std::cout << "0- Retour" << std::endl;
	std::cin >> choix;
	
	switch(choix){
	case 1:
		std::cout<<"Rentrer les informations du produit"<<std::endl;
		std::getline(std::cin,titre);
		std::cout<<"Rentrer le titre"<<std::endl;
		std::getline(std::cin,titre);
		std::cout<<"Rentrer la description"<<std::endl;
		std::getline(std::cin,description);
		std::cout<<"Rentrer la quantité"<<std::endl;
		std::cin>>quantite;
		std::cout<<"Rentrer le prix"<<std::endl;
		std::cin>>prix;
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.AjoutProduit(titre,description,quantite,prix);
			affichageAjoutProduit();break;
		case 0:affichageAjoutProduit();break;	
		}
	break;
	case 0:affichageGestionProduit();break;
	}
}

void Vue::affichageSimpleProduit(){
	clear();
	std::string retour;
	_magasin.AffichageProduits();
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	affichageGestionProduit();
}

void Vue::affichageComplexeProduit(){
	clear();
	std::string nomP;
	std::string retour;
	std::cout << "Rentrer le nom de produit" << std::endl;
	std::cin >> nomP;
	_magasin.AffichageProduit(nomP);
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	affichageGestionProduit();
}

void Vue::affichageAjoutQuantiteProduit(){
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
		std::cout <<"Rentrer la quantité du produit"<<std::endl;
		std::cin >> quantite;
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.AjoutQuantiteProduit(id,quantite);
			affichageAjoutQuantiteProduit();break;
		case 0:affichageAjoutQuantiteProduit();break;	
		}break;
	case 0:affichageGestionProduit();break;
	}
}

void  Vue::affichageGestionProduit(){
	clear();
	std::cout << "Sélectionner votre choix : " << std::endl;
	std::cout << "1- Affichage des Produits" << std::endl;
	std::cout << "2- Affichage du Produit par son nom" << std::endl;
	std::cout << "3- Ajout du Produit" << std::endl;
	std::cout << "4- Ajout de la quantité du Produit" << std::endl;
	std::cout << "\n0- Retour" << std::endl;
	int choix;
	std::cin >> choix;
	
	switch(choix){
	case 1: affichageSimpleProduit();break;
	case 2: affichageComplexeProduit();break;
	case 3: affichageAjoutProduit();break;
	case 4: affichageAjoutQuantiteProduit();break;
	case 0:menu(_magasin);break;
	}
}

void Vue::affichageSimpleClient(){
	clear();
	std::string retour;
	_magasin.AffichageClients();
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	affichageGestionClient();
}

void Vue::affichageClientNP(){
	clear();
	std::string nomC;
	std::string prenomC;
	std::string retour;
	std::cout << "Rentrer le nom du Client" << std::endl;
	std::cin >> nomC;
	std::cout << "Rentrer le prénom du Client" << std::endl;
	std::cin >> prenomC;
	_magasin.AffichageClient(prenomC,nomC);
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	affichageGestionClient();
}

void Vue::affichageClientID(){
	clear();
	int idC;
	std::string retour;
	std::cout << "Rentrer l'ID du Client" << std::endl;
	std::cin >> idC;
	_magasin.AffichageClient(idC);
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	affichageGestionClient();
}

void Vue::affichageAjoutClient(){
	clear();
	std::string prenom="";
	std::string nom="";
	std::vector<Produit> panier;
	int choix;
	int choix2;
	
	std::cout << "1- Ajouter un Client" << std::endl;
	std::cout << "0- Retour" << std::endl;
	std::cin >> choix;
	
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
			affichageAjoutClient();break;
		case 0:affichageAjoutClient();break;	
		}
	break;
	case 0:affichageGestionClient();break;
	}
}

void Vue::identificationClient(){
	clear();
	std::string prenom;
	std::string nom;
	int id;
	std::cout << "Identification Client" << std::endl;
	std::cout << "Rentrer le prénom" << std::endl;
	std::cin >> prenom;
	std::cout << "Rentrer le nom" << std::endl;
	std::cin >> nom;
	std::cout << "Rentre l'ID" << std::endl;
	std::cin >> id;
	_prenom = prenom;
	_nom = nom;
	_id = id;
	affichageMenuClient();
}

void Vue::affichageGestionClient(){
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
	
	switch(choix){
	case 1: affichageSimpleClient();break;
	case 2: affichageClientNP();break;
	case 3: affichageClientID();break;
	case 4: affichageAjoutClient();break;
	case 5: identificationClient();break;
	case 0:menu(_magasin);break;
	}
}

void Vue::affichageInfo(){
	clear();
	std::string retour;
	_magasin.AffichageClient(_id);
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	affichageMenuClient();
}

void Vue::affichageAjoutPdtPanier(){
	clear();
	_magasin.AffichageProduits();
	int choix;
	int choix2;
	int id;
	int quantite;
	
	std::cout<<"1- Ajouter un produit au panier"<<std::endl;
	std::cout<<"0- Retour"<<std::endl;
	std::cin >> choix;
	
	switch(choix){
	case 1:
		std::cout<<"Rentrer l'ID du produit"<<std::endl;
		std::cin >> id;
		std::cout <<"Rentrer la quantité du produit"<<std::endl;
		std::cin >> quantite;
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.AjoutProduitPanier(id,_id,quantite);
			affichageAjoutPdtPanier();break;
		case 0:affichageAjoutPdtPanier();break;	
		}break;
	case 0:affichageMenuClient();break;
	}
}

void Vue::affichageSuppPdtPanier(){
	clear();
	_magasin.AffichageClient(_id);
	int choix;
	int choix2;
	int id;
	
	std::cout<<"1- Supprimer un produit du panier"<<std::endl;
	std::cout<<"0- Retour"<<std::endl;
	std::cin >> choix;
	
	switch(choix){
	case 1:
		std::cout<<"Rentrer l'ID du produit"<<std::endl;
		std::cin >> id;
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.SuppProduitPanier(id,_id);
			affichageSuppPdtPanier();break;
		case 0:affichageSuppPdtPanier();break;	
		}break;
	case 0:affichageMenuClient();break;
	}
}

void Vue::affichageModifQuantPanier(){
	clear();
	_magasin.AffichageClient(_id);
	int choix;
	int choix2;
	int id;
	int quantite;
	
	std::cout<<"1- Modifier la quantité d'un produit du panier"<<std::endl;
	std::cout<<"0- Retour"<<std::endl;
	std::cin >> choix;
	
	switch(choix){
	case 1:
		std::cout<<"Rentrer l'ID du produit"<<std::endl;
		std::cin >> id;
		std::cout<<"Rentrer la quantité"<<std::endl;
		std::cin >> quantite;
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.ModifQuantProdPanier(id,_id,quantite);
			affichageModifQuantPanier();break;
		case 0:affichageModifQuantPanier();break;	
		}break;
	case 0:affichageMenuClient();break;
	}
}

void Vue::affichageViderPanier(){
	clear();
	int choix;
	std::cout << "Vider le panier"<< std::endl;
	std::cout << "1- Confirmer"<<std::endl;
	std::cout << "0- Retour" <<std::endl;
	std::cin >> choix;
	
	switch(choix){
	case 1:_magasin.ViderPanier(_id);
		affichageMenuClient();
		break;
	case 0:affichageMenuClient();break;
	}
}

void Vue::affichageMenuClient(){
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
	
	switch(choix){
	case 1: affichageInfo();break;
	case 2: affichageAjoutPdtPanier();break;
	case 3: affichageSuppPdtPanier();break;
	case 4: affichageModifQuantPanier();break;
	case 5: affichageViderPanier();break;
	case 0: affichageGestionClient();break;
	}
}

/*void MajStatutCommande(int IdCommande, bool statusSouhaite);
	void AffichageCommandesDemandees();
	void AffichageCommandeDetail(int idCommande);
	void AffichageCommandeClient(int idClient);*/

void Vue::affichageMajStatutCommande(){
	clear();
	_magasin.AffichageCommandesDemandees();
	int choix;
	int choix2;
	int id;
	bool status;
	std::string s;
	
	std::cout<<"1- Mise a jour d'un status de commande"<<std::endl;
	std::cout<<"0- Retour"<<std::endl;
	std::cin >> choix;
	
	switch(choix){
	case 1:
		std::cout << "Selectionner l'ID de la Commande" << std::endl;
		std::cin >> id;
		std::cout << "Selectionner le status (true/false)" << std::endl;
		std::cin >> s;
		
		if(s=="true"){
		status=true;
		}else{
		status=false;
		}
		
		std::cout<<"\n1- Confirmer"<<std::endl;
		std::cout<<"0- Annuler"<<std::endl;
		std::cin >> choix2;
		switch(choix2){
		case 1:_magasin.MajStatutCommande(id,status);
			affichageMajStatutCommande();break;
		case 0:affichageMajStatutCommande();break;	
		}break;
	case 0:affichageGestionCommande();break;
	}
}

void Vue::affichageCommandesDemandees(){
	clear();
	std::string retour;
	_magasin.AffichageCommandesDemandees();
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	affichageGestionCommande();
}

void Vue::affichageCommandeClient(){
	clear();
	std::string retour;
	int id;
	std::cout<<"Rentrer l'ID du clien"<<std::endl;
	std::cin>>id;
	_magasin.AffichageCommandeClient(id);
	std::cout << "0- Retour" << std::endl;
	std::cin >> retour;
	affichageGestionCommande();
}

void Vue::affichageGestionCommande(){
	clear();
	std::cout << "Sélectionner votre choix : " << std::endl;
	std::cout << "1- Affichage des Commandes demandées" << std::endl;
	std::cout << "2- Affichage des Commandes d'un client" << std::endl;
	std::cout << "3- Mise à jour d'un status de commande" << std::endl;
	std::cout << "\n0- Retour" << std::endl;
	int choix;
	std::cin >> choix;
	
	switch(choix){
	case 1: affichageCommandesDemandees();break;
	case 2: affichageCommandeClient();break;
	case 3: affichageMajStatutCommande();break;
	case 0:menu(_magasin);break;
	}
}

void Vue::menu(Magasin magasin){
	_magasin = magasin;
	clear();
	std::cout << "Sélectionner votre choix : " << std::endl;
	std::cout << "1- Gestion Produit" << std::endl;
	std::cout << "2- Gestion Client" << std::endl;
	std::cout << "3- Gestion Commande" << std::endl;
	std::cout << "\n0- Quitter" << std::endl;
	int c;
	std::cin >> c;
	
	switch(c){
	case 1: affichageGestionProduit();break;
	case 2: affichageGestionClient();break;
	case 3: affichageGestionCommande();break;
	case 0:std::cout<<"\nAu revoir\n";break; 
	}
}
