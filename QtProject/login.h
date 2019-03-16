#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
#include <QSqlDatabase>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    //login(QWidget *parent, QSqlDatabase db);
     login(QWidget *parent,QSqlDatabase db);
     login(QSqlDatabase db);
    ~login();

private slots:

    void connection();

private:
    Ui::login *ui;
    MainWindow *w;
    RequeteBD * requetebd;
    QSqlDatabase database;
    bool verificationLogin(QString login, QString password);

};

#endif // LOGIN_H
