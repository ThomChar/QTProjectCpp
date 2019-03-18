#include "modifierpatient.h"
#include "ui_modifierpatient.h"
#include "mainwindow.h"
#include "patient.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>

modifierPatient::modifierPatient(QWidget *parent, int idPatient) :
    QDialog(parent),
    ui(new Ui::modifierPatient)
{
    ui->setupUi(this);
    this->setWindowTitle("Modification Patient");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);
    calendrier = new Calendrier(this);
    calendrier_2 = new Calendrier(this);

    //Récupération du patient à modifier
    this->currentPatient = qobject_cast<MainWindow*>(parent)->getBD()->getPatient(qobject_cast<MainWindow*>(parent)->getBD()->getDB(),idPatient);
    this->currentPatient.setMedecin(qobject_cast<MainWindow*>(parent)->getBD()->getNomPrenomPersonnelConsult(
                                        qobject_cast<MainWindow*>(parent)->getBD()->getDB(),idPatient).toStdString());
    //qDebug()<<QString::fromStdString("Le medecin est "+this->currentPatient.getMedecin());
    //Récuperation de l'Id medecin avant modification
    /*QStringList nomPrenom = QString::fromStdString(currentPatient.getMedecin()).split(" ");
    string nomP = nomPrenom.value(0).toStdString();
    string prenomP = nomPrenom.value(1).toStdString();
    qDebug()<<QString::fromStdString(nomP);
    qDebug()<<QString::fromStdString(prenomP);*/
    this->idPatient = idPatient;
    this->pastIdPersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getIdPersonnel(qobject_cast<MainWindow*>(parent)->getBD()->getDB(),currentPatient.getMedecin());
    //this->currentPatient = patient;

    ui->lineEdit->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->lineEdit_2->setPlaceholderText("ex: Jean");
    ui->lineEdit_3->setPlaceholderText("ex: Marc");
    ui->lineEdit_4->setPlaceholderText("ex: 65 avenue Jean Portalis");
    ui->lineEdit_5->setPlaceholderText("ex: Tours");
    ui->lineEdit_6->setPlaceholderText("ex: 37200");
    ui->lineEdit_7->setPlaceholderText("ex: JJ/MM/AAAA");
    ui->lineEdit_10->setPlaceholderText("ex: 0701020304");
    ui->lineEdit_11->setPlaceholderText("ex: jean.marc@email.fr");

    //Affectation de la combo box à la liste des personnels
    this->listePersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getListePersonnel(qobject_cast<MainWindow*>(parent)->getBD()->getDB());
    /*for(int i=0;i<listePersonnel.size();i++){
    ui->comboBox->addItem(QString::fromStdString(listePersonnel[i].getNom()+" "+listePersonnel[i].getPrenom()));
    }*/

    QList<typePersonnel> listeTypePersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent)->getBD()->getDB());
    for(int i=0;i<listeTypePersonnel.size();i++){
    this->listeTypePersonnel.push_back(QString::fromStdString(listeTypePersonnel[i].getLabel()));
    }

    //Obtenir l'id des personnels du patient sélectionné
    //QList<Consult> listeConsults = qobject_cast<MainWindow*>(parent)->getBD()->getListeConsults(qobject_cast<MainWindow*>(parent)->getBD()->getDB());
    QList<int> listeIdPersonnel =  qobject_cast<MainWindow*>(parent)->getBD()->getIdRessourcesPatient(qobject_cast<MainWindow*>(parent)->getBD()->getDB(), idPatient);

    //Obtenir les personnels liés à la liste des id et remplir la liste des Personnel traitant
    for(int i=0;i<listeIdPersonnel.size();i++){
        for(int j=0;j<listePersonnel.size();j++){
            if(listeIdPersonnel[i] == listePersonnel[j].getNumId()){
                this->listePersonnelTraitant.push_back(listePersonnel[j]);
            }
        }
    }

    //Obtenir les personnels  sans ceux qui sont contenus dans la liste des médecin traitant
    /*bool idTrouve = false;
    for(int i=0;i<listePersonnel.size();i++){
        for(int j=0;j<listeIdPersonnel.size();j++){
            if(listePersonnel[i].getNumId() != listeIdPersonnel[j]){
                idTrouve = true;
            }
        }
        if(idTrouve ==true){
            this->listePersonnelBD.push_back(listePersonnel[i]);
        }
        idTrouve = false;
    }*/
    QList<Personnel>listePersonnelBDTemp;
    bool idTrouve = true;
    for(int i=0;i<listePersonnel.size();i++){
        for(int j=0;j<listeIdPersonnel.size();j++){
            if(listePersonnel[i].getNumId() != listeIdPersonnel[j]){
                idTrouve = false;
            }else{
                idTrouve = true;
                break;
            }
        }
        if(idTrouve ==false){
            listePersonnelBDTemp.push_back(listePersonnel[i]);
        }
        idTrouve = false;
    }

    this->listePersonnelBD = listePersonnelBDTemp;

    //this->listePersonnelBD = listePersonnel;
    //this->listePersonnelTraitant = listePersonnel;// à adapter selon le vector du Personnel

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
    //Affichage des informations actuelles du Patient selectionné

    ui->lineEdit->setText(QString::fromStdString(currentPatient.getDateCreation()));
    ui->lineEdit_2->setText(QString::fromStdString(currentPatient.getNom()));
    ui->lineEdit_3->setText(QString::fromStdString(currentPatient.getPrenom()));
    ui->lineEdit_4->setText(QString::fromStdString(currentPatient.getAdresse()));
    ui->lineEdit_5->setText(QString::fromStdString(currentPatient.getVille()));
    ui->lineEdit_6->setText(QString::fromStdString(currentPatient.getCodePostal()));
    ui->lineEdit_7->setText(QString::fromStdString(currentPatient.getDateConsultation()));
    ui->lineEdit_10->setText(QString::fromStdString(currentPatient.getNumTelephone()));
    ui->lineEdit_11->setText(QString::fromStdString(currentPatient.getEmail()));

    //Trouver la duree de Consultation
    /*QStringList dureeConsultation = QString::fromStdString(currentPatient.getDureeConsultation()).split(":");
    int minutes = dureeConsultation.value(0).toInt();
    int secondes = dureeConsultation.value(1).toInt();*/
    /*qDebug()<<dureeConsultation;
    qDebug()<<QString::number(minutes);
    qDebug()<<QString::number(secondes);*/
    ui->spinBox->setValue(QString::fromStdString(currentPatient.getDureeConsultation()).toInt());
    //qDebug()<<QString::fromStdString(currentPatient.getDureeConsultation());

    //Trouver la priorité associé au patient
    /*int indiceMedecin = 0;
    //qDebug()<<QString::fromStdString(currentPatient.getMedecin());
    indiceMedecin = ui->comboBox->findText(currentPatient.getMedecin().c_str());
    ui->comboBox->setCurrentIndex(indiceMedecin);*/

    int indicePriorite = 0;
    indicePriorite = ui->comboBox_2->findText(to_string(currentPatient.getPriorite()).c_str());
    qDebug()<<QString::fromStdString(to_string(currentPatient.getPriorite()));
    ui->comboBox_2->setCurrentIndex(indicePriorite);

    /*foreach (QString str, ui->comboBox_2 )
    {
        if(str == QString::QString::number(currentPatient.getPriorite())){
            ui->comboBox->setCurrentIndex(indicePriorite);
        }
        indicePriorite++;
    }*/

    //Trouver le medecin de la consultation
    /*int indiceMedecin = 0;
    foreach (QString str, ui->comboBox_2 )
    {
        if(str == QString::fromStdString(currentPatient.getMedecin())){
            ui->comboBox_2->setCurrentIndex(indiceMedecin);
        }
        indiceMedecin++;
    }*/
    ui->textEdit->setText(QString::fromStdString(currentPatient.getCommentaires()));


    //Evennements
    //evenements pour afficher calendrier
    QObject::connect(ui->toolButton, SIGNAL(clicked()),this, SLOT(afficherCalendrier()));
    QObject::connect(ui->toolButton_2, SIGNAL(clicked()),this, SLOT(afficherCalendrier_2()));
    //evenements pour ajouter un personnel de la listeBD à la listeTraitant
    QObject::connect(ui->rightArrow_toolButton, SIGNAL(clicked()),this, SLOT(ajouterPersonnelTraitant()));
    //evenements pour ajouter un personnel de la listeTraitant à la listeBD
    QObject::connect(ui->leftArrow_toolButton, SIGNAL(clicked()),this, SLOT(supprimerPersonnelTraitant()));
    //evenement pour quitter le formulaire
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour  afficher formulaire ajouterPatient
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(modificationPatient()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(calendrier->findChild<QWidget *>("pushButton"), SIGNAL(clicked()),this, SLOT(afficherDateSelect()));
    //evenement pour afficher date selectionnee dans tab recherche
    QObject::connect(calendrier_2->findChild<QWidget *>("pushButton"), SIGNAL(clicked()),this, SLOT(afficherDateSelect_2()));
}

modifierPatient::~modifierPatient()
{
    delete ui;
}

// afficher calendrier1 ajouterPatient (bloquant)
void modifierPatient::afficherCalendrier(){
    calendrier->exec();  // force l'affichage de la fenetre en mode modal, fenetre bloquante
    //calendrier->setModal(true);
}

// afficher calendrier1 ajouterPatient (bloquant)
void modifierPatient::afficherDateSelect(){
    ui->lineEdit_7 -> setText(calendrier->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}

// afficher calendrier ajouterPatient (bloquant)
void modifierPatient::afficherCalendrier_2(){
    calendrier_2->exec();  // force l'affichage de la fenetre en mode modal, fenetre bloquante
    //calendrier->setModal(true);
}

// afficher calendrier1 ajouterPatient (bloquant)
void modifierPatient::afficherDateSelect_2(){
    ui->lineEdit -> setText(calendrier_2->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}

/**
 * Methode permettant de verifier les informations entree et ajouter le patient si toutes les informations nécessaires sont correctes
 * @brief ajoutPatient::ajouterPatient
 */
void modifierPatient::annuler()
{
    // Fermeture du formulaire
    this->close();
}

void modifierPatient::ajouterPersonnelTraitant(){
    //Affectation des TreeView
    bool selected = ui->PersonnelBD_treeView->currentIndex().isValid();// return selected row(s)
    QList<QString> listeLabelTypesPersonnel =   qobject_cast<MainWindow*>(parent())->getBD()->getLabelsTypePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());


    if(selected){
        //Ajout d'une consultation pour le patient dans la BD
        QString nomPrenomPatient =  ui->PersonnelBD_treeView->selectionModel()->selectedIndexes()[0].data().toString();
        qDebug()<< nomPrenomPatient;
        int idPersonnel = qobject_cast<MainWindow*>(parent())->getBD()->getIdPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), nomPrenomPatient.toStdString());
        int idConsult = qobject_cast<MainWindow*>(parent())->getBD()->getListeConsults(qobject_cast<MainWindow*>(parent())->getBD()->getDB()).last().getIdConsult()+1;
        Consult consult(idConsult,this->idPatient,idPersonnel);
        qobject_cast<MainWindow*>(parent())->getBD()->ajouterConsult(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),consult);

        QList<int> listeIdPersonnel =  qobject_cast<MainWindow*>(parent())->getBD()->getIdRessourcesPatient(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), this->idPatient);
        QList<Personnel>listePersonnelMaj = qobject_cast<MainWindow*>(parent())->getBD()->getListePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        QList<Personnel>listePersonnelBDTemp;
        QList<Personnel>listePersonnelTraitantTemp;

        //Obtenir les personnels liés à la liste des id et remplir la liste des Personnel traitant
        for(int i=0;i<listeIdPersonnel.size();i++){
            for(int j=0;j<listePersonnelMaj.size();j++){
                if(listeIdPersonnel[i] == listePersonnelMaj[j].getNumId()){
                    listePersonnelTraitantTemp.push_back(listePersonnelMaj[j]);
                }
            }
        }

        this->listePersonnelTraitant = listePersonnelTraitantTemp;

        //Obtenir les personnels  sans ceux qui sont contenus dans la liste des médecin traitant
        bool idTrouve = true;
        for(int i=0;i<listePersonnelMaj.size();i++){
            for(int j=0;j<listeIdPersonnel.size();j++){
                if(listePersonnelMaj[i].getNumId() != listeIdPersonnel[j]){
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

void modifierPatient::supprimerPersonnelTraitant(){
    //Affectation des TreeView
    bool selected = ui->PersonnelTraitant_treeView->currentIndex().isValid();// return selected row(s)

    if(selected){
        //Supprimer une consultation pour le patient dans la BD
        QString nomPrenomPatient =  ui->PersonnelTraitant_treeView->selectionModel()->selectedIndexes()[0].data().toString();
        int idPersonnel = qobject_cast<MainWindow*>(parent())->getBD()->getIdPersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), nomPrenomPatient.toStdString());
        int idConsult = qobject_cast<MainWindow*>(parent())->getBD()->getIdConsult(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),this->idPatient,idPersonnel);
        //Consult consult(idConsult,this->idPatient,idPersonnel);
        qobject_cast<MainWindow*>(parent())->getBD()->supprimerConsult(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),idConsult);

        QList<int> listeIdPersonnel =  qobject_cast<MainWindow*>(parent())->getBD()->getIdRessourcesPatient(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), this->idPatient);
        QList<Personnel>listePersonnelMaj = qobject_cast<MainWindow*>(parent())->getBD()->getListePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());
        QList<Personnel>listePersonnelBDTemp;
        QList<Personnel>listePersonnelTraitantTemp;

        //Obtenir les personnels liés à la liste des id et remplir la liste des Personnel Traitant
        for(int i=0;i<listeIdPersonnel.size();i++){
            for(int j=0;j<listePersonnelMaj.size();j++){
                if(listeIdPersonnel[i] == listePersonnelMaj[j].getNumId()){
                    listePersonnelTraitantTemp.push_back(listePersonnelMaj[j]);
                }
            }
        }

        this->listePersonnelTraitant = listePersonnelTraitantTemp;

        //Obtenir les personnels  sans ceux qui sont contenus dans la liste des médecin traitant
        bool idTrouve = true;
        for(int i=0;i<listePersonnelMaj.size();i++){
            for(int j=0;j<listeIdPersonnel.size();j++){
                if(listePersonnelMaj[i].getNumId() != listeIdPersonnel[j]){
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

/** Methode permettant de controler le format d'une date (verification simple pour commencer, on pourrait faire attention -> jours/mois)
 * @brief ajoutPatient::verifierDate
 * @param date
 * @return
 */
bool modifierPatient::verifierDate(QString date){
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
bool modifierPatient::verifierNomPropre(QString nomPropre){
    bool valide = true;
    QRegExp rx("[À-ŸA-Z]{1}[à-ÿa-z]{0,39}");
    if(!rx.exactMatch(nomPropre)){
        valide = false;
    }
    return valide;
}
bool modifierPatient::verifierAdresse(QString adresse){
    bool valide = true;
    if(adresse == ""){
        valide = false;
    }
    return valide;
}
bool modifierPatient::verifierCodePostale(QString cdepostal){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(cdepostal)|| cdepostal == ""){
        valide = false;
    }
    return valide;
}
bool modifierPatient::verifierDureeConsult(QString dureeConsult){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(dureeConsult) || dureeConsult == ""){
        valide = false;
    }
    return valide;
}
bool modifierPatient::verifierNumPrio(QString numPrio){
    bool valide = true;
    QRegExp rx("[1-5]");
    if(!rx.exactMatch(numPrio) || numPrio == ""){
        valide = false;
    }
    return valide;
}
bool modifierPatient::verifierNumTel(QString numTel){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(numTel)){
        valide = false;
    }
    return valide;
}
bool modifierPatient::verifierEmail(QString email){
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
bool modifierPatient::verifierMedecin(QString medecin){
    bool valide = true;
    QRegExp rx("ex: Anne Marie");
    if(rx.exactMatch(medecin)){
        valide = false;
    }
    return valide;
}
bool modifierPatient::verifierlisteMedecins(QList<Personnel>listePersonnel){
   bool valide = true;
   if(listePersonnel.isEmpty()){
       valide = false;
   }
   return valide;
}

/**
 * Methode permettant de verifier les informations entree et ajouter le patient si toutes les informations nécessaires sont correctes
 * @brief modifierPatient::modifierPatient
 */
void modifierPatient::modificationPatient()
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
                       "1 (en minutes)<br></p>");
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
    /*}else if (!verifierMedecin(ui->comboBox->currentText())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                       "Champ médecin ne peut être vide"
                       "(veuillez saisir un autre médecin que l'exemple)<br></p>");
        msgBox.exec();
        verifier= false;*/
    }else if(!verifierlisteMedecins(listePersonnelTraitant)){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("<p align='center'>Attention ! <br>"
                   "Champ médecin ne peut être vide"
                   "(veuillez chosir au moins un médecin dans l'arbre)<br></p>");
        msgBox.exec();
        verifier= false;
    }

    if (verifier == true){  // Si le formulaire est correctement rempli

        QList<int> listeIdMedecins;
        for(int i = 0;i<this->listePersonnelTraitant.size();i++){
            listeIdMedecins.push_back(this->listePersonnelTraitant[i].getNumId());
        }
    //Ajout du Patient à la base de données
        //Création du Patient en local
        this->currentPatient.setDateCreation(ui->lineEdit->text().toStdString());
        this->currentPatient.setNom(ui->lineEdit_2->text().toStdString());
        this->currentPatient.setPrenom(ui->lineEdit_3->text().toStdString());
        this->currentPatient.setAdresse(ui->lineEdit_4->text().toStdString());
        this->currentPatient.setVille(ui->lineEdit_5->text().toStdString());
        this->currentPatient.setCodePostal(ui->lineEdit_6->text().toStdString());
        this->currentPatient.setNumTelephone(ui->lineEdit_10->text().toStdString());
        this->currentPatient.setEmail(ui->lineEdit_11->text().toStdString());
        this->currentPatient.setDateConsultation(ui->lineEdit_7->text().toStdString());
        this->currentPatient.setDureeConsultation(ui->spinBox->text().toStdString());
        //this->currentPatient.setMedecin(ui->comboBox->currentText().toStdString());
        this->currentPatient.setlistesMedecins(listeIdMedecins);
        this->currentPatient.setPriorite(ui->comboBox_2->currentText().toInt());
        this->currentPatient.setCommentaires(ui->textEdit->toPlainText().toStdString());

        //Modifie le patient dans la BD
         qobject_cast<MainWindow*>(parent())->getBD()->modifierPatient(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),this->currentPatient/*,this->pastIdPersonnel*/);
        //Redefini le model de BD
         qobject_cast<MainWindow*>(parent())->resetTablePatientModel(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

    //Envoyer l'information d'ajout dans status Bar

    qobject_cast<MainWindow*>(parent())->setStatusBar("Patient "+ui->lineEdit_2->text()+" "+ui->lineEdit_3->text()+" modifié !");

    // Fermeture du formulaire
    this->close();
    }
}
