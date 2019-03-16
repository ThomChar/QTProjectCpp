#include "mainwindow.h"
#include "login.h"
#include "c_init_bd.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    c_init_bd baseD;
    baseD.Creation_BD();
    //login l(new QWidget(),baseD.getDataBase());
    login l(baseD.getDataBase());
    //login l(baseD.getDataBase());
    l.show();
    //MainWindow w;
    //w.show();
    return a.exec();
}
