
#include "memoire.h"
#include "Vecteur.h"
#include <deque>
//====================================================================================================
void Memoire::ajouter_point(Vecteur const& P){

    if (points.size()>=taille){
        points.pop_front();
    }
    points.push_back(P);
}

size_t Memoire::getTaille()
{return taille;}
//=========================================================================================================
std::deque<Vecteur> Memoire::GetPoints(){
    return points;
}
//=========================================================================================================
Memoire::Memoire(size_t taille)
    :taille(taille){}
