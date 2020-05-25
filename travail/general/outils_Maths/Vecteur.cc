#include <iostream>
#include <vector>
#include <cmath>
#include <initializer_list>
#include "Vecteur.h"
#include "constant.h"

using namespace std;
//=========================================================================================================
//=========================================================================================================
	
bool Vecteur::meme_dimension(Vecteur const& comparaison) const {
	return (vecteur.size()==comparaison.vecteur.size());
}	
//=========================================================================================================
void Vecteur::verifier(){
	for (size_t i(0);i<vecteur.size();i++){
		if(abs(vecteur[i])<precision){
			vecteur[i]=0;
		}
	}
}
//=========================================================================================================
size_t Vecteur::dimension() const {
	return (*this).vecteur.size();
}
//=========================================================================================================
double Vecteur::get_coord(size_t composante)const{
    if((composante<=vecteur.size()) and (composante>0)) return vecteur[composante-1];
    else throw 3;
}
//=========================================================================================================
void Vecteur::augmente(double const& valeur) {
	vecteur.push_back(valeur);
}
//=========================================================================================================
Vecteur::Vecteur(vector<double> const& composantes) :vecteur(composantes) {}
//=========================================================================================================
Vecteur::Vecteur(initializer_list<double> const& composantes) :vecteur(composantes) {}
//=========================================================================================================
Vecteur::Vecteur(double x, double y, double z) :vecteur({x,y,z}) {}	
//=========================================================================================================
Vecteur::Vecteur(size_t dimension) :vecteur(vector<double>(dimension, 0.0)) {}
//=========================================================================================================
ostream& Vecteur::affiche(ostream& sortie) const {
	for (auto composante:vecteur) {
		sortie << composante << " ";
	}
	return sortie;
}	
//=========================================================================================================
bool Vecteur::operator==(Vecteur const& comparaison) const {
	if(meme_dimension(comparaison)) {
		for (size_t i(0); i < vecteur.size(); ++i) {
			if ((abs(vecteur[i]-comparaison.vecteur[i]))>precision) {
				return false;
			}
		}
		return true;	
	}
	else {
		return false;
	}	
}
//=========================================================================================================
bool Vecteur::operator!=(Vecteur const& comparaison) const {
	return (not (*this==comparaison));
}
//=========================================================================================================
const Vecteur Vecteur::operator-() const {
	Vecteur oppose(*this);
	for (auto& composante:oppose.vecteur) {
		    if (composante!=0) composante=-composante;
	}
	return oppose;
}
//=========================================================================================================
const Vecteur Vecteur::operator~() const {
	if (this->norme()!=0) {
		return (1/this->norme())*(*this);
	}
	else throw 1;
}
//=========================================================================================================
Vecteur& Vecteur::operator+=(Vecteur const& somme) {
	if(meme_dimension(somme)) {
		for (size_t i(0); i < vecteur.size(); ++i) {
			vecteur[i]+=somme.vecteur[i];
		}
		verifier();
		return *this;
	}
	
	else throw 3;
}
//=========================================================================================================
Vecteur& Vecteur::operator-=(Vecteur const& soustraction) {
	*this+=-soustraction;
	return *this;
}
//=========================================================================================================
Vecteur& Vecteur::operator*=(double scalaire) {
	for (auto& composante:vecteur) {
		composante*=scalaire;
		verifier();
	}
	return *this;
}
//=========================================================================================================
Vecteur& Vecteur::operator^=(Vecteur const& prod_vect) {
	if((prod_vect.vecteur.size()==3)and (vecteur.size()==3)){
        Vecteur temp({0,0,0});
        temp.vecteur[0]=vecteur[1]*prod_vect.vecteur[2]-vecteur[2]*prod_vect.vecteur[1];
        temp.vecteur[1]=-(vecteur[0]*prod_vect.vecteur[2]-vecteur[2]*prod_vect.vecteur[0]);
        temp.vecteur[2]=vecteur[0]*prod_vect.vecteur[1]-vecteur[1]*prod_vect.vecteur[0];
        vecteur=temp.vecteur;
		verifier();
		return *this;
	}
	else throw 2;
}
//=========================================================================================================
double Vecteur::operator*(Vecteur const& prod_scal) const {
	if (meme_dimension(prod_scal)) {
	    double produit_scalaire(0);
	    for (size_t i(0); i<vecteur.size(); ++i) {
			produit_scalaire += (vecteur[i]* prod_scal.vecteur[i]);
		}
		return produit_scalaire;
	}
	else throw 2;
}
//=========================================================================================================
double Vecteur::norme() const {
	Vecteur temp(*this);
	return sqrt(temp*temp);
}
//=========================================================================================================
double Vecteur::norme2() const {
	return pow(this->norme(),2);
}
//=========================================================================================================
ostream& operator<<(ostream& sortie, Vecteur etre_affiche) {
	return etre_affiche.affiche(sortie);
}
//=========================================================================================================
const Vecteur operator+(Vecteur v1, Vecteur const& v2) {
	v1+=v2;
	return v1;
}
//=========================================================================================================
const Vecteur operator-(Vecteur v1, Vecteur const& v2) {
	v1-=v2;
	return v1;
}
//=========================================================================================================
const Vecteur operator*(Vecteur v, double scalaire) {
	v*=scalaire;
	return v;
}
//=========================================================================================================
const Vecteur operator*(double scalaire, Vecteur v) {
	v*=scalaire;
	return v;
}
//=========================================================================================================
const Vecteur operator^(Vecteur v1, Vecteur const& v2) {
	v1^=v2;
	return v1;
}
	
//=========================================================================================================
//=========================================================================================================


	
	
	
	

