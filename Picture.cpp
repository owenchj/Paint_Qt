#include "Picture.h"




// void drawForm(QPoint start, QPoint end, QPen pencile, int formType, QPainter &painter){

//   painter.setPen(pencile);
 
//   if(formType == LINE){
//     painter.drawLine(start, end);
//   }
//   else if(formType == RECTANGLE){
//     QRectF * rectangle = new QRectF(start, end);
//     painter.drawRect( *rectangle );
//   }
//   else if(formType == ELLIPSE){
//     QRectF * rectangle = new QRectF(start, end);
//     painter.drawEllipse(*rectangle);
//   }
    
// }

void Picture::paintEvent(QPaintEvent* e) {
  
  QWidget::paintEvent(e); // comportement standard (afficher le fond, etc.)
  
  // set pen
  pen.setCapStyle(Qt::RoundCap);
  pen.setJoinStyle(Qt::RoundJoin); 

  QPainter painter(this); // crée un Painter pour ce Picture
  painter.setPen(pen);

  if(type == LINE){
    painter.drawLine(StartPoint, EndPoint);
  }
  else if(type == RECTANGLE){
    QRectF * rectangle = new QRectF(StartPoint, EndPoint);
    painter.drawRect( *rectangle );
  }
  else if(type == ELLIPSE){
    QRectF * rectangle = new QRectF(StartPoint, EndPoint);
    painter.drawEllipse(*rectangle);
  }

 
  for (int i = 0; i < list.getLength(); ++i) {
    if(!list.isEmpty()){
      // choose the pen
      painter.setPen(list.getPen(i));

      if(list.getType(i) == LINE){

	painter.drawLine(list.getStart(i), list.getEnd(i));
      }
      else if(list.getType(i) == RECTANGLE){
	QRectF * rectangle = new QRectF(list.getStart(i), list.getEnd(i));
	painter.drawRect( *rectangle );
      }
      else if(list.getType(i) == ELLIPSE){
	QRectF * rectangle = new QRectF(list.getStart(i), list.getEnd(i));
	painter.drawEllipse(*rectangle);
      }
    
    }
  } 

}

void Picture::mousePressEvent(QMouseEvent* e) {

  // align list: let the list length equal to be the length which user want  
  list.alignList();

  // initial
  StartPoint = EndPoint = e->pos();
  update(); // demande de réaffichage

}

void Picture::mouseReleaseEvent(QMouseEvent* e) {
  
  EndPoint = e->pos(); 
  

  //
  list.append(StartPoint, EndPoint, pen, type);

  update(); // demande de réaffichage
 

  
  
}

void Picture::mouseMoveEvent(QMouseEvent* e) {
  
  EndPoint = e->pos(); 
  update(); // demande de réaffichage
 
}


void Picture::setStyle(int id){
  
  std::cout <<"s: " <<id << std::endl;
  if (id == -2) pen.setStyle(Qt::DashLine);
  else if (id == -3) pen.setStyle(Qt::DotLine);
  else if (id == -4) pen.setStyle(Qt::DashDotLine);
    
}

void Picture::setWidth(int id){
  
  std::cout <<"w: " <<id << std::endl;
  if (id == -2) pen.setWidth(1);
  else if (id == -3) pen.setWidth(2);
  else if (id == -4) pen.setWidth(3);
}

void Picture::setColor(int id){
  
  std::cout <<"c: " <<id << std::endl;
  if (id == -2) pen.setColor(Qt::red);
  else if (id == -3) pen.setColor(Qt::green);
  else if (id == -4) pen.setColor(Qt::blue);
  
}


void Picture::setControl(int id){
  
  list.setControl(id);
  // clear the points
  StartPoint = EndPoint;
  update();
}

void Picture::drawType(int id ){

  // clear the points
  StartPoint = EndPoint;
  
  if (id == 1) type = LINE;
  else if (id == 2) type = RECTANGLE;
  else if (id == 3) type = ELLIPSE;
  update();
}
