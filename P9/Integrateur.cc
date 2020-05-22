#include <iostream> 
#include "Integrateur.h"
#include "Vecteur.h"
#include "Toupie.h"
#include "constant.h"
#include <cmath>
using namespace std;


//Integrateur Euler-Cromer================================================================================
void IntegrateurEulerCromer::integre(double const& delta_t,Toupie& evolue){ 
    evolue.setP_point(evolue.getP_point()+delta_t*evolue.eq_mouv());
	evolue.setP(evolue.getP()+delta_t*evolue.getP_point());

}
//=========================================================================================================
Integrateur* IntegrateurEulerCromer::copie() const {
    return new IntegrateurEulerCromer(*this);
}
//=========================================================================================================
ostream& IntegrateurEulerCromer::affiche(std::ostream& sortie) const {
    sortie << "Integrateur d'Euler-Cromer";
    return sortie;
}
//=========================================================================================================
ostream& operator<<(ostream& sortie,IntegrateurEulerCromer const& etre_affiche) {
    return etre_affiche.affiche(sortie);
}
//=========================================================================================================
//Integrateur Newmark====================================================================================
void IntegrateurNewmark::integre(double const& delta_t,Toupie& evolue){
    P_precedent=evolue.getP();
    P_point_precedent=evolue.getP_point();
    s=evolue.eq_mouv();
    do {
        q=evolue.getP();
        r=evolue.eq_mouv();
        evolue.setP_point(P_point_precedent + (delta_t/2.0) * (r+s));
        evolue.setP( P_precedent + delta_t * P_point_precedent + (1/3.0) * (delta_t*delta_t) * (0.5*r+s) );
      } while(((evolue.getP()-q).norme())>=epsilon);
}
//=========================================================================================================
Integrateur* IntegrateurNewmark::copie() const {
    return new IntegrateurNewmark(*this);
}
//=========================================================================================================
ostream& IntegrateurNewmark::affiche(std::ostream& sortie) const {
    sortie << "Integrateur de Newmark";
    return sortie;
}
//=========================================================================================================
ostream& operator<<(ostream& sortie,IntegrateurNewmark const& etre_affiche) {
    return etre_affiche.affiche(sortie);
}
//=========================================================================================================
//Integrateur Runge-Kutta================================================================================
void IntegrateurRungeKutta::integre(double const& delta_t,Toupie& evolue){
    Vecteur k0(evolue.getP());
    k1=evolue.getP_point();
    k1_=evolue.eq_mouv();
    k2=k1+(delta_t/2.)*k1_;
    evolue.setP(k0+(delta_t/2.)*k1);
    evolue.setP_point(k1+(delta_t/2.)*k1_);
    k2_=evolue.eq_mouv();
    k3=k1+(delta_t/2.)*k2_;
    evolue.setP(k0+(delta_t/2.)*k2);
    evolue.setP_point(k1+(delta_t/2.)*k2_);
    k3_=evolue.eq_mouv();
    k4=k1+delta_t*k3_;
    evolue.setP(k0+delta_t*k3);
    evolue.setP_point(k1+delta_t*k3_);
    k4_=evolue.eq_mouv();
    evolue.setP(k0+(delta_t/6.)*(k1+2*k2+2*k3+k4));
    evolue.setP_point(k1+(delta_t/6.)*(k1_+2*k2_+2*k3_+k4_));
}
//=========================================================================================================
Integrateur* IntegrateurRungeKutta::copie() const {
    return new IntegrateurRungeKutta(*this);
}
//=========================================================================================================
ostream& IntegrateurRungeKutta::affiche(std::ostream& sortie) const {
    sortie << "Integrateur de Runge-Kutta";
    return sortie;
}
//=========================================================================================================
ostream& operator<<(ostream& sortie,IntegrateurRungeKutta const& etre_affiche) {
    return etre_affiche.affiche(sortie);
}
//============================================================================================================
//=============================================================================================================

Integrateur::~Integrateur()
{}
