#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calendar.h"
#include "ajoutpatient.h"
#include "ajoutpersonnel.h"
#include "apropos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ajouterPatient();
    void afficherCalendrier();
    void ajouterPersonnel();
    void afficherAPropos();


private:
    Ui::MainWindow *ui;
    calendar *calendrier;
    ajoutPatient *patientWindow;
    ajoutPersonnel *personnnelWindow;
    aPropos *aProposWindow;
};

#endif // MAINWINDOW_H
