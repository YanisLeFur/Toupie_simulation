#include <iostream>
#include <cmath>
#include "Toupie.h"
#include "constant.h"
#include "Vecteur.h"
#include "Dessinable.h"
#include <vector>

using namespace std;

int main(){

    try{

    // notre support a dessin textuel

    TextViewer text(cout);

//ConeSimple=======================================================================================================================================================

    cout << endl << "==========CONE SIMPLE==========" << endl << endl;

    double masse_volumique_cone(0.1);

    // on modelise un cone simple par une hauteur et un rayon

    double hauteur_cone(1.5);
    double rayon_cone(0.5);

    // le vecteur de parametre contient les angles d'Euler (psi,theta,phi)

    Vecteur P_cone({0,M_PI/6,0});
    Vecteur P_point_cone({0,0,60});

    // méthode calculant la masse d'un cône à partir d'une masse volumique, une hauteur et un rayon

    double m_cone(masse_cone(masse_volumique_cone,hauteur_cone,rayon_cone));

    // construction d'une toupie cônique avec:

    // un support à dessin, une masse, une hauteur, un rayon , un Vecteur de paramètre,

    // un Vecteur de dérivée des paramètre et un point de contact

    ConeSimple cone_simple(&text,m_cone,hauteur_cone,rayon_cone,P_cone,P_point_cone,Vecteur());

    cout<<"--------------------------------------"<<endl;

    // test l'affichage  des attributs d'un cone simple

    cout << cone_simple;

    // donne la position du centre de masse (G)

    cone_simple.trace_G();

    cout<<"--------------------------------------"<<endl;

    // donne les équations de mouvements/l'accélération d'une toupie conique

    cout << "Le vecteur d'acceleration du cone simple est : " << cone_simple.eq_mouv() << endl;

    cout<<"--------------------------------------"<<endl;

    // Energie totale de la toupie conique

    cout << "L'energie totale du cone simple est : " << cone_simple.E() << endl;

    cout<<"--------------------------------------"<<endl;

//Solide de Révolution==========================================================================================================================================================

    cout << endl << "==========SOLIDE REVOLUTION==========" << endl << endl;

    // le Solide de Revolution est le cadre le plus generale de notre toupie

    // on modelise un solide de revolution avec une hauteur

    double hauteur_sr(1.5);

    // une masse volumique

    double masse_volumique_sr(0.1);

    // et une liste de rayons

    // vector des rayons différents

    vector<double> r_i;

    // premier rayon

    double r(0.001);

    // une boucle for qui cree une liste de rayon qui augmente lineairement

    // ce qui approximerait un cone

    for(int i(0); i<500 ; ++i) {
        r_i.push_back(r+i*(0.001));
    }

    // Construction d'un solide de révolution à partir:

    // d'un support à dessin, une masse volumique, une hauteur,

    // un tableau des rayons différents, un Vecteur de paramètres,

    // un Vecteur dérivée de paramètre, un point de contact

    // à noter: ici on construit un solide de revolution

    // avec des attributs similaires

    // au cône vu plus haut pour vérifier que les

    // deux toupies ont les mêmes valeurs

    SolideRevolution sr(&text,masse_volumique_sr,hauteur_sr,r_i,Vecteur(0,M_PI/6,0),Vecteur(0,0,60),Vecteur());

    cout<<"--------------------------------------"<<endl;

    // test l'affichage  des attributs du solide de révolution

    cout << sr;

    //donne la position du centre de masse (G)

    sr.trace_G();

    cout<<"--------------------------------------"<<endl;

    // donne les équations de mouvements/l'accélération du solide de révolution

    // ce qui correspond en fait au equations du mouvement

    // d'une toupie generale

    cout << "Le vecteur acceleration de la toupie est " << sr.eq_mouv() << endl;

    cout<<"--------------------------------------"<<endl;

    // Energie totale du solide de revolution

    // qui correspond au cadre d'une toupie generale

    cout << "L'energie totale du solide de revolution est : " << sr.E() << endl;

    cout<<"--------------------------------------"<<endl;

//Toupie Chinoise==========================================================================================================================================================

    cout << endl << "==========TOUPIE CHINOISE==========" << endl<<endl;

    double masse_volumique(0.1);

    // on modelise une toupie chinoise avec une hauteur tronquee

    double hauteur(0.02);

    // et un rayon

    double rayon(0.15);

    // méthode calculant la masse d'une toupie chinoise à partir d'une masse volumique, une hauteur et un rayon

    double m_chinoise(masse_chinoise(masse_volumique,hauteur,rayon));

    // Construction d'une Toupie chinoise à partir:

    // d'un support à dessin, une masse, une hauteur, un rayon,

    // un Vecteur de paramètres, un Vecteur dérivée de paramètre, un point de contact

    ToupieChinoise chinoise(&text,m_chinoise,hauteur,rayon,Vecteur({0,0.11,0,0,0}),Vecteur({50,0,0,0,0}),Vecteur({1,2,3}));

    // le vecteur de parametres d'une toupie chinoise est de dimension 5

    // les premieres 3 dimensions correspondent au 3 angles d'Euler (psi,theta,phi)

    // les 2 dernieres composantes correspondent au translation P4 et P5

    // ou P4 est la translation dans le sens des x  du centre geometrique de la sphere C

    // et de meme pour P5 dans le sens des y

    // les 2 dernieres composantes du vecteur des derivees

    // correspondent donc a Cx et Cy, les coordonnees du point C

    cout<<"--------------------------------------"<<endl;

    // test l'affichage  des attributs d'une toupie chinoise

    cout << chinoise;

    //donne la position du centre de masse (G)

    chinoise.trace_G();

    cout<<"--------------------------------------"<<endl;

    // donne les équations de mouvements/l'accélération d'une toupie chinoise

    cout << "Le vecteur acceleration de la toupie chinoise est : " << chinoise.eq_mouv() << endl;

    cout<<"--------------------------------------"<<endl;


//Pendule==========================================================================================================================================================

    cout << endl << "=========PENDULE==========" << endl << endl;

    double masse_pendule(1);

    // Construction d'un pendule avec (Support à dessin, masse, Vecteur de paramètre, Vecteur de derivée des paramètres, Point de contact)

    // le point de contact du pendule correspond en faite a l'origine du fil au quel il est accroche

    // (avec ses coordonnees exprime en coordonnee cartesiennes)

    // on modelise le pendule en coordonnées cylindriques

    // c'est a dire le vecteur de parametre correspond a (r,theta,z), un rayon, un angle et une hauteur

    // (l'extension des coordonnees polaire en 3 dimensions)

    Pendule pendule(&text,masse_pendule,Vecteur({1,M_PI/6,0}),Vecteur({0,0,0}),Vecteur(0,1,2));

    // ce pendule correspond donc a une masse de 1kg

    // suspendu a un fil de longueur 1m (rayon initiale dans la construction du pendule)

    // tenu initiallement a un angle de 30 degrees par rapport a la verticale (angle initialle de PI/6)

    // lache avec une vitesse initialle nul (vecteur des derivees initiallement nul)

    // avec l'origine du fil situe a (0,1,2) en coordonnee cartesiennes

    cout<<"--------------------------------------"<<endl;

    // test l'affichage  des attributs d'un pendule

    cout << pendule;

    // donne la position du centre de masse (G)

    // qui est equivalent a sa position

    // car le pendule est un point materiel

    pendule.trace_G();

    cout<<"--------------------------------------"<<endl;

    // donne les équations de mouvements/l'accélération du pendule

    cout << "Le vecteur acceleration du pendule est : " << pendule.eq_mouv() << endl;

    // ceci correspond concretement a l'equation characteristique d'un pendule

    // theta_point_point = -g/l * sin(theta)

    cout<<"--------------------------------------"<<endl;

    // Energie potentielle du pendule

    // (correspondant a son energie gravitationelle)

    cout << "L'energie potentielle du pendule est : " << pendule.EP() << endl;

    // Energie cinétique du pendule

    // (proportionnelle a la vitesse du pendule)

    cout << "L'energie cinetique du pendule est : " << pendule.EC() << endl;

    // Energie totale du pendule

    // (reste constante car les forces sont conservatives)

    cout << "L'energie totale du pendule est : " << pendule.E() << endl;

    cout << "--------------------------------------" << endl;

//Masse qui tombe==========================================================================================================================================================

    cout << endl << "==========MASSE QUI TOMBE==========" << endl<<endl;

    // Construction d'une masse en chute libre à partir:

    // d'un support à dessin, une masse, un Vecteur de paramètres et un Vecteur dérivée de paramètre

    MasseTombe masse_tombe(&text,1,Vecteur({10,100,1}), Vecteur({2,2,1}));

    // on a donc une masse de 1kg avec une position initiale de (10,100,1) et

    // une vitesse initiale de (2,2,1)

    cout<<"--------------------------------------"<<endl;

    // test l'affichage  des attributs d'une masse en chute libre

    cout << masse_tombe;

    // donne la position du centre de masse (G)

    masse_tombe.trace_G();

    cout<<"--------------------------------------"<<endl;

    // donne les équations de mouvements/l'accélération de la masse en chute libre

    cout << "Le vecteur acceleration de la masse tombante est " << masse_tombe.eq_mouv() << endl;

    cout<<"--------------------------------------"<<endl;

    // Energie potentielle de la masse en chute libre

    // (energie gravifique)

    cout << "L'energie potentielle de la masse est : " << masse_tombe.EP() << endl;

    // Energie cinétique de la masse en chute libre

    cout << "L'energie cinetique de la masse est : " << masse_tombe.EC() << endl;

    //Energie totale de la masse en chute libre

    cout << "L'energie totale de la masse est : " << masse_tombe.E() << endl;

    cout<<"--------------------------------------"<<endl;

//Gestion des erreurs==========================================================================================================================================================

    cout << endl << "==========GESTION D'ERREURS==========" << endl << endl;

    // test d'un solide de revolution avec un de ses rayons negatif

    cout << "On essaye de construire un Solide de Revolution avec un de ses rayons negatif : ";

    vector<double> r_i_2({1,-1,1});

    try {
        SolideRevolution toupie_erreur_3(&text,1,1,r_i_2,P_cone,P_point_cone,Vecteur());
    }

    catch (int const& i) {
        affiche_erreur(i);
    }

    // test d'une toupie chinoise avec un vecteur de parametre de dimension 3

    cout << "On essaye de construire une ToupieChinoise avec un vecteur de parametre de dimension 3 : ";

    try {
        ToupieChinoise chinoise(&text,m_chinoise,hauteur,rayon,Vecteur({0,0.11,0}),Vecteur({50,0,0,0,0}),Vecteur({1,2,3}));
    }

    catch (int const& i) {
        affiche_erreur(i);
    }

    // la liste des erreurs qu'on gere

    // a noter que dans certain cas, l'erreur affiche peut

    // paraitre differente de ce que l'on pensait avoir

    // par exemple, un rayon nul d'un ConeSimple

    // implique que le constructeur de Toupie construit

    // une toupie avec un coefficient d'inertie I1 nul

    // car I1 est proportionelle au rayon pour un ConeSimple

    // l'erreur affiche serait donc celle de I1

    }

    catch(int const& i) {
        switch(i){
        case 1:cout << endl << endl << "Erreur : division par 0 impossible" << endl << endl;
        break;
        case 2:cout << endl << endl << "Erreur : dimension differente de 3" << endl << endl;
        break;
        case 3:cout << endl << endl << "Erreur : dimensions des vecteurs incompatibles" << endl << endl;
        break;
        case 4:cout << endl << endl << "Erreur : la composante voulu n'existe pas" << endl << endl;
        break;
        case 5:cout << endl << endl << "Erreur : masse de la toupie negative ou nulle"<< endl <<endl;
        break;
        case 6:cout << endl << endl << "Erreur : rayon de la toupie negatif ou nul"<< endl <<endl;
        break;
        case 7:cout << endl << endl << "Erreur : coefficient du tenseur d'inertie (I1) negatif ou nul"<< endl << endl;
        break;
        case 8:cout << endl << endl << "Erreur : coefficient du tenseur d'inertie (I3) negatif ou nul"<< endl << endl;
        break;
        case 9:cout << endl << endl << "Erreur : hauteur de la toupie negatif ou nulle"<< endl << endl;
        break;
        case 10:cout << endl << endl << "Erreur : theta du Vecteur de parametre de la toupie nul"<< endl << endl;
        break;
        case 11:cout << endl << endl << "Erreur : le solide de révolution ne comporte aucun rayon"<< endl << endl;
        break;
        case 12:cout << endl << endl << "Erreur : un des rayons du solide de revolution est negatif ou nul"<< endl << endl;
        break;
        case 13:cout << endl << endl << "Erreur : distance entre le centre de masse et le point de contact est negatif ou nul"<< endl << endl;
        break;
        case 14:cout << endl << endl << "Erreur : hauteur tronque superieur au rayon de la toupie chinoise"<< endl << endl;
        break;
        case 15:cout << endl << endl << "Erreur : hauteur tronque negative" << endl << endl;
        break;
        case 16:cout << endl << endl << "Erreur : masse volumique du solide de revolution est negative ou nulle" << endl << endl;
        break;
        case 17:cout << endl << endl << "Erreur : longueur du pendule negatif ou nul" << endl << endl;
        break;
        case 18:cout << endl << endl << "Erreur : cone simple avec un vecteur de parametre ou de derivee de dimension differente de 3" << endl << endl;
        break;
        case 19:cout << endl << endl << "Erreur : toupie chinoise avec un vecteur de parametre ou de derivee de dimension differente de 5" << endl << endl;
        break;
        case 20:cout << endl << endl << "Erreur : solide de revolution avec un vecteur de parametre ou de derivee de dimension differente de 3" << endl << endl;
        break;
        case 21:cout << endl << endl << "Erreur : masse qui tombe avec un vecteur de parametre ou de derivee de dimension differente de 3" << endl << endl;
        break;
        case 22:cout << endl << endl << "Erreur : pendule avec un vecteur de parametre ou de derivee de dimension differente de 3" << endl << endl;
        break;
        case 23:cout << endl << endl << "Erreur : point de contact du referentiel R_O de dimension differente de 3" << endl << endl;
        break;
        case 24:cout << endl << endl << "Erreur : coordonnee z du point de contact negatif" << endl << endl; // pour l'affichage graphique
        }
    }

    return  0;
}
