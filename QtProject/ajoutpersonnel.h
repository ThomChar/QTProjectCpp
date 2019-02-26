#ifndef AJOUTPERSONNEL_H
#define AJOUTPERSONNEL_H

#include <QDialog>
#include "calendrier.h"

namespace Ui {
class ajoutPersonnel;
}

class ajoutPersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutPersonnel(QWidget *parent = nullptr);
    ~ajoutPersonnel();
    bool verifierDate(QString date);
    bool verifierNomPropre(QString nomPropre);
    bool verifierAdresse(QString adresse);
    bool verifierVille(QString ville);
    bool verifierCodePostale(QString cdePostal);
    bool verifierTypeMedecin(QString typeMedecin);
    bool verifierLogin(QString login);
    bool verifierPassword(QString password);
    bool verifierNumTel(QString numTel);
    bool verifierEmail(QString email);

private slots:
    void annuler();
    void ajouterPersonnel();
    void afficherCalendrier();
    void afficherDateSelect();
    void afficherLogPass();

private:
    Ui::ajoutPersonnel *ui;
    Calendrier *calendrier;
};

#endif // AJOUTPERSONNEL_H
