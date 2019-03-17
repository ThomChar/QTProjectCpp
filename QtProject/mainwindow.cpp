#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutpatient.h"
#include "ajoutpersonnel.h"
#include "apropos.h"
#include "personnel.h"
#include "modelTreePersonnel.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QAbstractItemModel>
#include <QStandardItem>
#include <QString>


MainWindow::MainWindow(/*QWidget *parent,*/ QSqlDatabase db, QString login) :
    //QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Accueil");

    calendrier = new Calendrier();
    calendrier_2 = new Calendrier();
    //patientWindow = new ajoutPatient(this);
    //personnnelWindow = new ajoutPersonnel(this);
    aProposWindow = new aPropos();
    baseDonnee = new RequeteBD(db);
    requestDataBase = db;

    ui->lineEdit->setPlaceholderText("ex: 01020304");
    ui->lineEdit_2->setPlaceholderText("ex: Jean");
    ui->lineEdit_3->setPlaceholderText("ex: Marc");
    ui->lineEdit_4->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->lineEdit_5->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->statusBar->showMessage("Bienvenue " + tr(login.toStdString().c_str()) + " ! Vous êtes connecté");

    //Test allocation de tableau pour liste de patient or du model

    //Création de Patients test
   /* Patient patient1("01/03/04","Nom1" ,"Prenom1", "a", "Tours", "37200", "", "", "01/03/04", "01:00", 1,"Tom Hille", "");
    patient1.setNumId(1);
    Patient patient2("01/03/04","Nom2" ,"Prenom2", "a", "Tours", "37200", "", "", "02/03/04", "01:00", 1,"Tom Hille","");
    patient2.setNumId(2);
    Patient patient3("01/03/04","Nom3" ,"Prenom3", "a", "Tours", "37200", "", "", "03/03/04", "01:00", 1,"Tom Hille","");
    patient3.setNumId(3);
    Patient patient4("01/03/04","Nom4" ,"Prenom4", "a", "Tours", "37200", "", "", "04/03/04", "01:00", 1,"Tom Hille","");
    patient4.setNumId(4);

    Personnel personnel1("01/03/04", "Alai", "Parfait", "adresse", "ville", "codepostal", "numTelephone", "email",
                                   "MedecinB", "login", "password");
    Personnel personnel2("01/03/04", "Deni", "Chon", "adresse", "ville", "codepostal", "numTelephone", "email",
                                   "MedecinB", "login", "password");*/



    //QList<Patient>listePatients = baseDonnee->getListePatients(baseDonnee->getDB());
    //qDebug() << listePatients.size();

    //QList<Personnel> listePersonnel = baseDonnee->getListePersonnel(baseDonnee->getDB());
    //qDebug() << listePersonnel.size();

    /*QList<Personnel>listePersonnels =baseDonnee->getListePersonnel(baseDonnee->getDB());
    QList<QString> listeTypes = baseDonnee->getLabelsTypePersonnel(baseDonnee->getDB());*/

    //PatientTable
    modelPatient = new modelTablePatient(this, baseDonnee->getListePatients(db));
    ui->tableView->setModel(modelPatient);
    /*QItemSelectionModel *select =  ui->tableView->selectionModel();
    QItemSelectionModel *select1 =  ui->treeView->selectionModel();
    select->hasSelection(); //check if has selection
    select->selectedRows();// return selected row(s)
    select->selectedColumns(); // return selected column(s)*/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableView->horizontalHeader()->setResizeContentsPrecision(QHeaderView::Stretch);
    ui->tableView->show();

    //Personnel Tree model;
    modelPersonnel = new modelTreePersonnel(this, baseDonnee->getLabelsTypePersonnel(baseDonnee->getDB()), baseDonnee->getListePersonnel(baseDonnee->getDB()));
    modelPersonnel->setTree();
   // QStandardItem *parentItem = modelPersonnel->invisibleRootItem();
    modelPersonnel->setHeaderData(0, Qt::Horizontal, "Personnels de santé");
    ui->treeView->setModel(modelPersonnel);

    //Evennements
    //evenement pour afficher calendrier 1
    QObject::connect(ui->tabWidget->findChild<QWidget *>("toolButton"), SIGNAL(clicked()),this, SLOT(afficherCalendrier()));
    //evenement pour afficher calendrier 2
    QObject::connect(ui->tabWidget->findChild<QWidget *>("toolButton_2"), SIGNAL(clicked()),this, SLOT(afficherCalendrier_2()));
    //evenement pour quitter application
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()),this,SLOT(close()));
    //evenement pour  afficher formulaire ajouterPatient
    QObject::connect(ui->actionPatient, SIGNAL(triggered()),this, SLOT(ajouterPatient()));
    //evenement pour afficher formulaire supprimerPatient
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(supprimerPatient()));
    //evenement pour afficher formulaire modifierPatient
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(modifPatient()));
    //evenement pour afficher formulaire ajouterPersonnel
    QObject::connect(ui->actionPersonnel_de_soins, SIGNAL(triggered()),this, SLOT(ajouterPersonnel()));
    //evenement pour afficher formulaire supprimerPersonnel
    QObject::connect(ui->deleteButtonPersonnel, SIGNAL(clicked()),this, SLOT(supprimerPersonnel()));
    //evenement pour afficher formulaire modifierPersonnel
    QObject::connect(ui->updateButtonPersonnel, SIGNAL(clicked()),this, SLOT(modifierPersonnel()));
    //evenement pour  afficher formulaire GestionTypesPersonnel
    QObject::connect(ui->actionG_rer_Types_Personnel, SIGNAL(triggered()),this, SLOT(gererTypesPersonnel()));
    //evenement pour afficher page apropos
    QObject::connect(ui->actionA_propos, SIGNAL(triggered()),this, SLOT(afficherAPropos()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(calendrier->findChild<QWidget *>("pushButton"), SIGNAL(clicked()),this, SLOT(afficherDateSelect()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(calendrier_2->findChild<QWidget *>("pushButton"), SIGNAL(clicked()),this, SLOT(afficherDateSelect_2()));
    //evenement pour effectuer la recherche selon les critères
    QObject::connect(ui->tabWidget->findChild<QWidget *>("pushButton"), SIGNAL(clicked()),this, SLOT(rechercherPatient()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Methode permettant de changer le message de la status bar
 * @brief calendar::setStatusBar
 */
void MainWindow::setStatusBar(const QString &message){
   ui->statusBar->showMessage(message) ;
}

RequeteBD* MainWindow::getBD(){
    return this->baseDonnee;
}

void  MainWindow::resetTablePatientModel(QSqlDatabase db){
    this->modelPatient = new modelTablePatient(this, baseDonnee->getListePatients(db));
    ui->tableView->setModel(this->modelPatient);
}
void MainWindow::resetTreePersonnelModel(QSqlDatabase db){
    //qDebug()<< baseDonnee->getListePersonnel(db).last().getNom().c_str();
    this->modelPersonnel = new modelTreePersonnel(this, baseDonnee->getLabelsTypePersonnel(db), baseDonnee->getListePersonnel(db));
    modelPersonnel->setTree();
    modelPersonnel->setHeaderData(0, Qt::Horizontal, "Personnels de santé");
    ui->treeView->setModel(modelPersonnel);
}

void  MainWindow::resetTableTypesPersModel(QSqlDatabase db){
    this->modelTypePers = new modelTableTypeMedecin(this, baseDonnee->getListeTypePersonnels(db));
    ui->tableView->setModel(this->modelTypePers);
}

// afficher calendrier (bloquant)
void MainWindow::afficherCalendrier(){
    calendrier->show();
}

// afficher calendrier (bloquant)
void MainWindow::afficherDateSelect(){
    ui->lineEdit_4 -> setText(calendrier->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}
// afficher calendrier 2 (bloquant)
void MainWindow::afficherCalendrier_2(){
    calendrier_2->show();
}

// afficher calendrier 2 (bloquant)
void MainWindow::afficherDateSelect_2(){
    ui->lineEdit_5 -> setText(calendrier_2->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}

// afficher formulaire ajouterPatient (bloquant)
void MainWindow::ajouterPatient(){
    patientWindow = new ajoutPatient(this);
    patientWindow->exec();  // force l'affichage de la fenetre en mode modal, fenetre bloquante
}

void MainWindow::modifPatient(){
    bool selected = ui->tableView->currentIndex().isValid();// return selected row(s)

    if(selected){
        /*Patient selectedPatient(baseDonnee->getPatient(baseDonnee->getDB(),ui->tableView->selectionModel()->selectedIndexes()[0].data().toInt()));
        string he = baseDonnee->getPatient(baseDonnee->getDB(),ui->tableView->selectionModel()->selectedIndexes()[0].data().toInt()).getNom();
        qDebug() << QString::fromStdString(baseDonnee->getPatient(baseDonnee->getDB(),ui->tableView->selectionModel()->selectedIndexes()[0].data().toInt()).getNom());
        qDebug() << QString::fromStdString(he);
        qDebug() << ui->tableView->selectionModel()->selectedIndexes()[0].data().toString().toInt();*/
        int idPatient =  ui->tableView->selectionModel()->selectedIndexes()[0].data().toString().toInt();
        modPatWindow = new modifierPatient(this, idPatient);
        modPatWindow->exec();

    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Modification Patient");
        msgBox.setText("Veuillez selectionner un Patient avant de modifier");
        msgBox.exec();
    }
}


void MainWindow::supprimerPatient(){

    //bool verifier = ui->tableView->selectionModel()->hasSelection();//check if has selection
    //ui->tableView->selectionModel()->selectedColumns(); // return selected column(s)
    //int test = ui->tableView->selectionModel()->selectedRows().at(0).row();
    /*for (int i = 0; i < ui->tableView->selectionModel()->selectedIndexes().size(); i++){
            qDebug() << ui->tableView->selectionModel()->selectedIndexes()[i].data().toString();
    }*/

    bool selected = ui->tableView->currentIndex().isValid();// return selected row(s)

    if(selected){
        QString idPatient =  ui->tableView->selectionModel()->selectedIndexes()[0].data().toString();
        QString nomPatient =  ui->tableView->selectionModel()->selectedIndexes()[1].data().toString();
        QString prenomPatient =  ui->tableView->selectionModel()->selectedIndexes()[2].data().toString();

        supPatWindow = new SupprimerPatient(this, idPatient.toInt(), nomPatient, prenomPatient);
        supPatWindow->exec();

    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Supprimer Patient");
        msgBox.setText("Veuillez selectionner un Patient avant de supprimer");
        msgBox.exec();
    }
}

// afficher formulaire ajouterPersonnel (bloquant)
void MainWindow::ajouterPersonnel(){
    personnnelWindow = new ajoutPersonnel(this);
    personnnelWindow->exec();    // force l'affichage de la fenetre en mode modal, fenetre bloquante
}

void MainWindow::supprimerPersonnel(){
    bool selected = ui->treeView->currentIndex().isValid();// return selected row(s)

    if(selected){
        QString nomPrenomPatient =  ui->treeView->selectionModel()->selectedIndexes()[0].data().toString();

        supPerWindow = new SupprimerPersonnel(this, nomPrenomPatient);
        supPerWindow->exec();

    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Supprimer Personnel");
        msgBox.setText("Veuillez selectionner un Personnel avant de supprimer");
        msgBox.exec();
    }
}
void MainWindow::modifierPersonnel(){
    bool selected = ui->treeView->currentIndex().isValid();// return selected row(s)

    if(selected){
        QString nomPrenomPatient =  ui->treeView->selectionModel()->selectedIndexes()[0].data().toString();

        modPerWindow = new ModifierPersonnel(this, nomPrenomPatient);
        modPerWindow->exec();

    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Modifier Personnel");
        msgBox.setText("Veuillez selectionner un Personnel avant de supprimer");
        msgBox.exec();
    }
}

void MainWindow::gererTypesPersonnel(){
    //modelTypePers = new modelTableTypeMedecin(this, baseDonnee->getListeTypePersonnels(this->getBD()->getDB()));;
    gestionTypesPerWindow = new gestionTypeMedecin(this);
    gestionTypesPerWindow->exec();
}

// afficher page apropos (on pourrait mettre  bloquant par soucis de ne pas surcharger la vue)
void MainWindow::afficherAPropos(){
    aProposWindow->show();
}

/** Methode permettant de controler le format d'une date (verification simple pour commencer, on pourrait faire attention -> jours/mois)
 * @brief ajoutPersonnel::verifierDate
 * @param date
 * @return
 */
bool MainWindow::verifierDate(QString date){
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
        if(!rx1.exactMatch(date) && date != ""){
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

bool MainWindow::verifierNomPropre(QString nomPropre){
    bool valide = true;
    QRegExp rx("[A-Z][a-z]*");
    if(!rx.exactMatch(nomPropre) && nomPropre != ""){
        valide = false;
    }
    return valide;
}

bool MainWindow::verifierNumID(QString numId){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(numId)){
        valide = false;
    }
    return valide;
}

void MainWindow::rechercherPatient(){
    bool verifier = true;

    //Verifications
    if (!verifierNumID(ui->lineEdit->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Numero Identification incorrect<br>"
                       "(uniquement des chiffres ou laisser libre)</p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierNomPropre(ui->lineEdit_2->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Nom du Patient incorrect<br>"
                       "(1 Majuscule + minuscules ou laisser vide)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierNomPropre(ui->lineEdit_3->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Prénom du Patient incorrect<br>"
                       "(1 Majuscule + minuscules ou laisser vide)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierDate(ui->lineEdit_4->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Date de RDV (après le) incorrect<br>"
                       "(JJ/MM/AAAA ou laisser vide)</p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierDate(ui->lineEdit_5->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Date de RDV (avant le) incorrect<br>"
                       "(JJ/MM/AAAA ou laisser vide)</p>");
        msgBox.exec();
        verifier= false;
    }

    if (verifier == true){  // Si le formulaire est correctement rempli
        //Si Vrai on lance la recherche
        this->setStatusBar("Recherche effectuée");
    }

}


