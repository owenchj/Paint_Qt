#ifndef ELLIPSE_H
#define ELLIPSE_H


#include "form.h"
#include <QPoint>
#include <QRect>

class Ellipse : public Form{
 private:
  QPoint start;
  QPoint end;

 public:
  Ellipse(){}
  virtual ~Ellipse(){}

  virtual void setEllipse(QPoint start, QPoint end ) {
    path = QPainterPath();
    path.moveTo(start);
    path.addEllipse(QRect(start, end));
  }

};


#endif // ELLIPSE_H
