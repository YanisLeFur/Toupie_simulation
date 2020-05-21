#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include "Dessinable.h"
#include "Toupie.h"
#include "glsphere.h"
#include "glchinoise.h"
#include "constant.h"
#include <deque>

//Memoire================================================
class Memoire{
    private:
          std::deque<Vecteur> points;
           size_t taille;
     public:
           Memoire(size_t taille=100);
           std::deque<Vecteur> GetPoints();
           void ajouter_point(Vecteur const&);
};


//VueOpenGl================================================
class VueOpenGL : public SupportADessin {
 public:

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineCone(QMatrix4x4 const& point_de_vue = QMatrix4x4(), double h = 1.5, double r = 0.5,
                   Grandeur_physique=phi_point,double =0,double =0,double=0);

  virtual void dessine(ConeSimple const&) override;

  virtual void dessine(Pendule const&) override;

  virtual void dessine(MasseTombe const&) override;

  virtual void dessine(Toupie const&) override;

  virtual void dessine(ToupieChinoise const&) override;

  virtual void trace_G(Toupie const&) override;

  virtual void trace_G(ConeSimple const&) override;

  virtual void trace_G(MasseTombe const&) override;

  virtual void trace_G(Pendule const&) override;

  virtual void trace_G(ToupieChinoise const&) override;


  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);

  void dessinePlateforme(QMatrix4x4 const& point_de_vue, bool en_couleur = true);

  void dessineSphere(QMatrix4x4 const& point_de_vue,
                       double rouge = 0.0, double vert = 0.0, double bleu = 1.0);

  void dessineSphereCoupe(QMatrix4x4 const& point_de_vue,                       //permet de représenter graphiquement la toupie chinoise
                       double rouge = 1.0, double vert = 0.0, double bleu = 0.0);

  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual SupportADessin* copie() const override;

  private:

  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;
  GLSphere sphere;
  GLSphereCoupe sphere_coupe;
  Memoire m;


  // Caméra
  QMatrix4x4 matrice_vue;

   //textures
  GLuint textureDeChat;
  GLuint textureFractale;

};

#endif
