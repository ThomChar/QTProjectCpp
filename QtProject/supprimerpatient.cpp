#include "supprimerpatient.h"
#include "mainwindow.h"
#include "patient.h"
#include "ui_supprimerpatient.h"

SupprimerPatient::SupprimerPatient(QWidget *parent, int idPatient, QString nomPatient, QString prenomPatient) :
    QDialog(parent),
    ui(new Ui::SupprimerPatient)
{
    ui->setupUi(this);
    this->idPatient = idPatient;
    this->nomPatient = nomPatient.toStdString();
    this->prenomPatient = prenomPatient.toStdString();
    this->setWindowTitle("Supprimer Patient");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->label_3->setText(nomPatient + " " + prenomPatient);

    //evenement pour quitter le fomulaire de suppression
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour supprimer le patient selectionné
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(supprimerPatient()));
}

SupprimerPatient::~SupprimerPatient()
{
    delete ui;
}

void SupprimerPatient::supprimerPatient(){
    //Supprimer le patient à la BD
     qobject_cast<MainWindow*>(parent())->getBD()->removePatient(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),this->idPatient);
    //Redefini le model de BD
     qobject_cast<MainWindow*>(parent())->resetTablePatientModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
    //Affichage de la Supression du patient dans la status bar
     qobject_cast<MainWindow*>(parent())->setStatusBar("Patient "+QString::fromStdString(nomPatient)+" "+QString::fromStdString(prenomPatient)+" a été supprimé !");
    // Fermeture du formulaire
    this->close();
}
void SupprimerPatient::annuler(){
    // Fermeture du formulaire
    this->close();
}

