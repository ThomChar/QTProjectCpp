#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    w = new MainWindow();
    this->setWindowTitle("Authentification");
    this->setFixedSize( this->size());

    //connection
    //evenement pour annuler
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(close()));
    //evenement pour connecter
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(connection()));
}


login::~login()
{
    delete ui;
}

/**
 * Methode permettant de verifier les informations entree pour connection et de renvoyer utilisateur vers main window si elles sont correctes
 * @brief login::connection
 */
void login::connection()
{
    QString login, password;
    login = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    // verifications
    if(verificationLogin(login, password)){ // à relier avec la fonction pour controler l'identifiant user
        this->close();
        w->setWindowTitle("Gestion Patient");
        w->show();
    }
    else {
        ui->lineEdit -> setText(login);
        ui->lineEdit_2 -> setText("");
        QMessageBox msgBox;
        msgBox.setText("Login ou mot de passe incorrecte");
        msgBox.exec();
    }
}

/**
 * @brief LogIn::verificationLogin
 * @return true or false
 */
bool login::verificationLogin(QString login, QString password) {

    bool test = false;

    // verifications
    if(login == "admin" && password == "password"){ // à relier avec la fonction pour controler l'identifiant user
       test = true;
    }

    return test;
}
