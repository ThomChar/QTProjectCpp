#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <string>

using namespace std;

class Personnel
{
public:
    Personnel();
    Personnel(string dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
                     string typeMedecin, string login, string password);
    ~Personnel();
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
    string getTypeMedecin();
    void setTypeMedecin(string typeMedecin);
    string getLogin();
    void setLogin(string login);
    string getPassword();
    void setPassword(string password);
private :
    string dateCreation;
    int numId;
    string nom;
    string prenom;
    string adresse;
    string ville;
    string codepostal;
    string numTelephone;
    string email;
    string typeMedecin;
    string login;
    string password;
};

#endif // PERSONNEL_H
