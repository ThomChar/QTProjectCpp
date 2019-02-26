#include "ajoutpatient.h"
#include "ui_ajoutpatient.h"
#include "mainwindow.h"
#include <QMessageBox>

ajoutPatient::ajoutPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutPatient)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Patient");
    this->setFixedSize( this->size());
    //this->setAttribute(Qt::WA_DeleteOnClose);
    calendrier = new Calendrier(this);
    calendrier_2 = new Calendrier(this);

    ui->lineEdit->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->lineEdit_2->setPlaceholderText("ex: Jean");
    ui->lineEdit_3->setPlaceholderText("ex: Marc");
    ui->lineEdit_4->setPlaceholderText("ex: 65 avenue Jean Portalis");
    ui->lineEdit_5->setPlaceholderText("ex: Tours");
    ui->lineEdit_6->setPlaceholderText("ex: 37200");
    ui->lineEdit_7->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->timeEdit->setTime(QTime(1, 0));
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_10->setPlaceholderText("ex: 0701020304");
    ui->lineEdit_11->setPlaceholderText("ex: jean.marc@email.fr");

    //Evennements
    //evenements pour afficher calendrier
    QObject::connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(afficherCalendrier()));
    QObject::connect(ui->toolButton_2, SIGNAL(clicked()),this, SLOT(afficherCalendrier_2()));
    //evenement pour quitter application
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour  afficher formulaire ajouterPatient
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(ajouterPatient()));
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

/**
 * Methode permettant de verifier les informations entree et ajouter le patient si toutes les informations nécessaires sont correctes
 * @brief ajoutPatient::ajouterPatient
 */
void ajoutPatient::annuler()
{
    // Fermeture du formulaire
    this->close();

    // Réaffectation des champs du formulaire à vide
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->timeEdit->setTime(QTime(1,0));
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->textEdit->setText("");
    ui->comboBox->setCurrentIndex(0);
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
    QRegExp rx("[0-9][0-9]:[0-9][0-9]");
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
    }else if (!verifierDureeConsult(ui->timeEdit->text())){
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
    }else if (!verifierMedecin(ui->comboBox->currentText())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Champ médecin ne peut être vide"
                       "(veuillez saisir un autre médecin que l'exemple)<br></p>");
        msgBox.exec();
        verifier= false;
    }

    if (verifier == true){  // Si le formulaire est correctement rempli

    //Ajout du Patient à la base de données
        //...

    //Envoyer l'information d'ajout dans status Bar

    //qobject_cast<MainWindow*>(parent())->setStatusBar("heolllllllool");
    //MainWindow *coucou = qobject_cast<MainWindow*>(parent());
    //coucou->setStatusBar("hello");

    // Fermeture du formulaire
    this->close();

    // Réaffectation des champs du formulaire à vide
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->timeEdit->setTime(QTime(1, 0));
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->textEdit->setText("");
    ui->comboBox->setCurrentIndex(0);
    }
}
