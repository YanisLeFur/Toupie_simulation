#pragma once
#include <array>
#include "Vecteur.h"
#include <iostream>

#ifndef M
#define M

class Matrice{
	private:

	std::array<std::array<double, 3>, 3> matrice; // on utilise la convention que le premier indice indique la ligne et le deuxieme la colonne 
	
	Matrice cofacteur() const; // retourne le matrice des cofacteurs de l'instance courante
	
	Matrice& verifier() ; // verifie si un des coefficient est < à une precision (par convention 1e-15) et le mettre à 0 si c'est le cas
	
	public:

	Matrice(double diag1=1.0, double diag2=1.0, double diag3=1.0); // constructeur qui construit une matrice diagonale en prenant 3 arguments
	
	Matrice(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33); // constructeur d'une matrice generale
	
	bool operator==(Matrice const& comparaison) const; // test l'egalite de 2 matrices
	
	bool operator!=(Matrice const& comparaison) const; // test l'inegalite de 2 matrices
	
	const Matrice operator-() const; // retourne l'oppose d'une matrice
	
	Matrice& operator+=(Matrice const& somme); // affecte la somme de 2 matrices dans l'instance courante
	
	Matrice& operator-=(Matrice const& soustraction); // affecte la difference de 2 matrices dans l'instance courante
	
	Matrice& operator*=(Matrice const& prod_mat); // affecte le produit de 2 matrices dans l'instance courante
	
	Matrice& operator*=(double const& scalaire); // affecte le produit d'un scalaire et une matrice dans l'instance courante
	
	Vecteur operator*=(Vecteur const& vecteur); // affecte le produit d'une matrice et un vecteur dans le vecteur passe en paramatre
	
	std::ostream& affiche(std::ostream& sortie) const; // affiche une matrice sur un flot de sortie passe en parametre
	
	Matrice transp() const; // retourne la transposee d'une matrice
	
	double det() const; // retourne le determinant de l'instance courante
	
    Matrice inv() const; // retourne l'inverse de l'instance courante
};

std::ostream& operator<<(std::ostream& sortie, Matrice etre_affiche);

const Matrice operator+(Matrice m1, Matrice const& m2);

const Matrice operator-(Matrice m1, Matrice const& m2);

const Matrice operator*(Matrice m1, Matrice const& m2);

const Matrice operator*(double const& scalaire, Matrice m2);

const Matrice operator*(Matrice m2, double const& scalaire);

const Vecteur operator*(Matrice m, Vecteur const& v);

#endif
	
