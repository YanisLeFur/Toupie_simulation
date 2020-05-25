#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>

class Vecteur {
	private:
	
		std::vector<double> vecteur;

		bool meme_dimension(Vecteur const& comparaison) const; /*test si 2 vecteurs ont la meme dimension*/
		
	public:

		void verifier();

		size_t dimension() const;

        void augmente(double const& valeur); //augmente la dimension du vecteur par 1 et affecte valeur a la nouvelle composante

        double get_coord(size_t composante) const; //retourne les coordonees de la composante choisie

		explicit Vecteur(std::initializer_list<double> const& composantes);

        explicit Vecteur(std::vector<double> const& composantes); //constructeur qui prends une liste de composantes

        explicit Vecteur(double x, double y, double z); //constructeur qui cree un vecteur 3D

        explicit Vecteur(size_t dimension=3); //constructeur qui cree le vecteur nul d'une dimension donnee

        std::ostream& affiche(std::ostream& sortie) const; //affichage des composantes d'un vecteur

        bool operator==(Vecteur const& comparaison) const; //test si 2 vecteurs sont egaux

        bool operator!=(Vecteur const& comparaison) const; //test si 2 vecteurs ne sont pas egaux

        const Vecteur operator-() const; //retourne l'inverse additif du vecteur

        const Vecteur operator~() const; //retourne le vecteur unitaire dans la meme direction que le vecteur

        Vecteur& operator+=(Vecteur const& somme); //additionne le vecteur somme au premier vecteur

        Vecteur& operator-=(Vecteur const& soustraction); //soustrait le vecteur soustraction au premier vecteur

        Vecteur& operator*=(double scalaire); //multiplie le vecteur par un scalaire

        Vecteur& operator^=(Vecteur const& prod_vect); //affecte le produit vectoriel du vecteur courant avec le vecteur prod_vect au vecteur courant

        double operator*(Vecteur const& prod_scal) const; //retourne le produit scalaire de 2 vecteurs

        double norme() const; //retourne la norme euclidienne du vecteur

        double norme2() const; //retourne la norme euclidienne du vecteur eleve au carre
		
};
	
std::ostream& operator<<(std::ostream& sortie,Vecteur etre_affiche); //affiche les composantes d'un vecteur a travers cout

const Vecteur operator+(Vecteur v1, Vecteur const& v2); //retourne la somme de 2 vecteurs

const Vecteur operator-(Vecteur v1, Vecteur const& v2); //retourne la difference de 2 vecteurs

const Vecteur operator*(Vecteur v, double scalaire); //retourne la multiplication d'un vecteur par un scalaire

const Vecteur operator*(double scalaire, Vecteur v); //retourne la multiplication d'un vecteur par un scalaire

const Vecteur operator^(Vecteur v1, Vecteur const& v2); //retourne le produit vectoriel de 2 vecteurs


	
