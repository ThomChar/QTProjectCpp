#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <QList>
#include <QString>
#include <QDate>


using namespace std;

class Patient
{
public:
    Patient();
    Patient(Patient* patient);
    Patient(QDate dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
            QDate dateConsultation, string dureeConsultation, int priorite, string medecin, string commentaires);
    Patient(int numId, QDate dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
            QDate dateConsultation, string dureeConsultation, int priorite, string medecin, string commentaires);
    Patient( QDate dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
            QDate dateConsultation, string dureeConsultation, int priorite,  QList<int> listesMedecins, string commentaires);
    Patient(int numId, QDate dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
                     QDate dateConsultation, string dureeConsultation, int priorite,  QList<int> listesMedecins, string commentaires);

    ~Patient();
    QDate getDateCreation();
    void setDateCreation(QDate dateCreation);
    int getNumId();
    void setNumId(int numId);
    string getNom();
    void setNom(string nom);
    string getPrenom();
    void setPrenom(string prenom);
    string getAdresse();
    void setAdresse(string adresse);
    string getVille();
    void setVille(string ville);
    string getCodePostal();
    void setCodePostal(string codePostal);
    string getNumTelephone();
    void setNumTelephone(string numTelephone);
    string getEmail();
    void setEmail(string email);
    QDate getDateConsultation();
    void setDateConsultation(QDate dateConsultation);
    string getDureeConsultation();
    void setDureeConsultation(string dureeConsultation);
    int getPriorite();
    void setPriorite(int priorite);
    string getMedecin();
    void setMedecin(string medecin);
     QList<int> getlistesMedecins();
    void setlistesMedecins( QList<int> listesMedecins);
    string getCommentaires();
    void setCommentaires(string commentaires);
private:
    QDate dateCreation;
    int numId;
    string nom;
    string prenom;
    string adresse;
    string ville;
    string codepostal;
    string numTelephone;
    string email;
    QDate dateConsultation;
    string dureeConsultation;
    int priorite;
     QList<int> listesMedecins;
    string medecin;
    string commentaires;
};

#endif // PATIENT_H
