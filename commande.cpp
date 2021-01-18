#include "commande.h"

//constructeur de la classe Commande
Commande::Commande(int id,Client client,std::vector<Produit> pdts,bool statut) : _id(id),_client(client), _pdtsCommand(pdts), _statut(statut){}

//retourne le statut de la commande
bool Commande::getStatut() const{
	return _statut;
}

//change le statut de la commande pour le statut passé en paramètre
void Commande::setStatut(bool statut){
	_statut = statut;
}

Client Commande::getClient() const
{
	return _client;
}

std::string Commande::AffichageSansDetail() const
{
	std::string id = std::to_string(_client.getID());
	std::string size = std::to_string(_pdtsCommand.size());
	return _id +  " " + _client.getPrenom() + "  " + _client.getNom() + id + "   " + size;
 
}

//surcharge de l'opérateur <<
std::ostream& operator << (std::ostream &out, const Commande &com){
	out << com._client.getID() << " " << com._client.getPrenom() << " " << com._client.getNom() << std::endl;
	for(std::size_t i=0; i < com._pdtsCommand.size(); i++){
		out << com._pdtsCommand.at(i).getTitre() << "	" << com._pdtsCommand.at(i).getDesc() << "		" << com._pdtsCommand.at(i).getPrixU() << std::endl;
	}
	if(com._statut == false){
		out << "\npas livrée" << std::endl;
	}else{
		out << "\nlivrée" << std::endl;
	}
	return out;
}
