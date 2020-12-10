#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

class Produit{
public:
	Produit(int id, std::string titre, std::string desc, int quantite, double prix);
	int getID() const;
	std::string getTitre() const;
	std::string getDesc() const;
	int getQuantD() const;
	double getPrixU() const;
	void setTitre(std::string titre);
	void setDesc(std::string desc);
	void setQuant(int quantite);
	void setPrixU(double prix);
	friend std::ostream& operator << (std::ostream &out, const Produit &pdt){
		out << pdt._titre << ' ' << pdt._description << " (" << pdt._quantiteDisp << ") " << pdt._prixUnit << " $";
		return out;
	}
private :
	int _ID;
	std::string _titre;
	std::string _description;
	int _quantiteDisp;
	double _prixUnit;
};
#endif
