#include <iostream>

class ConeSimple;
class Toupie;
class MasseTombe;
class Systeme;
class Pendule;
class ToupieChinoise;
class SolideRevolution;

#ifndef S
#define S
//Support à Dessin=============================================================
class SupportADessin{
	public:
	
        virtual SupportADessin* copie() const = 0;
	
        virtual ~SupportADessin();

        virtual void dessine(Toupie const&) = 0;
		
		virtual void dessine(ConeSimple const&) = 0;

        virtual void dessine(Pendule const&) = 0;
		
		virtual void dessine(MasseTombe const&) = 0;

        virtual void dessine(ToupieChinoise const&) = 0;

        virtual void dessine(SolideRevolution const&) = 0;

        virtual void trace_G(ConeSimple&) = 0;

        virtual void trace_G(Toupie&) = 0;

        virtual void trace_G(MasseTombe&) = 0;

        virtual void trace_G(Pendule&) = 0;

        virtual void trace_G(ToupieChinoise&) = 0;

        virtual void trace_G(SolideRevolution&) = 0;
};

//Dessinable=============================================================
class Dessinable{
    protected:
	
		SupportADessin* support;
		
	public:
	    
        Dessinable(SupportADessin const& support);
	    
	    Dessinable(SupportADessin* support);
	    
	    virtual ~Dessinable();
	    
        virtual void dessine() const = 0;

        virtual void trace_G() = 0;
};

//TextViewer=============================================================
class TextViewer: public SupportADessin{
	private:
	
        std::ostream& flot; //permet à l'utilisateur de choisir ou sortir les informations
	
	public:
	
		TextViewer(std::ostream& flot);

        virtual void dessine(Toupie const&) override;//retourne les paramètres en texte  du vecteur P et P_point de la toupie
	
		virtual void dessine(ConeSimple const&) override;

        virtual void dessine(ToupieChinoise const&) override;

        virtual void dessine(SolideRevolution const&) override;
		
		virtual void dessine(MasseTombe const&) override;

        virtual void dessine(Pendule const&) override;

        virtual SupportADessin* copie() const override;

        virtual void trace_G(ConeSimple&)override;

        virtual void trace_G(Toupie&)override;

        virtual void trace_G(MasseTombe&)override;

        virtual void trace_G(Pendule&)override;

        virtual void trace_G(ToupieChinoise&)override;

        virtual void trace_G(SolideRevolution&)override;

};
//==========================================================================================================================
#endif
