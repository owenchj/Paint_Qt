#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>

#include <QWidget> 
#include <QPainter>
#include <QAction>
#include <QMouseEvent>
#include <QLine>
#include <QDataStream> 
#include <QFile> 
#include <QFileDialog>
#include <QPicture>

#include "line.h"
#include "ellipse.h"
#include "rectangle.h"
#include "polyline.h"
#include "polygon.h"
#include "parameter.h"


class Picture : public QWidget
{
  Q_OBJECT
    
 private:
  QPoint EndPoint, StartPoint;
  QPoint end, start;
  QPen pen;
  int type;
  Line *line;
  Rectangle *rectangle;
  Ellipse *ellipse;
  Polyline *polyline;
  Polygon *polygon;
  QList <Form * > forms;
  
  bool started;
 
  int forms_length;
  

 public:

 Picture(QWidget * parent = 0) : QWidget(parent), type(1), started(false), forms_length(0) { pen.setColor(Qt::red); }

  virtual ~Picture(){}

  void alignList();
  
  void drawType(int id);

  void setStyle(Qt::PenStyle style);
  void setWidth(int w);
  void setColor(QColor c);
  void setControl(int id);

  void undo();
  void redo();
  void clear();

  void saveFile(QFile &);
  void openFile(QFile &);
  
  void moveForms(QPoint &);

  
 protected:
  virtual void paintEvent(QPaintEvent*);
  void mousePressEvent(QMouseEvent*); 
  void mouseReleaseEvent(QMouseEvent*); 
  void mouseMoveEvent(QMouseEvent*); 
  void mouseDoubleClickEvent(QMouseEvent*);  
    
};

  
#endif // MAINWINDOW_H
