#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calendrier.h"
#include "ajoutpatient.h"
#include "ajoutpersonnel.h"
#include "apropos.h"
#include "modeltablepatient.h"
#include "personnel.h"
#include <QStandardItemModel>
#include "modelTreePersonnel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setStatusBar(const QString &message);
    bool verifierDate(QString date);
    bool verifierNomPropre(QString nomPropre);
    bool verifierNumID(QString numId);

private slots:
    void ajouterPatient();
    void afficherCalendrier();
    void afficherCalendrier_2();
    void ajouterPersonnel();
    void afficherAPropos();

    //affichage
    void afficherDateSelect();
    void afficherDateSelect_2();
    void rechercherPatient();

private:
    Ui::MainWindow *ui;
    Calendrier *calendrier;
    Calendrier * calendrier_2;
    ajoutPatient *patientWindow;
    ajoutPersonnel *personnnelWindow;
    aPropos *aProposWindow;
    modelTablePatient *modelPatient;
    modelTreePersonnel *model;
};

#endif // MAINWINDOW_H
