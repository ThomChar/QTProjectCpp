#include "modifierpatient.h"
#include "ui_modifierpatient.h"
#include "mainwindow.h"
#include "patient.h"
#include "verifierformat.h"
#include <QMessageBox>
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

    this->idPatient = idPatient;
    this->pastIdPersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getIdPersonnel(qobject_cast<MainWindow*>(parent)->getBD()->getDB(),currentPatient.getMedecin());

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

    QList<typePersonnel> listeTypePersonnel = qobject_cast<MainWindow*>(parent)->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent)->getBD()->getDB());
    for(int i=0;i<listeTypePersonnel.size();i++){
    this->listeTypePersonnel.push_back(QString::fromStdString(listeTypePersonnel[i].getLabel()));
    }

    //Obtenir l'id des personnels du patient sélectionné
     QList<int> listeIdPersonnel =  qobject_cast<MainWindow*>(parent)->getBD()->getIdRessourcesPatient(qobject_cast<MainWindow*>(parent)->getBD()->getDB(), idPatient);

    //Obtenir les personnels liés à la liste des id et remplir la liste des Personnel traitant
    for(int i=0;i<listeIdPersonnel.size();i++){
        for(int j=0;j<listePersonnel.size();j++){
            if(listeIdPersonnel[i] == listePersonnel[j].getNumId()){
                this->listePersonnelTraitant.push_back(listePersonnel[j]);
            }
        }
    }

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
    ui->lineEdit->setText(currentPatient.getDateCreation().toString("dd/MM/yyyy"));
    ui->lineEdit_2->setText(QString::fromStdString(currentPatient.getNom()));
    ui->lineEdit_3->setText(QString::fromStdString(currentPatient.getPrenom()));
    ui->lineEdit_4->setText(QString::fromStdString(currentPatient.getAdresse()));
    ui->lineEdit_5->setText(QString::fromStdString(currentPatient.getVille()));
    ui->lineEdit_6->setText(QString::fromStdString(currentPatient.getCodePostal()));
    ui->lineEdit_7->setText(currentPatient.getDateConsultation().toString("dd/MM/yyyy"));
    ui->lineEdit_10->setText(QString::fromStdString(currentPatient.getNumTelephone()));
    ui->lineEdit_11->setText(QString::fromStdString(currentPatient.getEmail()));

    //Trouver la duree de Consultation
    ui->spinBox->setValue(QString::fromStdString(currentPatient.getDureeConsultation()).toInt());

        //Trouver la priorité associé au patient
    int indicePriorite = 0;
    indicePriorite = ui->comboBox_2->findText(to_string(currentPatient.getPriorite()).c_str());
    ui->comboBox_2->setCurrentIndex(indicePriorite);

    //Trouver le medecin de la consultation

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
}

// afficher calendrier1 ajouterPatient (bloquant)
void modifierPatient::afficherDateSelect(){
    ui->lineEdit_7 -> setText(calendrier->getCalendrier()->selectedDate().toString("dd/MM/yyyy"));
}

// afficher calendrier ajouterPatient (bloquant)
void modifierPatient::afficherCalendrier_2(){
    calendrier_2->exec();  // force l'affichage de la fenetre en mode modal, fenetre bloquante
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

/**
 * Methode permettant de verifier les informations entree et ajouter le patient si toutes les informations nécessaires sont correctes
 * @brief modifierPatient::modifierPatient
 */
void modifierPatient::modificationPatient()
{
    bool verifier = true;

    //Verifications

    verifier = verifierFormat().verificationsAjoutPatient(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_5->text(),
                                         ui->lineEdit_6->text(), ui->lineEdit_7->text(), ui->spinBox->text(), ui->comboBox_2->currentText(), ui->lineEdit_10->text(),
                                         ui->lineEdit_11->text(), listePersonnelTraitant);
    if (verifier == true){  // Si le formulaire est correctement rempli

        QList<int> listeIdMedecins;
        for(int i = 0;i<this->listePersonnelTraitant.size();i++){
            listeIdMedecins.push_back(this->listePersonnelTraitant[i].getNumId());
        }
    //Ajout du Patient à la base de données
        //Création du Patient en local
        QString dateCreation_QS = QString::fromStdString(ui->lineEdit->text().toStdString());
        QString dateConsultation_QS = QString::fromStdString(ui->lineEdit_7->text().toStdString());
        QDate dateCreation = QDate::fromString(dateCreation_QS, "dd/MM/yyyy");
        QDate dateConsultation = QDate::fromString(dateConsultation_QS, "dd/MM/yyyy");

        this->currentPatient.setDateCreation(dateCreation);
        this->currentPatient.setNom(ui->lineEdit_2->text().toStdString());
        this->currentPatient.setPrenom(ui->lineEdit_3->text().toStdString());
        this->currentPatient.setAdresse(ui->lineEdit_4->text().toStdString());
        this->currentPatient.setVille(ui->lineEdit_5->text().toStdString());
        this->currentPatient.setCodePostal(ui->lineEdit_6->text().toStdString());
        this->currentPatient.setNumTelephone(ui->lineEdit_10->text().toStdString());
        this->currentPatient.setEmail(ui->lineEdit_11->text().toStdString());
        this->currentPatient.setDateConsultation(dateConsultation);
        this->currentPatient.setDureeConsultation(ui->spinBox->text().toStdString());
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
