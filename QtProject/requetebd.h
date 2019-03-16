#ifndef REQUETEBD_H
#define REQUETEBD_H
#include <QSqlDatabase>
#include "patient.h"
#include "personnel.h"
#include "consult.h"
#include "compte.h"


class RequeteBD
{
private:
    QSqlDatabase db;
public:
    RequeteBD(QSqlDatabase db);
    QSqlDatabase getDB();
    void addPatient(QSqlDatabase db, Patient patient);
    int getIdPersonnel(QSqlDatabase db, string nom, string prenom);
    void removePatient(QSqlDatabase db, int numId);
    void modifierPatient(QSqlDatabase db, Patient patient/*,int pastIdPersonnel*/);
    QString getNomPatient(QSqlDatabase db, int numId);
    QString getNomPrenomPersonnelConsult(QSqlDatabase db, int idPatient);
    Patient getPatient(QSqlDatabase db, int numId);
    QList<Patient> getListePatients(QSqlDatabase db);
    QList<Consult> getListeConsults(QSqlDatabase db);
    QList<Compte> getListeComptes(QSqlDatabase db);
    void addPersonnel(QSqlDatabase db, Personnel personnel, int idType, int idCompte);
    void removePersonnel(QSqlDatabase db, int idRessource, int idCompte);
    void modifierPersonnel(QSqlDatabase db, Personnel personnel, int idType, int idCompte);
    Personnel getPersonnel(QSqlDatabase db, int numId);
    int getIdCompte(QSqlDatabase db, int idRessource);
    int getIdType(QSqlDatabase db, QString typeMedecin);
    QList<Personnel> getListePersonnel(QSqlDatabase db);
    bool verificationLogin(QSqlDatabase db, QString login, QString password);
};

#endif // REQUETEBD_H
