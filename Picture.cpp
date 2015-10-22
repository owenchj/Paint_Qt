#include "Picture.h"


void Picture::paintEvent(QPaintEvent* e) {
  
  QWidget::paintEvent(e); // comportement standard (afficher le fond, etc.)
  
  // set pen
  pen.setCapStyle(Qt::RoundCap);
  pen.setJoinStyle(Qt::RoundJoin); 
  
  
  // crée un Painter pour ce Picture

  QPainter painter(this);
  
  if(forms.length()){
    for(int i = 0; i < forms_length; i++){
      painter.setPen(forms[i]->getPen());
      painter.drawPath(forms[i]->getPath());
    }
  }

}



// align the list to let the forms length equal to the real length for redo
void Picture::alignList() {
  while(forms_length < forms.length()){
    // deconstructe
    delete (forms.last());
    forms.takeLast();
  }
}

void Picture::mousePressEvent(QMouseEvent* e) {

  // align the list to meet the user's demande for redo 
  alignList();
  
  
  if(e->button()==Qt::LeftButton){
    
    start = e->pos();
    
    if(mode == SELECT){
      form = selectForms();
    }
    else{
      if(type == LINE){
	line = new Line(LINE);
	line->setLine(start, start);
	line->setPen(pen);
	forms.append(line);
      }
      else if(type == RECTANGLE){
	rectangle = new Rectangle(RECTANGLE);
	rectangle->setRectangle(start, start);
	rectangle->setPen(pen);
	forms.append(rectangle);
      }
      else if(type == ELLIPSE){
	ellipse = new Ellipse(ELLIPSE);
	ellipse->setEllipse(start, start);
	ellipse->setPen(pen);
	forms.append(ellipse);
      }
      else if(type == POLYLINE){
	if(started == false){

	  polyline = new Polyline(POLYLINE);      
	  polyline->addPoint(start, true);
	  polyline->setPen(pen);
	  forms.append(polyline);
	  started = true;
	}
      }
      else if(type == POLYGON){
	if(started == false){

	  polygon = new Polygon(POLYGON);      
	  polygon->addPoint(start, true);
	  polygon->setPen(pen);
	  forms.append(polygon);
	  started = true;
	}
      }
    
      // give the ength of forms 
      forms_length = forms.length();
    }

    
    update();
  }
  
}



void Picture::mouseReleaseEvent(QMouseEvent* e) {

  
  if(e->button()==Qt::LeftButton){

    end = e->pos();

    if(mode == SELECT){
      start_move = false;      
    }
    else{
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
	//  ignore two single click between double click
	if(end != start)
	  ((Polyline*)forms.last())->addPoint(end, true);
      }
      else if(type == POLYGON){
	//  ignore two single click between double click
	if(end != start)
	  ((Polygon*)forms.last())->addPoint(end, true);
      }
    }    
    
    update();
  }  
}


void Picture::mouseMoveEvent(QMouseEvent* e) {
  
  
  end = e->pos();

  if(mode == SELECT){
    moveForms();
  }
  else{
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
  }

    
  update();
  
}


void Picture::mouseDoubleClickEvent(QMouseEvent* e) {
  
  end = e->pos();
  // initialize the started to start a new polyform
  started = false;
 
  update(); 
}



void Picture::setStyle(Qt::PenStyle style){
  
  if(mode == SELECT && form != NULL){
    pen = form->getPen();
    pen.setStyle(style);
    form->setPen(pen);
    
    update();
  }
  else{
    pen.setStyle(style);
  }
}

void Picture::setWidth(int w){

  if(mode == SELECT && form != NULL){

    pen = form->getPen();
    pen.setWidth(w); 
    form->setPen(pen);
    
    update();
  }
  else{
    pen.setWidth(w); 
  }
}

void Picture::setColor(QColor c){

  if(mode == SELECT && form != NULL){

    pen = form->getPen();
    pen.setColor(c); 
    form->setPen(pen);
    
    update();
  }
  else{
    pen.setColor(c); 
  }
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
    // deconstructe
    delete (forms.last());
    forms.takeLast();
  }
  forms.clear();
  
  // initial le length of forms
  forms_length = 0;

  update();
}



void Picture::drawType(int id ){
  // clear the points
  
  if (id == 1) type = LINE;
  else if (id == 2) type = RECTANGLE;
  else if (id == 3) type = ELLIPSE;
  else if (id == 4) type = POLYLINE;
  else if (id == 5) type = POLYGON;
}







void Picture::saveFile(QFile & file){
  // before we save the forms, align the list 
  alignList();

  
  QDataStream out(&file);
  
  out<<forms.size();
  
  
  for(int i=0;i<forms.size();i++){
    out<<forms.at(i)->getID()<<forms.at(i)->getPen()<<forms.at(i)->getPath();
  }
  
  clear();

}

void Picture::openFile(QFile & file){
  // before we save the forms, align the list 

  clear();
  
  QDataStream in(&file);
  
  in>>forms_length;
   
  for(int i = 0; i < forms_length;i++){
    
    QPen open_pen;
    
    QPainterPath open_path;
 
    in>>ID;

    in>>open_pen;
    
    in>>open_path;
    
    Form *f= new Form(ID);
    
    f->setPen(open_pen);
    
    f->setPath(open_path);
    
    forms.append(f);
  }
  
  update();
  
}


Form *Picture::selectForms(){
  
  for(int i = 0; i < forms_length;i++){
    if( (forms.at(i)->getPath()).intersects(QRect(start, QSize(20,20)))){
      return forms.at(i);
    }
  }
  
  return NULL;
}

void Picture::moveForms(){
  


  if(form != NULL){
    QPoint distance =  end - start;    
    path = QPainterPath();
   
    if(!start_move){
      old_path = form->getPath();
      old_start = form->getStart();
      old_end = form->getEnd();
      start_move = true;
    }
   
    
    // if(form->getID() == LINE){
    //   path.moveTo(form->getStart());
    //   path.lineTo(form->getEnd());
    // }
    // else if(form->getID() == RECTANGLE){
    //   path.moveTo(form->getStart());
    //   path.addRect(QRect(form->getStart(), form->getEnd()));
    // }
    if(form->getID() == ELLIPSE){  
      path.moveTo(old_start + distance);
      path.addEllipse(QRect(old_start + distance, old_end + distance));
    }
    else{
      int count = old_path.elementCount();
      for(int i = 0; i < count; i++){
	QPainterPath::Element Element = old_path.elementAt(i);
	
	element.setX(Element.x);
	element.setY(Element.y);
	element = element + distance;
	
	if(i == 0) path.moveTo(element);
	else path.lineTo(element);
      }
      
    }

    form->setPath(path);
  }

  update();

}

void Picture::selectMode(){
  
  if(mode == SELECT)
    mode = PAINT;
  else
    mode = SELECT;  
}
