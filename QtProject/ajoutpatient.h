#ifndef AJOUTPATIENT_H
#define AJOUTPATIENT_H

#include <QDialog>
#include <QSqlDatabase>
#include "calendrier.h"
#include "personnel.h"
#include "modeltreepersonnel.h"

namespace Ui {
class ajoutPatient;
}

class ajoutPatient : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutPatient(QWidget *parent);
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
    bool verifierlisteMedecins(QList<Personnel>listePersonnel);

private slots:
    void afficherDateSelect();
    void afficherDateSelect_2();
    void ajouterPatient();
    void annuler();
    void afficherCalendrier();
    void afficherCalendrier_2();
    void ajouterPersonnelTraitant();
    void supprimerPersonnelTraitant();

private:
    Ui::ajoutPatient *ui;

    Calendrier *calendrier;
    Calendrier *calendrier_2;
    modelTreePersonnel *modelPersonnelBD;
    modelTreePersonnel *modelPersonnelTraitant;
    QList<QString> listeTypePersonnel;
    QList<Personnel> listePersonnelBD;
    QList<Personnel> listePersonnelTraitant;
    QList<Personnel> listePersonnel;

};

#endif // AJOUTPATIENT_H
