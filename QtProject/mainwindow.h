#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "calendrier.h"
#include "ajoutpatient.h"
#include "supprimerpatient.h"
#include "modifierpatient.h"
#include "ajoutpersonnel.h"
#include "supprimerpersonnel.h"
#include "modifierpersonnel.h"
#include "apropos.h"
#include "requetebd.h"
#include "modeltablepatient.h"
#include "personnel.h"
#include "gestiontypemedecin.h"
#include "modeltreepersonnel.h"
#include "modeltabletypemedecin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, QSqlDatabase db);
    MainWindow(QSqlDatabase db, QString login);
    ~MainWindow();
    RequeteBD* getBD();
    void resetTablePatientModel(QSqlDatabase db);
    void resetTablePatientModel_filter(QSqlDatabase db);
    void resetTreePersonnelModel(QSqlDatabase db);
    void resetTableTypesPersModel(QSqlDatabase db);
    void setStatusBar(const QString &message);
    bool verifierDate(QString date);
    bool verifierNomPropre(QString nomPropre);
    bool verifierNumID(QString numId);

private slots:
    void ajouterPatient();
    void supprimerPatient();
    void modifPatient();
    void afficherCalendrier();
    void afficherCalendrier_2();
    void ajouterPersonnel();
    void supprimerPersonnel();
    void modifierPersonnel();
    void gererTypesPersonnel();
    void afficherAPropos();

    //affichage
    void afficherDateSelect();
    void afficherDateSelect_2();
    void rechercherPatients();

private:
    Ui::MainWindow *ui;
    Calendrier *calendrier;
    Calendrier * calendrier_2;
    ajoutPatient *patientWindow;
    SupprimerPatient *supPatWindow;
    modifierPatient *modPatWindow;
    ajoutPersonnel *personnnelWindow;
    SupprimerPersonnel *supPerWindow;
    ModifierPersonnel *modPerWindow;
    gestionTypeMedecin *gestionTypesPerWindow;
    aPropos *aProposWindow;
    RequeteBD *baseDonnee;
    QSqlDatabase requestDataBase;
    modelTablePatient *modelPatient;
    modelTreePersonnel *modelPersonnel;
    modelTableTypeMedecin *modelTypePers;
};

#endif // MAINWINDOW_H
