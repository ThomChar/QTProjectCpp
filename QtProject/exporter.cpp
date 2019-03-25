#include <QStringListModel>
#include <QMessageBox>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <ios>
#include "exporter.h"
#include "ui_exporter.h"
#include "mainwindow.h"

using namespace std;

exporter::exporter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exporter)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setWindowTitle("Ajout Patient");
    this->setFixedSize( this->size());
    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->objectExport_comboBox->setCurrentIndex(0);
    ui->nomfichier_edit->setPlaceholderText("ex: stat_patients");
    ui->extension_edit->setPlaceholderText("ex: .txt");

    ui->objectExport_comboBox->addItem("ex: Statistiques Patients");
    ui->objectExport_comboBox->addItem("Statistiques Patients");
    ui->objectExport_comboBox->addItem("Statistiques Personnels");
    ui->objectExport_comboBox->addItem("Statistiques Types de Personnel");
    //ui->objectExport_comboBox->addItem("Statistiques Consultations");

    this->listeStatsExport.push_back("ex: Statistiques Patients");
    this->listeStatsExport.push_back("Statistiques Patients");
    this->listeStatsExport.push_back("Statistiques Personnels");
    this->listeStatsExport.push_back("Statistiques Types de Personnel");
    //this->listeStatsExport.push_back("Statistiques Consultations");

    this->model = new QStringListModel();

    //Evennements
    //evenement pour quitter le formulaire
    QObject::connect(ui->cancel_button, SIGNAL(clicked()),this,SLOT(annuler()));
    //evenement pour valider le formulaire
    QObject::connect(ui->add_button, SIGNAL(clicked()),this,SLOT(valider()));
    //evenement pour  afficher formulaire ajouterTypePers
    QObject::connect(ui->addObjectToExport_toolButton, SIGNAL(clicked()),this, SLOT(ajouterExportAListe()));
    //evenement pour  vider la liste des export
    QObject::connect(ui->viderListe_toolButton, SIGNAL(clicked()),this, SLOT(viderListe()));
}

exporter::~exporter()
{
    delete ui;
}

void exporter::annuler(){
    this->close();
}
void exporter::valider(){

     bool verification = true;

     QString nomFichier = ui->nomfichier_edit->text();
     QString extension = ui->extension_edit->text();

     if(this->listeFonctionExports.isEmpty()){
         verification = false;
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warnig");
         msgBox.setText("Veuillez selectionner au moins un objet à exporter");
         msgBox.exec();
     }else if (nomFichier.isEmpty()){
         verification = false;
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warnig");
         msgBox.setText("Veuillez remplir le nom du fichier a créé");
         msgBox.exec();
     }else if (extension.isEmpty()){
         verification = false;
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warnig");
         msgBox.setText("Veuillez selectionner une extension entre .txt et .xml");
         msgBox.exec();
     }

     if (verification){

        ofstream fichier(nomFichier.toStdString() + extension.toStdString());
        //fichier.open(nomFichier.toStdString() + extension.toStdString());//, ios::out);
        for (int i =0;i<this->listeFonctionExports.size();i++){
            if(this->listeFonctionExports[i] == "Statistiques Patients"){
                qobject_cast<MainWindow*>(parent())->getBD()->getlisteNomPrePrioConsTot(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), fichier);
            }else if(this->listeFonctionExports[i] == "Statistiques Personnels"){
                qobject_cast<MainWindow*>(parent())->getBD()->getListeExportPersonnels(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), fichier);
            }else if(this->listeFonctionExports[i] == "Statistiques Types de Personnel"){
                qobject_cast<MainWindow*>(parent())->getBD()->getListeExportTypes(qobject_cast<MainWindow*>(parent())->getBD()->getDB(), fichier);
            //}else if(this->listeFonctionExports[i] == "Statistiques Consultations"){

            }
        }

        fichier.close();

        //validation et fermeture du formulaire
        this->close();
    }
}

//Ajoute le contenu de la combox selectionné dans la liste d'export
void exporter::ajouterExportAListe(){


    if (ui->objectExport_comboBox->currentText() != "ex: Statistiques Patients"){
        //Ajout de la nouvelle focntionnalités d'export
        this->listeFonctionExports.push_back(ui->objectExport_comboBox->currentText());

        //Mise à jour du model de la liste d'export avec le nouvel export
        this->model->insertRow(this->model->rowCount());
        QModelIndex index = this->model->index(this->model->rowCount()-1);
        this->model->setData(index, ui->objectExport_comboBox->currentText());
        ui->listeExport_listView->setModel(this->model);

        //Enlever l'élément ajouté de la combo box
        ui->objectExport_comboBox->removeItem(ui->objectExport_comboBox->currentIndex());

    }else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warnig");
        msgBox.setText("Veuillez selectionner un objet à exporter avant de l'ajouter à la liste");
        msgBox.exec();
    }
}

void exporter::viderListe(){

    //Vider la liste
    QStringList list;
    this->model->setStringList(list);
    ui->listeExport_listView->setModel(this->model);
    this->listeFonctionExports = list;

    //reaffecter les cases de la combo box
    ui->objectExport_comboBox->clear();
    ui->objectExport_comboBox->addItem("ex: Statistiques Patients");
    ui->objectExport_comboBox->addItem("Statistiques Patients");
    ui->objectExport_comboBox->addItem("Statistiques Personnels");
    ui->objectExport_comboBox->addItem("Statistiques Types de Personnel");
    //ui->objectExport_comboBox->addItem("Statistiques Consultations");
}
