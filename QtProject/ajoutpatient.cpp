#include "ajoutpatient.h"
#include "ui_ajoutpatient.h"
#include "mainwindow.h"
#include "patient.h"
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

        //QList<int> listeIdPersonnel; //=  qobject_cast<MainWindow*>(parent())->getBD()->getIdRessourcesPatient(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), this->idPatient);
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

        //QList<int> listeIdPersonnel; //=  qobject_cast<MainWindow*>(parent())->getBD()->getIdRessourcesPatient(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), this->idPatient);
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

/** Methode permettant de controler le format d'une date (verification simple pour commencer, on pourrait faire attention -> jours/mois)
 * @brief ajoutPatient::verifierDate
 * @param date
 * @return
 */
bool ajoutPatient::verifierDate(QString date){
    bool valide = true;
    QRegExp rx("[0-3][0-9]/[0-1][0-9]/[0-9]{4}"); // règle de base

    // règles pour mois de février
    QRegExp rx1("[0-2][0-9]/[0-0][2-2]/[0-9]{4}"); // règle pour mois de février

    // règles pour mois 10,11,12
    QRegExp rx2_1("[0-3][0-1]/[1-1][0-2]/[0-9]{4}"); // règle pour jour 30 et 31 des mois 10,11,12
    QRegExp rx2_2("[0-2][0-9]/[1-1][0-2]/[0-9]{4}"); // règle pour les autres jours des mois 10,11,12

    // règles pour mois 3 à 9
    QRegExp rx3_1("[0-3][0-1]/[0-0][3-9]/[0-9]{4}"); // règle pour jour 30 et 31 des mois 3 à 9
    QRegExp rx3_2("[0-2][0-9]/[0-0][3-9]/[0-9]{4}"); // règle pour les autres jours des mois 3 à 9

    // règles pour mois de janvier
    QRegExp rx4_1("[0-3][0-1]/[0-0][1-1]/[0-9]{4}"); // règle pour jour 30 et 31 de janvier
    QRegExp rx4_2("[0-2][0-9]/[0-0][1-1]/[0-9]{4}"); // règle pour les autres jours de janvier

    //Verifications
        if(!rx1.exactMatch(date)){
            if(!rx2_1.exactMatch(date)){
                if(!rx2_2.exactMatch(date)){
                    if(!rx3_1.exactMatch(date)){
                        if(!rx3_2.exactMatch(date)){
                            if(!rx4_1.exactMatch(date)){
                                if(!rx4_2.exactMatch(date)){
                                     valide = false;
                                }
                            }
                        }
                     }
                }
            }
        }
    return valide;
}
bool ajoutPatient::verifierNomPropre(QString nomPropre){
    bool valide = true;
    QRegExp rx("[A-Z][a-z]*");
    if(!rx.exactMatch(nomPropre)){
        valide = false;
    }
    return valide;
}
bool ajoutPatient::verifierAdresse(QString adresse){
    bool valide = true;
    if(adresse == ""){
        valide = false;
    }
    return valide;
}
bool ajoutPatient::verifierCodePostale(QString cdepostal){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(cdepostal)|| cdepostal == ""){
        valide = false;
    }
    return valide;
}
bool ajoutPatient::verifierDureeConsult(QString dureeConsult){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(dureeConsult) || dureeConsult == ""){
        valide = false;
    }
    return valide;
}
bool ajoutPatient::verifierNumPrio(QString numPrio){
    bool valide = true;
    QRegExp rx("[1-5]");
    if(!rx.exactMatch(numPrio) || numPrio == ""){
        valide = false;
    }
    return valide;
}
bool ajoutPatient::verifierNumTel(QString numTel){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(numTel)){
        valide = false;
    }
    return valide;
}
bool ajoutPatient::verifierEmail(QString email){
    bool valide = true;
    QRegExp rx("[a-z]*.[a-z]*@[a-z]*.fr");
    QRegExp rx1("[a-z]*@[a-z]*.fr");
    QRegExp rx2("[a-z]*@[a-z]*.com");
    QRegExp rx3("[a-z]*.[a-z]*@[a-z]*.com");
    if(!rx.exactMatch(email) && email != ""){
        if(!rx1.exactMatch(email)){
            if(!rx2.exactMatch(email)){
                if(!rx3.exactMatch(email)){
                    valide = false;
                }
            }
        }
    }
    return valide;
}
bool ajoutPatient::verifierMedecin(QString medecin){
    bool valide = true;
    QRegExp rx("ex: Anne Marie");
    if(rx.exactMatch(medecin)){
        valide = false;
    }
    return valide;
}

 bool ajoutPatient::verifierlisteMedecins(QList<Personnel>listePersonnel){
    bool valide = true;
    if(listePersonnel.isEmpty()){
        valide = false;
    }
    return valide;
}

/**
 * Methode permettant de verifier les informations entree et ajouter le patient si toutes les informations nécessaires sont correctes
 * @brief ajoutPatient::ajouterPatient
 */
void ajoutPatient::ajouterPatient()
{
    bool verifier = true;

    //Verifications
    if (!verifierDate(ui->lineEdit->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Date de création incorrect<br>"
                       "(JJ/MM/AAAA)</p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierNomPropre(ui->lineEdit_2->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Nom du Patient incorrect<br>"
                       "(1 Majuscule + minuscules)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierNomPropre(ui->lineEdit_3->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Prénom du Patient incorrect<br>"
                       "(1 Majuscule + minuscules)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierAdresse(ui->lineEdit_4->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Champ Adresse ne peut pas être vide<br>"
                       "(veuillez saisir une adresse)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierNomPropre(ui->lineEdit_5->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Ville incorrect<br>"
                       "(1 Majuscule + minuscules)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierCodePostale(ui->lineEdit_6->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Code Postale incorrect<br>"
                       "(uniquement des chiffres)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierDate(ui->lineEdit_7->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Date de RDV incorrect<br>"
                       "(JJ/MM/AAAA)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierDureeConsult(ui->spinBox->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Durée de Consultation incorrect<br>"
                       "01:00 (en minutes)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierNumPrio(ui->comboBox_2->currentText())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Num. Prioritaire incorrect<br>"
                       "de 1 à 5 (5 le plus prioritaire)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierNumTel(ui->lineEdit_10->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Num. de Téléphone incorrect<br>"
                       "(uniquement des chiffres)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierEmail(ui->lineEdit_11->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Email incorrect<br>"
                       "(prenom.nom@email.fr ou prenom.nom@email.com)<br></p>");
        msgBox.exec();
        verifier= false;
    }/*else if (!verifierMedecin(ui->comboBox->currentText())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Champ médecin ne peut être vide"
                       "(veuillez saisir un autre médecin que l'exemple)<br></p>");
        msgBox.exec();
        verifier= false;
    }*/else if (!verifierlisteMedecins(listePersonnelTraitant)){
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warning");
            msgBox.setText("<p align='center'>Attention ! <br>"
                           "Champ médecin ne peut être vide"
                           "(veuillez chosir au moins un médecin dans l'arbre)<br></p>");
            msgBox.exec();
            verifier= false;
        }

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
