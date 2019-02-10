#include "ajoutpersonnel.h"
#include "ui_ajoutpersonnel.h"

ajoutPersonnel::ajoutPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutPersonnel)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Personnel");

    //Evennements
    //evenement pour quitter application
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(close()));
    //evenement pour  afficher formulaire ajouterPatient
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(ajouterPersonnel()));

}

/**
 * Methode permettant de verifier les informations entree et ajouter le personnel si toutes les informations nécessaires sont correctes
 * @brief ajoutPersonnel::ajouterPersonnel
 */
void ajoutPersonnel::ajouterPersonnel()
{
    /*QString login, password;
    login = ui->lineEdit->text();
    password = ui->lineEdit_2->text();*/

    // verifications
   /* if(verificationLogin(login, password)){ // à relier avec la fonction pour controler l'identifiant user
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
    }*/

    // une fois ajout effectue, on close la fenetre
    this->close();
}


ajoutPersonnel::~ajoutPersonnel()
{
    delete ui;
}
