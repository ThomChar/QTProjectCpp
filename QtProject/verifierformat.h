#ifndef VERIFIERFORMAT_H
#define VERIFIERFORMAT_H

#include <QString>
#include "personnel.h"

class verifierFormat
{
public:
    verifierFormat();

    //Patient
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

    //Personnel
    bool verifierAdressePersonnel(QString adresse);
    bool verifierVille(QString ville);
    bool verifierCodePostalePersonnel(QString cdepostal);
    bool verifierTypeMedecin(QString typeMedecin);
    bool verifierLogin(QString login, QString type);
    bool verifierPassword(QString password, QString type);
    bool verifierNumTelPersonnel(QString numTel);

    //MainWindow
    bool verifierDates(QString dateBefore, QString dateAfter);
    bool verifierNomPropreMainWindow(QString nomPropre);
    bool verifierNumID(QString numId);

    bool verificationsAjoutPatient(QString dateCreation, QString nom, QString prenom, QString adresse, QString ville, QString cdepostal,
                                                   QString dateConsult, QString dureeConsult, QString numPrio, QString tel, QString email, QList <Personnel> listePersonnelsTraitant);
    bool verificationsAjoutPersonnel(QString dateCreation, QString nom, QString prenom, QString adresse, QString ville, QString cdepostal,
                                                     QString typeMedecin, QString login, QString password, QString tel, QString email);
    bool verificationsModifPersonnel(QString dateCreation, QString nom, QString prenom, QString adresse, QString ville, QString cdepostal,
                                                     QString typeMedecin, QString login, QString password, QString tel, QString email);
};

#endif // VERIFIERFORMAT_H
