#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>

#include <QWidget> 
#include <QPainter>
#include <QAction>
#include <QMouseEvent>

#include "formList.h"
#include "polyForms.h"
#include "parameter.h"


class Picture : public QWidget
{
  Q_OBJECT

 public:
  Picture(QWidget * parent = 0) : QWidget(parent), type(1), begin(false), length(0), order_length(0),order_type(0) {} 
  void drawType(int id);
  void alignList();
  void setStyle(Qt::PenStyle style);
  void setWidth(int w);
  void setColor(QColor c);
  // drawing control 
  void setControl(int id);
    
 private:
  QPoint EndPoint, StartPoint;
  QPoint singleEndPoint, singleStartPoint;
  QPen pen;
  int type;
  // normal forms
  formList list;
  // poly forms
  polyForms polyform_list;
  QList<QPoint > polyform;  
  QPoint *points;
  bool begin;
  int length;
  
  // for controle 
  QList<int > order;  
  int order_length;
  int  order_type;
  
 protected:
  virtual void paintEvent(QPaintEvent*);
  //void drawForm(QPoint , QPoint , QPen, int, QPainter );
  void mousePressEvent(QMouseEvent*); 
  void mouseReleaseEvent(QMouseEvent*); 
  void mouseMoveEvent(QMouseEvent*); 
  void mouseDoubleClickEvent(QMouseEvent*);  
    
};

  
#endif // MAINWINDOW_H
