#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendar.h"
#include "ajoutpatient.h"
#include "ajoutpersonnel.h"
#include "apropos.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Accueil");

    calendrier = new calendar();
    patientWindow = new ajoutPatient();
    personnnelWindow = new ajoutPersonnel();
    aProposWindow = new aPropos();

    //Evennements
    //evenement pour afficher calendrier
    QObject::connect(ui->tabWidget->setCurrentWidget(ui->tab)->push_button , SIGNAL(clicked()),this, SLOT(afficherCalendrier(this->tab->push_button)));
    //evenement pour quitter application
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()),this,SLOT(close()));
    //evenement pour  afficher formulaire ajouterPatient
    QObject::connect(ui->actionPatient, SIGNAL(triggered()),this, SLOT(ajouterPatient()));
    //evenement pour afficher formulaire ajouterPersonnel
    QObject::connect(ui->actionPersonnel_de_soins, SIGNAL(triggered()),this, SLOT(ajouterPersonnel()));
    //evenement pour afficher page apropos
    QObject::connect(ui->actionA_propos, SIGNAL(triggered()),this, SLOT(afficherAPropos()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// afficher calendrier ajouterPatient (bloquant)
void MainWindow::afficherCalendrier(){
    calendrier->exec();  // force l'affichage de la fenetre en mode modal, fenetre bloquante
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
