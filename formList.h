#ifndef FORMLIST_H
#define FORMLIST_H

#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QList>



class formList
{
 
 private:

  QList<QPoint > starts;
  QList<QPoint > ends;
  QList<QPen > pens;
  QList<int > types;
  int listLength;

 public:
 formList(): listLength(0){}
  ~formList(){}
  
  void setControl(int id){
    
    

    if (id == -2){
      if(listLength != 0) listLength = listLength - 1;
    }
    else if (id == -3){
      if(listLength < pens.size()) listLength = listLength + 1;
    }
    else if (id == -4){
      while (!pens.isEmpty()){
	pens.clear();
	starts.clear();
	ends.clear();
    types.clear();
      }
    }
     
  }


  void append(QPoint start, QPoint end, QPen pen, int type) {
    pens.append(pen);
    starts.append(start);
    ends.append(end);
    types.append(type);
    listLength = pens.size();
    std::cout <<"Num of lines:  " << pens.length() << ' '<<listLength << std::endl;

  }

  int getType(int i) const { return types.at(i); }
  int getLength() const { return listLength; }
  QPen  getPen(int i) const { return pens.at(i); }
  QPoint  getStart(int i) const { return starts.at(i); }
  QPoint  getEnd(int i) const { return ends.at(i); }
  
  bool isEmpty() const { return pens.isEmpty(); }

  void alignList() {
    while(listLength < pens.size()){
      pens.takeLast();
      starts.takeLast();
      ends.takeLast();
      types.takeLast();
    }
  }
  
};

  
#endif // MAINWINDOW_H
