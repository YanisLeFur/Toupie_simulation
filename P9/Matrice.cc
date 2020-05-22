#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>
#include "constant.h"
#include "Matrice.h"
#include "Vecteur.h"
using namespace std;
//=========================================================================================================
//=========================================================================================================
Matrice& Matrice::verifier() {
	for (size_t i(0); i < matrice.size(); i++){
		for (size_t j(0); j < matrice[0].size(); j++){
			if (abs(matrice[i][j])<=precision) matrice[i][j]=0;
			else if (matrice[i][j]==0) matrice[i][j]=0;
		}
	}
	return *this;
}
//=========================================================================================================
Matrice::Matrice(double diag1, double diag2, double diag3)
:matrice({{{diag1,0,0},{0,diag2,0},{0,0,diag3}}})
{}
//=========================================================================================================
Matrice::Matrice(double a11, double a12, double a13, double a21,double a22, double a23, double a31, double a32, double a33)
:matrice({{{a11,a12,a13},{a21,a22,a23},{a31,a32,a33}}}){}
//=========================================================================================================
const Matrice Matrice::operator-() const {
	return -1*(*this);
}
//=========================================================================================================
bool Matrice::operator==(Matrice const& comparaison) const {
	for (size_t i(0); i<3; ++i) {
		for (size_t j(0); j<3; ++j) {
			if (matrice[i][j]!=comparaison.matrice[i][j]) return false;
		}
	}
	return true;
}
//=========================================================================================================
bool Matrice::operator!=(Matrice const& comparaison) const {
	return (not (*this==comparaison));
}
//=========================================================================================================
Matrice& Matrice::operator+=(Matrice const& somme) {
	for (size_t i(0); i<3; ++i) {
		for (size_t j(0); j<3; ++j) {
			matrice[i][j]+=somme.matrice[i][j];
		}
	}
	this->verifier();
	return *this;
}
//=========================================================================================================
Matrice& Matrice::operator-=(Matrice const& soustraction) {
	*this+=-soustraction;
	return *this;
}
//=========================================================================================================
Matrice& Matrice::operator*=(Matrice const& prod_mat) {
	const Matrice temp(*this);
	for(size_t i(0); i<matrice.size(); ++i) {
		for(size_t j(0); j<matrice[0].size(); ++j) {
			double produit_coefficient(0.0);
			for(size_t k(0); k<prod_mat.matrice[0].size(); ++k){
				produit_coefficient += temp.matrice[i][k]*prod_mat.matrice[k][j];
			}
			matrice[i][j] = produit_coefficient;
		}
	}
	this->verifier();
	return *this;
}
//=========================================================================================================
Matrice& Matrice::operator*=(double const& scalaire) {
	for (auto& ligne: matrice) {
		for (auto& composante: ligne) {
			composante*=scalaire;
		}
	}
	verifier();
	return *this;
}
//=========================================================================================================
Vecteur Matrice::operator*=(Vecteur const& vect) {
	if (vect.dimension()==3) {
        return Vecteur(matrice[0][0]*vect.get_coord(1)+matrice[0][1]*vect.get_coord(2)+matrice[0][2]*vect.get_coord(3),
                       matrice[1][0]*vect.get_coord(1)+matrice[1][1]*vect.get_coord(2)+matrice[1][2]*vect.get_coord(3),
                       matrice[2][0]*vect.get_coord(1)+matrice[2][1]*vect.get_coord(2)+matrice[2][2]*vect.get_coord(3)); }
    else throw 2;				       
}
//=========================================================================================================
ostream& operator<<(std::ostream& sortie, Matrice etre_affiche){
	return etre_affiche.affiche(sortie);
}
//=========================================================================================================
std::ostream& Matrice::affiche(std::ostream& sortie) const {
	for (size_t i(0); i<3; ++i) {
		sortie<<"[";
		for (size_t j(0); j<3; ++j) {
            sortie<<setw(8)<<matrice[i][j];
            sortie<<"  ";
		}
		sortie<<"]"<<endl;
	} 
	return sortie;
}
//=========================================================================================================
const Matrice operator+(Matrice m1, Matrice const& m2) {
	m1+=m2;
	return m1;
}
//=========================================================================================================
Matrice Matrice::transp() const {
	Matrice transp_(matrice[0][0],matrice[1][0],matrice[2][0],
					matrice[0][1],matrice[1][1],matrice[2][1],
					matrice[0][2],matrice[1][2],matrice[2][2]);
	return transp_;
}
//=========================================================================================================
double Matrice::det() const {

	double det( matrice[0][0]*(matrice[1][1]*matrice[2][2]-matrice[1][2]*matrice[2][1])
	-matrice[0][1]*(matrice[1][0]*matrice[2][2]-matrice[1][2]*matrice[2][0])
	+matrice[0][2]*(matrice[1][0]*matrice[2][1]-matrice[1][1]*matrice[2][0]));
	if(abs(det)<=precision){return 0;}
	else return det;
}
//=========================================================================================================
Matrice Matrice::cofacteur() const{
    Matrice m((matrice[1][1]*matrice[2][2]-matrice[2][1]*matrice[1][2]),
			-(matrice[1][0]*matrice[2][2]-matrice[2][0]*matrice[1][2]),
			 (matrice[1][0]*matrice[2][1]-matrice[2][0]*matrice[1][1]),
			-(matrice[0][1]*matrice[2][2]-matrice[2][1]*matrice[0][2]),
			 (matrice[0][0]*matrice[2][2]-matrice[2][0]*matrice[0][2]),
			-(matrice[0][0]*matrice[2][1]-matrice[0][1]*matrice[2][0]),
			 (matrice[0][1]*matrice[1][2]-matrice[1][1]*matrice[0][2]),
			-(matrice[0][0]*matrice[1][2]-matrice[1][0]*matrice[0][2]),
			 (matrice[0][0]*matrice[1][1]-matrice[1][0]*matrice[0][1]));
			 m.verifier();
	return m;
}				
//=========================================================================================================
Matrice Matrice::inv() const {
	if (det()!=0){
	    Matrice m(1/det()*(cofacteur()).transp());
	    m.verifier();
	    return m;
	}
	else throw 1;
}
//=========================================================================================================
const Matrice operator-(Matrice m1, Matrice const& m2) {
	m1-=m2;
	return m1;
}
//=========================================================================================================
const Matrice operator*(Matrice m1, Matrice const& m2) {
	m1*=m2;
	return m1;
}
//=========================================================================================================
const Matrice operator*(double const& scalaire, Matrice m) {
	return m*=scalaire;
}
//=========================================================================================================
const Matrice operator*(Matrice  m, double const& scalaire){
	m*=scalaire;
	return m;
}
//=========================================================================================================
const Vecteur operator*(Matrice m, Vecteur const& v){
	return m*=v;
}
//=========================================================================================================
//=========================================================================================================

	
