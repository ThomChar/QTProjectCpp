#include "modifiertypepersonnel.h"
#include "ui_modifiertypepersonnel.h"
#include "mainwindow.h"

modifierTypePersonnel::modifierTypePersonnel(QWidget *parent, int idType) :
    QDialog(parent),
    ui(new Ui::modifierTypePersonnel)
{
    ui->setupUi(this);
    this->setWindowTitle("Modification Type Personnel");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->idType = idType;
    ui->addType_edit->setPlaceholderText("ex: médecin A");

    //Trouver le label associé à l'idType
    QList <typePersonnel> listeTypesPersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent)->getBD()->getDB());
    for(int i=0;i<listeTypesPersonnel.size();i++){
        if(listeTypesPersonnel[i].getIdType() == idType){
            this->label = QString::fromStdString(listeTypesPersonnel[i].getLabel());
        }
    }
     ui->addType_edit->setText(this->label);

    //Evennements
    //evenement pour quitter application
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour  modifier le type de Personnel selectionné
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(modificationPersonnel()));
}

modifierTypePersonnel::~modifierTypePersonnel()
{
    delete ui;
}

void modifierTypePersonnel::modificationPersonnel(){

    //Creation du patient en local
     typePersonnel type(this->idType, ui->addType_edit->text().toStdString());

    //Modification du type de Personnel dans la BD
     qobject_cast<MainWindow*>(parent())->getBD()->modifierTypePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),type);

     //Récupérer la nouvelle liste des Types de personnel
     QList<typePersonnel> listType = qobject_cast<MainWindow*>(parent())->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

    //Redefinir le model de tableTypePersonnel
     qobject_cast<MainWindow*>(parent())->resetTableTypesPersModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

    // Fermeture du formulaire
     this->close();
}

void modifierTypePersonnel::annuler(){
    // Fermeture du formulaire
    this->close();
}
