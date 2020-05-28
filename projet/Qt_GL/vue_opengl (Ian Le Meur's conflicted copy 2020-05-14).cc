#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Toupie.h"
#include "Vecteur.h"
#include <cmath>

//memoire==============================================================
void Memoire::ajouter_point(Vecteur const& P){

    if (points.size()>=taille){
        points.pop_front();
    }
    points.push_back(P);
}

std::deque<Vecteur> Memoire::GetPoints() const {
    return points;
}

Memoire::Memoire(size_t taille)
    :taille(taille){}

// ======================================================================

void VueOpenGL::dessine(Toupie const& a_dessiner) {
    QMatrix4x4 matrice;
    dessineAxes(matrice);
    double psi(a_dessiner.getP().get_coord(1));
    double theta(a_dessiner.getP().get_coord(2));
    double phi(a_dessiner.getP().get_coord(3));
    matrice.rotate(psi*360/(2*M_PI),0.0,1.0,0.0);
    matrice.rotate(theta*360/(2*M_PI),1.0,0.0,0.0);
    matrice.rotate(phi*360/(2*M_PI),0.0,0.0,0.0);
    matrice.scale(0.25);
    dessineCone2(matrice);
}

void VueOpenGL::dessine(ConeSimple const& a_dessiner)
{
    QMatrix4x4 matrice;
    dessineAxes(matrice);
    double psi(a_dessiner.getP().get_coord(1));
    double theta(a_dessiner.getP().get_coord(2));
    double phi(a_dessiner.getP().get_coord(3));
    //double psi_point(a_dessiner.getP_point().get_coord(1));
    //double theta_point(a_dessiner.getP_point().get_coord(2));
    //double phi_point(a_dessiner.getP_point().get_coord(3));

    matrice.rotate(psi*360/(2*M_PI),0.0,0.0,1.0);
    matrice.rotate(theta*360/(2*M_PI),1.0,0.0,0.0);
    matrice.rotate(phi*360/(2*M_PI),0.0,0.0,1.0);


    /*matrice.rotate(psi,0.0,0.0,1.0);
    matrice.rotate(theta,cos(psi),sin(psi),0.0);
    matrice.rotate(phi,cos(psi)*sin(theta),sin(psi)*sin(theta),cos(theta));*/

    /*matrice.rotate(theta_point*cos(psi)+phi_point*sin(psi)*sin(theta),1,0,0);
    matrice.rotate(theta_point*sin(psi)-phi_point*cos(psi)*sin(theta),0,1,0);
    matrice.rotate(psi_point+phi_point*cos(theta),0,0,1);*/

    //matrice.scale(0.25);

    dessineCone2(matrice);
}

void VueOpenGL::dessine(Pendule const& a_dessiner)
{
  QMatrix4x4 matrice;
  dessineAxes(matrice);

  glBegin(GL_LINES);

  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId,
                         a_dessiner.get_l()*sin(a_dessiner.getP().get_coord(2)),
                                                                              0,
                         -a_dessiner.get_l()*cos(a_dessiner.getP().get_coord(2)));

  glEnd();

  matrice.translate(a_dessiner.get_l()*sin(a_dessiner.getP().get_coord(2)),
                                                                         0,
                    -a_dessiner.get_l()*cos(a_dessiner.getP().get_coord(2)));
  matrice.scale(0.25);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // passe en mode "fil de fer"

  dessineSphere(matrice);
}

void VueOpenGL::dessine(MasseTombe const& a_dessiner) {
    QMatrix4x4 matrice;
    glBegin(GL_LINES);
    dessineAxes(matrice);
    matrice.translate(a_dessiner.getP().get_coord(1),
                      a_dessiner.getP().get_coord(2),
                      a_dessiner.getP().get_coord(3));
    matrice.scale(0.25);

    dessineSphere(matrice,0.0);

    glEnd();
}

void VueOpenGL::trace_G(ConeSimple const& c) {
    QMatrix4x4 point_de_vue;
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    m.ajouter_point(c.G_O());
    if (m.GetPoints().size()>=2){
        glBegin(GL_LINES);
        for(size_t i(0);i<m.GetPoints().size()-1;++i) {
           prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);
           prog.setAttributeValue(SommetId, m.GetPoints()[i].get_coord(1), m.GetPoints()[i].get_coord(2), m.GetPoints()[i].get_coord(3));
           prog.setAttributeValue(SommetId, m.GetPoints()[i+1].get_coord(1), m.GetPoints()[i+1].get_coord(2), m.GetPoints()[i+1].get_coord(3));
        }
        glEnd();
    }
}

void VueOpenGL::dessine(ToupieChinoise const& a_dessiner) {}

void VueOpenGL::trace_G(Toupie const& t){}

void VueOpenGL::trace_G(Pendule const& p){}

void VueOpenGL::trace_G(MasseTombe const& m){}



/*void VueOpenGL::dessine(Contenu const& a_dessiner)
{
  Q_UNUSED(a_dessiner); // dans cet exemple simple on n'utilise pas le paramètre

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       // efface l'écran

  QMatrix4x4 matrice;

  dessineAxes(matrice); // dessine le repère principal

  matrice.translate(-0.5, 0.0, -2.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // passe en mode "fil de fer"
  dessineSphere(matrice, 0.0, 0.0); // bleu
  matrice.scale(1.5); // taille des axes (1.5 pour qu'ils dépassent un peu)
  dessineAxes(matrice, false); // dessine (en blanc) les axes de la sphere

  matrice.setToIdentity();
  matrice.translate(1.0, 0.0, -2.0);
  matrice.scale(0.5);
  matrice.rotate(-30, 0.0, 1.0, 0.0);
  matrice.rotate(-30, 1.0, 0.0, 0.0);
  dessineSphere(matrice, 1.0, 1.0, 0.0); // jaune
  matrice.scale(1.5);
  dessineAxes(matrice); // dessine (en couleur) les axes de la sphere

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // repasse en mode "plein"

  matrice.setToIdentity();
  matrice.translate(0.0, 0.0, -2.0);
  matrice.scale(0.125);
  dessineSphere(matrice, 1.0, 0.0, 0.0); // rouge
}*/

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

SupportADessin* VueOpenGL::copie() const {}

/*void VueOpenGL::dessine(Contenu const& a_dessiner)
{
   // Dessine le 1er cube (à l'origine)
  dessineCube();

  QMatrix4x4 matrice;
  // Dessine le 2e cube
  matrice.translate(0.0, 1.5, 0.0);
  matrice.scale(0.25);
  dessineCube(matrice);

  // Dessine le 3e cube
  matrice.setToIdentity();
  matrice.translate(0.0, 0.0, 1.5);
  matrice.scale(0.25);
  matrice.rotate(45.0, 0.0, 1.0, 0.0);
  dessineCube(matrice);

  // Dessine le 4e cube
  matrice.setToIdentity();
  matrice.rotate(a_dessiner.infos(), 1.0, 0.0, 0.0);
  matrice.translate(0.0, 2.3, 0.0);
  matrice.scale(0.2);
  dessineCube(matrice);
}
*/

// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  sphere.initialize();
  cone.initialize();
  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.rotate(-90,1,0,0);
  matrice_vue.translate(0.0, 4.0, -1.0);
  /*matrice_vue.rotate(-90.0, 1.0, 0.0, 0.0);
  matrice_vue.rotate(-90.0, 0.0, 0.0, 1.0);
  matrice_vue.rotate(30.0, 0.0, 1.0, 0.0);
  matrice_vue.rotate(-30.0, 0.0, 0.0, 1.0);*/
}

// ======================================================================
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

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
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


void VueOpenGL::dessineCone2(QMatrix4x4 const& point_de_vue){
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);


    double h(1.5);
    double r(0.5);
    double slices(50);
    double theta(2*M_PI/slices);
    for(unsigned int i(1);i<=slices;i++){
     glBegin(GL_TRIANGLES);
    if(i%2==0){

        prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // magenta
        prog.setAttributeValue(SommetId, 0.0,0.0,h);
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);    //y=h!!
        prog.setAttributeValue(SommetId, r*cos((i+1)*theta),r*sin((i+1)*theta),h);
    }
    else{
        prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // magenta
        prog.setAttributeValue(SommetId, 0.0,0.0,h);
        prog.setAttributeValue(SommetId, r*cos(i*theta),r*sin(i*theta),h);    //y=h!!
        prog.setAttributeValue(SommetId, r*cos((i+1)*theta),r*sin((i+1)*theta),h);
    }
     glEnd();
    }


   for(unsigned int i(1);i<=slices;i++){
    glBegin(GL_TRIANGLES);
    if(i%2==0){
       prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // magenta
       prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
       prog.setAttributeValue(SommetId, r*sin(i*theta),r*cos(i*theta),h);    //y=h!!
       prog.setAttributeValue(SommetId, r*sin((i+1)*theta),r*cos((i+1)*theta),h);
    }
    else{
        prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // magenta
        prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
        prog.setAttributeValue(SommetId, r*sin(i*theta),r*cos(i*theta),h);    //y=h!!
        prog.setAttributeValue(SommetId, r*sin((i+1)*theta),r*cos((i+1)*theta),h);

    }
    glEnd();
   }


}

void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}

void VueOpenGL::dessineCone (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  cone.draw(prog, SommetId);                           // dessine la sphère
}
