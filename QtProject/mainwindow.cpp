#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutpatient.h"
#include "ajoutpersonnel.h"
#include "apropos.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Accueil");

    calendrier = new Calendrier();
    calendrier_2 = new Calendrier();
    patientWindow = new ajoutPatient();
    personnnelWindow = new ajoutPersonnel();
    aProposWindow = new aPropos();
    modelPatient = new modelTablePatient();

    ui->lineEdit->setPlaceholderText("ex: 01020304");
    ui->lineEdit_2->setPlaceholderText("ex: Jean");
    ui->lineEdit_3->setPlaceholderText("ex: Marc");
    ui->lineEdit_4->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->lineEdit_5->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->statusBar->showMessage("Bienvenue Admin ! Vous êtes connecté");

    //PatientTable
    ui->tableView->setModel(modelPatient);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->verticalLayout->addWidget(ui->tableView);
    //this->setLayout(ui->verticalLayout);
    //ui->tableView->horizontalHeader()->setResizeContentsPrecision(QHeaderView::Stretch);
    ui->tableView->show();

    //Evennements
    //evenement pour afficher calendrier 1
    QObject::connect(ui->tabWidget->findChild<QWidget *>("toolButton"), SIGNAL(clicked()),this, SLOT(afficherCalendrier()));
    //evenement pour afficher calendrier 2
    QObject::connect(ui->tabWidget->findChild<QWidget *>("toolButton_2"), SIGNAL(clicked()),this, SLOT(afficherCalendrier_2()));
    //evenement pour quitter application
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()),this,SLOT(close()));
    //evenement pour  afficher formulaire ajouterPatient
    QObject::connect(ui->actionPatient, SIGNAL(triggered()),this, SLOT(ajouterPatient()));
    //evenement pour afficher formulaire ajouterPersonnel
    QObject::connect(ui->actionPersonnel_de_soins, SIGNAL(triggered()),this, SLOT(ajouterPersonnel()));
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
   ui->statusBar->clearMessage();
   ui->statusBar->showMessage(message) ;
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
    patientWindow->exec();  // force l'affichage de la fenetre en mode modal, fenetre bloquante
}

// afficher formulaire ajouterPersonnel (bloquant)
void MainWindow::ajouterPersonnel(){
    personnnelWindow->exec();    // force l'affichage de la fenetre en mode modal, fenetre bloquante
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
    }
}