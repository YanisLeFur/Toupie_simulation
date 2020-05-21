#include <QApplication>
#include "glwidget.h"
#include "Toupie.h"
#include "iostream"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w;
  VueOpenGL* v(w.get_Vue_ptr());
  //Pendule p(v,1,Vecteur({0,3*PI/4,0}),Vecteur({0,0,0}),2);
  //MasseTombe mt(v,1,Vecteur({0,0,0}),Vecteur({0,5,5}));
  ConeSimple c1(v,0.039270,1.5,0.5,Vecteur({0,PI/6,0}),Vecteur({0,0,200}),Vecteur(1,1,0));
  //ConeSimple c2(v,0.039270,0.5,0.5,Vecteur({0,PI/6,0}),Vecteur({0,0,200}),Vecteur());
  //ToupieChinoise tc1(v,masse_chinoise(0.1,0.02,0.15),0.02,0.15,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur({0,0,0}));
  //ToupieChinoise tc2(v,masse_chinoise(0.1,0.02,0.15),0.02,0.15,Vecteur({0,0.11,0,0,0}),Vecteur({20,0,0,0,0}),Vecteur({0,0,0}));
  // w.ajouter_Toupie(p);
  //w.ajouter_Toupie(mt);
  //w.ajouter_Toupie(tc1);
  //w.ajouter_Toupie(tc2);
  w.ajouter_Toupie(c1);
  //w.ajouter_Toupie(c2);
  ///w.affiche(std::cout);
  w.show();
  return a.exec();
}
