#ifndef PICTURE_H
#define PICTURE_H

#include <QWidget> 
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QAction>
#include <QMouseEvent>
#include <iostream>
#include <QList>
#include "formList.h"

#define LINE 1
#define RECTANGLE 2
#define ELLIPSE 3


class Picture : public QWidget
{
  Q_OBJECT

 public:
  Picture(QWidget * parent = 0) : QWidget(parent), type(1) {} 
  void drawType(int id);

 private:
  QPoint EndPoint, StartPoint;
  QPen pen;
  int type;
  // to contain all the parameters of a form
  formList list;


 protected:
  virtual void paintEvent(QPaintEvent*);
  //void drawForm(QPoint , QPoint , QPen, int, QPainter );
  void mousePressEvent(QMouseEvent*); 
  void mouseReleaseEvent(QMouseEvent*); 
  void mouseMoveEvent(QMouseEvent*); 
  

  public slots:
    void setStyle(int id);
    void setWidth(int id);
    void setColor(int id);
    // drawing control 
    void setControl(int id);
   
};

  
#endif // MAINWINDOW_H
