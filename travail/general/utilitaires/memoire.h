#pragma once
#include "Vecteur.h"
#include <deque>

class Memoire{
    private:
          std::deque<Vecteur> points;
           size_t taille;
     public:
           Memoire(size_t taille=50);
           std::deque<Vecteur> GetPoints();
           void ajouter_point(Vecteur const& );
           size_t getTaille();
};

