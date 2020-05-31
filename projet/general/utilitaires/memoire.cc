
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

void Memoire::setTaille(const size_t &t)
{
    taille=t;
}

bool Memoire::get_on(){return on;}
//=========================================================================================================
std::deque<Vecteur> Memoire::GetPoints(){
    return points;
}
//=========================================================================================================
Memoire::Memoire(bool on,size_t taille)
    :on(on),taille(taille){}
