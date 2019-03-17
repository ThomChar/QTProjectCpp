#include <string>
#include "supprimertypepersonnel.h"
#include "ui_supprimertypepersonnel.h"
#include "mainwindow.h"

using namespace std;

supprimerTypePersonnel::supprimerTypePersonnel(QWidget *parent, int idType, QString label) :
    QDialog(parent),
    ui(new Ui::supprimerTypePersonnel)
{
    ui->setupUi(this);
    this->setWindowTitle("Supprimer Type Personnel");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->idType = idType;
    this->label = label;

    ui->label_3->setText(label);

    //evenement pour quitter le fomulaire de suppression
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour supprimer le type de personnel selectionné
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(suppressionTypePersonnel()));
}

supprimerTypePersonnel::~supprimerTypePersonnel()
{
    delete ui;
}

void supprimerTypePersonnel::suppressionTypePersonnel(){

    //Supprimer le personnel à la BD
     qobject_cast<MainWindow*>(parent())->getBD()->supprimerTypePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),this->idType);

     QList<Personnel> list = qobject_cast<MainWindow*>(parent())->getBD()->getListePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
     //qDebug()<<list.size();

    //Redefinir le model de tableTypePersonnel
     qobject_cast<MainWindow*>(parent())->resetTableTypesPersModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

    // Fermeture du formulaire
     this->close();
}

void supprimerTypePersonnel::annuler(){
    // Fermeture du formulaire
    this->close();
}
