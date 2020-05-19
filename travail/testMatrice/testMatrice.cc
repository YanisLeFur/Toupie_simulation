#include <iostream>
#include "Matrice.h"
#include "Vecteur.h"
using namespace std;
int main(){
	Matrice mat1(-1,0,1,   // test la consruction d'une matrice en utilisant le constructeur qui prend 9 argument
	             4,2,-4,
	             1,1,-1);
	Matrice mat2(1,2,5);     // test la construction d'une matrice diagonale qui prend 3 arguments
    Matrice I;

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

	
	return 0;
}
