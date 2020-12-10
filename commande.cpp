#include "commande.h"

//constructeur de la classe Commande
Commande::Commande(Client client,std::vector<Produit> pdts,bool statut) : _client(client), _pdtCommand(pdts), _statut(statut){}

//retourne le statut de la commande
bool Commande::getStatut() const{
	return _statut;
}

//change le statut de la commande pour le statut passé en paramètre
void Commande::setStatut(bool statut){
	_statut = statut;
}

//surcharge de l'opérateur <<
std::ostream& operator << (std::ostream &out, const Commande &com){
	out << com._client.getID() << " " << com._client.getPrenom() << " " << com._client.getNom() << std::endl;
	for(std::size_t i=0; i < com._pdtCommand.size(); i++){
		out << com._pdtCommand.at(i).getTitre() << "	" << com._pdtCommand.at(i).getDesc() << "		" << com._pdtCommand.at(i).getPrixU() << std::endl;
	}
	if(com._statut == false){
		out << "\npas livrée" << std::endl;
	}else{
		out << "\nlivrée" << std::endl;
	}
	return out;
}
