#include "enregistrement.h"

//Constructeur qui a comme param le nom du fichier où sont stockées les données
Enregistrement::Enregistrement(std::string nomFichier) : _nFichier(nomFichier){}

//Ecriture des données
void Enregistrement::writeF(std::vector<Produit> pdts,std::vector<Client> clients,std::vector<Commande> commandes){
	std::ofstream fichier(_nFichier);
	fichier << "Produits : \n";
	for( int i=0; i < pdts.size(); i++){
		fichier << pdts[i];
	}
	fichier << "Clients : \n";
	for( int i=0; i < clients.size(); i++){
		fichier << clients[i];
	}
	fichier << "Commandes : \n";
	for( int i=0; i < commandes.size(); i++){
		fichier << commandes[i];
	}
	fichier.close();
}

//Ouverture du fichier
void Enregistrement::openF(){
	std::ifstream fichierRead(_nFichier);
	while (getline (fichierRead, _nFichier)){
		std::cout << _nFichier <<"\n";
	}
	std::cout << "\n";
	fichierRead.close();
}
