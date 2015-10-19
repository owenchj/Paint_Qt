#ifndef FORM_H
#define FORM_H

#include "parameter.h"
#include <QPainterPath>
#include <QPen>


class Form{
 protected:
  QPen pen;
  QPainterPath path;
  
 public:
  Form(){}
  virtual ~Form(){}
 
  virtual QPen getPen() const{ return pen; }
  
  virtual void setPen(QPen const &pen) { this->pen = pen; }
  
  virtual QPainterPath getPath() const{ return path;}

  virtual void setPath(QPainterPath const &path) { this->path = path;}
};






#endif // FORM_H
