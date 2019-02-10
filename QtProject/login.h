#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:

    void connection();

private:
    Ui::login *ui;
    MainWindow *w;
    bool verificationLogin(QString login, QString password);

};

#endif // LOGIN_H
