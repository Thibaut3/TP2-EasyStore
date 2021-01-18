#include "Magasin.h"

Magasin::Magasin()
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
	std::cout << "| Name          Description             Quantity     Price       |\n";
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
		std::cout << "| Details of a product                                           |\n";
		std::cout << Creationmenu(2);
		std::cout << "| Name          Description             Quantity     Price       |\n";
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

void Magasin::AffichageClient(int id)
{
	std::cout << Creationmenu(1);
	std::cout << *m_clients.at(id);
	std::cout << Creationmenu(1);
	std::cout << std::endl;
}

void Magasin::AjoutProduit(Produit produit, int Id)
{
	m_clients.at(Id)->addProduit(produit);
}

void Magasin::SuppProduit(Produit produit, int Id)
{
	m_clients.at(Id)->delProduit(produit);
}

void Magasin::ModifQuantProd(Produit produit, int Id, int quantite)
{
	m_clients.at(Id)->modifierQuant(produit, quantite);
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
