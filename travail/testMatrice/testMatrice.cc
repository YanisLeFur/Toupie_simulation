#include <iostream>
#include "Matrice.h"
#include "Vecteur.h"
using namespace std;

int main(){
    // construction des matrices

    cout << "Construction des Matrices : " << endl << endl;

    // test du constructeur par default qui cree la matrice identite

    Matrice I;

    // test du constructeur qui prend 3 doubles et qui cree une matrice diagonale

    Matrice diag(1, 2, 3);

    // test du constructeur qui prend 9 doubles et qui cree une matrice ligne par ligne

    Matrice mat(1.1, 1.2, 1.3,
                2.1, 2.2, 2.3,
                3.1, 3.2, 3.3);

    Matrice mat2(1, 2, 0,
                 3, 4, 0,
                 0, 0, 1);

    // construction d'un vecteur pour tester la multiplication d'une matrice avec un vecteur

    Vecteur v(5.5, 6.6, 7.7);

    // affichage des matrices

    cout << "Affichage des Matrices : " << endl << endl;

    cout << "I : " << endl << endl << I << endl << endl;

    cout << "diag : " << endl << endl << diag << endl << endl;

    cout << "mat : " << endl << endl << mat << endl << endl;

    cout << "mat2 : " << endl << endl << mat2 << endl << endl;

    // test du calcul du determinant

    cout << "Test du calcul du determinant : " << endl << endl;

    cout << "det(I) = " << I.det() << endl << endl;

    cout << "det(diag) = " << diag.det() << endl << endl;

    cout << "det(mat) = " << mat.det() << endl << endl;

    cout << "det(mat2) = " << mat2.det() << endl << endl;

    // test de l'inverse

    cout << "Test de l'inverse : " << endl << endl;

    cout << "(I)^-1 = " << endl << endl << I.inv() << endl << endl;

    cout << "(diag)^-1 = " << endl << endl << diag.inv() << endl << endl;

    cout << "(mat2)^-1 = " << endl << endl << mat2.inv() << endl << endl;

    // test du calcul de l'inverse d'une matrice singuliere

    cout << "Test du calcul de l'inverse d'une Matrice singuliere : " << endl << endl;

    try{
        cout << "(mat)^-1 = " << mat.inv() << endl << endl;
    }

    catch(int const& i){
        switch(i){
        case 1:cout << endl << endl << "Erreur: division par 0 impossible" << endl << endl;
        break;
        case 2:cout << endl << endl << "Erreur: dimension differente de 3" << endl << endl;
        break;
        case 3:cout << endl << endl << "Erreur: dimensions des vecteurs incompatibles" << endl << endl;
        break;
        case 4:cout << endl << endl << "Erreur: la composante voulu n'existe pas" << endl << endl;
        break;
        }
    }

    // test de l'addition de deux matrices

    cout << "Test de l'addition de deux Matrices : " << endl << endl;

    cout << "mat + mat = " << endl << endl << mat+mat << endl << endl;

    // test de la soustraction de deux matrices

    cout << "Test de la soustraction de deux Matrices : " << endl << endl;

    cout << "mat - mat = " << endl << endl << mat-mat << endl << endl;

    cout << "diag - I = " << endl << endl << diag-I << endl << endl;

    // test de la multiplication d'une matrice par un scalaire

    cout << "Test de la multiplication d'une Matrice par un scalaire : " << endl << endl;

    cout << "4.4 * diag = " << endl << endl << 4.4*diag << endl << endl;

    cout << "2 * mat = " << endl << endl << 2*mat << endl << endl;

    // test de la multiplication d'une matrice et d'un vecteur de dimension 3

    cout << "Test de la multiplication d'une Matrice et d'un Vecteur de dimension 3 : "





    /*

	Matrice mat1(-1,0,1,   // test la consruction d'une matrice en utilisant le constructeur qui prend 9 argument
	             4,2,-4,
	             1,1,-1);
	Matrice mat2(1,2,5);     // test la construction d'une matrice diagonale qui prend 3 arguments


	          // test la construction par default de la matrice identite
	
	cout << " ================================ " << endl;
	
	cout << " Mat1 : " << endl; // affiche les matrices construites
	cout << mat1 << endl;
	cout << " Mat2 : " << endl;
	cout << mat2 << endl;
	cout << " I : " << endl;
    cout<<I<<endl;

	
	cout << " ================================ " << endl;
	
	Matrice mat3(mat1);                  // test la construction d'une copie
	
	cout << "La matrice 1 est ";
    if (mat1==mat2) {                    // test de l'operateur ==
    cout << "egale au";
    } else {
    cout << "differente de la";
    }
    cout << " matrice 2," << endl << "et est ";
    
    if (mat1!=mat3) {                    // test de l'operateur !=
    cout << "differente du";
    } else {
    cout << "egale a la";
    }
    cout << " matrice 3." << endl; 
    
    cout << " ================================ " << endl;
	
	cout << " Mat1+(-Mat1) : " << endl; // test le fonctionnement de l'opppose
	cout << mat1+(-mat1) << endl; 
	
	cout << " Mat1+Mat2 : " << endl; // test l'addition de 2 matrices
	cout << mat1+mat2 << endl;
	
	cout << " Mat2+Mat1 : " << endl; // test la commutativite de l'addition
	cout << mat2+mat1 << endl;
	
	cout << " Mat1-Mat2 : " << endl; // test la soustraction de 2 matrices
	cout << mat1-mat2 << endl;
	
	cout << " Mat2-Mat1 : " << endl; // test l'antisymmetrie de la soustraction
	cout << mat2-mat1 << endl; 
	
	cout << " 5*Mat1 : " << endl; // test la multiplication scalaire-matrice
	cout << 5*mat1 << endl;
	    
	cout << " Mat1*Mat2 : " << endl; // test le produit de 2 matrices
	cout << mat1*mat2 << endl;
	
	cout << " Mat2*Mat1 : " << endl; // test la non-commutativite de la multiplication matricielle
	cout << mat2*mat1 << endl;
	
	cout << " (Mat1)^T " << endl; // test le calcule de la transpose d'une matrice
	cout << mat1.transp() << endl;
	
	cout << " det(Mat1): " << endl; // test le calcul de determinant
	cout << mat1.det() << endl;
	
	cout << " (Mat1)^-1 : " << endl; // test le calcul de l'inverse
	
	try {                            // la matrice n'est pas inversible 
	cout << mat1.inv() << endl;
	}
	
	catch(int const& i){
	    switch(i){
		case 1:cerr << "Erreur: matrice non-inversible" << endl;
		case 2:cerr << "Erreur: dimension differente de 3" << endl;
	    }
    }
    
    cout << " (Mat2)^-1 : " << endl; // test le calcul de l'inverse
    cout << mat2.inv() << endl;

    Vecteur v(1,2,3);
    Matrice mat(-1,0,1,   // test la consruction d'une matrice en utilisant le constructeur qui prend 9 argument
                 4,2,-4,
                 1,1,-1);

    cout << "mat*v: " << mat*v;

    */

	return 0;
}
