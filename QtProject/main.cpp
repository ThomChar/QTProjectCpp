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
    login l(baseD.getDataBase());
    l.show();
    return a.exec();
}
