#include "ajoutpersonnel.h"
#include "ui_ajoutpersonnel.h"
#include "mainwindow.h"
#include "personnel.h"
#include "verifierformat.h"
#include <QMessageBox>

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
}

void ajoutPersonnel::ajouterTypePersonnel(){
    if(!ui->addType_edit->text().isEmpty()){
        //Récupération de la liste de Personnel
        QList<typePersonnel>listTypePersonnel = qobject_cast<MainWindow*>(parent())->getBD()->getListeTypePersonnels(qobject_cast<MainWindow*>(parent())->getBD()->getDB());

        //Création en local du nouveau typePersonnel
        typePersonnel type(listTypePersonnel.last().getIdType()+1,ui->addType_edit->text().toStdString());

        //Ajout du Type dans la base de donnée
        qobject_cast<MainWindow*>(parent())->getBD()->ajouterTypePersonnel(qobject_cast<MainWindow*>(parent())->getBD()->getDB(),type);

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


/**
 * Methode permettant de verifier les informations entree et ajouter le personnel si toutes les informations nécessaires sont correctes
 * @brief ajoutPersonnel::ajouterPersonnel
 */
void ajoutPersonnel::ajouterPersonnel()
{
    bool verifier = true;

    //Verifications
    verifier = verifierFormat().verificationsAjoutPersonnel(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_5->text(),
                                         ui->lineEdit_6->text(), ui->comboBox_2->currentText(), ui->lineEdit_8->text(), ui->lineEdit_9->text(), ui->lineEdit_10->text(),
                                         ui->lineEdit_11->text());

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
    }
}
