#pragma once
#include "Vecteur.h"

extern const double g; // constante de gravité

extern const Vecteur grav; // vecteur gravité

extern const double precision; // precision des doubles (1e-18)

extern const double epsilon; // utilise dans l'integrateur de Newmark

double modulo_2pi(double angle); // utilise pour reduire les angles modulo 2*PI

enum Grandeur_physique{null,psi_point,theta_point,phi_point};//grandeurs utilisées pour l'affichage

void affiche_erreur(int const& i); // utiliser dans les catchs pour les erreurs
