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

    try{

    // notre support a dessin textuel

    TextViewer text(cout);

    //Intégrateurs---------------------

    IntegrateurRungeKutta RK;
    IntegrateurNewmark NM;
    IntegrateurEulerCromer EC;

    //----------------------------------

    // le systeme est simule numeriquement par l'integrateur de Runge-Kutta

    Systeme systeme(RK);

    // pas de temps pour l'integration des toupies

    double pas_de_temps(0.01);

    // on cree maintenant les objets qu'on va implementer

    // dans notre systeme

    // a noter que la construction de ces objets est identique

    // a celle de l'executable TestToupie

    // et donc toute les Toupies et leur construction

    // sont expliques la-bas

//ConeSimple-----------------------------------------------------------------------------------------------------------------------------------

    double masse_volumique_cone(0.1);
    double hauteur_cone(1.5);
    double rayon_cone(0.5);
    Vecteur P_cone({0,M_PI/6,0});
    Vecteur P_point_cone({0,0,60});

    double m_cone(masse_cone(masse_volumique_cone,hauteur_cone,rayon_cone));

    ConeSimple cone_simple(&text,m_cone,hauteur_cone,rayon_cone,P_cone,P_point_cone,Vecteur({1,1,1}));

//ToupieChinoise-----------------------------------------------------------------------------------------------------------------------------------

    double masse_volumique(0.1);
    double hauteur(0.02);
    double rayon(0.15);
    double m_chinoise(masse_chinoise(masse_volumique,hauteur,rayon));

    ToupieChinoise chinoise(&text,m_chinoise,hauteur,rayon,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur({1,2,3}));

//SolideRevolution---------------------------------------------------------------------------------------------------------------------------------

    vector<double> r_i;
    double r(0.01);
    double hauteur_sr(1.5);
    double masse_volumique_sr(0.1);

    for(int i(0); i<50 ; ++i) {
        r_i.push_back(r+i*(0.01));
    }

    SolideRevolution sr(&text,masse_volumique_sr,hauteur_sr,r_i,Vecteur(0,M_PI/6,0),Vecteur(0,0,200),Vecteur());

//==================================================================================================================================================

    // place les objets déclarées plus haut dans le systeme lui aussi déclaré tout en haut

    systeme.ajouter_Toupie(cone_simple);
    systeme.ajouter_Toupie(sr);
    systeme.ajouter_Toupie(chinoise);


    // affiche tout les objets dans le systeme

    cout<<systeme;

    // evolution du systeme

    cout<<"Le systeme evolue et se dessine a chaque pas de temps (dt="<<pas_de_temps<<") :"<<endl<<endl;

    // evolution du systeme selon un pas de temps et un nombre de fois (ici 2).

    systeme.evolue(pas_de_temps,2);

    // on change maintenant l'integrateur a celui d'Euler-Cromer

    // tout les objets de notre systeme sont maintenant

    // simule avec cette integrateur

    systeme.changer_integrateur(EC);



    }

    // la liste des erreurs peut se trouver dans le fichier constant.cc

    catch (int const& i) {
       affiche_erreur(i);
    }

    return 0;
}
