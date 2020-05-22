#include <iostream>
#include "Systeme.h"
#include "Dessinable.h"
#include "Vecteur.h"
#include "Integrateur.h"
#include "Toupie.h"
#include "Matrice.h"
#include <cmath>
using namespace std;

int main(){

	TextViewer text(cout);
	IntegrateurRungeKutta RK;
	IntegrateurNewmark NM;
	IntegrateurEulerCromer EC;
	Systeme systeme(&NM);


    Vecteur P1(0.,0.523599,0.);
    Vecteur P1_point(0.,0.,60.);
    Vecteur P2(0.,0.785398,0.);
    Vecteur P2_point(0,0,40.);
    double h(1.5);
    double r(0.5);
    double m(masse_cone(0.1,h,r));
    double I1(3.*m/20.*(r*r+1./4.*h*h));
    double I3(3.*m/10.*r*r);
    double d((3./4.)*h);

    Toupie toupie(&text,m,P1,P1_point,I1,I3,d,Vecteur());
    ConeSimple cone1(&text,m,1.5,0.5,P1,P1_point,Vecteur());
    ConeSimple cone2(&text,masse_cone(0.1,0.5,1.5),1.5,0.5,P2,P2_point,Vecteur());


    toupie.get_m().ajouter_point(Vecteur({0,0,0}));
    cout<<"test: "<<toupie.get_m().GetPoints().size()<<endl;

    ToupieChinoise tc(&text,masse_chinoise(0.1,0.02,0.15),0.02,0.15,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur({0,0,0}));


    systeme.ajouter_Toupie(toupie);
    systeme.ajouter_Toupie(cone1);
    systeme.ajouter_Toupie(cone2);
    systeme.ajouter_Toupie(tc);
    cout<<systeme;
    cout<<endl;

    double dt(0.1);
    double nb_echantillons(10);
    double temps(0);

    for (int i(0); i <nb_echantillons; i++){

       cout << "temps: " << temps+i*dt << endl;
       cout << "=====cone=====" << endl;
       text.dessine(cone1);
       cout << "======toupie generale=====" << endl;
       text.dessine(toupie);
    }

	return 0;
}
