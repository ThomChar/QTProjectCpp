#ifndef MODIFIERPERSONNEL_H
#define MODIFIERPERSONNEL_H

#include <QDialog>
#include "calendrier.h"
#include "personnel.h"

namespace Ui {
class ModifierPersonnel;
}

class ModifierPersonnel : public QDialog
{
    Q_OBJECT

public:
    ModifierPersonnel(QWidget *parent, QString nomPrenom);
    ~ModifierPersonnel();
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
    void afficherDateSelect();
    void ajouterTypePersonnel();
    void modificationPersonnel();
    void annuler();
    void afficherCalendrier();
    void afficherLogPass();

private:
    Ui::ModifierPersonnel *ui;
    Calendrier *calendrier;
    Personnel currentPersonnel;
    //int pastIdPersonnel;
};

#endif // MODIFIERPERSONNEL_H
