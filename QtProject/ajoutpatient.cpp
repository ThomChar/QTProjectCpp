#include "ajoutpatient.h"
#include "ui_ajoutpatient.h"
#include "mainwindow.h"
#include "patient.h"
#include "verifierformat.h"
#include <QMessageBox>
#include <iostream>
#include <QDate>

using namespace std;

ajoutPatient::ajoutPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutPatient)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Patient");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);
    calendrier = new Calendrier(this);
    calendrier_2 = new Calendrier(this);

    ui->lineEdit->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->lineEdit_2->setPlaceholderText("ex: Jean");
    ui->lineEdit_3->setPlaceholderText("ex: Marc");
    ui->lineEdit_4->setPlaceholderText("ex: 65 avenue Jean Portalis");
    ui->lineEdit_5->setPlaceholderText("ex: Tours");
    ui->lineEdit_6->setPlaceholderText("ex: 37200");
    ui->lineEdit_7->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->spinBox->setValue(1);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_10->setPlaceholderText("ex: 0701020304");
    ui->lineEdit_11->setPlaceholderText("ex: jean.marc@email.fr");

    //Affectation de la combo box à la liste des personnels
    QList<Personnel> listePersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getListePersonnel(qobject_cast<MainWindow*>(parent)->getBD()->getDB());

    //Affectation de la liste des Types de personnel
    QList<typePersonnel> listeTypePersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent)->getBD()->getDB());
    for(int i=0;i<listeTypePersonnel.size();i++){
        this->listeTypePersonnel.push_back(QString::fromStdString(listeTypePersonnel[i].getLabel()));
    }

    this->listePersonnelBD = listePersonnel;

    //Affectation des TreeView
        //Affectation de l'Arbre BD
    this->modelPersonnelBD = new modelTreePersonnel(qobject_cast<MainWindow*>(parent),this->listeTypePersonnel,this->listePersonnelBD);
    modelPersonnelBD->setTree();
    modelPersonnelBD->setHeaderData(0, Qt::Horizontal, "Personnels de santé Base");
    ui->PersonnelBD_treeView->setModel(modelPersonnelBD);

        //Affectation de l'Arbre medecin traitant
    this->modelPersonnelTraitant = new modelTreePersonnel(qobject_cast<MainWindow*>(parent),this->listeTypePersonnel,this->listePersonnelTraitant);
    modelPersonnelTraitant->setTree();
    modelPersonnelTraitant->setHeaderData(0, Qt::Horizontal, "Personnels de santé Traitant");
    ui->PersonnelTraitant_treeView->setModel(modelPersonnelTraitant);

    //Evennements
    //evenements pour afficher calendrier
    QObject::connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(afficherCalendrier()));
    QObject::connect(ui->toolButton_2, SIGNAL(clicked()),this, SLOT(afficherCalendrier_2()));
    //evenement pour quitter le formulaire
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour  afficher formulaire ajouterPatient
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(ajouterPatient()));
    //evenements pour ajouter un personnel de la listeBD à la listeTraitant
    QObject::connect(ui->rightArrow_toolButton, SIGNAL(clicked()),this, SLOT(ajouterPersonnelTraitant()));
    //evenements pour ajouter un personnel de la listeTraitant à la listeBD
    QObject::connect(ui->leftArrow_toolButton, SIGNAL(clicked()),this, SLOT(supprimerPersonnelTraitant()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(calendrier->findChild<QWidget *>("pushButton"), SIGNAL(clicked()),this, SLOT(afficherDateSelect()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(calendrier_2->findChild<QWidget *>("pushButton"), SIGNAL(clicked()),this, SLOT(afficherDateSelect_2()));

}

ajoutPatient::~ajoutPatient()
{
    delete ui;
}

// afficher calendrier1 ajouterPatient (bloquant)
void ajoutPatient::afficherCalendrier(){
    calendrier->exec();  // force l'affichage de la fenetre en mode modal, fenetre bloquante
    //calendrier->setModal(true);
}

// afficher calendrier1 ajouterPatient (bloquant)
void ajoutPatient::afficherDateSelect(){
    ui->lineEdit_7 -> setText(calendrier->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}

// afficher calendrier ajouterPatient (bloquant)
void ajoutPatient::afficherCalendrier_2(){
    calendrier_2->exec();  // force l'affichage de la fenetre en mode modal, fenetre bloquante
    //calendrier->setModal(true);
}

// afficher calendrier1 ajouterPatient (bloquant)
void ajoutPatient::afficherDateSelect_2(){
    ui->lineEdit -> setText(calendrier_2->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}

void ajoutPatient::ajouterPersonnelTraitant(){

    //Affectation des TreeView
    bool selected = ui->PersonnelBD_treeView->currentIndex().isValid();
    bool control = true;
    if(selected){
        // Savoir si l'item sélectioné est un type
        QList<QString> listeLabelTypesPersonnel =   qobject_cast<MainWindow*>(parent())->getBD()->getLabelsTypePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        for(int i=0;i<listeLabelTypesPersonnel.size();i++){
            if(listeLabelTypesPersonnel[i] == ui->PersonnelBD_treeView->selectionModel()->selectedIndexes()[0].data().toString()){
                control = false;
            }
        }
    }

    if(selected and control){

        //Ajout d'une consultation pour le patient dans la BD

        //Obtenir le Médecin à ajouter à la liste
        QString itemSelect =  ui->PersonnelBD_treeView->selectionModel()->selectedIndexes()[0].data().toString();
        int idPersonnelSelect = qobject_cast<MainWindow*>(parent())->getBD()->getIdPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),itemSelect.toStdString());
        Personnel persoSelect = qobject_cast<MainWindow*>(parent())->getBD()->getPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),idPersonnelSelect);

        QList<Personnel>listePersonnelMaj = qobject_cast<MainWindow*>(parent())->getBD()->getListePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        QList<Personnel>listePersonnelBDTemp;
        QList<Personnel>listePersonnelTraitantTemp;// = this->listePersonnelTraitant;

        //Obtenir les personnels liés à la liste des id et remplir la liste des Personnel traitant
        for(int i=0;i<listePersonnelMaj.size();i++){
                if(listePersonnelMaj[i].getNumId() == persoSelect.getNumId()){
                    this->listePersonnelTraitant.push_back(listePersonnelMaj[i]);
                }
        }

        //Obtenir les personnels  sans ceux qui sont contenus dans la liste des médecin traitant
        bool idTrouve = true;
        for(int i=0;i<listePersonnelMaj.size();i++){
            for(int j=0;j<this->listePersonnelTraitant.size();j++){
                if(listePersonnelMaj[i].getNumId() != this->listePersonnelTraitant[j].getNumId()){
                    idTrouve = false;
                }else{
                    idTrouve = true;
                    break;
                }
            }
            if(idTrouve ==false){
                listePersonnelBDTemp.push_back(listePersonnelMaj[i]);
            }
            idTrouve = false;
        }

        this->listePersonnelBD = listePersonnelBDTemp;

            //Affectation de l'Arbre BD
        this->modelPersonnelBD = new modelTreePersonnel(qobject_cast<MainWindow*>(parent()),this->listeTypePersonnel,this->listePersonnelBD);
        modelPersonnelBD->setTree();
        modelPersonnelBD->setHeaderData(0, Qt::Horizontal, "Personnels de santé Base");
        ui->PersonnelBD_treeView->setModel(modelPersonnelBD);

            //Affectation de l'Arbre medecin traitant
        this->modelPersonnelTraitant = new modelTreePersonnel(qobject_cast<MainWindow*>(parent()),this->listeTypePersonnel,this->listePersonnelTraitant);
        modelPersonnelTraitant->setTree();
        modelPersonnelTraitant->setHeaderData(0, Qt::Horizontal, "Personnels de santé Traitant");
        ui->PersonnelTraitant_treeView->setModel(modelPersonnelTraitant);

    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("ajouter PersonnelTraitant");
        msgBox.setText("Veuillez selectionner un Personnel avant de l'ajouter");
        msgBox.exec();
    }

    ui->PersonnelBD_treeView->reset();
    ui->PersonnelTraitant_treeView->reset();

}

void ajoutPatient::supprimerPersonnelTraitant(){
    //Affectation des TreeView
    bool selected = ui->PersonnelTraitant_treeView->currentIndex().isValid();// return selected row(s)

    bool control = true;
    if(selected){
        // Savoir si l'item sélectioné est un type
        QList<QString> listeLabelTypesPersonnel =   qobject_cast<MainWindow*>(parent())->getBD()->getLabelsTypePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        for(int i=0;i<listeLabelTypesPersonnel.size();i++){
            if(listeLabelTypesPersonnel[i] == ui->PersonnelTraitant_treeView->selectionModel()->selectedIndexes()[0].data().toString()){
                control = false;
            }
        }
    }

    if(selected and control){
        //Supprimer une consultation pour le patient dans la BD

        //Obtenir le Médecin à ajouter à la liste
        QString itemSelect =  ui->PersonnelTraitant_treeView->selectionModel()->selectedIndexes()[0].data().toString();
        int idPersonnelSelect = qobject_cast<MainWindow*>(parent())->getBD()->getIdPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),itemSelect.toStdString());
        Personnel persoSelect = qobject_cast<MainWindow*>(parent())->getBD()->getPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),idPersonnelSelect);

        QList<Personnel>listePersonnelMaj = qobject_cast<MainWindow*>(parent())->getBD()->getListePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        QList<Personnel>listePersonnelBDTemp;
        QList<Personnel>listePersonnelTraitantTemp;

        //Obtenir les personnels liés à la liste des id et remplir la liste des Personnel traitant
        for(int i=0;i<this->listePersonnelTraitant.size();i++){
                if(this->listePersonnelTraitant[i].getNumId() != persoSelect.getNumId()){
                    listePersonnelTraitantTemp.push_back(this->listePersonnelTraitant[i]);
                }
        }
        this->listePersonnelTraitant = listePersonnelTraitantTemp;

        //Obtenir les personnels  sans ceux qui sont contenus dans la liste des médecin traitant
        bool idTrouve = true;
        for(int i=0;i<listePersonnelMaj.size();i++){
            for(int j=0;j<this->listePersonnelTraitant.size();j++){
                if(listePersonnelMaj[i].getNumId() != this->listePersonnelTraitant[j].getNumId()){
                    idTrouve = false;
                }else{
                    idTrouve = true;
                    break;
                }
            }
            if(idTrouve ==false){
                listePersonnelBDTemp.push_back(listePersonnelMaj[i]);
            }
            idTrouve = false;
        }


        this->listePersonnelBD = listePersonnelBDTemp;

        //Affectation de l'Arbre BD
        this->modelPersonnelBD = new modelTreePersonnel(qobject_cast<MainWindow*>(parent()),this->listeTypePersonnel,this->listePersonnelBD);
        modelPersonnelBD->setTree();
        modelPersonnelBD->setHeaderData(0, Qt::Horizontal, "Personnels de santé Base");
        ui->PersonnelBD_treeView->setModel(modelPersonnelBD);

        //Affectation de l'Arbre medecin traitant
        this->modelPersonnelTraitant = new modelTreePersonnel(qobject_cast<MainWindow*>(parent()),this->listeTypePersonnel,this->listePersonnelTraitant);
        modelPersonnelTraitant->setTree();
        modelPersonnelTraitant->setHeaderData(0, Qt::Horizontal, "Personnels de santé Traitant");
        ui->PersonnelTraitant_treeView->setModel(modelPersonnelTraitant);

    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Supprimer PersonnelTraitant");
        msgBox.setText("Veuillez selectionner un Personnel avant à supprimer");
        msgBox.exec();
    }

    ui->PersonnelBD_treeView->reset();
    ui->PersonnelTraitant_treeView->reset();
}

/**
 * Methode permettant de verifier les informations entree et ajouter le patient si toutes les informations nécessaires sont correctes
 * @brief ajoutPatient::ajouterPatient
 */
void ajoutPatient::annuler()
{
    // Fermeture du formulaire
    this->close();

}


/**
 * Methode permettant de verifier les informations entree et ajouter le patient si toutes les informations nécessaires sont correctes
 * @brief ajoutPatient::ajouterPatient
 */
void ajoutPatient::ajouterPatient()
{
    bool verifier = true;

    //Verifications
    verifier = verifierFormat().verificationsAjoutPatient(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_5->text(),
                                         ui->lineEdit_6->text(), ui->lineEdit_7->text(), ui->spinBox->text(), ui->comboBox_2->currentText(), ui->lineEdit_10->text(),
                                         ui->lineEdit_11->text(), listePersonnelTraitant);
    if (verifier == true){  // Si le formulaire est correctement rempli

    //Ajout du Patient à la base de données

        // Création du Patient en local

        QList<int> listeIdMedecins;
        for(int i = 0;i<this->listePersonnelTraitant.size();i++){
            listeIdMedecins.push_back(this->listePersonnelTraitant[i].getNumId());
        }
        QString dateCreation_QS = QString::fromStdString(ui->lineEdit->text().toStdString());
        QString dateConsultation_QS = QString::fromStdString(ui->lineEdit_7->text().toStdString());
        QDate dateCreation = QDate::fromString(dateCreation_QS, "dd/MM/yyyy");
        QDate dateConsultation = QDate::fromString(dateConsultation_QS, "dd/MM/yyyy");

        Patient newPatient(dateCreation,ui->lineEdit_2->text().toStdString(),
                           ui->lineEdit_3->text().toStdString(),ui->lineEdit_4->text().toStdString(),
                           ui->lineEdit_5->text().toStdString(),ui->lineEdit_6->text().toStdString(),
                           ui->lineEdit_10->text().toStdString(),ui->lineEdit_11->text().toStdString(),
                           dateConsultation, ui->spinBox->text().toStdString(),
                           ui->comboBox_2->currentText().toInt(), listeIdMedecins,
                           ui->textEdit->toPlainText().toStdString());

        //Obtenir la liste des patients de la BD
        QList<Patient> listePatients = qobject_cast<MainWindow*>(parent())->getBD()->getListePatients(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

        //Définir Id du patient
        newPatient.setNumId(listePatients.last().getNumId()+1);

        //Ajoute le patient à la BD
         qobject_cast<MainWindow*>(parent())->getBD()->addPatient(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),newPatient);

        //Redefini le model de BD
         qobject_cast<MainWindow*>(parent())->resetTablePatientModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

    //Envoyer l'information d'ajout dans status Bar
    qobject_cast<MainWindow*>(parent())->setStatusBar("Patient "+ui->lineEdit_2->text()+" "+ui->lineEdit_3->text()+" ajouté !");

    // Fermeture du formulaire
    this->close();
    }
}
