#include <iostream>
#include <cmath>
#include <memory>
#include "Vecteur.h"
#include "Matrice.h"
#include "Toupie.h"
#include "constant.h"
#include "memoire.h"
using namespace std;

//Toupie====================================================================================================================================

Toupie::~Toupie(){}

	Vecteur Toupie::getP() const {return P;}

    Vecteur Toupie::getP_point() const {return P_point;}

    Vecteur Toupie::get_OA() const {return OA;}

    Memoire Toupie::get_m() const{return m;}

    Grandeur_physique Toupie::get_Grandeur() const {return grandeur;}

    bool Toupie::get_trace_on() {return m.get_on();}

    void Toupie::changer_grandeur(Grandeur_physique g) {grandeur=g;}

    void Toupie::setP(Vecteur const& v) {
      if(P.dimension()!=v.dimension()){throw 3;}
        P=v;
    }

    void Toupie::setP_point(Vecteur const& v) {
        if(P.dimension()!=v.dimension()){throw 3;}
        P_point=v;
    }

    void Toupie::ajouter_point_memoire(Vecteur const& v){
        m.ajouter_point(v);
    }

    Toupie::Toupie(SupportADessin* support,double masse,Vecteur P,Vecteur P_point,double I1,double I3,double distance,Vecteur OA,Grandeur_physique grandeur, bool trace_on)
        :Dessinable(support),masse(masse),P(P),P_point(P_point),I1(I1),I3(I3),distance(distance),OA(OA),grandeur(grandeur),m(Memoire(trace_on)){
        if (masse<=0) throw 5;
        if (I1<=0) throw 7;
        if (I3<=0) throw 8;
        if (distance<=0) throw 13;
        if (OA.dimension()!=3) throw 23;
        if (OA.get_coord(3)<0) throw 24;
    }
	
    ostream& Toupie::affiche(ostream& sortie) const {
    sortie  <<"Toupie Generale : " << endl
            <<"Masse (kg) : "<<masse<<endl
			<<"I1 : "<<I1<<endl
			<<"I3 : "<<I3<<endl
			<<"Vecteur P : "<<P<<endl
            <<"Derivee de P : "<<P_point<<endl
            <<"Point de contact : "<<OA<<endl;
			return sortie;
	}


    Vecteur Toupie::eq_mouv() const {
        return Vecteur(psi_point_point(),theta_point_point(),phi_point_point());
    }

    Vecteur Toupie::omega_G() const {
        return Vecteur(getP_point().get_coord(2),
                       getP_point().get_coord(1)*sin(getP().get_coord(2)),
                       getP_point().get_coord(1)*cos(getP().get_coord(2))+getP_point().get_coord(3));
    }

    Vecteur Toupie::omega_O() const {
        return GtoO(omega_G());
    }

    Vecteur Toupie::omega_point_G() const {
        return IA_G().inv()*(MA_G()-((omega_e_G())^(IA_G()*omega_G()))-IA_point()*omega_G());

    }

    Vecteur Toupie::omega_point_O() const {
        return GtoO(omega_point_G());
    }

    Vecteur Toupie::omega_e_G() const {
        return omega_G()-Vecteur(0,0,P_point.get_coord(3));
    }

    Vecteur Toupie::omega_e_O() const {
        return GtoO(omega_e_G());
    }

    double Toupie::psi_point_point() const {
        if (P.get_coord(2)!=0) return ((omega_point_G().get_coord(2)-P_point.get_coord(1)*P_point.get_coord(2)*cos(P.get_coord(2)))/sin(P.get_coord(2)));
        else return 0;
    }

    double Toupie::theta_point_point() const {
        return omega_point_G().get_coord(1);
    }

    double Toupie::phi_point_point() const {
        if (P.get_coord(2)!=0) return omega_point_G().get_coord(3)+(P_point.get_coord(1)*P_point.get_coord(2)-omega_point_G().get_coord(2)*cos(P.get_coord(2)))/sin(P.get_coord(2));
        else return omega_point_G().get_coord(3);
    }

    Vecteur Toupie::MA_G() const {
        return AG_G()^P_G();
    }

    Vecteur Toupie::MA_O() const {
        return AG_O()^P_O();
    }

    Matrice Toupie::IG_G() const {
       return Matrice(I1,I1,I3);
    }

    Matrice Toupie::IG_O() const {
        return S_().transp()*IG_G()*S_();
    }

    Matrice Toupie::IA_G() const {
        return Matrice(IG_G()+masse*distance*distance*Matrice(1,1,0));
    }

    Matrice Toupie::IA_O() const {
        return S_().transp()*IA_G()*S_();
    }

    Matrice Toupie::IA_point() const {
        return Matrice(0,0,0);
    }

    Matrice Toupie::S_() const {
        Matrice S_theta(1,0,0,0,cos(P.get_coord(2)),sin(P.get_coord(2)),0,-sin(P.get_coord(2)),cos(P.get_coord(2)));
        Matrice S_psi(cos(P.get_coord(1)),sin(P.get_coord(1)),0,-sin(P.get_coord(1)),cos(P.get_coord(1)),0,0,0,1);
        return S_theta*S_psi;
    }

    Vecteur Toupie::GtoO(Vecteur G) const {
        return S_().transp()*G;
    }

    Vecteur Toupie::OtoG(Vecteur O) const {
        return S_()*O;
    }

    Vecteur Toupie::LG_G() const {
        return (IG_G()*omega_G());
    }
    
    Vecteur Toupie::LG_O() const {
        return IG_O()*omega_O();
    }

    Vecteur Toupie::LA_G() const {
        return IA_G()*omega_G();
    }

    Vecteur Toupie::LA_O() const {
        return IA_O()*omega_O();
    }

    double Toupie::LA_k() const {
        return LA_O()*Vecteur({0,0,1});
    }

    double Toupie::LA_a() const {
        return LA_G()*Vecteur({0,0,1});
    }

    Vecteur Toupie::AG_G() const {
        return Vecteur(0,0,distance);
    }

    Vecteur Toupie::AG_O() const {
        return GtoO(AG_G());
    }

    Vecteur Toupie::OG_G() const
    {
        return OtoG(OG_O());
    }

    Vecteur Toupie::OG_O() const
    {
        return OA+AG_O();
    }

    Vecteur Toupie::P_G() const {
        return OtoG(P_O());
    }

    Vecteur Toupie::P_O() const {
        return masse*grav;
    }

    double Toupie::EC() const {
        return 1/2.*omega_G()*LA_G();
    }

    double Toupie::E() const {
        return EC()-P_G()*AG_G();
    }

    double Toupie::prod_mixt() const {
        return (Vecteur({0,0,1}))*(omega_G()^LG_G());
    }


//endToupie================================================================================================
    ostream& operator<<(ostream& sortie,Toupie const& etre_affiche) {
        return etre_affiche.affiche(sortie);
    }

//ConeSimple================================================================================================

    ConeSimple::ConeSimple(SupportADessin* support, double m, double h, double r, Vecteur P, Vecteur P_point,Vecteur OA,Grandeur_physique grandeur, bool trace_on)
    :Toupie(support,m,P,P_point,3.*m/20.*(r*r+1./4.*h*h),3.*m/10.*r*r,h*3./4.,OA,grandeur,trace_on),hauteur(h),rayon(r)
    {
        if(r<=0) throw 6;
        if(h<=0) throw 9;
        if ((P.dimension()!=3) or (P_point.dimension()!=3)) throw 18;
    }


    ostream& ConeSimple::affiche(ostream& sortie) const {
        sortie<<"Cone Simple : " << endl
              <<"Hauteur (m) : " << hauteur << endl
              <<"Rayon (m) : " << rayon << endl
              <<"Masse (kg) : "<<masse<<endl
              <<"I1 : "<<I1<<endl
              <<"I3 : "<<I3<<endl
              <<"Vecteur P : "<<P<<endl
              <<"Derivee de P : "<<P_point<<endl
              <<"Point de contact : "<<OA<<endl;
        return sortie;
    }

    double ConeSimple::get_hauteur() const
    {
        return hauteur;
    }

    double ConeSimple::get_rayon() const
    {
        return rayon;
    }

    Vecteur ConeSimple::eq_mouv() const {
        double I_A1((I1+masse*distance*distance));
        if(getP().get_coord(2)==0){throw 10;}
        else{
        return Vecteur(getP_point().get_coord(2)/(I_A1*sin(getP().get_coord(2)))*((I3-2.*I_A1)*getP_point().get_coord(1)*cos(getP().get_coord(2))+I3*getP_point().get_coord(3)),
                       1./(I_A1)*(masse*g*distance*sin(getP().get_coord(2))+getP_point().get_coord(1)*sin(getP().get_coord(2))*((I_A1-I3)*getP_point().get_coord(1)*cos(getP().get_coord(2))-I3*getP_point().get_coord(3))),
                       getP_point().get_coord(2)/(I_A1*sin(getP().get_coord(2)))*((I_A1-(I3-I_A1)*cos(getP().get_coord(2))*cos(getP().get_coord(2)))*getP_point().get_coord(1)-I3*getP_point().get_coord(3)*cos(getP().get_coord(2))));
        }
    }

    void ConeSimple::dessine() const {
      support->dessine(*this);
    }

	unique_ptr<Toupie> ConeSimple::copie() const {
		return clone();
	}
	
	unique_ptr<ConeSimple> ConeSimple::clone() const {
		return unique_ptr<ConeSimple>(new ConeSimple(*this));
	}

    void ConeSimple::trace_G(){
        support->trace_G(*this);
    }
//endConeSimple===============================================================================================
    double masse_cone(double masse_volumique,double hauteur,double rayon) {
    return double(masse_volumique*(M_PI*rayon*rayon*hauteur)/3);
    }

	ostream& operator<<(ostream& sortie,ConeSimple const& etre_affiche) {
		return etre_affiche.affiche(sortie);
	}

//ToupieChinoise==============================================================
	
    ToupieChinoise::ToupieChinoise(SupportADessin* support, double m, double h, double R, Vecteur P, Vecteur P_point,Vecteur OA,Grandeur_physique grandeur, bool trace_on) // d???????
        :Toupie(support,m,P,P_point,I1_chinoise(m,h,R),I3_chinoise(m,h,R),1,OA,grandeur,trace_on),h(h),R(R)
    {
        if (R<=0) throw 6;
        if (h<0) throw 15;
        if (h>R) throw 14;
        if ((P.dimension()!=5) or (P_point.dimension()!=5)) throw 19;

        this->m.setTaille(25); // pour eviter du lag avec une memoire trop grande
    }

    ostream& ToupieChinoise::affiche(ostream& sortie) const {
        sortie<<"Toupie Chinoise : " << endl
              <<"Hauteur tronquee (m) : " << h << endl
              <<"Rayon (m) : " << R << endl
              <<"Masse (kg) : "<<masse<<endl
              <<"I1 : "<<I1<<endl
              <<"I3 : "<<I3<<endl
              <<"Vecteur P : "<<P<<endl
              <<"Derivee de P : "<<P_point<<endl
              <<"Point de contact : "<<OA<<endl;
        return sortie;
    }

    void ToupieChinoise::dessine() const {
      support->dessine(*this);
    }

    double ToupieChinoise::psi() const {
        return P.get_coord(1);
    }

    double ToupieChinoise::theta() const {
        return P.get_coord(2);
    }

    double ToupieChinoise::phi() const {
        return P.get_coord(3);
    }

    double ToupieChinoise::psi_point()  const {
        return P_point.get_coord(1);
    }

    double ToupieChinoise::theta_point()  const{
        return P_point.get_coord(2);
    }

    double ToupieChinoise::phi_point() const {
        return P_point.get_coord(3);
    }

    double ToupieChinoise::f1() const {
        return phi_point() + psi_point() * cos(theta()); //OK
    }

    double ToupieChinoise::f2() const {
        if (theta()==0) {throw 10;}
        return theta_point() / sin(theta())* f1() *  ( I3* ( I3 + masse * R * R * ( 1 - alpha_chinoise(h,R) * cos(theta()) ) ) / f3() )
                -2 * psi_point() * theta_point() * cos(theta()) / sin(theta()); //OK
    }

    double ToupieChinoise::f3() const {
        return I1 * I3 + masse * R * R * I1 * pow(sin(theta()),2) + masse * R * R * I3 * pow(alpha_chinoise(h,R)-cos(theta()),2); //OK
    }

    unique_ptr<Toupie> ToupieChinoise::copie() const {
        return clone();
    }

    unique_ptr<ToupieChinoise> ToupieChinoise::clone() const {
        return unique_ptr<ToupieChinoise>(new ToupieChinoise(*this));
    }

    Vecteur ToupieChinoise::get_OA() const
    {
        return Vecteur(OA.get_coord(1)+P_point.get_coord(4),OA.get_coord(2)+P_point.get_coord(5),OA.get_coord(3));
    }

    double ToupieChinoise::get_rayon() const
    {
        return R;
    }

    Vecteur ToupieChinoise::eq_mouv() const {
        return Vecteur({psi_point_point(),theta_point_point(),phi_point_point(),P4_point_point(),P5_point_point()});
    }

    double ToupieChinoise::psi_point_point() const {
        return f2();
    }

    double ToupieChinoise::theta_point_point() const {
        return sin(theta()) / ( I1 + masse * R * R * ( pow(alpha_chinoise(h,R)-cos(theta()),2) + pow(sin(theta()),2)) ) *
               ( pow(psi_point(),2) * ( - masse * R * R * ( alpha_chinoise(h,R) - cos(theta()) ) * ( 1 - alpha_chinoise(h,R) * cos(theta()) ) + I1 * cos(theta()) )
               + f1() * psi_point() * ( masse * R * R * ( alpha_chinoise(h,R) * cos(theta()) - 1 ) - I3 ) - masse * R * R * pow(theta_point(),2) * alpha_chinoise(h,R) - masse * R * alpha_chinoise(h,R) * g ); //OK
    }

    double ToupieChinoise::phi_point_point() const {
        return psi_point() * theta_point() * sin(theta()) - cos(theta()) * f2()
               - f1() * theta_point() * sin(theta()) * ( masse * R * R * ( I3 * ( alpha_chinoise(h,R) - cos(theta()) ) + I1 * cos(theta()) ) / f3() ); //OK
    }

    double ToupieChinoise::P4_point_point() const {
        return R * ( theta_point() * sin(psi()) - phi_point() * cos(psi()) * sin(theta()) ); //OK
    }

    double ToupieChinoise::P5_point_point() const {
        return - R * ( theta_point() * cos(psi()) + phi_point() * sin(psi()) * sin(theta()) ); //OK
    }

    Vecteur ToupieChinoise::GC_G() const
    {
        return R*alpha_chinoise(h,R)*Vecteur(0,0,1);
    }

    Vecteur ToupieChinoise::GC_O() const
    {
        return GtoO(GC_G());
    }

    Vecteur ToupieChinoise::AC_G() const
    {
        return OtoG(AC_O());
    }

    Vecteur ToupieChinoise::AC_O() const
    {
        return R*Vecteur(0,0,1);
    }

    Vecteur ToupieChinoise::AG_G() const
    {
        return AC_G()-GC_G();
    }

    Vecteur ToupieChinoise::AG_O() const
    {
        return AC_O()-GC_O();
    }

    Vecteur ToupieChinoise::vC_O() const {
        return R*omega_O()^Vecteur(0,0,1);
    }

    void ToupieChinoise::trace_G(){
        support->trace_G(*this);
    }

    double masse_chinoise(double rho,double h,double R) {
        return M_PI * rho * ( 4.0/3.0 * pow(R,3) - pow(h,2) * ( R - h/3.0 ) ); //OK
    }

    double rho_chinoise(double m, double h, double R) {
        return m / ( M_PI * ( 4.0/3.0 * pow(R,3) - pow(h,2) * ( R - h/3.0 ) ) ); //OK
    }

    double alpha_chinoise(double h, double R) {
        return 3 * h * h / ( 4 * R * ( R + h ) ); //OK
    }

    double integrale_z_carre(double m, double h, double R) {
        return ( M_PI / 15.0 ) * rho_chinoise(m,h,R) * pow((2*R-h),2) * ( pow(R,3) + h * R * R - 3 * h * h * R + 3 * pow(h,3) ); //OK
    }

    double I1_chinoise(double m, double h, double R) {
        return ( I3_chinoise(m,h,R) / 2.0 ) + integrale_z_carre(m,h,R) - m * R * R * pow(alpha_chinoise(h,R),2); //OK
    }

    double I3_chinoise(double m, double h, double R) {
        return ( M_PI / 30.0 ) * rho_chinoise(m,h,R) * pow((2*R-h),3) * ( 2 * R * R + 3 * h * R + 3 * h * h ); //OK
    }


    ostream& operator<<(ostream& sortie, ToupieChinoise const& etre_affiche) {
        return etre_affiche.affiche(sortie);
    }

//SolideRevolution===============================================================

    SolideRevolution::SolideRevolution(SupportADessin* support, double rho, double L, std::vector<double> r_i, Vecteur P, Vecteur P_point, Vecteur OA, Grandeur_physique grandeur, bool trace_on)
    :Toupie(support,masse_solide_revolution(rho,L,r_i),P,P_point,I1_solide_revolution(rho,L,r_i),I3_solide_revolution(rho,L,r_i),d_solide_revolution(L,r_i),OA,grandeur,trace_on),rho(rho),L(L),r_i(r_i)
    {
        if (L<=0) throw 9;
        if (rho<=0) throw 16;
        if (r_i.size()==0) throw 11;

        bool probleme(false);
        for(size_t i(0);i<r_i.size();i++){
            if(r_i[i]<=0){probleme=true;}
        }

        if (probleme) throw 12;
        if ((P.dimension()!=3) or (P_point.dimension()!=3)) throw 20;
    }

    ostream& SolideRevolution::affiche(ostream& sortie) const {
        sortie<<"Solide de Revolution : " << endl
              <<"Hauteur (m) : " << L << endl
              <<"Masse (kg) : "<<masse<<endl
              <<"I1 : "<<I1<<endl
              <<"I3 : "<<I3<<endl
              <<"Vecteur P : "<<P<<endl
              <<"Derivee de P : "<<P_point<<endl
              <<"Point de contact : "<<OA<<endl;
        return sortie;
    }

    void SolideRevolution::dessine() const {
      support->dessine(*this);
    }

    unique_ptr<Toupie> SolideRevolution::copie() const {
        return clone();
    }

    unique_ptr<SolideRevolution> SolideRevolution::clone() const {
        return unique_ptr<SolideRevolution>(new SolideRevolution(*this));
    }

    void SolideRevolution::trace_G(){
        support->trace_G(*this);
    }

    double SolideRevolution::get_L() const
    {
        return L;
    }

    std::vector<double> SolideRevolution::get_r_i() const
    {
        return r_i;
    }

    ostream& operator<<(ostream& sortie, SolideRevolution const& etre_affiche) {
        return etre_affiche.affiche(sortie);
    }

    double masse_solide_revolution(double rho, double L, const std::vector<double> &r_i)
    {
        double somme_r_i_carre(0.0);
        double N(r_i.size());
        for (auto r:r_i) {
            somme_r_i_carre += r*r;
        }
        return M_PI*rho*L/N*somme_r_i_carre;
    }

    double d_solide_revolution(double L, const std::vector<double> &r_i)
    {
        double somme_numerateur(0.0);
        double somme_denominateur(0.0);
        double N(r_i.size());
        for (size_t i(1); i<=r_i.size(); ++i) {
            somme_numerateur += ((2*i-1)/2.0)*(L/N)*pow(r_i[i-1],2);
            somme_denominateur += pow(r_i[i-1],2);
        }
        return somme_numerateur/somme_denominateur;
    }

    double I3_solide_revolution(double rho, double L, const std::vector<double> &r_i)
    {
        double somme(0.0);
        double N(r_i.size());
        for(auto r:r_i){
            somme += pow(r,4);
        }
        return M_PI/2*rho*L/N*somme;
    }

    double I1_solide_revolution(double rho, double L, const std::vector<double> &r_i)
    {
        double somme(0.0);
        double N(r_i.size());
        for (size_t i(1); i<=r_i.size(); ++i) {
            somme += pow(((2*i-1)/2.0)*(L/N)*r_i[i-1],2);
        }
        return 0.5*I3_solide_revolution(rho,L,r_i)+M_PI*rho*L/N*somme
        -masse_solide_revolution(rho,L,r_i)*pow(d_solide_revolution(L,r_i),2);
    }

//Toupie(SupportADessin* support, double masse, Vecteur P, Vecteur P_point, double I1, double I3,double distance,Vecteur OA,Grandeur_physique grandeur=null, bool trace_on = true);


//MasseTombe=====================================================================
    MasseTombe::MasseTombe(SupportADessin* support, double m,Vecteur P,Vecteur P_point,bool trace_on)
    :Toupie(support,m,P,P_point,1,1,0.5,Vecteur(),null,trace_on)
    {
        if (m<=0) throw 5;
        if ((P.dimension()!=3) or (P_point.dimension()!=3)) throw 21;
    }
	
    ostream& MasseTombe::affiche(std::ostream& sortie) const {
        sortie<<"Masse Tombante : "<<endl
            <<"Masse (kg) : "<<masse<<endl
            <<"Vecteur P : "<< P<<endl
            <<"Derivee de P : "<<P_point<<endl;
			return sortie;
	}
	
    Vecteur MasseTombe::eq_mouv() const {
        return Vecteur({0,0,-9.81});
	}

    void MasseTombe::dessine() const {
      support->dessine(*this);
    }
	
	unique_ptr<Toupie> MasseTombe::copie() const {
		return clone();
	}
	
	unique_ptr<MasseTombe> MasseTombe::clone() const {
		return unique_ptr<MasseTombe>(new MasseTombe(*this));
	}

    double MasseTombe::EC() const {
        return (1/2.*(masse*P_point.norme2()));
    }

    double MasseTombe::EP() const {
        return (masse*g*P.get_coord(2));
    }

    double MasseTombe::E() const {
        return (EC()+EP());
    }

    Vecteur MasseTombe::OG_O() const
    {
        return P;
    }

    void MasseTombe::trace_G(){
        support->trace_G(*this);
    }

//endMasseTombe================================================================================================
    ostream& operator<<(std::ostream& sortie,MasseTombe const& etre_affiche) {
        return etre_affiche.affiche(sortie);
    }

//Pendule======================================================================================================
    Pendule::Pendule(SupportADessin* support, double m, Vecteur P, Vecteur P_point, Vecteur OA, bool trace_on)
    :Toupie(support,m,P,P_point,1,1,1,OA,null,trace_on)
    {
          if (P.get_coord(1)<=0) throw 17;
          if (m<=0) throw 5;
          if ((P.dimension()!=3) or (P_point.dimension()!=3)) throw 22;

          this->m.setTaille(25); // pour rendre la trace plus joli
    }

    ostream& Pendule::affiche(std::ostream& sortie) const{
        sortie<<"Pendule : "<<endl
              <<"Longueur (m) : "<<P.get_coord(1)<<endl
              <<"Masse (kg) : "<<masse<<endl
              <<"Accroche en : "<<OA<< endl
              <<"Vecteur P : "<<P<<endl
              <<"Derivee de P : "<<P_point<<endl;
        return sortie;
    }
    Vecteur Pendule::eq_mouv() const{
        return Vecteur({0,-g/P.get_coord(1)*sin(P.get_coord(2)),0});
    }

    unique_ptr<Toupie> Pendule::copie() const {
        return clone();
    }

    unique_ptr<Pendule> Pendule::clone() const {
        return unique_ptr<Pendule>(new Pendule(*this));
    }

 void Pendule::dessine() const{
   support->dessine(*this);
 }

 double Pendule::EC() const {
return 1/2.*masse*pow(P.get_coord(1)*P_point.get_coord(2),2);
}

 double Pendule::EP() const{
   return (-masse*g*P.get_coord(1)*cos(P.get_coord(2)));
 }

 double Pendule::E() const {
     return (EC()+EP());
 }

 Vecteur Pendule::AG_O() const
 {
     return P;
 }

 void Pendule::trace_G(){
     support->trace_G(*this);
 }

 //endPendule======================================================================================

 ostream& operator<<(std::ostream& sortie,Pendule const& etre_affiche) {
     return etre_affiche.affiche(sortie);
 }


