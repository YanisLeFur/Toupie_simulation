#include <iostream>
#include "Dessinable.h"
#include "Toupie.h"
#include "Systeme.h"
#include "constant.h"

using namespace std;


//Dessinable=========================================================================================
Dessinable::Dessinable(SupportADessin const& support): support(support.copie()) {}

Dessinable::Dessinable(SupportADessin* support): support(support) {}

Dessinable::~Dessinable() { delete support; }

//SupportADessin=====================================================================================

SupportADessin::~SupportADessin() {}

//TextViewer==========================================================================================

TextViewer::TextViewer(ostream& flot) :flot(flot) {}

void TextViewer::dessine(Toupie const& toupie) {flot<<"parametre : "<<toupie.getP() << endl <<"derivee : "<<toupie.getP_point()<<endl;}

void TextViewer::dessine(ConeSimple const& conesimple) {flot<<"parametre : "<<Vecteur(modulo_2pi(conesimple.getP().get_coord(1)),modulo_2pi(conesimple.getP().get_coord(2)),modulo_2pi(conesimple.getP().get_coord(3))) << endl
                                                            <<"derivee : "<<Vecteur(modulo_2pi(conesimple.getP_point().get_coord(1)),modulo_2pi(conesimple.getP_point().get_coord(2)),modulo_2pi(conesimple.getP_point().get_coord(3)))<<endl; }

void TextViewer::dessine(MasseTombe const& massetombe) {flot<<"parametre : "<< massetombe.getP() << endl <<"derivee : "<< massetombe.getP_point()<<endl;}
	
void TextViewer::dessine(Pendule const& pendule) {flot<<"parametre : "<<pendule.getP() << endl <<"derivee : "<<pendule.getP_point()<<endl;}

void TextViewer::dessine(ToupieChinoise const& chinoise) {flot<<"parametre : "<<Vecteur({modulo_2pi(chinoise.getP().get_coord(1)),modulo_2pi(chinoise.getP().get_coord(2)),modulo_2pi(chinoise.getP().get_coord(3)),chinoise.getP().get_coord(4),chinoise.getP().get_coord(5)}) << endl
                                                              <<"derivee : "<<Vecteur({modulo_2pi(chinoise.getP_point().get_coord(1)),modulo_2pi(chinoise.getP_point().get_coord(2)),modulo_2pi(chinoise.getP_point().get_coord(3)),chinoise.getP_point().get_coord(4),chinoise.getP_point().get_coord(5)})<<endl;}

void TextViewer::trace_G(Toupie const& toupie) {}

void TextViewer::trace_G(ConeSimple const& toupie) {}

void TextViewer::trace_G(MasseTombe const& toupie) {}

void TextViewer::trace_G(Pendule const& toupie) {}

SupportADessin* TextViewer::copie() const { return new TextViewer(*this); }

//====================================================================================================
