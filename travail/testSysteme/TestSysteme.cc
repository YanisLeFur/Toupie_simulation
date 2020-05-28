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

    ConeSimple cone_simple(&text,m_cone,hauteur_cone,rayon_cone,P_cone,P_point_cone,Vecteur());

//ToupieChinoise-----------------------------------------------------------------------------------------------------------------------------------

    double masse_volumique(0.1);
    double hauteur(0.02);
    double rayon(0.15);
    double m_chinoise(masse_chinoise(masse_volumique,hauteur,rayon));

    ToupieChinoise chinoise(&text,m_chinoise,hauteur,rayon,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur({1,2,3}));

//SolideRevolution---------------------------------------------------------------------------------------------------------------------------------

    vector<double> r_i;
    double r(0.001);
    double hauteur_sr(1.5);
    double masse_volumique_sr(0.1);

    for(int i(0); i<500 ; ++i) {
        r_i.push_back(r+i*(0.001));
    }

    SolideRevolution sr(&text,masse_volumique_sr,hauteur_sr,r_i,Vecteur(0,M_PI/6,0),Vecteur(0,0,60),Vecteur());

//==================================================================================================================================================

    // place les objets déclarées plus haut dans le systeme lui aussi déclaré tout en haut

    systeme.ajouter_Toupie(cone_simple);
    systeme.ajouter_Toupie(sr);
    systeme.ajouter_Toupie(chinoise);


    // affiche tout les objets dans le systeme

    cout<<systeme;

    // on change maintenant l'integrateur a celui d'Euler-Cromer

    // tout les objets de notre systeme sont maintenant

    // simule avec cette integrateur

    cout << "On change la methode d'integration a celle d'Euler-Cromer." << endl << endl;

    systeme.changer_integrateur(EC);

    // on a aussi la possibilite d'enlever la derniere toupie dans notre systeme

    cout << "On enleve la derniere Toupie de notre systeme." << endl << endl;

    systeme.enlever_Toupie();

    // affichage du systeme pour montrer ce qui a change

    cout << systeme;

    // evolution du systeme

    // on compare ici le comportement d'une toupie de type ConeSimple

    // avec celle d'une modelisation plus generale : un Solide de Revolution

    // avec une liste de rayons permettant d'approximer une forme conique

    cout << "Comparaison textuelle d'un ConeSimple et d'un Solide de Revolution (toupie generale) : " << endl << endl;

    cout<<"Le systeme evolue et se dessine a chaque pas de temps (dt="<<pas_de_temps<<") :"<<endl<<endl;

    // evolution du systeme selon un pas de temps et un nombre de fois (ici 300)

    // ici la simulation se deroule pendant 3 secondes

    systeme.evolue(pas_de_temps,300);

    }

    // la liste des erreurs peut se trouver dans le fichier constant.cc

    catch (int const& i) {
       affiche_erreur(i);
    }

    return 0;
}
