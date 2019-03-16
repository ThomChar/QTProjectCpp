#include "supprimerpersonnel.h"
#include "ui_supprimerpersonnel.h"
#include "mainwindow.h"

SupprimerPersonnel::SupprimerPersonnel(QWidget *parent, int idPersonnel, QString nomPersonnel, QString prenomPersonnel) :
    QDialog(parent),
    ui(new Ui::SupprimerPersonnel)
{
    ui->setupUi(this);
    this->idPersonnel = idPersonnel;
    this->nomPersonnel = nomPersonnel.toStdString();
    this->prenomPersonnel = prenomPersonnel.toStdString();
    this->setWindowTitle("Supprimer Patient");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->label_3->setText(nomPersonnel + " " + prenomPersonnel);

    //evenement pour quitter le fomulaire de suppression
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour supprimer le patient selectionné
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(supprimerPersonnel()));
}

SupprimerPersonnel::~SupprimerPersonnel()
{
    delete ui;
}

void SupprimerPersonnel::supprimerPersonnel(){
    //Supprimer le patient à la BD
     qobject_cast<MainWindow*>(parent())->getBD()->removePatient(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),this->idPersonnel);
    //Redefini le model de BD
     qobject_cast<MainWindow*>(parent())->resetTablePatientModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
    //Affichage de la Supression du patient dans la status bar
     qobject_cast<MainWindow*>(parent())->setStatusBar("Personnel "+QString::fromStdString(nomPersonnel)+" "+QString::fromStdString(prenomPersonnel)+" a été supprimé !");
    // Fermeture du formulaire
    this->close();
}
void SupprimerPersonnel::annuler(){
    // Fermeture du formulaire
    this->close();
}


