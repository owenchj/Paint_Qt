#ifndef POLYLINE_H
#define POLYLINE_H


#include "form.h"
#include <QPoint>
#include <QList>

class Polyline:public Form{
 private:
  QList <QPoint> points;

 public:
  Polyline(int ID = POLYLINE):Form(ID){}
  virtual ~Polyline(){}

  virtual unsigned int getLength() const{
    return points.length();
  }

  virtual void addPoint(QPoint next, bool add) {
    //std::cout<<"begin: "<<points.length()<<std::endl;
    
    path = QPainterPath(); 
    if(points.length()){

      path.moveTo(points.at(0));
 
      for(int i = 1; i< points.length();i++){
	path.lineTo(points.at(i));
      }
    
      path.lineTo(next);
    }
    
    if(add) points.append(next);
    
    //std::cout<<"after: "<<points.length()<<std::endl;
  }

  virtual int getID() const{
    return ID;
  }
};


#endif // POLYLINE_H
