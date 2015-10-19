#include "Picture.h"


void Picture::paintEvent(QPaintEvent* e) {
  
  QWidget::paintEvent(e); // comportement standard (afficher le fond, etc.)
  
  // set pen
  pen.setCapStyle(Qt::RoundCap);
  pen.setJoinStyle(Qt::RoundJoin); 

  
  QPainter painter(this); // crée un Painter pour ce Picture

  
  if(forms.length()){
    for(int i = 0; i < forms_length; i++){
      painter.setPen(forms[i]->getPen());
      painter.drawPath(forms[i]->getPath());
    }
  }


}



void Picture::alignList() {
  while(forms_length < forms.length()){
      forms.takeLast();
  }
}


void Picture::mousePressEvent(QMouseEvent* e) {
 
  alignList();
  
  if(e->button()==Qt::LeftButton){

    start = e->pos();
    
    if(type == LINE){
      line = new Line();
      line->setLine(start, start);
      line->setPen(pen);
      forms.append(line);
    }
    else if(type == RECTANGLE){
      rectangle = new Rectangle();
      rectangle->setRectangle(start, start);
      rectangle->setPen(pen);
      forms.append(rectangle);
    }
    else if(type == ELLIPSE){
      ellipse = new Ellipse();
      ellipse->setEllipse(start, start);
      ellipse->setPen(pen);
      forms.append(ellipse);
    }
    else if(type == POLYLINE){
      if(started == false){

	polyline = new Polyline();      
	polyline->addPoint(start, true);
	polyline->setPen(pen);
	forms.append(polyline);
	started = true;
      }
    }
    else if(type == POLYGON){
      if(started == false){
	std::cout<<type<<std::endl;
	polygon = new Polygon();      
	polygon->addPoint(start, true);
	polygon->setPen(pen);
	forms.append(polygon);
	started = true;
      }
    }
    
    forms_length = forms.length();
    
    update();
  }
  
}



void Picture::mouseReleaseEvent(QMouseEvent* e) {

  
  if(e->button()==Qt::LeftButton){

    end = e->pos();
    
    if(type == LINE){
      ((Line*)forms.last())->setLine(start, end);
    }
    else if(type == RECTANGLE){
      ((Rectangle*)forms.last())->setRectangle(start, end);
    }
    else if(type == ELLIPSE){
      ((Ellipse*)forms.last())->setEllipse(start, end);
    }
    else if(type == POLYLINE){
      if(end != start)
	((Polyline*)forms.last())->addPoint(end, true);
    }
    else if(type == POLYGON){
      if(end != start)
	((Polygon*)forms.last())->addPoint(end, true);
    }
    

    update();
  }  
}


void Picture::mouseMoveEvent(QMouseEvent* e) {
  
  
  end = e->pos();
  
  if(type == LINE){
    ((Line*)forms.last())->setLine(start, end);
  }
  else if(type == RECTANGLE){
    ((Rectangle*)forms.last())->setRectangle(start, end);
  }
  else if(type == ELLIPSE){
    ((Ellipse*)forms.last())->setEllipse(start, end);
  }
  else if(type == POLYLINE){
    ((Polyline*)forms.last())->addPoint(end, false);
  }
  else if(type == POLYGON){
    ((Polygon*)forms.last())->addPoint(end, false);
  }

    
  update();
  
}


void Picture::mouseDoubleClickEvent(QMouseEvent* e) {
  
  end = e->pos();
 
  // if(type == POLYLINE){
  //   ((Polyline*)forms.last())->addPoint(end, true);
  // }
  
  started = false;
  update(); 
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
  if(id == UNDO) undo();
  else if(id == REDO) redo();
  else if(id == CLEAR) clear();
}



void Picture::undo(){
  if(forms_length != 0) 
    forms_length = forms_length - 1;

  update();
}


void Picture::redo(){
  if(forms_length < forms.length())
    forms_length = forms_length + 1;
  
  update();
}


void Picture::clear(){
  while(!forms.isEmpty()){
    forms.clear();
  }
  forms_length = 0;
  update();
}



void Picture::drawType(int id ){
  // clear the points
  start = end;
  started = false;

  if (id == 1) type = LINE;
  else if (id == 2) type = RECTANGLE;
  else if (id == 3) type = ELLIPSE;
  else if (id == 4) type = POLYLINE;
  else if (id == 5) type = POLYGON;
}


