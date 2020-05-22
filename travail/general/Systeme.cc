#include <iostream>
#include "Toupie.h"
#include "Systeme.h"
#include "Integrateur.h"
using namespace std;
//=========================================================================================================
//=========================================================================================================
Systeme::Systeme(Integrateur const& integrateur) :integrateur(integrateur.copie()){}
//=========================================================================================================
Systeme::Systeme(Integrateur* integrateur) :integrateur(integrateur){}

Systeme::~Systeme()
{
    delete integrateur;
}
//=========================================================================================================
void Systeme::changer_integrateur(Integrateur& nouvel_integrateur) {
    integrateur = &nouvel_integrateur;
}
//=========================================================================================================
void Systeme::ajouter_Toupie(Toupie const& toupie) {
	systeme.push_back(toupie.copie());
}
//=========================================================================================================
ostream& Systeme::affiche(ostream& sortie) const {
    sortie<<"Le systeme est constitue des "<<systeme.size()<<" toupies suivantes (independantes) :"<<endl;
	for (size_t i(0);i<systeme.size();i++) {
        sortie<<"==== Toupie "<<i+1<<" :"<<endl;
		systeme[i]->affiche(sortie);
		sortie<<endl;
	}

    sortie << "====" << endl <<"et utilise un ";
    integrateur->affiche(sortie);
    sortie << "." << endl;

	return sortie;
}
//=========================================================================================================
void Systeme::integre(double const& pas_de_temps,unsigned int nb_fois) {
    for(auto& toupies:systeme){
        for (unsigned int i(0); i < nb_fois; ++i){
           integrateur->integre(pas_de_temps,*toupies);
        }
    }
}
//=========================================================================================================
void Systeme::evolue(double const& pas_de_temps,unsigned int nb_fois) {
    for(auto& toupies:systeme){
        for (unsigned int i(0); i < nb_fois; ++i){
           toupies->dessine();
           integrateur->integre(pas_de_temps,*toupies);
        }
    }
}
//=========================================================================================================
void Systeme::dessine(){
    for (auto& toupies: systeme) {
    toupies->dessine();
    }
}
//=========================================================================================================
void Systeme::trace_G(){
    for (auto& toupie: systeme) {
        if (toupie->get_trace_on()) toupie->trace_G();
    }
}
//=========================================================================================================
ostream& operator <<(ostream& sortie,Systeme const& etre_afficher){
     return etre_afficher.affiche(sortie);
}
//=========================================================================================================
//=========================================================================================================

	
	
	

