#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "Toupie.h"
#include "constant.h"
#include "Systeme.h"
#include "Integrateur.h"

class GLWidget : public QOpenGLWidget
/* La fenêtre hérite de QOpenGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
  GLWidget(QWidget* parent = nullptr)
    : QOpenGLWidget(parent)
    , s(new IntegrateurRungeKutta)
  {}
  virtual ~GLWidget() {}

  void ajouter_Toupie(Toupie const& toupie); // ajoute une toupie dans le systeme du widget

  VueOpenGL* get_Vue_ptr(); // retourne un pointeur sur le VueOpenGL du widget

  std::ostream& affiche(std::ostream& sortie) const; // appelle la fonction afficher des toupies du systeme du widget



private:
  // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // systeme à faire évoluer
  Systeme s;



};

#endif // GLWIDGET_H
