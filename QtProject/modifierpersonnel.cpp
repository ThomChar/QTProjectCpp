#include "modifierpersonnel.h"
#include "ui_modifierpersonnel.h"
#include "mainwindow.h"
#include "personnel.h"
#include "calendrier.h"
#include <QMessageBox>
#include <iostream>

ModifierPersonnel::ModifierPersonnel(QWidget *parent, QString nomPrenom) :
    QDialog(parent),
    ui(new Ui::ModifierPersonnel)
{
    ui->setupUi(this);
    this->setWindowTitle("Modification Personnel");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);
    calendrier = new Calendrier(this);

    ui->lineEdit->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->lineEdit_2->setPlaceholderText("ex: Jean");
    ui->lineEdit_3->setPlaceholderText("ex: Marc");
    ui->lineEdit_4->setPlaceholderText("ex: 65 avenue Jean Portalis");
    ui->lineEdit_5->setPlaceholderText("ex: Tours");
    ui->lineEdit_6->setPlaceholderText("ex: 37200");
    ui->lineEdit_10->setPlaceholderText("ex: 0701020304");
    ui->lineEdit_11->setPlaceholderText("ex: jean.marc@email.fr");

    //Affectation de la combo box à la liste des Types de médecin
    QList<QString> listeTypesPersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getLabelsTypePersonnel(qobject_cast<MainWindow*>(parent)->getBD()->getDB());
    for(int i=0;i<listeTypesPersonnel.size();i++){
    ui->comboBox_2->addItem(listeTypesPersonnel[i]);
    }

    //Récupération de idPersonnel
    int idPersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getIdPersonnel(qobject_cast<MainWindow*>(parent)->getBD()->getDB(), nomPrenom.toStdString());

    //Récupération du patient à modifier
    this->currentPersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getPersonnel(qobject_cast<MainWindow*>(parent)->getBD()->getDB(), idPersonnel);

    //Récupération du label medecin correspondant à idType personnel et affectation à typeMedecin de current Personnel
    QString typeMedecin = qobject_cast<MainWindow*>(parent)->getBD()->getTypeMedecin(qobject_cast<MainWindow*>(parent)->getBD()->getDB(),this->currentPersonnel.getNumId());
    this->currentPersonnel.setTypeMedecin(typeMedecin.toStdString());

    //Si diférrent de "Informaticien" on cache les champs login et password
    if(this->currentPersonnel.getTypeMedecin() != "Informaticien"){
        ui->label_11->hide();
        ui->label_12->hide();
        ui->label_16->hide();
        ui->lineEdit_8->hide();
        ui->lineEdit_9->hide();
    }else {
        ui->lineEdit_8->setText(QString::fromStdString(currentPersonnel.getLogin()));
        ui->lineEdit_9->setText(QString::fromStdString(currentPersonnel.getPassword()));
    }


    //Affichage des informations actuelles du Personnel selectionné
    ui->lineEdit->setText(QString::fromStdString(currentPersonnel.getDateCreation()));
    ui->lineEdit_2->setText(QString::fromStdString(currentPersonnel.getNom()));
    ui->lineEdit_3->setText(QString::fromStdString(currentPersonnel.getPrenom()));
    ui->lineEdit_4->setText(QString::fromStdString(currentPersonnel.getAdresse()));
    ui->lineEdit_5->setText(QString::fromStdString(currentPersonnel.getVille()));
    ui->lineEdit_6->setText(QString::fromStdString(currentPersonnel.getCodePostal()));
    ui->lineEdit_10->setText(QString::fromStdString(currentPersonnel.getNumTelephone()));
    ui->lineEdit_11->setText(QString::fromStdString(currentPersonnel.getEmail()));

    //Affichage du type de medecin actuel
    int indiceTypeMedecin = 0;
    indiceTypeMedecin = ui->comboBox_2->findText(currentPersonnel.getTypeMedecin().c_str());
    ui->comboBox_2->setCurrentIndex(indiceTypeMedecin);

    //Evennements
    //evenements pour afficher calendrier
    QObject::connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(afficherCalendrier()));
    //evenement pour quitter application
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenements pour ajouter des types de personnel
    QObject::connect(ui->addType_toolButton, SIGNAL(clicked()),this, SLOT(ajouterTypePersonnel()));
    //evenement pour  afficher formulaire ajouterPatient
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(modificationPersonnel()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(calendrier->findChild<QWidget *>("pushButton"), SIGNAL(clicked()),this, SLOT(afficherDateSelect()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(ui->comboBox_2, SIGNAL(currentTextChanged(QString)),this, SLOT(afficherLogPass()));
}

ModifierPersonnel::~ModifierPersonnel()
{
    delete ui;
}

void ModifierPersonnel::annuler(){
    this->close();
}

/** Methode permmettant d'afficher la fenêtre calendrier
 * @brief ajoutPersonnel::afficherCalendrier
 */
void ModifierPersonnel::afficherCalendrier(){
    calendrier->show();
}

/** Methode permettant de récupérer la date de calendrier et de l'afficher dans le lne edit correspondant
 * @brief ajoutPersonnel::afficherDateSelect
 */
void ModifierPersonnel::afficherDateSelect(){
    ui->lineEdit-> setText(calendrier->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}

/** Methode permettant de récupérer la date de calendrier et de l'afficher dans le lne edit correspondant
 * @brief ajoutPersonnel::afficherDateSelect
 */
void ModifierPersonnel::afficherLogPass(){
    if(ui->comboBox_2->currentText() == "Informaticien"){
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

void ModifierPersonnel::ajouterTypePersonnel(){
    if(!ui->addType_edit->text().isEmpty()){
        //Récupération de la liste de Personnel
        QList<typePersonnel>listTypePersonnel = qobject_cast<MainWindow*>(parent())->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

        //Création en local du nouveau typePersonnel
        typePersonnel type(listTypePersonnel.last().getIdType()+1,ui->addType_edit->text().toStdString());

        //Ajout du Type dans la base de donnée
        qobject_cast<MainWindow*>(parent())->getBD()->ajouterTypePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),type);

        //Redefinir le model des Types de patient de BD
        //qobject_cast<MainWindow*>(parent())->resetTreePersonnelModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

        //Ajout à la combo box du nouveau type de médecin
        QList<QString> listeTypesPersonnel = qobject_cast<MainWindow*>(parent())->getBD()->getLabelsTypePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        ui->comboBox_2->addItem(listeTypesPersonnel.last());

        //Pop de prévention ajout typePersonnel effectué

        QMessageBox msgBox;
        msgBox.setWindowTitle("Information");
        msgBox.setText("<p align='center'>Succès ! <br>"
                       "Le type : "+ ui->addType_edit->text() +" a bien été ajouté à la liste<br>"
                        "Pour choisir le nouveau type "+ ui->addType_edit->text() +"<br>"
                        "veuillez le sélectionner dans le menu déroulant Type</p>");
        msgBox.exec();

        //Reset le champ d'ajout TypePersonnel
        ui->addType_edit->setText("");

    }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Veillez remplir le champ correspondant au type avant d'ajouter<br></p>");
        msgBox.exec();
    }
}

/** Methode permettant de controler le format d'une date (verification simple pour commencer, on pourrait faire attention -> jours/mois)
 * @brief ajoutPersonnel::verifierDate
 * @param date
 * @return
 */
bool ModifierPersonnel::verifierDate(QString date){
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
bool ModifierPersonnel::verifierNomPropre(QString nomPropre){
    bool valide = true;
    QRegExp rx("[A-Z][a-z]*");
    if(!rx.exactMatch(nomPropre)){
        valide = false;
    }
    return valide;
}
bool ModifierPersonnel::verifierAdresse(QString adresse){
    bool valide = true;
    if(adresse == ""){}
      /*  valide = false;
    }*/ //adresse facultative dans ce formulaire
    return valide;
}
bool ModifierPersonnel::verifierVille(QString ville){
    bool valide = true;
    QRegExp rx("[À-ŸA-Z]{1}[à-ÿa-z]{0,39}");
    if(!rx.exactMatch(ville) && ville !=""){
        valide = false;
    }
    return valide;
}
bool ModifierPersonnel::verifierCodePostale(QString cdepostal){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(cdepostal) && cdepostal !=""){
        valide = false;
    }
    return valide;
}
bool ModifierPersonnel::verifierTypeMedecin(QString typeMedecin){
    bool valide = true;
    QRegExp rx("ex: médecin A");
    if(rx.exactMatch(typeMedecin)){
        valide = false;
    }
    return valide;
}
bool ModifierPersonnel::verifierLogin(QString login){
    bool valide = true;
    /*QRegExp rx("[1-5]");
    if(!rx.exactMatch(login) || login == ""){
        valide = false;
    }*/
    if(ui->comboBox_2->currentText() != "Informaticien" && login != ""){
        valide = false;
    }else if(ui->comboBox_2->currentText() == "Informaticien" && login == ""){
        valide = false;
    }
    return valide;
}
bool ModifierPersonnel::verifierPassword(QString password){
    bool valide = true;
    /*QRegExp rx("[1-5]");
    if(!rx.exactMatch(password) || password == ""){
        valide = false;
    }*/
    if(ui->comboBox_2->currentText() != "Informaticien" && password != ""){
        valide = false;
    }else if(ui->comboBox_2->currentText() == "Informaticien" && password == ""){
        valide = false;
    }
    return valide;
}
bool ModifierPersonnel::verifierNumTel(QString numTel){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(numTel) && numTel !=""){
        valide = false;
    }
    return valide;
}
bool ModifierPersonnel::verifierEmail(QString email){
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
 * Methode permettant de verifier les informations entree et ajouter le patient si toutes les informations nécessaires sont correctes
 * @brief modifierPatient::modifierPatient
 */
void ModifierPersonnel::modificationPersonnel()
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
    }else if (ui->lineEdit_8->text()!="Informaticien" and !verifierLogin(ui->lineEdit_8->text())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Format du Login incorrect<br>"
                       "(si type Informaticien, veuillez saisir un login sinon ne pas compléter ce champ)<br></p>");
        msgBox.exec();
        verifier= false;
    }else if (ui->lineEdit_9->text()!="Informaticien" and !verifierPassword(ui->lineEdit_9->text())){
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

        //Obtenir idPersonnel correspondant à nomPrenompersonnel
        string nomPrenom =  this->currentPersonnel.getNom() + " " + this->currentPersonnel.getPrenom();
        string ancienTypeMeddecin =  this->currentPersonnel.getTypeMedecin();
        int idPersonnel= qobject_cast<MainWindow*>(parent())->getBD()->getIdPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),nomPrenom);

        //Modification du Personnel à la base de données
        //Création du Patient en local
        this->currentPersonnel.setNumId(idPersonnel);
        this->currentPersonnel.setDateCreation(ui->lineEdit->text().toStdString());
        this->currentPersonnel.setNom(ui->lineEdit_2->text().toStdString());
        this->currentPersonnel.setPrenom(ui->lineEdit_3->text().toStdString());
        this->currentPersonnel.setAdresse(ui->lineEdit_4->text().toStdString());
        this->currentPersonnel.setVille(ui->lineEdit_5->text().toStdString());
        this->currentPersonnel.setCodePostal(ui->lineEdit_6->text().toStdString());
        this->currentPersonnel.setNumTelephone(ui->lineEdit_10->text().toStdString());
        this->currentPersonnel.setEmail(ui->lineEdit_11->text().toStdString());
        this->currentPersonnel.setTypeMedecin(ui->comboBox_2->currentText().toStdString());
        this->currentPersonnel.setLogin(ui->lineEdit_8->text().toStdString());
        this->currentPersonnel.setPassword(ui->lineEdit_9->text().toStdString());

        //Obtenir idCompte du Personnel
         int idCompte = qobject_cast<MainWindow*>(parent())->getBD()->getIdCompte(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),this->currentPersonnel.getNumId());

         //Obtenir idType lié au Personnel
        int idType= qobject_cast<MainWindow*>(parent())->getBD()->getIdType(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),QString::fromStdString(this->currentPersonnel.getTypeMedecin()));

        //Modifie le personnel dans la BD
         qobject_cast<MainWindow*>(parent())->getBD()->modifierPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),this->currentPersonnel,idType,idCompte);

         Personnel test = qobject_cast<MainWindow*>(parent())->getBD()->getPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), idPersonnel);

        //Si nouveau type est informaticien Creation compte
         if(this->currentPersonnel.getTypeMedecin() == "Informaticien" and ancienTypeMeddecin != "Informaticien"){
          QList<Compte> listComptes =  qobject_cast<MainWindow*>(parent())->getBD()->getListeComptes(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
          Compte newcompte(listComptes.last().getIdCompte()+1, ui->lineEdit_8->text().toStdString(), ui->lineEdit_9->text().toStdString(), this->currentPersonnel.getNumId());
          qobject_cast<MainWindow*>(parent())->getBD()->ajouterCompte(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),newcompte);
        }

        //Si ancien informaticien et devient autre type Suppression compte
         if(ancienTypeMeddecin == "Informaticien" and this->currentPersonnel.getTypeMedecin() != "Informaticien"){
          qobject_cast<MainWindow*>(parent())->getBD()->supprimerCompte(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),this->currentPersonnel.getNumId());
        }

        //Redefini le model de BD
         qobject_cast<MainWindow*>(parent())->resetTreePersonnelModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

    //Envoyer l'information de modification dans status Bar

    qobject_cast<MainWindow*>(parent())->setStatusBar("Personnel "+ui->lineEdit_2->text()+" "+ui->lineEdit_3->text()+" modifié !");

    // Fermeture du formulaire
    this->close();
    }
}
