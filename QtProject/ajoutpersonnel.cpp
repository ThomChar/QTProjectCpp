#include "ajoutpersonnel.h"
#include "ui_ajoutpersonnel.h"
#include "mainwindow.h"
#include "personnel.h"
#include <QMessageBox>
#include <QDebug>

ajoutPersonnel::ajoutPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutPersonnel)
{
    ui->setupUi(this);
    this->setWindowTitle("Ajout Personnel");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);
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

    //Affectation de la combo box à la liste des Types de médecin
    QList<QString> listeTypesPersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getLabelsTypePersonnel(qobject_cast<MainWindow*>(parent)->getBD()->getDB());
    for(int i=0;i<listeTypesPersonnel.size();i++){
    ui->comboBox_2->addItem(listeTypesPersonnel[i]);
    }
    //Evennements
    //evenements pour afficher calendrier
    QObject::connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(afficherCalendrier()));
    //evenement pour quitter application
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenements pour ajouter des types de personnel
    QObject::connect(ui->addType_toolButton, SIGNAL(clicked()),this, SLOT(ajouterTypePersonnel()));
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

/**
 * Methode permettant fermer le formulaire et de remttre les attribus à des valeurs nuls
 * @brief ajoutPersonnel::annuler
 */
void ajoutPersonnel::annuler(){

    //fermeture du formulaire
    this->close();

    // Réaffectation des champs du formulaire à vide
    /*ui->lineEdit->setText("");
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
    ui->comboBox_2->setCurrentIndex(0);*/
}

void ajoutPersonnel::ajouterTypePersonnel(){
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
    if(ui->comboBox_2->currentText() != "Informaticien" && login != ""){
        valide = false;
    }else if(ui->comboBox_2->currentText() == "Informaticien" && login == ""){
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
    if(ui->comboBox_2->currentText() != "Informaticien" && password != ""){
        valide = false;
    }else if(ui->comboBox_2->currentText() == "Informaticien" && password == ""){
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

        //Création du Patient en local
        Personnel newPersonnel(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString(),
                           ui->lineEdit_3->text().toStdString(),ui->lineEdit_4->text().toStdString(),
                           ui->lineEdit_5->text().toStdString(),ui->lineEdit_6->text().toStdString(),
                           ui->lineEdit_10->text().toStdString(),ui->lineEdit_11->text().toStdString(),
                           ui->comboBox_2->currentText().toStdString(),ui->lineEdit_8->text().toStdString(),
                           ui->lineEdit_9->text().toStdString());


        //Obtenir la liste des personnels de la BD
        QList<Personnel> listePersonnels = qobject_cast<MainWindow*>(parent())->getBD()->getListePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        //Définir Id du personnel
        newPersonnel.setNumId(listePersonnels.last().getNumId()+1);

        //Savoir si le personnel possède un compte et affecter un idCompte
        QList<Compte> listeCompte =  qobject_cast<MainWindow*>(parent())->getBD()->getListeComptes(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        int idCompte = 0;
        if(ui->comboBox_2->currentText()=="Informaticien"){
            idCompte = listeCompte.last().getIdCompte()+1;
        }
        //Trouver idType correspondant au label entré
        int idType = qobject_cast<MainWindow*>(parent())->getBD()->getIdType(qobject_cast<MainWindow*>(parent())->getBD()->getDB()
                                                                             ,QString::fromStdString(newPersonnel.getTypeMedecin()));
        //Ajoute le personnel à la BD
         qobject_cast<MainWindow*>(parent())->getBD()->addPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),newPersonnel,idType,idCompte);
        //Redefini le model de BD
         qobject_cast<MainWindow*>(parent())->resetTreePersonnelModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());


    //Mise à jour de la status Bar

    qobject_cast<MainWindow*>(parent())->setStatusBar("Personnel "+ui->lineEdit_2->text()+" "+ui->lineEdit_3->text()+" ajouté !");

    // Fermeture du formulaire
    this->close();

    // Réaffectation des champs du formulaire à vide
    /*ui->lineEdit->setText("");
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
    ui->comboBox_2->setCurrentIndex(0);*/
    }
}
