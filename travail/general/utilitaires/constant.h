#pragma once
#include "Vecteur.h"

extern const double g; // constante de gravité

extern const Vecteur grav; // vecteur gravité

extern const double precision; // precision des doubles (1e-18)

extern const double PI; // constante PI

extern const double epsilon; // utilise dans l'integrateur de Newmark

double modulo_2pi(double angle);
