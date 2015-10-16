#include "Picture.h"


void Picture::paintEvent(QPaintEvent* e) {
  
  QWidget::paintEvent(e); // comportement standard (afficher le fond, etc.)
  
  // set pen
  pen.setCapStyle(Qt::RoundCap);
  pen.setJoinStyle(Qt::RoundJoin); 



  QPainter painter(this); // crée un Painter pour ce Picture
  painter.setPen(pen);

    // draw the irregular forms real time
  if(type == POLYGON || type == POLYLINE){
    painter.drawLine(StartPoint, EndPoint);
    
    length = polyform.length();
    points = new QPoint[length];
    
    for (int i = 0; i < length; i++){
      points[i] = polyform.at(i);
    }
      
    // draw polyform
    if(type == POLYLINE)
      painter.drawPolyline(points, length);
    else
      painter.drawPolygon(points, length);


    for (int i = 0; i < length; i++) 
      points[i].isNull();
    length = 0;
  }
  // draw the regular forms real time
  else{
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
  }

  // draw the irregular forms in the list
  for (int i = 0; i < polyform_list.getLength(); i++) {
    length = (polyform_list.getList(i)).length();
    points = new QPoint[length];
      
    for (int j = 0; j < length; j++)
      points[j] = (polyform_list.getList(i)).at(j);
    
    // draw polyform
    painter.setPen(polyform_list.getPen(i));
    if(polyform_list.getType(i) == POLYLINE)
      painter.drawPolyline(points, length);
    else
      painter.drawPolygon(points, length);
        
    for (int j = 0; j < length; j++) points[i].isNull();
    
  }

  // draw the regular forms in the list
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


void Picture::alignList(){
  while(order_length < order.size())
    order.takeLast();
}

void Picture::mousePressEvent(QMouseEvent* e) {

  // particular for the single click when the pointer does not move 
  singleStartPoint = singleEndPoint = e->pos();
  
  /* align list: let the list length equal to be the length which user want  
   * useful for 'redo' and 'undo'  
   */
  list.alignList();
  polyform_list.alignList();
  alignList();

  /* initial
   * for polyforms, we need to seperate the two conditions
   * begin drawing and continue drawing
   */ 
  if(type ==POLYLINE || type == POLYGON){
    if(begin == false){
      begin = true;
      StartPoint = EndPoint = e->pos();
      polyform.append(StartPoint);
    }
    else{
      StartPoint = EndPoint ;
    }
  }
  else
    StartPoint = EndPoint = e->pos();
  

  update(); // demande de réaffichage
}



void Picture::mouseReleaseEvent(QMouseEvent* e) {
 
  // particular for the single click when the pointer does not move 
  singleEndPoint = e->pos();
  
  // if the curse moved, continue
  if(singleEndPoint != singleStartPoint){
    
    // to create a normal form or add a point to polyform
    if(StartPoint != EndPoint){
      if(type ==POLYLINE || type == POLYGON)
	polyform.append(EndPoint);
      else{
	list.append(StartPoint, EndPoint, pen, type);
	order.append(type);
	order_length = order.length();
      }

    }
    EndPoint = e->pos(); 

  }
  
  update(); 
}


void Picture::mouseMoveEvent(QMouseEvent* e) {
  // particular for the single click when the pointer does not move 
  singleEndPoint = e->pos();

  // get the position of moving pointer 
  EndPoint = e->pos(); 
  update(); 
}


void Picture::mouseDoubleClickEvent(QMouseEvent* e) {
  
  begin = false;

  // initial 
  StartPoint = EndPoint = e->pos();

  // add to polyfrom list  
  polyform_list.append(polyform, pen, type);
  // clear the element
  polyform.clear(); 

  // control between two lists
  order.append(type);
  order_length = order.length();
  
  update(); // demande de réaffichage
}



void Picture::setStyle(Qt::PenStyle style){
  pen.setStyle(style);
}

void Picture::setWidth(int w){
  pen.setWidth(w); 
}

void Picture::setColor(QColor c){
  pen.setColor(c); 
}


void Picture::setControl(int id){
   
  // find the control order
  if (id == UNDO){
    if(order_length)  order_length = order_length - 1;
    order_type = order.at(order_length);
  }
  else if (id == REDO){
    if(order_length < order.length())  order_length = order_length + 1;
    else order_length = order.length();
    order_type = order.at(order_length -1 ); 
  }
  else if (id == CLEAR){
    polyform_list.setControl(id);
    list.setControl(id);
    order_length = 0;
  }
  
  std::cout << "order_length"  << order_length << std::endl;  
  std::cout << "order"  << order_type << std::endl;  
  
  if( id != 3 && (order_type == POLYLINE || order_type == POLYGON))
    polyform_list.setControl(id);
  else list.setControl(id);
  

  // clear the points
  StartPoint = EndPoint;
  polyform.clear();  

  update();
}

void Picture::drawType(int id ){
  // clear the points
  StartPoint = EndPoint;
  
  if (id == 1) type = LINE;
  else if (id == 2) type = RECTANGLE;
  else if (id == 3) type = ELLIPSE;
  else if (id == 4) type = POLYLINE;
  else if (id == 5) type = POLYGON;
  update();
}
