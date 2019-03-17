#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutpatient.h"
#include "ajoutpersonnel.h"
#include "apropos.h"
#include "personnel.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QAbstractItemModel>
#include <QStandardItem>
#include <QString>


MainWindow::MainWindow(QSqlDatabase db, QString login) : ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Accueil");

    calendrier = new Calendrier();
    calendrier_2 = new Calendrier();
    aProposWindow = new aPropos();
    baseDonnee = new RequeteBD(db);
    requestDataBase = db;

    // Exemples de remplissage pour le filtre des patients
    ui->idPatient_r->setPlaceholderText("ex: 01020304");
    ui->prenomPatient_r->setPlaceholderText("ex: Maxime");
    ui->nomPatient_r->setPlaceholderText("ex: Dupont");
    ui->dateDebut_r->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->dateFin_r->setPlaceholderText("ex: JJ/MM/AAAA");

    // StatusBar : Bienvenue
    ui->statusBar->showMessage("Bienvenue " + tr(login.toStdString().c_str()) + " ! Vous êtes connecté");

    // le tableau de Patients
    modelPatient = new modelTablePatient(this, baseDonnee->getListePatients(db));
    ui->tableView->setModel(modelPatient);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->show();

    // Le treeview de Personnels
    modelPersonnel = new modelTreePersonnel(this, baseDonnee->getLabelsTypePersonnel(baseDonnee->getDB()), baseDonnee->getListePersonnel(baseDonnee->getDB()));
    modelPersonnel->setTree();
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
    QObject::connect(ui->tabWidget->findChild<QWidget *>("searchButton"), SIGNAL(clicked()),this, SLOT(rechercherPatients()));
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
    ui->dateDebut_r-> setText(calendrier->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}
// afficher calendrier 2 (bloquant)
void MainWindow::afficherCalendrier_2(){
    calendrier_2->show();
}

// afficher calendrier 2 (bloquant)
void MainWindow::afficherDateSelect_2(){
    ui->dateFin_r -> setText(calendrier_2->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}

// afficher formulaire ajouterPatient (bloquant)
void MainWindow::ajouterPatient(){
    patientWindow = new ajoutPatient(this);
    patientWindow->exec();  // force l'affichage de la fenetre en mode modal, fenetre bloquante
}

void MainWindow::modifPatient(){
    bool selected = ui->tableView->currentIndex().isValid();// return selected row(s)

    if(selected){
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

    try
    {
        if(selected == 0)
            throw 1; // aucun élément de selectionné

        QString nomPrenomPatient =  ui->treeView->selectionModel()->selectedIndexes()[0].data().toString();

        // on vérifie que la selection n'est pas sur un type de personnel
        auto enfant = modelPersonnel->findItems(nomPrenomPatient, Qt::MatchWrap | Qt::MatchExactly, 0);

        if(!enfant.isEmpty())
            throw 1; // ce n'est pas un personnel qui est selectionné

        // suppression
        supPerWindow = new SupprimerPersonnel(this, nomPrenomPatient);
        supPerWindow->exec();

    }
    catch (int e)
    {
        if(e == 1) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Supprimer Personnel");
            msgBox.setText("Veuillez selectionner un Personnel avant de supprimer");
            msgBox.exec();
        }
    }
}
void MainWindow::modifierPersonnel(){
    bool selected = ui->treeView->currentIndex().isValid();// return selected row(s)

    try
    {
        if(selected == 0)
            throw 1; // aucun élément de selectionné

        QString nomPrenomPatient =  ui->treeView->selectionModel()->selectedIndexes()[0].data().toString();

        // on vérifie que la selection n'est pas sur un type de personnel
        auto enfant = modelPersonnel->findItems(nomPrenomPatient, Qt::MatchWrap | Qt::MatchExactly, 0);

        if(!enfant.isEmpty())
            throw 1; // ce n'est pas un personnel qui est selectionné

        // modification
        modPerWindow = new ModifierPersonnel(this, nomPrenomPatient);
        modPerWindow->exec();

    }
    catch (int e)
    {
        if(e == 1) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Modifier Personnel");
            msgBox.setText("Veuillez selectionner un Personnel avant de supprimer");
            msgBox.exec();
        }
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
    QRegExp rx("[À-ŸA-Zà-ÿa-z]*");
    if(!rx.exactMatch(nomPropre)){
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

void MainWindow::rechercherPatients(){
    bool verifier = true;

    //Verifications
    if (!verifierNumID(ui->idPatient_r->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Numero Identification incorrect<br>"
                       "(uniquement des chiffres ou laisser libre)</p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierNomPropre(ui->nomPatient_r->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Nom du Patient incorrect<br>"
                       "(1 Majuscule + minuscules ou laisser vide)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierNomPropre(ui->prenomPatient_r->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Prénom du Patient incorrect<br>"
                       "(1 Majuscule + minuscules ou laisser vide)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierDate(ui->dateDebut_r->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Date de RDV (après le) incorrect<br>"
                       "(JJ/MM/AAAA ou laisser vide)</p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierDate(ui->dateFin_r->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Date de RDV (avant le) incorrect<br>"
                       "(JJ/MM/AAAA ou laisser vide)</p>");
        msgBox.exec();
        verifier= false;
    }

    if (verifier == true){  // Si le formulaire est correctement rempli

        modelPatient = new modelTablePatient(this, baseDonnee->getListePatientsFilter(requestDataBase,
                                                                                      ui->idPatient_r->text(),
                                                                                      ui->nomPatient_r->text(),
                                                                                      ui->prenomPatient_r->text(),
                                                                                      ui->dateDebut_r->text(),
                                                                                      ui->dateFin_r->text()));
        ui->tableView->setModel(modelPatient);

        this->setStatusBar("Recherche effectuée");
    } else {
        this->setStatusBar("Impossible de faire la recherche avec les paramètres renseignés.");
    }

}


