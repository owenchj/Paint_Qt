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

  Rectangle(int ID = RECTANGLE):Form(ID){}
  virtual ~Rectangle(){}

  virtual void setRectangle(QPoint start, QPoint end ) {
    this->start = start;
    this->end = end;
    path = QPainterPath();
    path.moveTo(start);
    path.addRect(QRect(start, end));
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


#endif // RECTANGLE_H
