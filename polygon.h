#ifndef POLYGON_H
#define POLYGON_H


#include "form.h"
#include <QPoint>
#include <QList>

class Polygon:public Form{
 private:
  QList <QPoint> points;

 public:
  Polygon(){}
  virtual ~Polygon(){}

  virtual unsigned int getLength() const{
    return points.length();
  }

  virtual void addPoint(QPoint next, bool add) {
    std::cout<<"begin: "<<points.length()<<std::endl;
    
    path = QPainterPath(); 
    if(points.length()){

      path.moveTo(points.at(0));
 
      for(int i = 1; i< points.length();i++){
	path.lineTo(points.at(i));
      }
    
      path.lineTo(next);
      path.lineTo(points.at(0));
    }
    
    if(add) points.append(next);
    
    std::cout<<"after: "<<points.length()<<std::endl;
  }

};


#endif // POLYGON_H
