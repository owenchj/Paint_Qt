
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QtWidgets>
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QPainter>
#include "Picture.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  
 protected:
  void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
  
 private:
  Ui::MainWindow *ui;


  // file menu
  QMenu *fileMenu;
  QAction *NewAction;
  QAction *OpenAction;
  QAction *SaveAction;
  QAction *QuitAction;

  // edit menu
  QMenu *editMenu;
  QAction * CutAction;
  QAction * CopyAction;
  QAction * PasteAction;

  // draw menu
  QMenu * drawMenu;
  QAction * LineAction;
  QAction * RectangleAction;
  QAction * EllipseAction;
  QAction * PolylineAction;
  QAction * PolygonAction;
  
  // help menu
  QMenu * helpMenu;


  
  // tool bars
  QToolBar * New_toolBar;
  QToolBar * Open_toolBar;
  QToolBar * Save_toolBar;
  QToolBar * Cut_toolBar;
  QToolBar * Copy_toolBar;
  QToolBar * Paste_toolBar;
  QToolBar * Line_toolBar;
  QToolBar * Rectangle_toolBar;
  QToolBar * Ellipse_toolBar;
  QToolBar * Polyline_toolBar;
  QToolBar * Polygon_toolBar;



  Picture * pic;
  /* // actions to adjust color */
  /* QAction * colorAction_r; */
  /* QAction * colorAction_g; */
  /* QAction * colorAction_b; */

  /* // actions to adjust width */
  /* QAction * widthAction_1; */
  /* QAction * widthAction_2; */
  /* QAction * widthAction_3; */

  /* // actions to adjust style */
  /* QAction * styleAction_1; */
  /* QAction * styleAction_2; */
  /* QAction * styleAction_3; */

  // color button 
  QPushButton *colorButton_r ;
  QPushButton *colorButton_g ;
  QPushButton *colorButton_b ;

  // style button 
  QPushButton *styleButton_1 ;
  QPushButton *styleButton_2 ;
  QPushButton *styleButton_3 ;
  
  // width button   
  QPushButton *widthButton_1 ;
  QPushButton *widthButton_2 ;
  QPushButton *widthButton_3 ;
 
  // control button   
  QPushButton *controlButton_1 ;
  QPushButton *controlButton_2 ;
  QPushButton *controlButton_3 ;
 
  // text edit
  QTextEdit *textEdit;
  // quit button
  QPushButton *quitButton;

 private slots:
    void openFile();
    void saveFile();
    void quitFile();
    void cutFile();
    void copyFile();
    void pasteFile();
    void setType(QAction * sender);
    void setColor(QAbstractButton* button);
    void setWidth(QAbstractButton* button);
    void setStyle(QAbstractButton* button);
    void setControl(QAbstractButton* button);
    // signals:
    // void triggered();
};

#endif // MAINWINDOW_H
