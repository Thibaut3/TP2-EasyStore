#include "Magasin.h"

Magasin::Magasin(std::string nomMagasin)
	: m_nomMagasin(nomMagasin),m_enregistrement(Enregistrement(nomMagasin))
{
}

void Magasin::AjoutProduit(std::string titre, std::string description, int quantite, double prix)
{
	bool produitexistant = false; //vérification de l'existance du produit
	for (int i = 0; i < m_products.size(); i++)
	{
		if (titre == m_products.at(i)->getTitre()) //produit existant
		{
			produitexistant = true;
			int nouvQuantite = m_products.at(i)->getQuantD() + quantite;
			m_products.at(i)->setQuant(nouvQuantite);
		}
	}

	if (!produitexistant) // produit non-existant
	{
		Produit* produit = new Produit(m_products.size() ,titre, description, quantite, prix);
		m_products.push_back(produit);
	}
}

void Magasin::AffichageProduits() const
{
	std::cout << Creationmenu(1);
	std::cout << "| Products                                                       |\n";
	std::cout << Creationmenu(2);
	std::cout << "| ID  Name          Description             Quantity     Price       |\n";
	std::cout << Creationmenu(2);
	
	for (int i = 0; i < m_products.size(); i++)
	{
		std::cout << "| " << *m_products.at(i) << " |\n";
		
	}
	std::cout << Creationmenu(1);
	std::cout << std::endl;
}

void Magasin::AffichageProduit(std::string titre) const
{
	int referenceProd = -1;
	for (int i = 0; i < m_products.size(); i++)
	{
		if (titre == m_products.at(i)->getTitre())
			referenceProd = i;
	}
	if (referenceProd >= 0)
	{
		std::cout << Creationmenu(1);
		std::cout << "| Details of a product                                         |\n";
		std::cout << Creationmenu(2);
		std::cout << "| ID Name          Description             Quantity     Price  |\n";
		std::cout << Creationmenu(2);
		std::cout << "| " << *m_products.at(referenceProd) << " |\n";
		std::cout << Creationmenu(1);
		std::cout << std::endl;
	}
	else
		std::cout << " Produit non trouvé \n";
}

void Magasin::AjoutQuantiteProduit(std::string titre, int quantité)
{
	AjoutProduit(titre," ",quantité,0);
}

void Magasin::AjoutQuantiteProduit(int IdProduit, int quantité)
{
	int nouvQuantite = m_products.at(IdProduit)->getQuantD() + quantité;
	m_products.at(IdProduit)->setQuant(nouvQuantite);
}



void Magasin::AjoutClient(std::string prenom, std::string nom, std::vector<Produit> panier)
{
	Client* client = new Client(m_clients.size(), prenom, nom, panier);
	m_clients.push_back(client);
}

void Magasin::AffichageClients() const
{
	std::cout << Creationmenu(1);
	std::cout << "| Client                                                         |\n";
	std::cout << Creationmenu(2);
	std::cout << "| Uid           Identity                                         |\n";
	std::cout << Creationmenu(2);
	for (int i = 0; i < m_clients.size(); i++)
	{
		std::cout << "| " << m_clients.at(i)->getID() << "  " << m_clients.at(i)->getPrenom() << " " << m_clients.at(i)->getNom() << "              |\n";

	}
	std::cout << Creationmenu(1);
	std::cout << std::endl;
}

void Magasin::AffichageClient(std::string prenom, std::string nom ) const
{
	int referenceClient = -1;
	for (int i = 0; i < m_clients.size(); i++)
	{
		if (prenom == m_clients.at(i)->getPrenom() && nom == m_clients.at(i)->getNom())
			referenceClient = i;
	}

	if (referenceClient >= 0)
	{
		std::cout << Creationmenu(1);
		std::cout << *m_clients.at(referenceClient);
		std::cout << Creationmenu(1);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Client non trouvé \n";
	}
}

void Magasin::AffichageClient(int IdClient)
{
	std::cout << Creationmenu(1);
	std::cout << *m_clients.at(IdClient);
	std::cout << Creationmenu(1);
	std::cout << std::endl;
}




void Magasin::AjoutProduitPanier(int IdProduit , int IdClient, int quantite)
{

	if (m_products.at(IdProduit)->getQuantD() >= quantite) // verif si il y a des stocks
	{
		Produit produit = *m_products.at(IdProduit);
		produit.setQuant(quantite);
		m_clients.at(IdClient)->addProduit(produit);
		std::cout << "Produit ajouté\n";
	}
	else
	{
		std::cout << "Il n'y a pas assez de stocks \n";
	}
}

void Magasin::SuppProduitPanier(int IdProduit, int IdClient)
{
	Produit produit(0,"", "", 0, 0);
	for (std::size_t i = 0; i < m_clients.at(IdClient)->getPanier().size(); i++)
	{
		if (m_clients.at(IdClient)->getPanier().at(i).getID() == IdProduit)
			produit = m_clients.at(IdClient)->getPanier().at(i);
	}
	m_clients.at(IdClient)->delProduit(produit);
	std::cout << "Produit supprimé\n";
}

void Magasin::ModifQuantProdPanier(int IdProduit, int IdClient, int quantite)
{
	Produit produit(0, "", "", 0, 0);
	for (std::size_t i = 0; i < m_clients.at(IdClient)->getPanier().size(); i++)
	{
		if (m_clients.at(IdClient)->getPanier().at(i).getID() == IdProduit)
			produit = m_clients.at(IdClient)->getPanier().at(i);
	}
	if (m_products.at(produit.getID())->getQuantD() >= quantite)
	{//verif si il y a des stocks
		m_clients.at(IdClient)->modifierQuant(produit, quantite);
		std::cout << "Quantite modifié\n";
	}
}

void Magasin::ViderPanier(int IdClient)
{
	m_clients.at(IdClient)->viderPanier();
}



void Magasin::ValidationCommande(int Idclient)
{
	Client client = *m_clients.at(Idclient);
	// verif si il y a des stocks + suppression stocks
	std::vector<Produit> produitsIndisponibles;
	for (int i = 0; i < client.getPanier().size(); i++)
	{
		if (client.getPanier().at(i).getQuantD() > m_products.at(client.getPanier().at(i).getID())->getQuantD())
			produitsIndisponibles.push_back(client.getPanier().at(i));
	}

	if (produitsIndisponibles.size() > 0)
	{
		//Afficher que les produits sont indisponibles
		std::cout << " Les produits indisponibles sont :\n";
		for (int j = 0; j < produitsIndisponibles.size(); j++)
		{
			std::cout << produitsIndisponibles.at(j).getTitre() << std::endl;
		}
	}
	else
	{
		// Suppresion des produits commandés des stocks
		for (int j = 0; j < client.getPanier().size(); j++) 
		{
			AjoutQuantiteProduit(client.getPanier().at(j).getID(), -client.getPanier().at(j).getQuantD());
		}
		
		// Creation commande
		Commande* commande = new Commande(m_orders.size(),client, client.getPanier(), false); 
		std::cout << *commande;
		m_orders.push_back(commande);

		client.viderPanier();
	}
}

void Magasin::MajStatutCommande(int IdCommande, bool statutSouhaite)
{
	if (m_orders.at(IdCommande)->getStatut() == statutSouhaite)
	{
		std::cout << " Le statut de votre commande était déjà similaire\n";
	}
	else
	{
		m_orders.at(IdCommande)->setStatut(statutSouhaite);
		std::cout << "Statut modifié\n";
	}
}


void Magasin::AffichageCommandesDemandees()
{
	std::cout << Creationmenu(1);
	std::cout << "| Commandes en attente                                           |\n";
	std::cout << Creationmenu(2);
	std::cout << "| IDCommande   Prenom       Nom         Uid     Taille Commande  |\n";
	std::cout << Creationmenu(2);
	for (int i = 0; i < m_orders.size() ; i++)
	{
		if (!m_orders.at(i)->getStatut())
		{
			std::cout << "| " << m_orders.at(i)->AffichageSansDetail() << "|\n";
		}
	}
	std::cout << Creationmenu(1);
	std::cout << std::endl;
}

void Magasin::AffichageCommandeDetail(int idCommande)
{
	std::cout << Creationmenu(1);
	std::cout << "| Commande" << idCommande << "                                |\n";
	std::cout << Creationmenu(2);
	std::cout << *m_orders.at(idCommande);
	std::cout << Creationmenu(2);
	std::cout << std::endl;
}

void Magasin::AffichageCommandeClient(int idClient)
{
	std::cout << Creationmenu(1);
	std::cout << "| Commande" << idClient << "                                |\n";
	std::cout << Creationmenu(2);
	for (int g = 0; g < m_orders.size(); g++)
	{
		if (m_orders.at(g)->getClient().getID() == idClient)
			std::cout << *m_orders.at(g);
	}

	std::cout << Creationmenu(2);
	std::cout << std::endl;
}



bool Magasin::VerificationIdProduitExistant(int idAVerifier)
{
	if (m_products.size() > idAVerifier)
	{
		return true; //l'id est attribué
	}
	else
	{
		return false; //l'id n'est pas attribué
	}
}

bool Magasin::VerificationNomProduitExistant(std::string nomP)
{
	bool retour = false;
	for (int i = 0; i < m_products.size(); i++)
	{
		if (m_products.at(i)->getTitre() == nomP )
			retour = true;
	}
	return retour;
}

bool Magasin::VerificationIdClientExistant(int idAVerifier)
{
	if (m_clients.size() > idAVerifier)
	{
		return true; //l'id est attribué
	}
	else
	{
		return false; //l'id n'est pas attribué
	}
}

bool Magasin::VerificationIdCommandeExistant(int idAVerifier)
{
	if (m_orders.size() > idAVerifier)
	{
		return true; //l'id est attribué
	}
	else
	{
		return false; //l'id n'est pas attribué
	}
}

bool Magasin::VerificationNomPrenomClientExistant(std::string nom, std::string prenom)
{
	bool retour = false;
	for (int i = 0; i < m_clients.size(); i++)
	{
		if (m_clients.at(i)->getNom() == nom && m_clients.at(i)->getPrenom() == prenom)
			retour = true;
	}
	return retour;
}


int Magasin::VerificationIdentificationClientExistant(int id,std::string nom, std::string prenom)
{
	int retour = 0;
	if (VerificationNomPrenomClientExistant(nom,prenom))
	{
		retour = 2;
	}
	if (m_clients.size() > id)
	{
		retour++; //l'id est attribué
		if (m_clients.at(id)->getNom() == nom && m_clients.at(id)->getPrenom() == prenom)
		{
			retour += 3;
		}
	}
	
	return retour; // 0 : rien n'est bon , 1 : id bon reste non, 2 : NP bon reste non ,3 : id et NP bon , 6 : tout est bon
}

bool Magasin::VerificationMenu(int choix, int max)
{
	if (choix >= 0 && choix <= max)
		return true;
	else
	{
		return false;
	}
}




Magasin::~Magasin()
{
	m_enregistrement.writeF(m_products, m_clients, m_orders);
	m_clients.~vector();
	m_orders.~vector();
	m_products.~vector();
}

std::string Magasin::Creationmenu(int typeLigne) const
{
	switch (typeLigne)
	{
	case 1:
		return "------------------------------------------------------------------\n";
		break;
	case 2:
		return "|----------------------------------------------------------------|\n"; 
		break;
	default:
		break;
	}
}
