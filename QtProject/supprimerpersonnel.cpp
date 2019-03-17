#include "supprimerpersonnel.h"
#include "ui_supprimerpersonnel.h"
#include "mainwindow.h"
#include <QDebug>

SupprimerPersonnel::SupprimerPersonnel(QWidget *parent, QString nomPrenomPersonnel) :
    QDialog(parent),
    ui(new Ui::SupprimerPersonnel)
{
    ui->setupUi(this);
    this->setWindowTitle("Supprimer Personnel");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);

   /* QStringList nomPrenom = QString::fromStdString(nomPrenomPersonnel.toStdString()).split(" ");
    this->nom = nomPrenom.value(0).toStdString();
    this->prenom = nomPrenom.value(1).toStdString();*/
    this->nomPrenom = nomPrenomPersonnel;

    ui->label_3->setText(nomPrenomPersonnel);

    //evenement pour quitter le fomulaire de suppression
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour supprimer le personnel selectionné
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(supprimerPersonnel()));
}

SupprimerPersonnel::~SupprimerPersonnel()
{
    delete ui;
}

void SupprimerPersonnel::supprimerPersonnel(){

    /*qDebug()<< QString::fromStdString(this->nom);
    qDebug()<< QString::fromStdString(this->prenom);*/
    //Obtenir idPersonnel correspondant à nomPrenompersonnel
     int idPersonnel= qobject_cast<MainWindow*>(parent())->getBD()->getIdPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),this->nomPrenom.toStdString());
     //qDebug()<<idPersonnel;

    //Obtenir idCompte du Personnel
     int idCompte = qobject_cast<MainWindow*>(parent())->getBD()->getIdCompte(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),idPersonnel);
     //qDebug()<<idCompte;

    //Supprimer le personnel à la BD
     qobject_cast<MainWindow*>(parent())->getBD()->removePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),idPersonnel,idCompte);

     QList<Personnel> list = qobject_cast<MainWindow*>(parent())->getBD()->getListePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
     //qDebug()<<list.size();

    //Redefinir le model de treeView
     qobject_cast<MainWindow*>(parent())->resetTreePersonnelModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

    //Affichage de la Supression du patient dans la status bar
     qobject_cast<MainWindow*>(parent())->setStatusBar("Personnel "+this->nomPrenom+" a été supprimé !");

    // Fermeture du formulaire
     this->close();
}
void SupprimerPersonnel::annuler(){
    // Fermeture du formulaire
    this->close();
}


