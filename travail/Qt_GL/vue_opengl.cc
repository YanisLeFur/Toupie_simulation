#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Toupie.h"
#include "Vecteur.h"
#include <cmath>
#include <QGLContext>
#include <QOpenGLFunctions>


// VueOpenGL===============================================================================================

void VueOpenGL::dessine(Toupie const& a_dessiner) {
    QMatrix4x4 matrice;
    dessineAxes(matrice);
    dessinePlateforme(matrice);
    double psi(a_dessiner.getP().get_coord(1));
    double theta(a_dessiner.getP().get_coord(2));
    double phi(a_dessiner.getP().get_coord(3));
    matrice.rotate(psi*360/(2*M_PI),0.0,0.0,1.0);
    matrice.rotate(theta*360/(2*M_PI),1.0,0.0,0.0);
    matrice.rotate(phi*360/(2*M_PI),0.0,0.0,1.0);
    dessineCone(matrice,1.5,0.5);
}
//=========================================================================================================
void VueOpenGL::dessine(ConeSimple const& a_dessiner)
{
    QMatrix4x4 matrice;
    dessineAxes(matrice);
    dessinePlateforme(matrice);
    double psi(a_dessiner.getP().get_coord(1));
    double theta(a_dessiner.getP().get_coord(2));
    double phi(a_dessiner.getP().get_coord(3));
    double Ax(a_dessiner.get_OA().get_coord(1));
    double Ay(a_dessiner.get_OA().get_coord(2));
    double Az(a_dessiner.get_OA().get_coord(3));
    matrice.translate(Ax,Ay,Az);
    matrice.rotate(psi*360/(2*M_PI),0.0,0.0,1.0);
    matrice.rotate(theta*360/(2*M_PI),1.0,0.0,0.0);
    matrice.rotate(phi*360/(2*M_PI),0.0,0.0,1.0);

    dessineCone(matrice,a_dessiner.get_hauteur(),a_dessiner.get_rayon(),
                a_dessiner.get_Grandeur(),a_dessiner.getP_point().get_coord(1),a_dessiner.getP_point().get_coord(2),
                a_dessiner.getP_point().get_coord(3));
}
//=========================================================================================================
void VueOpenGL::dessine(ToupieChinoise const& a_dessiner)
{
    QMatrix4x4 matrice;
    dessineAxes(matrice);
    dessinePlateforme(matrice);
    double psi(a_dessiner.getP().get_coord(1));
    double theta(a_dessiner.getP().get_coord(2));
    double phi(a_dessiner.getP().get_coord(3));
    matrice.rotate(psi*360/(2*M_PI),0.0,0.0,1.0);
    matrice.rotate(theta*360/(2*M_PI),1.0,0.0,0.0);
    matrice.rotate(phi*360/(2*M_PI),0.0,0.0,1.0);
    dessineSphereCoupe(matrice);
}

//=========================================================================================================
void VueOpenGL::dessine(Pendule const& a_dessiner)
{
  QMatrix4x4 matrice;
  dessineAxes(matrice);
  dessinePlateforme(matrice);

  double Ax(a_dessiner.get_OA().get_coord(1));
  double Ay(a_dessiner.get_OA().get_coord(2));
  double Az(a_dessiner.get_OA().get_coord(3));

  glBegin(GL_LINES);

  prog.setAttributeValue(SommetId, Ax, Ay, Az);
  prog.setAttributeValue(SommetId,
                         Ax+a_dessiner.get_l()*sin(a_dessiner.getP().get_coord(2)),
                                                                              Ay,
                         Az-a_dessiner.get_l()*cos(a_dessiner.getP().get_coord(2)));

  glEnd();

  matrice.translate(Ax,Ay,Az);

  matrice.translate(a_dessiner.get_l()*sin(a_dessiner.getP().get_coord(2)),
                                                                         0,
                   -a_dessiner.get_l()*cos(a_dessiner.getP().get_coord(2)));
  matrice.scale(0.25);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // passe en mode "plein"

  dessineSphere(matrice);
}
//=========================================================================================================
void VueOpenGL::dessine(MasseTombe const& a_dessiner) {
    QMatrix4x4 matrice;
    glBegin(GL_LINES);
    dessineAxes(matrice);
    dessinePlateforme(matrice);
    matrice.translate(a_dessiner.getP().get_coord(1),
                      a_dessiner.getP().get_coord(2),
                      a_dessiner.getP().get_coord(3));
    matrice.scale(0.25);

    dessineSphere(matrice,0.0);

    glEnd();
}
//=========================================================================================================
void VueOpenGL::trace_G(ConeSimple& c){

    QMatrix4x4 point_de_vue;
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    c.ajouter_point_memoire(c.G_O()+c.get_OA());

    if (c.get_m().GetPoints().size()>=2){
        glBegin(GL_LINES);
        for(size_t i(0);i<c.get_m().GetPoints().size()-1;i++){

            prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);
            prog.setAttributeValue(SommetId, c.get_m().GetPoints()[i].get_coord(1), c.get_m().GetPoints()[i].get_coord(2), c.get_m().GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, c.get_m().GetPoints()[i+1].get_coord(1), c.get_m().GetPoints()[i+1].get_coord(2), c.get_m().GetPoints()[i+1].get_coord(3));

        }
        glEnd();
    }
}
//=========================================================================================================
void VueOpenGL::trace_G(Toupie& t){
    QMatrix4x4 point_de_vue;
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    t.ajouter_point_memoire(t.G_O()+t.get_OA());
    if (t.get_m().GetPoints().size()>=2){
        glBegin(GL_LINES);
        for(size_t i(0);i<t.get_m().GetPoints().size()-1;i++){
            prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0);
            prog.setAttributeValue(SommetId, t.get_m().GetPoints()[i].get_coord(1), t.get_m().GetPoints()[i].get_coord(2), t.get_m().GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, t.get_m().GetPoints()[i+1].get_coord(1), t.get_m().GetPoints()[i+1].get_coord(2), t.get_m().GetPoints()[i+1].get_coord(3));
        }
        glEnd();
    }
}
//=========================================================================================================
void VueOpenGL::trace_G(Pendule& p){
    QMatrix4x4 point_de_vue;
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    p.ajouter_point_memoire(p.G_O());
    if (p.get_m().GetPoints().size()>=2){
        glBegin(GL_LINES);
        for(size_t i(0);i<p.get_m().GetPoints().size()-1;i++){
            prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);
            prog.setAttributeValue(SommetId, p.get_m().GetPoints()[i].get_coord(1), p.get_m().GetPoints()[i].get_coord(2), p.get_m().GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, p.get_m().GetPoints()[i+1].get_coord(1), p.get_m().GetPoints()[i+1].get_coord(2), p.get_m().GetPoints()[i+1].get_coord(3));
        }
        glEnd();
    }
}

void VueOpenGL::trace_G(ToupieChinoise&)
{

}
//=========================================================================================================
void VueOpenGL::trace_G(MasseTombe& mt){
    QMatrix4x4 point_de_vue;
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    mt.ajouter_point_memoire(mt.G_O());
    if (mt.get_m().GetPoints().size()>=2){
        glBegin(GL_LINES);
        for(size_t i(0);i<mt.get_m().GetPoints().size()-1;i++){
            prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
            prog.setAttributeValue(SommetId, mt.get_m().GetPoints()[i].get_coord(1), mt.get_m().GetPoints()[i].get_coord(2), mt.get_m().GetPoints()[i].get_coord(3));
            prog.setAttributeValue(SommetId, mt.get_m().GetPoints()[i+1].get_coord(1), mt.get_m().GetPoints()[i+1].get_coord(2), mt.get_m().GetPoints()[i+1].get_coord(3));
        }
        glEnd();
    }
}
//=========================================================================================================
void VueOpenGL::dessineAxes (QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);

  // axe X
  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);

  // axe Y
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);

  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

  glEnd();
}

void VueOpenGL::dessinePlateforme(const QMatrix4x4 &point_de_vue)
{
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();
    glFuncs->glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureBois);

    glBegin(GL_POLYGON);

    /*prog.setAttributeValue(CouleurId, 0.707, 0.395, 0.113); // bleu
    prog.setAttributeValue(SommetId, 1000.0, 1000.0, 0.0);
    prog.setAttributeValue(SommetId, 50.0, -50.0, 0.0);
    prog.setAttributeValue(SommetId, -50.0, 50.0, 0.0);
    prog.setAttributeValue(SommetId, -50.0, -50.0, 0.0);*/

    double r(100);
    double slices(50);
    double theta(2*M_PI/slices);

    for(unsigned int i(0);i<=slices;i++){

        prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.0);
        prog.setAttributeValue(CoordonneeTextureId,r*cos(i*theta)+0.5,r*sin(i*theta)+0.5);
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),0);

   }

   glEnd();
}
//=========================================================================================================
SupportADessin* VueOpenGL::copie() const {}
//=========================================================================================================
void VueOpenGL::init()
{
    // Initialisation des shaders

    prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
    prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

    prog.bindAttributeLocation("sommet",  SommetId);
    prog.bindAttributeLocation("coordonnee_texture", CoordonneeTextureId);

    prog.link();
    prog.bind();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // Préparation d'une première texture à partir d'une image (cat.jpeg).
    QGLContext* context =  const_cast<QGLContext*>(QGLContext::currentContext());
    textureDeChat = context->bindTexture(QPixmap(":/cat.jpeg"), GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    // Autres variantes au lieu de GL_MIRRORED_REPEAT : GL_REPEAT, GL_CLAMP_TO_EDGE

    // Préparation d'une seconde texture.
    // S'il y devait y en avoir plus, on ferait bien sûr une fonction ;-)
    textureBois= context->bindTexture(QPixmap(":/wood_texture_208389.jpg"), GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);


  sphere.initialize();
  sphere_coupe.initialize();
  initializePosition();
}
//=========================================================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -4.0);
  matrice_vue.rotate(-90.0, 1.0, 0.0, 0.0);
  matrice_vue.translate(0.0, 0.0, -4.0);
}
//=========================================================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}
//=========================================================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}
//=========================================================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}
//=========================================================================================================
void VueOpenGL::dessineCone(QMatrix4x4 const& point_de_vue,double hauteur, double rayon,
                            Grandeur_physique grandeur,double psi_point_,double theta_point_,double phi_point_){


    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    /// Attribut la texture 'textureDeChat' à la texture numéro 0 du shader
    QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();
    glFuncs->glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureDeChat);

    double h(hauteur);
    double r(rayon);
    double slices(50);
    double theta(2*M_PI/slices);

    prog.setUniformValue("textureId", 5);
    glBegin(GL_TRIANGLES);

    for(unsigned int i(0);i<=slices;i++){
        prog.setAttributeValue(CouleurId,0.0,0.0,0.0);
        switch (grandeur) {

            case psi_point: prog.setAttributeValue(CouleurId, 0.2+abs(psi_point_)/2.0, 0.0, 0.0);
            break;
            case theta_point: prog.setAttributeValue(CouleurId, 0.0, 0.2+abs(theta_point_)/2.0, 0.0);
            break;
            case phi_point: prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.2+abs(phi_point_)/2.0);
            break;
            case null:prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0);
            break;
        }

       prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
       prog.setAttributeValue(SommetId, r*cos((i+1)*theta),r*sin((i+1)*theta),h);
       prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);


   }
    glEnd();

    prog.setUniformValue("textureId", 0);
    glBegin(GL_POLYGON);

    for(unsigned int i(0);i<=slices;i++){

        prog.setAttributeValue(CouleurId, 0.0, 0.0, 0.0);
        prog.setAttributeValue(CoordonneeTextureId,r*cos(i*theta)+0.5,r*sin(i*theta)+0.5);
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);

   }
   glEnd();
}

//=========================================================================================================
void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}
//=========================================================================================================
void VueOpenGL::dessineSphereCoupe (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{

    prog.setUniformValue("textureId", 5);

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    prog.setAttributeValue(CouleurId, rouge,vert,bleu);  // met la couleur
    sphere_coupe.draw(prog, SommetId);


   prog.setUniformValue("textureId", 0);
   QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();
   glFuncs->glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, textureDeChat);

   double slices(25);
   double beta(2*M_PI/slices);
   double r(0.5877);

  glBegin(GL_POLYGON);

  for(unsigned int i(0);i<=25;i++){
    prog.setAttributeValue(CouleurId, 0.0,0.0,0.0);
    prog.setAttributeValue(CoordonneeTextureId,r*cos(i*beta)+0.5,r*sin(i*beta)+0.5);
    prog.setAttributeValue(SommetId, r*cos(i*beta),r*sin(i*beta),abs(cos((20*M_PI)/25)));
  }

  glEnd();

}
//=========================================================================================================
