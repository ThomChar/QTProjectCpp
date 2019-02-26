#ifndef AJOUTPATIENT_H
#define AJOUTPATIENT_H

#include <QDialog>
#include "calendrier.h"

namespace Ui {
class ajoutPatient;
}

class ajoutPatient : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutPatient(QWidget *parent = nullptr);
    ~ajoutPatient();
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
    void ajouterPatient();
    void annuler();
    void afficherCalendrier();
    void afficherCalendrier_2();

private:
    Ui::ajoutPatient *ui;
    //methodes de verifications à ajouter
    Calendrier *calendrier;
    Calendrier *calendrier_2;

};

#endif // AJOUTPATIENT_H
