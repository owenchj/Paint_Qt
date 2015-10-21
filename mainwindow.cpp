#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPalette>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);


  // menuBar() est une method de QMainWindow
  QMenuBar * menuBar = this->menuBar();
  
  /* Add to menu bar 'file'
  **/
  fileMenu = menuBar->addMenu( tr ("&File") );
  
  NewAction = new QAction( QIcon(":new.png"), tr("&New..."), this);
  NewAction->setShortcut( tr("Ctrl+N")); // accélérateur clavier
  NewAction->setToolTip( tr("New file")); // bulle d’aide
  NewAction->setStatusTip( tr("New file")); // barre de statut
  fileMenu->addAction(NewAction); // rajouter l’action au menu déroulant
  // connecter le signal à un slot de this
  connect(NewAction, SIGNAL(triggered( )), this, SLOT(openFile( )));

  
  OpenAction = new QAction( QIcon(":open.png"), tr("&Open..."), this);
  OpenAction->setShortcut( tr("Ctrl+O")); // accélérateur clavier
  OpenAction->setToolTip( tr("Open file")); // bulle d’aide
  OpenAction->setStatusTip( tr("Open file")); // barre de statut
  fileMenu->addAction(OpenAction); // rajouter l’action au menu déroulant
  // connecter le signal à un slot de this
  connect(OpenAction, SIGNAL(triggered( )), this, SLOT(openFile( )));


  SaveAction = new QAction( QIcon(":save.png"), tr("&Save..."), this);
  SaveAction->setShortcut( tr("Ctrl+S")); // accélérateur clavier
  SaveAction->setToolTip( tr("Save file")); // bulle d’aide
  SaveAction->setStatusTip( tr("Save file")); // barre de statut
  fileMenu->addAction(SaveAction); // rajouter l’action au menu déroulant
  // connecter le signal à un slot de this
  connect(SaveAction, SIGNAL(triggered( )), this, SLOT(saveFile( )));

  QuitAction = new QAction( QIcon(":quit.png"), tr("&Quit..."), this);
  QuitAction->setShortcut( tr("Ctrl+Q")); // accélérateur clavier
  QuitAction->setToolTip( tr("Quit file")); // bulle d’aide
  QuitAction->setStatusTip( tr("Quit file")); // barre de statut
  fileMenu->addAction(QuitAction); // rajouter l’action au menu déroulant
  // connecter le signal à un slot de this
  connect(QuitAction, SIGNAL(triggered( )), this, SLOT(quitFile( )));
  


  /* Add to menu bar 'edit'
  **/
  editMenu = menuBar->addMenu( tr ("&Edit") );
  
  CutAction = new QAction( QIcon(":cut.png"), tr("&Cut..."), this);
  CutAction->setShortcut( tr("Ctrl+X")); // accélérateur clavier
  CutAction->setToolTip( tr("Cut file")); // bulle d’aide
  CutAction->setStatusTip( tr("Cut file")); // barre de statut
  editMenu->addAction(CutAction); // rajouter l’action au menu déroulant
  // connecter le signal à un slot de this
  connect(CutAction, SIGNAL(triggered( )), this, SLOT(cutFile( )));
  
  CopyAction = new QAction( QIcon(":copy.png"), tr("&Copy..."), this);
  CopyAction->setShortcut( tr("Ctrl+C")); // accélérateur clavier
  CopyAction->setToolTip( tr("Copy file")); // bulle d’aide
  CopyAction->setStatusTip( tr("Copy file")); // barre de statut
  editMenu->addAction(CopyAction); // rajouter l’action au menu déroulant
  // connecter le signal à un slot de this
  connect(CopyAction, SIGNAL(triggered( )), this, SLOT(copyFile( )));

  PasteAction = new QAction( QIcon(":paste.png"), tr("&Paste..."), this);
  PasteAction->setShortcut( tr("Ctrl+P")); // accélérateur clavier
  PasteAction->setToolTip( tr("Paste file")); // bulle d’aide
  PasteAction->setStatusTip( tr("Paste file")); // barre de statut
  editMenu->addAction(PasteAction); // rajouter l’action au menu déroulant
  // connecter le signal à un slot de this
  connect(PasteAction, SIGNAL(triggered( )), this, SLOT(pasteFile( )));
  
  

  /* Add to menu bar 'draw'
  **/
  drawMenu = menuBar->addMenu( tr ("&Draw") );
  LineAction = new QAction( QIcon(":line.png"), tr("&Line..."), this);
  LineAction->setShortcut( tr("Ctrl+l")); // accélérateur clavier
  LineAction->setToolTip( tr("Line file")); // bulle d’aide
  LineAction->setStatusTip( tr("Line file")); // barre de statut
  drawMenu->addAction(LineAction); // rajouter l’action au menu déroulant
  // connecter le signal à un slot de this
  // connect(LineAction, SIGNAL(triggered( )), pic, SLOT(cutFile( )));
  
  RectangleAction = new QAction( QIcon(":rectangle.png"), tr("&Rectangle..."), this);
  RectangleAction->setShortcut( tr("Ctrl+r")); // accélérateur clavier
  RectangleAction->setToolTip( tr("Rectangle file")); // bulle d’aide
  RectangleAction->setStatusTip( tr("Rectangle file")); // barre de statut
  drawMenu->addAction(RectangleAction); // rajouter l’action au menu déroulant
 


  EllipseAction = new QAction( QIcon(":ellipse.png"), tr("&Ellipse..."), this);
  EllipseAction->setShortcut( tr("Ctrl+e")); // accélérateur clavier
  EllipseAction->setToolTip( tr("Ellipse file")); // bulle d’aide
  EllipseAction->setStatusTip( tr("Ellipse file")); // barre de statut
  drawMenu->addAction(EllipseAction); // rajouter l’action au menu déroulant

  PolylineAction = new QAction( QIcon(":polyline.png"), tr("&Polyline..."), this);
  PolylineAction->setShortcut( tr("Ctrl+a")); // accélérateur clavier
  PolylineAction->setToolTip( tr("Polyline file")); // bulle d’aide
  PolylineAction->setStatusTip( tr("Polyline file")); // barre de statut
  drawMenu->addAction(PolylineAction); // rajouter l’action au menu déroulant
 
  PolygonAction = new QAction( QIcon(":polygon.png"), tr("&Polygon..."), this);
  PolygonAction->setShortcut( tr("Ctrl+b")); // accélérateur clavier
  PolygonAction->setToolTip( tr("Polygon file")); // bulle d’aide
  PolygonAction->setStatusTip( tr("Polygon file")); // barre de statut
  drawMenu->addAction(PolygonAction); // rajouter l’action au menu déroulant
 

  /* Add to menu bar 'help'
  **/
  helpMenu = menuBar->addMenu( tr ("&Help") );




  /* Tool Bar
  **/
  New_toolBar = this->addToolBar( tr("New") );
  New_toolBar->addAction(NewAction); 
 
  Open_toolBar = this->addToolBar( tr("Open") );
  Open_toolBar->addAction(OpenAction); 
  
  Save_toolBar = this->addToolBar( tr("Save") );
  Save_toolBar->addAction(SaveAction); 
  
  Cut_toolBar = this->addToolBar( tr("Cut") );
  Cut_toolBar->addAction(CutAction); 
  
  Copy_toolBar = this->addToolBar( tr("Copy") );
  Copy_toolBar->addAction(CopyAction); 
  
  Paste_toolBar = this->addToolBar( tr("Paste") );
  Paste_toolBar->addAction(PasteAction); 

  Line_toolBar = this->addToolBar( tr("Line") );
  Line_toolBar->addAction(LineAction); 
  
  Rectangle_toolBar = this->addToolBar( tr("Rectangle") );
  Rectangle_toolBar->addAction(RectangleAction); 
  
  Ellipse_toolBar = this->addToolBar( tr("Ellipse") );
  Ellipse_toolBar->addAction(EllipseAction); 
  
  Polyline_toolBar = this->addToolBar( tr("Polyline") );
  Polyline_toolBar->addAction(PolylineAction); 
  
  Polygon_toolBar = this->addToolBar( tr("Polygon") );
  Polygon_toolBar->addAction(PolygonAction); 
  
  
  

  
    
  QWidget * wdg = new QWidget(this);
  QVBoxLayout *layout = new QVBoxLayout(wdg);
  
  // // add widget text
  // textEdit = new QTextEdit;
  // layout->addWidget(textEdit);
  // // add widget button
  // quitButton = new QPushButton(tr("Quit"));
  // connect(quitButton, SIGNAL(clicked()), this, SLOT(quitFile()));
  // layout->addWidget(quitButton);
  
  pic = new Picture;
  pic->setMaximumSize(500,500);
  // QPalette pal = pic->palette();
  // pal.setColor(pic->backgroundRole(), Qt::blue);
  // pic->setPalette(pal);
  layout->addWidget(pic);

  QVBoxLayout * color_v_layout = new QVBoxLayout();
  QVBoxLayout * style_v_layout = new QVBoxLayout();
  QVBoxLayout * width_v_layout = new QVBoxLayout();
  QVBoxLayout * control_v_layout = new QVBoxLayout();
  
  colorButton_r = new QPushButton(tr("Red"));
  colorButton_g = new QPushButton(tr("Green"));
  colorButton_b = new QPushButton(tr("Blue"));

  styleButton_1 = new QPushButton(tr("---"));
  styleButton_2 = new QPushButton(tr("..."));
  styleButton_3 = new QPushButton(tr("-.-"));
  
  widthButton_1 = new QPushButton(tr("w_1"));
  widthButton_2 = new QPushButton(tr("w_2"));
  widthButton_3 = new QPushButton(tr("W_3"));

  controlButton_1 = new QPushButton(tr("undo"));
  controlButton_2 = new QPushButton(tr("redo"));
  controlButton_3 = new QPushButton(tr("clear"));

  color_v_layout->addWidget(colorButton_r);
  color_v_layout->addWidget(colorButton_g);
  color_v_layout->addWidget(colorButton_b);
 

  style_v_layout->addWidget( styleButton_1 );
  style_v_layout->addWidget( styleButton_2 );
  style_v_layout->addWidget( styleButton_3 );
   
  width_v_layout->addWidget(widthButton_1);
  width_v_layout->addWidget(widthButton_2);
  width_v_layout->addWidget(widthButton_3);
 
  control_v_layout->addWidget(controlButton_1);
  control_v_layout->addWidget(controlButton_2);
  control_v_layout->addWidget(controlButton_3);
 
  
  QHBoxLayout * h_layout = new QHBoxLayout( );
  h_layout->addLayout( color_v_layout ); 
  h_layout->addLayout( style_v_layout ); 
  h_layout->addLayout( width_v_layout ); 
  h_layout->addLayout( control_v_layout ); 
  
  // the top layout 
  layout -> addLayout(h_layout);
  

  // connect the layout and new wdg
  wdg->setLayout(layout);	   
  setCentralWidget(wdg); 

  // button group
  QButtonGroup * colorgroup = new QButtonGroup(this);
  colorgroup->addButton(colorButton_r);
  colorgroup->addButton(colorButton_g);
  colorgroup->addButton(colorButton_b);
  connect(colorgroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(setColor(QAbstractButton* )));

  
  QButtonGroup * stylegroup = new QButtonGroup(this);
  stylegroup->addButton(styleButton_1);
  stylegroup->addButton(styleButton_2);
  stylegroup->addButton(styleButton_3);
  connect(stylegroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(setStyle(QAbstractButton* )));

  QButtonGroup * widthgroup = new QButtonGroup(this);
  widthgroup->addButton(widthButton_1);
  widthgroup->addButton(widthButton_2);
  widthgroup->addButton(widthButton_3);
  connect(widthgroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(setWidth(QAbstractButton* )));

  QButtonGroup * controlgroup = new QButtonGroup(this);
  controlgroup->addButton(controlButton_1);
  controlgroup->addButton(controlButton_2);
  controlgroup->addButton(controlButton_3);
  connect(controlgroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(setControl(QAbstractButton*)));

  // action group
  QActionGroup *drawgroup = new QActionGroup(this);
  drawgroup->addAction(LineAction);
  drawgroup->addAction(RectangleAction); 
  drawgroup->addAction(EllipseAction); 
  drawgroup->addAction(PolylineAction); 
  drawgroup->addAction(PolygonAction); 
  connect(drawgroup, SIGNAL(triggered(QAction *)), this, SLOT(setType(QAction *)));

  
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::openFile()
{
  QString fileName =
    QFileDialog::getOpenFileName( this,
				  tr("Open File"), // titre
				  "/home/owen", // répertoire initial
				  tr("Image Files (*)") // filtre
				  );

  if (fileName != "") {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
      return;
    }
  
   
    pic->openFile(file);
   
    file.close();
  }
}
  
void MainWindow::saveFile()
{
  QString fileName =
    QFileDialog::getSaveFileName( this,
				  tr("Save File"), // titre
				  "/home/owen", // répertoire initial
				  tr("Image Files (*)") // filtre
				  );
  
  if (fileName != "") {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
      // error message
    } else {
      pic->saveFile(file);
      file.close();
    }
    
  } else{
    // error
  }
    
}

void MainWindow::quitFile()
{
  QMessageBox messageBox;
  messageBox.setWindowTitle(tr("Notepad"));
  messageBox.setText(tr("Do you really want to quit?"));
  messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  messageBox.setDefaultButton(QMessageBox::No);
  if (messageBox.exec() == QMessageBox::Yes)
    qApp->quit();
}



void MainWindow::closeEvent(QCloseEvent *event)
{
  // the same with quit button
  quitFile(); 
  // if it doesn't quit, ignore the event request
  event->ignore();
}

void MainWindow::cutFile(){}
void MainWindow::copyFile(){}
void MainWindow::pasteFile(){}

void MainWindow::setType(QAction * sender){
  if (sender == LineAction) pic->drawType(LINE);
  else if (sender == RectangleAction) pic->drawType(RECTANGLE);
  else if (sender == EllipseAction) pic->drawType(ELLIPSE);
  else if (sender == PolylineAction) pic->drawType(POLYLINE);
  else if (sender == PolygonAction) pic->drawType(POLYGON);
}

void MainWindow::setColor(QAbstractButton* button){
     if( button == colorButton_r) pic->setColor(Qt::red);
     else if(button == colorButton_g) pic->setColor(Qt::green);
     else if(button == colorButton_b) pic->setColor(Qt::blue);
}

void MainWindow::setWidth(QAbstractButton* button){
     if(button == widthButton_1) pic->setWidth(1);
     else if(button == widthButton_2) pic->setWidth(2);
     else if(button == widthButton_3) pic->setWidth(3);
}

void MainWindow::setStyle(QAbstractButton* button){

     if(button == styleButton_1) pic->setStyle(Qt::DashLine);
     else if(button == styleButton_2) pic->setStyle(Qt::DotLine);
     else if(button == styleButton_3) pic->setStyle(Qt::DashDotLine);
}

void MainWindow::setControl(QAbstractButton* button){
 
     if(button == controlButton_1) pic->setControl(UNDO);
     else if(button == controlButton_2) pic->setControl(REDO);
     else if(button == controlButton_3) pic->setControl(CLEAR);
}

// # widget
// greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
