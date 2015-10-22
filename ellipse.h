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

  Ellipse(int ID = ELLIPSE):Form(ID){}
  virtual ~Ellipse(){}

  virtual void setEllipse(QPoint start, QPoint end ) {
    this->start = start;
    this->end = end;
    path = QPainterPath();
    path.moveTo(start);
    path.addEllipse(QRect(start, end));
  }
  
  virtual int getID() const{
    return ID;
  }

  virtual QPoint getStart() const{
    return start;
  }

  virtual QPoint getEnd() const{
    return end;
  }
};


#endif // ELLIPSE_H
