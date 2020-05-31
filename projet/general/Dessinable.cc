#include <iostream>
#include <iomanip>
#include "Dessinable.h"
#include "Toupie.h"
#include "Systeme.h"
#include "constant.h"

using namespace std;


//Dessinable=========================================================================================
Dessinable::Dessinable(SupportADessin const& support): support(support.copie()) {}

Dessinable::Dessinable(SupportADessin* support): support(support) {}

Dessinable::~Dessinable() {
    //delete support;
    support = nullptr;
}

//SupportADessin=====================================================================================

SupportADessin::~SupportADessin() {}

//TextViewer==========================================================================================

TextViewer::TextViewer(ostream& flot) :flot(flot) {}

void TextViewer::dessine(ConeSimple const& conesimple) {
    flot<<"Parametre : "<<Vecteur(modulo_2pi(conesimple.getP().get_coord(1)),modulo_2pi(conesimple.getP().get_coord(2)),modulo_2pi(conesimple.getP().get_coord(3))) << endl
        <<"Derivee : "<<Vecteur(modulo_2pi(conesimple.getP_point().get_coord(1)),modulo_2pi(conesimple.getP_point().get_coord(2)),modulo_2pi(conesimple.getP_point().get_coord(3)))<<endl;
}

void TextViewer::dessine(MasseTombe const& massetombe) {
    flot<<"Parametre : "<< massetombe.getP() << endl <<"Derivee : "<< massetombe.getP_point()<<endl;
}

void TextViewer::dessine(Pendule const& pendule) {
    flot<<"Parametre : "<<pendule.getP() << endl <<"Derivee : "<<pendule.getP_point()<<endl;
}

void TextViewer::dessine(ToupieChinoise const& chinoise) {
    flot<<"Parametre : "<<Vecteur({modulo_2pi(chinoise.getP().get_coord(1)),modulo_2pi(chinoise.getP().get_coord(2)),modulo_2pi(chinoise.getP().get_coord(3)),chinoise.getP().get_coord(4),chinoise.getP().get_coord(5)}) << endl
        <<"Derivee : "<<Vecteur({modulo_2pi(chinoise.getP_point().get_coord(1)),modulo_2pi(chinoise.getP_point().get_coord(2)),modulo_2pi(chinoise.getP_point().get_coord(3)),chinoise.getP_point().get_coord(4),chinoise.getP_point().get_coord(5)})<<endl;
}

void TextViewer::dessine(SolideRevolution const& solide) {
    flot<<"Parametre : "<<Vecteur(modulo_2pi(solide.getP().get_coord(1)),modulo_2pi(solide.getP().get_coord(2)),modulo_2pi(solide.getP().get_coord(3))) << endl
        <<"Derivee : "<<Vecteur(modulo_2pi(solide.getP_point().get_coord(1)),modulo_2pi(solide.getP_point().get_coord(2)),modulo_2pi(solide.getP_point().get_coord(3)))<<endl;
}

void TextViewer::trace_G(ConeSimple& conesimple) {
    flot<<"Centre de masse : "<< conesimple.OG_O() << endl;
}

void TextViewer::trace_G(MasseTombe& massetombe) {
    flot<<"Centre de masse : "<< massetombe.OG_O() << endl;
}

void TextViewer::trace_G(Pendule& pendule) {
    flot<<"Centre de masse : "<< pendule.OG_O() << endl;
}

void TextViewer::trace_G(ToupieChinoise & chinoise)
{
    flot<<"Centre de masse : "<< chinoise.OG_O() << endl;
}

void TextViewer::trace_G(SolideRevolution& solide)
{
    flot<<"Centre de masse : "<< solide.OG_O() << endl;
}

SupportADessin* TextViewer::copie() const { return new TextViewer(*this); }

//====================================================================================================

void TextViewer::dessine(Toupie const&) {}

void TextViewer::trace_G(Toupie&) {}
