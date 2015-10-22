#ifndef FORM_H
#define FORM_H

#include "parameter.h"
#include <QPainterPath>
#include <QPen>


class Form{
 protected:
  QPen pen;
  QPainterPath path;
  int ID;
 
 public:
  Form(){ ID=0; }
  Form(int ID = 0):ID(ID){}
  virtual ~Form(){}
 
  virtual QPen getPen() const{ return pen; }
  
  virtual void setPen(QPen const &pen) { this->pen = pen; }
  
  virtual QPainterPath getPath() const{ return path;}

  virtual void setPath(QPainterPath const &path) { this->path = path;}

  virtual int getID() const {return 0;}

  virtual QPoint getStart() const{ return QPoint(0,0); }

  virtual QPoint getEnd() const{ return QPoint(0,0); }
};






#endif // FORM_H
