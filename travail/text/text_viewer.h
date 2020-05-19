#ifndef TEXT_VIEWER_H
#define TEXT_VIEWER_H

#include <iostream>
#include "Dessinable.h"

class TextViewer : public SupportADessin {
 public:
 TextViewer(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~TextViewer() {}

  virtual void dessine(Contenu const& a_dessiner) override;

 private:
  std::ostream& flot;
};

#endif
