
#pragma once
#include <iostream>
#include <memory>
#include "Toupie.h"
#include "Integrateur.h"
//Systeme==========================================================================================================================
class Systeme{
	private:
	
        std::vector<std::unique_ptr<Toupie>> systeme; // comment expliquer que l'on prends unique_ptr de toupie
		
        Integrateur* integrateur; // regarde juste une façon d'integrer une toupie et donc ne possède pas réellement d'integrateur
		
	public:
	
        Systeme(Integrateur const& integrateur); // construit un systeme avec un pointeur sur un integrateur par rapport à un integrateur rentré en argument
		
        Systeme(Integrateur* integrateur); // construit un systeme avec un pointeur sur un integrateur

        ~Systeme();
		
        void changer_integrateur(Integrateur& nouvel_integrateur); // change l'integrateur
		
        void ajouter_Toupie(Toupie const& toupie); // ajoute une toupie dans le systeme

        //void enlever_Toupie(); // enleve la derniere toupie dans le systeme
		
        std::ostream& affiche(std::ostream& sortie) const; // appelle la fonction afficher des toupies du systeme
		
        void evolue(double const& pas_de_temps=0.01,unsigned int nb_fois=1); // integre et dessine toutes les toupies du systeme une ou plusieurs fois

        void integre(double const& pas_de_temps=0.01,unsigned int nb_fois=1); // integre toutes les toupies du systeme une ou plusieurs fois
		
        void dessine(); // dessine toutes les toupies du systeme

        void trace_G(); // trace le point G de toutes les toupies du systeme
};
	
	std::ostream& operator <<(std::ostream& sortie,Systeme const& systeme);

//==========================================================================================================================


