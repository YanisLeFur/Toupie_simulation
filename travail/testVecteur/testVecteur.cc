#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "constant.h"

using namespace std;

int main(){

    try {

    // construction des vecteurs =========================================================================================

    cout << "Construction des Vecteurs : " << endl << endl;

    // un vecteur en 3D :

    Vecteur vect1(1.0, 2.0, -0.1);

    // declaration d'un vector pour tester la  deuxieme methode de construction

    vector<double> v({2.6, 3.5, 4.1});

    // un autre vecteur en 3D :

    Vecteur vect2(v);

    // copie du Vecteur 1

    Vecteur vect3(vect1);

    // affichage des vecteurs =========================================================================================

    cout << "Affichage des Vecteurs : " << endl << endl;

    cout << "Vecteur 1 : ";

    vect1.affiche(cout) << endl;

    // test de l'operateur <<

    cout << "Vecteur 2 : ";

    cout << vect2 << endl;

    cout << "Vecteur 3 : ";

    cout << vect3 << endl << endl;

    // test de l'egalite de 2 vecteurs =========================================================================================

    cout << "Test de l'egalite de 2 Vecteurs : " << endl << endl;

    cout << "Le Vecteur 1 est ";

    // test de l'operateur ==

    if (vect1==vect2) cout << "egal au";

    else cout << "different du";

    cout << " Vecteur 2," << endl << "et est ";

    // test de l'operateur !=

    if (vect1!=vect3) cout << "different du";

    else cout << "egal au";

    cout << " Vecteur 3." << endl << endl;

    // test l'addition et sa commutativite =========================================================================================

    cout << "Test l'addition et sa commutativite : " << endl << endl;

    cout << vect1 << " + " << vect2 << " = " << vect1+vect2 << endl;

    // test la commutativite de l'addition

    cout << vect2 << " + " << vect1 << " = " << vect2+vect1 << endl << endl;

    // construction du vecteur nul de dimension 3 (constructeur par default) =========================================================================================

    cout << "Construction du Vecteur nul et test de ses proprietes : " << endl << endl;

    Vecteur vect4;

    cout << "Vecteur 4 : ";

    cout << vect4 << endl;

    // test l'element neutre pour l'addition

    cout << vect1 << " + " << vect4 << " = " << vect1+vect4 << endl;

    cout << vect4 << " + " << vect1 << " = " << vect4+vect1 << endl << endl;

    // test de la soustraction =========================================================================================

    cout << "Test de la soustraction : " << endl << endl;

    cout << vect1 << " - " << vect2 << " = " << vect1-vect2 << endl;

    // test si la soustraction d'un vecteur a lui meme retourne le vecteur nul

    cout << vect2 << " - " << vect2 << " = " << vect2-vect2 << endl << endl;

    // construction d'un vecteur de dimension 2 =========================================================================================

    cout << "Construction d'un Vecteur de dimension 2 : " << endl << endl;

    Vecteur vect5({1,2});

    cout << "Vecteur 5 : ";

    cout << vect5 << endl << endl;

    // addition de deux vecteurs de dimensions differentes

    cout << "Addition de deux Vecteurs de dimensions differentes : " << endl << endl;

    try {
        cout << vect2 << " + " << vect5 << " = " << vect2+vect5 << endl;
    }

    catch(int const& i){
        affiche_erreur(i);
    }

    try {
        cout << vect5 << " + " << vect2 << " = " << vect5+vect2 << endl;
    }

    catch(int const& i){
        affiche_erreur(i);
    }

    // test de l'oppose d'un vecteur =========================================================================================

    cout << "Test de l'oppose d'un Vecteur : " << endl << endl;

    cout << "- " << vect1 << " = " << -vect1 << endl;

    cout << "- " << vect2 << " + " << vect1 << " = "  << -vect2+vect1 << endl << endl;

    // test de la multiplication d'un vecteur par un scalaire =========================================================================================

    cout << "Test de la multiplication d'un Vecteur par un scalaire : " << endl << endl;

    cout << 3 << " * " << vect1 << " = " << 3*vect1 << endl << endl;

    // test du produit scalaire entre deux vecteurs et de sa symetrie =========================================================================================

    cout << "Test du produit scalaire entre deux Vecteurs et de sa symetrie : " << endl << endl;

    cout << vect1 << " * " << vect2 << " = " << vect1*vect2 << endl;

    cout << vect2 << " * " << vect1 << " = " << vect2*vect1 << endl << endl;

    // test du produit vectoriel entre deux vecteurs de dimension 3 =========================================================================================

    cout << "Test du produit vectoriel entre deux Vecteurs de dimension 3 : " << endl << endl;

    cout << vect1 << " ^ " << vect2 << " = " << (vect1^vect2) << endl << endl;

    // test du produit vectoriel entre deux vecteurs de dimensions differentes de 3 =========================================================================================

    cout << "Test du produit vectoriel entre deux Vecteurs avec une dimension differente de 3 : " << endl << endl;

    try {
        cout << vect1 << " ^ " << vect5 << " = " << (vect1^vect5);
    }

    catch(int const& i){
        affiche_erreur(i);
    }

    // test de la norme d'un vecteur et de son carre =========================================================================================

    cout << "Test de la norme d'un Vecteur et de son carre : " << endl << endl;

    cout << "||" << vect1 << "|| = " << vect1.norme() << endl;

    cout << "||" << vect1 << "||^2 = " << vect1.norme2() << endl;

    cout << "||" << vect2 << "|| = " << vect2.norme() << endl;

    cout << "||" << vect2 << "||^2 = " << vect2.norme2() << endl << endl;

    // test du vecteur unitaire d'un vecteur non-nul =========================================================================================

    cout << "Test du Vecteur unitaire d'un Vecteur non-nul : " << endl << endl;

    cout << "Le Vecteur " << vect1 << " norme a 1 donne " << ~vect1 << endl << endl;

    // test du vecteur unitaire du vecteur nul =========================================================================================

    cout << "Test du Vecteur unitaire du Vecteur nul : " << endl << endl;

    try{
        cout << "Le Vecteur " << vect4 << " norme a 1 donne " << ~vect4;
    }

    catch(int const& i){
        affiche_erreur(i);
    }

    // test de la methode augmente =========================================================================================

    cout << "Test de la methode augmente : " << endl << endl;

    cout << "En augmentant le Vecteur " << vect4 << " d'une dimension avec la composante " << 5.3 << " on obtiens : " << endl << endl;

    vect4.augmente(5.3);

    cout << vect4 << endl << endl;

    // test de la methode get_coord =========================================================================================

    cout << "Test de la methode get_coord : " << endl << endl;

    cout << "La composante " << 3 << " du vecteur " << vect2 << " est : " << endl << endl;

    cout << vect2.get_coord(3) << endl << endl;

    // test de la gestion d'erreurs de la methode get_coord =========================================================================================

    cout << "Test de la gestion d'erreurs de la methode get_coord : " << endl << endl;

    cout << "La composante " << -1 << " du vecteur " << vect2 << " est : ";

    try{
        cout << vect2.get_coord(-1) << endl;
    }

    catch(int const& i){
        affiche_erreur(i);
    }

    cout << "La composante " << 5 << " du vecteur " << vect2 << " est : ";

    try{
        cout << vect2.get_coord(5) << endl;
    }

    catch(int const& i){
        affiche_erreur(i);
    }

    // test des operateurs += , -= , *= , et ^=  =========================================================================================

    cout << "Test des operateurs += , -= , *= , et ^= : " << endl << endl;

    cout << "Si on additionne le Vecteur " << vect3 << " au Vecteur " << vect1 << endl;

    // test l'operateur +=

    vect1+=vect3;

    cout << " on obtiens : " << vect1 << endl << endl;

    cout << "Si on soustrais le Vecteur " << vect3 << " au Vecteur " << vect2 << endl;

    // test l'operateur -=

    vect2-=vect3;

    cout << " on obtiens : " << vect2 << endl << endl;

    cout << "Si on multiplie le Vecteur " << vect3 << " par le scalaire " << 5 << endl;

    // test l'operateur *=

    vect3*=5;

    cout << " on obtiens : " << vect3 << endl << endl;

    cout << "Si on multiplie (produit vectoriel) le Vecteur " << vect3 << " par le Vecteur " << vect2 << endl;

    // test l'operateur ^=

    vect3 ^= vect2;

    cout << " on obtiens : " << vect3 << endl << endl;

    }

    catch(int const& i){
        switch(i){
        case 1:cerr << endl << endl << "Erreur: division par 0 impossible" << endl << endl;
        break;
        case 2:cerr << endl << endl << "Erreur: dimension differente de 3" << endl << endl;
        break;
        case 3:cerr << endl << endl << "Erreur: dimensions des vecteurs incompatibles" << endl << endl;
        break;
        case 4:cerr << endl << endl << "Erreur: la composante voulu n'existe pas" << endl << endl;
        break;
        }
    }

    // N.B.

    // les messages d'erreurs qui servent de test sont afficher avec cout

    // pour les avoir au bon endroit dans l'affichage

    // ceci apparaitront dans la meme couleur que le reste de l'affichage

    // si des erreurs innatendu adviennent, on les affichent avec cerr

    // les messages seront donc a la fin de l'affichage en rouge

    return 0;
}
