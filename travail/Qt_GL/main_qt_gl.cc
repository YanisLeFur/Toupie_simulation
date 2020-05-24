#include <QApplication>
#include "glwidget.h"
#include "Toupie.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w;
  VueOpenGL* v(w.get_Vue_ptr());
  Pendule p(v,1,Vecteur(2,3*M_PI/4,0),Vecteur(0,0,0),Vecteur(0,0,5),2);
  MasseTombe mt(v,1,Vecteur(0,0,0),Vecteur(0,5,5));
  ConeSimple c1(v,0.039270,1.5,0.5,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(4,4,0),psi_point);
  ConeSimple c2(v,0.039270,3,1.5,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(),phi_point,false);
  ToupieChinoise tc1(v,masse_chinoise(0.1,0.02,0.15),0.02,0.15,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur(0,0,0));
  ToupieChinoise tc2(v,0.7,0.1,0.3,Vecteur({0,0.5,0,0,0}),Vecteur({15,0,0,0,0}),Vecteur(0,0,0));
  vector<double> r_i;

  double r(0.1);
  double L(5);
  double rho(0.5);

  for(int i(0); i<3 ; ++i) {
      r_i.push_back(r+i);
  }

  SolideRevolution sr(v,rho,L,r_i,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur(),phi_point,false);

  //w.ajouter_Toupie(p);
  //w.ajouter_Toupie(mt);
  //w.ajouter_Toupie(tc1);
  //w.ajouter_Toupie(tc2);
  //w.ajouter_Toupie(c1);
  //w.ajouter_Toupie(c2);
  w.ajouter_Toupie(sr);
  //w.affiche(std::cout);
  w.show();
  return a.exec();
}
