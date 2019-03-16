#ifndef MODIFIERPATIENT_H
#define MODIFIERPATIENT_H

#include <QDialog>
#include "calendrier.h"
#include "patient.h"

namespace Ui {
class modifierPatient;
}

class modifierPatient : public QDialog
{
    Q_OBJECT

public:
    modifierPatient(QWidget *parent, int idPatient);
    ~modifierPatient();
    bool verifierDate(QString date);
    bool verifierNomPropre(QString nomPropre);
    bool verifierAdresse(QString adresse);
    bool verifierCodePostale(QString cdePostal);
    bool verifierDureeConsult(QString dureeConsult);
    bool verifierNumPrio(QString numPrio);
    bool verifierNumTel(QString numTel);
    bool verifierEmail(QString email);
    bool verifierMedecin(QString medecin);

private slots:
    void afficherDateSelect();
    void afficherDateSelect_2();
    void modificationPatient();
    void annuler();
    void afficherCalendrier();
    void afficherCalendrier_2();

private:
     Ui::modifierPatient *ui;
    Calendrier *calendrier;
    Calendrier *calendrier_2;
    Patient currentPatient;
    int pastIdPersonnel;

};

#endif // MODIFIERPATIENT_H
