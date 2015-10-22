#ifndef LINE_H
#define LINE_H


#include "form.h"
#include <QPoint>

class Line:public Form{
 private:
  QPoint start;
  QPoint end;

 public:
  Line(int ID = LINE):Form(ID){}
  virtual ~Line(){}

  virtual void setLine(QPoint start, QPoint end ) {
    this->start = start;
    this->end = end;
    path = QPainterPath();
    path.moveTo(start);
    path.lineTo(end);
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


#endif // LINE_H
