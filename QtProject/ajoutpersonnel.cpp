#include "ajoutpersonnel.h"
#include "ui_ajoutpersonnel.h"
#include <QMessageBox>

ajoutPersonnel::ajoutPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutPersonnel)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Personnel");
    this->setFixedSize( this->size());
    calendrier = new Calendrier();

    ui->lineEdit->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->lineEdit_2->setPlaceholderText("ex: Jean");
    ui->lineEdit_3->setPlaceholderText("ex: Marc");
    ui->lineEdit_4->setPlaceholderText("ex: 65 avenue Jean Portalis");
    ui->lineEdit_5->setPlaceholderText("ex: Tours");
    ui->lineEdit_6->setPlaceholderText("ex: 37200");
    //ui->lineEdit_8->setPlaceholderText("ex: 15 (en minutes)s");           //login
    //ui->lineEdit_9->setPlaceholderText("ex: 5 (le plus prioritaire)");    //password
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_16->hide();
    ui->lineEdit_8->hide();
    ui->lineEdit_9->hide();
    ui->lineEdit_10->setPlaceholderText("ex: 0701020304");
    ui->lineEdit_11->setPlaceholderText("ex: jean.marc@email.fr");
    //Evennements
    //evenements pour afficher calendrier
    QObject::connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(afficherCalendrier()));
    //evenement pour quitter application
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour  afficher formulaire ajouterPatient
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(ajouterPersonnel()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(calendrier->findChild<QWidget *>("pushButton"), SIGNAL(clicked()),this, SLOT(afficherDateSelect()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(ui->comboBox_2, SIGNAL(currentTextChanged(QString)),this, SLOT(afficherLogPass()));

}

ajoutPersonnel::~ajoutPersonnel()
{
    delete ui;
}

/** Methode permmettant d'afficher la fenêtre calendrier
 * @brief ajoutPersonnel::afficherCalendrier
 */
void ajoutPersonnel::afficherCalendrier(){
    calendrier->show();
}

/** Methode permettant de récupérer la date de calendrier et de l'afficher dans le lne edit correspondant
 * @brief ajoutPersonnel::afficherDateSelect
 */
void ajoutPersonnel::afficherDateSelect(){
    ui->lineEdit-> setText(calendrier->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}

/** Methode permettant de récupérer la date de calendrier et de l'afficher dans le lne edit correspondant
 * @brief ajoutPersonnel::afficherDateSelect
 */
void ajoutPersonnel::afficherLogPass(){
    if(ui->comboBox_2->currentText() == "informaticien"){
         ui->label_11->show();
         ui->label_12->show();
         ui->label_16->show();
         ui->lineEdit_8->show();
         ui->lineEdit_9->show();
    }else{
         ui->lineEdit_8->hide();
         ui->lineEdit_9->hide();
         ui->label_11->hide();
         ui->label_12->hide();
         ui->label_16->hide();
    }
}

/**
 * Methode permettant fermer le formulaire et de remttre les attribus à des valeurs nuls
 * @brief ajoutPersonnel::annuler
 */
void ajoutPersonnel::annuler(){

    //fermeture du formulaire
    this->close();

    // Réaffectation des champs du formulaire à vide
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_8->hide();
    ui->lineEdit_9->setText("");
    ui->lineEdit_9->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_16->hide();
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->comboBox_2->setCurrentIndex(0);
}

/** Methode permettant de controler le format d'une date (verification simple pour commencer, on pourrait faire attention -> jours/mois)
 * @brief ajoutPersonnel::verifierDate
 * @param date
 * @return
 */
bool ajoutPersonnel::verifierDate(QString date){
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
bool ajoutPersonnel::verifierNomPropre(QString nomPropre){
    bool valide = true;
    QRegExp rx("[A-Z][a-z]*");
    if(!rx.exactMatch(nomPropre)){
        valide = false;
    }
    return valide;
}
bool ajoutPersonnel::verifierAdresse(QString adresse){
    bool valide = true;
    if(adresse == ""){}
      /*  valide = false;
    }*/ //adresse facultative dans ce formulaire
    return valide;
}
bool ajoutPersonnel::verifierVille(QString ville){
    bool valide = true;
    QRegExp rx("[A-Z][a-z]*");
    if(!rx.exactMatch(ville) && ville !=""){
        valide = false;
    }
    return valide;
}
bool ajoutPersonnel::verifierCodePostale(QString cdepostal){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(cdepostal) && cdepostal !=""){
        valide = false;
    }
    return valide;
}
bool ajoutPersonnel::verifierTypeMedecin(QString typeMedecin){
    bool valide = true;
    QRegExp rx("ex: médecin A");
    if(rx.exactMatch(typeMedecin)){
        valide = false;
    }
    return valide;
}
bool ajoutPersonnel::verifierLogin(QString login){
    bool valide = true;
    /*QRegExp rx("[1-5]");
    if(!rx.exactMatch(login) || login == ""){
        valide = false;
    }*/
    if(ui->comboBox_2->currentText() != "informaticien" && login != ""){
        valide = false;
    }else if(ui->comboBox_2->currentText() == "informaticien" && login == ""){
        valide = false;
    }
    return valide;
}
bool ajoutPersonnel::verifierPassword(QString password){
    bool valide = true;
    /*QRegExp rx("[1-5]");
    if(!rx.exactMatch(password) || password == ""){
        valide = false;
    }*/
    if(ui->comboBox_2->currentText() != "informaticien" && password != ""){
        valide = false;
    }else if(ui->comboBox_2->currentText() == "informaticien" && password == ""){
        valide = false;
    }
    return valide;
}
bool ajoutPersonnel::verifierNumTel(QString numTel){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(numTel) && numTel !=""){
        valide = false;
    }
    return valide;
}
bool ajoutPersonnel::verifierEmail(QString email){
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

/**
 * Methode permettant de verifier les informations entree et ajouter le personnel si toutes les informations nécessaires sont correctes
 * @brief ajoutPersonnel::ajouterPersonnel
 */
void ajoutPersonnel::ajouterPersonnel()
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
    }else if (!verifierVille(ui->lineEdit_5->text())){
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
    }else if (!verifierTypeMedecin(ui->comboBox_2->currentText())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du champ Type Médecin incorrect<br>"
                       "Faire un autre choix que l'exemple<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierLogin(ui->lineEdit_8->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du Login incorrect<br>"
                       "(si type Informaticien, veuillez saisir un login sinon ne pas compléter ce champ)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (!verifierPassword(ui->lineEdit_9->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du Password incorrect<br>"
                       "si type Informaticien, veuillez saisir un password sinon ne pas compléter ce champ<br></p>");
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
    }

    if (verifier == true){  // Si le formulaire est correctement rempli

    // Fermeture du formulaire
    this->close();

    // Réaffectation des champs du formulaire à vide
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_8->hide();
    ui->lineEdit_9->setText("");
    ui->lineEdit_9->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_16->hide();
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->comboBox_2->setCurrentIndex(0);
    }
}
