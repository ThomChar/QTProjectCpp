#include "personnel.h"

Personnel::Personnel()
{

}

Personnel::Personnel(string dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
                 string typeMedecin, string login, string password){
    this->dateCreation = dateCreation;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this-> ville = ville;
    this->codepostal = codepostal;
    this-> numTelephone= numTelephone;
    this->email = email;
    this->typeMedecin = typeMedecin;
    this->login =  login;
    this-> password = password;
}

Personnel::~Personnel(){

}

string Personnel::getDateCreation(){
    return this->dateCreation;
}
void Personnel::setDateCreation(string dateCreation){
    this->dateCreation = dateCreation;
}
string Personnel::getNom(){
    return this->nom;
}
void Personnel::setNom(string nom){
    this->nom = nom;
}
string Personnel::getPrenom(){
    return this->prenom;
}
void Personnel::setPrenom(string prenom){
    this->prenom = prenom;
}
string Personnel::getAdresse(){
    return this->adresse;
}
void Personnel::setAdresse(string adresse){
    this->adresse = adresse;
}
string Personnel::getVille(){
    return this->ville;
}
void Personnel::setVille(string ville){
    this->ville = ville;
}
string Personnel::getCodePostal(){
    return this->codepostal;
}
void Personnel::setCodePostal(string codePostal){
    this->codepostal = codePostal;
}
string Personnel::getNumTelephone(){
return this->numTelephone;

}
void Personnel::setNumTelephone(string numTelephone){
    this->numTelephone = numTelephone;
}
string Personnel::getEmail(){
    return this->email;
}
void Personnel::setEmail(string email){
    this->email = email;
}
string Personnel::getTypeMedecin(){
    return this->typeMedecin;
}
void Personnel::setTypeMedecin(string typeMedecin){
    this->typeMedecin = typeMedecin;
}
string Personnel::getLogin(){
    return this->login;
}
void Personnel::setLogin(string login){
    this->login = login;
}
string Personnel::getPassword(){
    return this->password;
}
void Personnel::setPassword(string password){
    this->password = password;
}
