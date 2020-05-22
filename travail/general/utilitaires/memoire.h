#pragma once
#include "Vecteur.h"
#include <deque>

class Memoire{

    private:

           std::deque<Vecteur> points; // les points en memoire

           bool on; // si on veut utiliser la memoire ou pas

           size_t taille; // la taille de la memoire

     public:

           Memoire(bool on = true, size_t taille=75);

           std::deque<Vecteur> GetPoints();

           void ajouter_point(Vecteur const&);

           size_t getTaille();

           bool get_on();
};

