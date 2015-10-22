#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(600, 600);
    w.setWindowTitle("Painter");
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    w.show();

    return a.exec();
}
