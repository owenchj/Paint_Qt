#ifndef POLYFORMS
#define POLYFORMS

#include <QPoint>
#include <QPen>
#include <QList>
#include "parameter.h"



class polyForms
{
 
 private:

  QList<QList<QPoint > > lists;
  QList<QPen > pens;
  QList<int> types;
  int listLength;


 public:
 polyForms():listLength(0){}
  ~polyForms(){}
  
  void setControl(int id){

    if (id == UNDO){
      if(listLength != 0) listLength = listLength - 1;
    }
    else if (id == REDO){
      if(listLength < pens.size()) listLength = listLength + 1;
    }
    else if (id == CLEAR){
      listLength = 0;
      while(listLength < pens.size()){
	pens.takeLast();
        lists.takeLast();   // !!
	types.takeLast();
      }
    }

  }
  

  void append( QList<QPoint > list, QPen pen, int type) {
    pens.append(pen);
    lists.append(list);
    types.append(type);
    listLength = lists.length();
 
    std::cout <<"Num of poly:  " << pens.length() << ' '<<listLength << std::endl;
  }

  int getType(int i) const { return types.at(i); }
  int getLength() const { return listLength; }
  QPen  getPen(int i) const { return pens.at(i); }
  QList<QPoint >  getList(int i) const { return lists.at(i); }
  
  bool isEmpty() const { return pens.isEmpty(); }

  void alignList() {
    while(listLength < pens.size()){
      pens.takeLast();
      lists.takeLast();
      types.takeLast();
    }
  }
  
};

  
#endif // MAINWINDOW_H
