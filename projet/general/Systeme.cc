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
    integrateur=nullptr;
}
//=========================================================================================================
void Systeme::changer_integrateur(Integrateur& nouvel_integrateur) {
    integrateur = &nouvel_integrateur;
}
//=========================================================================================================
void Systeme::ajouter_Toupie(Toupie const& toupie) {
    systeme.push_back(toupie.copie());
}

void Systeme::enlever_Toupie()
{
    if (systeme.size()==0) throw 25;
    else systeme.pop_back();
}
//=========================================================================================================
ostream& Systeme::affiche(ostream& sortie) const {
    sortie<<"Le systeme est constitue des "<<systeme.size()<<" objets suivants (independants) :"<< endl << endl;
	for (size_t i(0);i<systeme.size();i++) {
        sortie<<"==== Objet "<<i+1<<" :"<<endl;
		systeme[i]->affiche(sortie);
		sortie<<endl;
	}

    sortie <<"et utilise un ";
    integrateur->affiche(sortie);
    sortie << "." << endl << endl;

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
    for (unsigned int i(0); i < nb_fois; ++i){
        cout<<"t = "<<i*pas_de_temps<<endl << endl;
        for(size_t k(0);k<systeme.size();k++){
           cout<<"Dessin de l'objet "<<k+1<<" : " << endl << endl;
           systeme[k]->dessine();
           cout << endl;
           integrateur->integre(pas_de_temps,*systeme[k]);
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

	
	
	

