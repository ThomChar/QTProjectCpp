#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <QString>

using namespace std;

class Patient
{
public:
    Patient();
    Patient(Patient* patient);
    Patient(string dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
            string dateConsultation, string dureeConsultation, int priorite, string medecin, string commentaires);
    Patient(int numId, string dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
            string dateConsultation, string dureeConsultation, int priorite, string medecin, string commentaires);
    ~Patient();
    string getDateCreation();
    void setDateCreation(string dateCreation);
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
    string getDateConsultation();
    void setDateConsultation(string dateConsultation);
    string getDureeConsultation();
    void setDureeConsultation(string dureeConsultation);
    int getPriorite();
    void setPriorite(int priorite);
    string getMedecin();
    void setMedecin(string medecin);
    string getCommentaires();
    void setCommentaires(string commentaires);
    /*int getIdConsult();
    void setIdConsult(int idConsult);*/
private:
    string dateCreation;
    int numId;
    string nom;
    string prenom;
    string adresse;
    string ville;
    string codepostal;
    string numTelephone;
    string email;
    string dateConsultation;
    string dureeConsultation;
    int priorite;
    string medecin;
    string commentaires;
    //int idConsult;
};

#endif // PATIENT_H
