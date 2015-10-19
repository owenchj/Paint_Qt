#ifndef LINE_H
#define LINE_H


#include "form.h"
#include <QPoint>

class Line:public Form{
 private:
  QPoint start;
  QPoint end;

 public:
  Line(){}
  virtual ~Line(){}

  virtual void setLine(QPoint start, QPoint end ) {
    path = QPainterPath();
    path.moveTo(start);
    path.lineTo(end);
  }

};


#endif // LINE_H
