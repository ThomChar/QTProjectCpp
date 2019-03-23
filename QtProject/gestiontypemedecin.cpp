#include <QMessageBox>
#include "gestiontypemedecin.h"
#include "ui_gestiontypemedecin.h"
#include "mainwindow.h"
#include "typepersonnel.h"
#include "supprimertypepersonnel.h"
#include "modifiertypepersonnel.h"

gestionTypeMedecin::gestionTypeMedecin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionTypeMedecin)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Patient");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->addType_edit->setPlaceholderText("ex: médecin A");


    //Affectation de la combo box à la liste des personnels
    this->listeTypesPers = qobject_cast<MainWindow*>(parent)->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent)->getBD()->getDB());
    this->modelTypePers = new modelTableTypeMedecin(this,qobject_cast<MainWindow*>(parent)->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent)->getBD()->getDB()));
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(this->modelTypePers);

    //Evennements
    //evenement pour quitter le formulaire
    QObject::connect(ui->cancel_pushButton, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour valider le formulaire
    QObject::connect(ui->valid_pushButton, SIGNAL(clicked()),this,SLOT(valider()));
    //evenement pour  afficher formulaire ajouterTypePers
    QObject::connect(ui->add_pushButton, SIGNAL(clicked()),this, SLOT(ajouterTypePersonnel()));
    //evenement pour quitter le formulaire supprimerTypePers
    QObject::connect(ui->remove_pushButton, SIGNAL(clicked()),this,SLOT(suppressionTypePersonnel()));
    //evenement pour quitter le formulaire modifierTypePers
    QObject::connect(ui->mod_pushButton, SIGNAL(clicked()),this,SLOT(modificationTypePersonnel()));

}

gestionTypeMedecin::~gestionTypeMedecin()
{
    delete ui;
}

void gestionTypeMedecin::ajouterTypePersonnel(){
    if(!ui->addType_edit->text().isEmpty()){

        //Récupération de la liste de Personnel
        QList<typePersonnel>listTypePersonnel = qobject_cast<MainWindow*>(parent())->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

        //Création en local du nouveau typePersonnel
        typePersonnel type(listTypePersonnel.last().getIdType()+1,ui->addType_edit->text().toStdString());

        //Ajout du Type dans la base de donnée
        qobject_cast<MainWindow*>(parent())->getBD()->ajouterTypePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),type);

        //Maj du model de la table des Types de Méedecin
        this->listeTypesPers = qobject_cast<MainWindow*>(parent())->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        this->modelTypePers = new modelTableTypeMedecin(this,this->listeTypesPers);
        ui->tableView->setModel(this->modelTypePers);

        //Pop de prévention ajout typePersonnel effectué
        QMessageBox msgBox;
        msgBox.setWindowTitle("Information");
        msgBox.setText("<p align='center'>Succès ! <br>"
                       "Le type : "+ ui->addType_edit->text() +" a bien été ajouté à la liste<br>"
                        "Pour valider cet ajout veuillez valider le formulaire<br></p>");
        msgBox.exec();

        //Reset le champ d'ajout TypePersonnel
        ui->addType_edit->setText("");

        //

    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Veillez remplir le champ type avant d'appuyer sur le bouton d'ajout<br></p>");
        msgBox.exec();
    }
}
void gestionTypeMedecin::suppressionTypePersonnel(){
    bool selected = ui->tableView->currentIndex().isValid();// return selected row(s)
    if(selected){
        QString idType =  ui->tableView->selectionModel()->selectedIndexes()[0].data().toString();

        //Déterminer si la liste de Personnel correspondant à ce Type
        bool listePersonnelEstVide = qobject_cast<MainWindow*>(parent())->getBD()->getListePersType(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), idType.toInt());

        if(ui->tableView->selectionModel()->selectedIndexes()[1].data().toString()=="Informaticien"){
            QMessageBox msgBox;
            msgBox.setWindowTitle("Supprimer Type");
            msgBox.setText("<p align='center'>Vous ne pouvez pas supprimer le type Informaticien selectionner un autre Type de personnel</p>");
            msgBox.exec();
        }else if(!listePersonnelEstVide){
            QMessageBox msgBox;
            msgBox.setWindowTitle("Supprimer Type");
            msgBox.setText("<p align='center'>Vous ne pouvez pas supprimer le type "+ ui->tableView->selectionModel()->selectedIndexes()[0].data().toString()+
                    " car la liste des Personnels de ce type n'est pas vide</p>");
            msgBox.exec();
        }else{

            //Supression du Type
            supTypePersWindow = new supprimerTypePersonnel(qobject_cast<MainWindow*>(parent()),idType.toInt(),ui->tableView->selectionModel()->selectedIndexes()[1].data().toString());
            supTypePersWindow->exec();

            //Maj du model de la table des Types de Méedecin
            this->listeTypesPers = qobject_cast<MainWindow*>(parent())->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
            this->modelTypePers = new modelTableTypeMedecin(this,this->listeTypesPers);
            ui->tableView->setModel(this->modelTypePers);
        }
    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Supprimer Type");
        msgBox.setText("<p align='center'>Veuillez selectionner un Type de personnel avant de supprimer</p>");
        msgBox.exec();
    }
}
void gestionTypeMedecin::modificationTypePersonnel(){
    bool selected = ui->tableView->currentIndex().isValid();// return selected row(s)

    if(selected){
        QString idType =  ui->tableView->selectionModel()->selectedIndexes()[0].data().toString();

        //Modification du type
        modTypePersWindow = new modifierTypePersonnel(qobject_cast<MainWindow*>(parent()), idType.toInt());
        modTypePersWindow->exec();

        //Maj du model de la table des Types de Méedecin
        this->listeTypesPers = qobject_cast<MainWindow*>(parent())->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        this->modelTypePers = new modelTableTypeMedecin(this,this->listeTypesPers);
        ui->tableView->setModel(this->modelTypePers);

    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Supprimer Type");
        msgBox.setText("<p align='center'>Veuillez selectionner un Type de personnel avant de supprimer</p>");
        msgBox.exec();
    }
}

void gestionTypeMedecin::annuler(){
    // Fermeture du formulaire
    this->close();
}
void gestionTypeMedecin::valider(){

    // Maj du modelPersonnel
    qobject_cast<MainWindow*>(parent())->resetTreePersonnelModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

    // Fermeture du formulaire
     this->close();
}
