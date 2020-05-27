#include "mainwindow.h"
#include "skin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //QApplication::setStyle("Windows");
    QApplication a(argc, argv);
    Skin skin;
    skin.show();
    return a.exec();
}
