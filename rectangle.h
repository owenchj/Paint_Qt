#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "form.h"
#include <QPoint>
#include <QRect>

class Rectangle : public Form{
 private:
  QPoint start;
  QPoint end;

 public:
  Rectangle(){}
  virtual ~Rectangle(){}

  virtual void setRectangle(QPoint start, QPoint end ) {
    path = QPainterPath();
    path.moveTo(start);
    path.addRect(QRect(start, end));
  }

};


#endif // RECTANGLE_H
