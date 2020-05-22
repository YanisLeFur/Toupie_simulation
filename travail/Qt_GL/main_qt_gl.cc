#include <QApplication>
#include "glwidget.h"
#include "Toupie.h"
#include "iostream"
#include <cmath>

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w;
  VueOpenGL* v(w.get_Vue_ptr());
  //Pendule p(v,1,Vecteur({0,3*M_PI/4,0}),Vecteur({0,0,0}),Vecteur(0,0,5),2);
  //MasseTombe mt(v,1,Vecteur({0,0,0}),Vecteur({0,5,5}));
  ConeSimple c1(v,0.039270,1.5,0.5,Vecteur({0,M_PI/6,0}),Vecteur({0,0,200}),Vecteur(4,4,0),psi_point);
  ConeSimple c2(v,0.039270,3,1.5,Vecteur({0,M_PI/6,0}),Vecteur({0,0,200}),Vecteur(),phi_point,false);
  ToupieChinoise tc1(v,masse_chinoise(0.1,0.02,0.15),0.02,0.15,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur({0,0,0}));
  ToupieChinoise tc2(v,masse_chinoise(10,0.2,1.5),0.2,1.5,Vecteur({0,0.11,0,0,0}),Vecteur({25,0,0,0,0}),Vecteur({0,0,0}));
  //w.ajouter_Toupie(p);
  //w.ajouter_Toupie(mt);
  //w.ajouter_Toupie(tc1);
  w.ajouter_Toupie(tc2);
  //w.ajouter_Toupie(c1);
  //w.ajouter_Toupie(c2);
  ///w.affiche(std::cout);
  w.show();
  return a.exec();
}
