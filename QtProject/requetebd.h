#ifndef REQUETEBD_H
#define REQUETEBD_H
#include <QSqlDatabase>
#include "patient.h"
#include "personnel.h"
#include "consult.h"
#include "compte.h"
#include "typepersonnel.h"


class RequeteBD
{
private:
    QSqlDatabase db;
public:
    RequeteBD(QSqlDatabase db);
    QSqlDatabase getDB();
    bool verificationLogin(QSqlDatabase db, QString login, QString password);
    void addPatient(QSqlDatabase db, Patient patient);
    void removePatient(QSqlDatabase db, int numId);
    void modifierPatient(QSqlDatabase db, Patient patient/*,QList<int>pastIdListesMedecins*/);
    void addPersonnel(QSqlDatabase db, Personnel personnel, int idType, int idCompte);
    void removePersonnel(QSqlDatabase db, int idRessource, int idCompte);
    void modifierPersonnel(QSqlDatabase db, Personnel personnel, int idType, int idCompte);
    void ajouterCompte(QSqlDatabase db, Compte newcompte);
    void supprimerCompte(QSqlDatabase db,int idRessource);
    void ajouterTypePersonnel(QSqlDatabase db, typePersonnel type);
    void modifierTypePersonnel(QSqlDatabase db, typePersonnel type);//
    void supprimerTypePersonnel(QSqlDatabase db,int idType);//
    void ajouterConsult(QSqlDatabase db, Consult consult);
    void supprimerConsult(QSqlDatabase db, int idConsult);
    int getIdConsult(QSqlDatabase db,int idPatient, int idPersonnel);
    bool getListePersType(QSqlDatabase db,int idType);
    int getIdPersonnel(QSqlDatabase db, string nomPrenom);
    int getIdCompte(QSqlDatabase db, int idRessource);
    int getIdType(QSqlDatabase db, QString typeMedecin);
    QString getTypeMedecin(QSqlDatabase db, int idRessource);
    //int getIdPersonnel(QSqlDatabase db, string nom, string prenom);
    Patient getPatient(QSqlDatabase db, int numId);
    Personnel getPersonnel(QSqlDatabase db, int idPersonnel);
    QString getNomPatient(QSqlDatabase db, int numId);
    QString getNomPrenomPersonnelConsult(QSqlDatabase db, int idPatient);
    QList<Patient> getListePatients(QSqlDatabase db);
    QList<Patient> getListePatientsFilter(QSqlDatabase db, QString idPatient, QString nomPatient, QString prenomPatient, const QString dateDebut, const QString dateFin);
    QList<Consult> getListeConsults(QSqlDatabase db);
    QList<Compte> getListeComptes(QSqlDatabase db);
    QList<Personnel> getListePersonnel(QSqlDatabase db);
    QList<typePersonnel> getListeTypePersonnels(QSqlDatabase db);
    QList<QString> getLabelsTypePersonnel(QSqlDatabase db);
    QList<int> getIdRessourcesPatient(QSqlDatabase db, int idPatient);
    void getlisteNomPrePrioConsTot(QSqlDatabase db, ofstream &fichier);
    void getListeExportPersonnels(QSqlDatabase db, ofstream &fichier);
    void getListeExportTypes(QSqlDatabase db, ofstream &fichier);

};

#endif // REQUETEBD_H
