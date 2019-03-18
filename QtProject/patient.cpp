#include "patient.h"
#include <QString>
#include <QList>

Patient::Patient()
{
}

Patient::Patient(Patient* patient){
    Patient currentPatient;
    this->numId = patient->getNumId();
    this->dateCreation = patient->getDateCreation();
    this->nom = patient->getNom();
    this->prenom = patient->getPrenom();
    this->adresse = patient->getAdresse();
    this->ville = patient->getVille();
    this->codepostal = patient->getCodePostal();
    this->numTelephone = patient->getNumTelephone();
    this->email = patient->getEmail();
    this->dateConsultation = patient->getDateConsultation();
    this->medecin = patient->getMedecin();
    this->priorite = patient->getPriorite();
    this->dureeConsultation = patient->getDureeConsultation();
    this->commentaires = patient->getCommentaires();
}

Patient::Patient(string dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
                 string dateConsultation, string dureeConsultation, int priorite, string medecin, string commentaires){
    this->dateCreation = dateCreation;
    this->numId = 0.0;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this-> ville = ville;
    this->codepostal = codepostal;
    this-> numTelephone= numTelephone;
    this->email = email;
    this->dateConsultation = dateConsultation;
    this->dureeConsultation =  dureeConsultation;
    this-> priorite = priorite;
    this->medecin = medecin;
    this->commentaires = commentaires;
}

Patient::Patient(int numId, string dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
                 string dateConsultation, string dureeConsultation, int priorite, string medecin, string commentaires){
    this->dateCreation = dateCreation;
    this->numId = numId;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this-> ville = ville;
    this->codepostal = codepostal;
    this-> numTelephone= numTelephone;
    this->email = email;
    this->dateConsultation = dateConsultation;
    this->dureeConsultation =  dureeConsultation;
    this-> priorite = priorite;
    this->medecin = medecin;
    this->commentaires = commentaires;
}

Patient::Patient( string dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
                 string dateConsultation, string dureeConsultation, int priorite,  QList<int> listesMedecins, string commentaires){
    this->dateCreation = dateCreation;
    this->numId = numId;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this-> ville = ville;
    this->codepostal = codepostal;
    this-> numTelephone= numTelephone;
    this->email = email;
    this->dateConsultation = dateConsultation;
    this->dureeConsultation =  dureeConsultation;
    this-> priorite = priorite;
    this->listesMedecins = listesMedecins;
    this->commentaires = commentaires;
}

Patient::Patient(int numId, string dateCreation, string nom, string prenom, string adresse, string ville, string codepostal, string numTelephone, string email,
                 string dateConsultation, string dureeConsultation, int priorite,  QList<int> listesMedecins, string commentaires){
    this->dateCreation = dateCreation;
    this->numId = numId;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this-> ville = ville;
    this->codepostal = codepostal;
    this-> numTelephone= numTelephone;
    this->email = email;
    this->dateConsultation = dateConsultation;
    this->dureeConsultation =  dureeConsultation;
    this-> priorite = priorite;
    this->listesMedecins = listesMedecins;
    this->commentaires = commentaires;
}

Patient::~Patient(){

}

string Patient::getDateCreation(){
    return this->dateCreation;
}
void Patient::setDateCreation(string dateCreation){
    this->dateCreation = dateCreation;
}
int Patient::getNumId(){
    return this->numId;
}
void Patient::setNumId(int numId){
    this->numId = numId;
}
string Patient::getNom(){
    return this->nom;
}
void Patient::setNom(string nom){
    this->nom = nom;
}
string Patient::getPrenom(){
    return this->prenom;
}
void Patient::setPrenom(string prenom){
    this->prenom = prenom;
}
string Patient::getAdresse(){
    return this->adresse;
}
void Patient::setAdresse(string adresse){
    this->adresse = adresse;
}
string Patient::getVille(){
    return this->ville;
}
void Patient::setVille(string ville){
    this->ville = ville;
}
string Patient::getCodePostal(){
    return this->codepostal;
}
void Patient::setCodePostal(string codePostal){
    this->codepostal = codePostal;
}
string Patient::getNumTelephone(){
return this->numTelephone;

}
void Patient::setNumTelephone(string numTelephone){
    this->numTelephone = numTelephone;
}
string Patient::getEmail(){
    return this->email;
}
void Patient::setEmail(string email){
    this->email = email;
}
string Patient::getDateConsultation(){
    return this->dateConsultation;
}
void Patient::setDateConsultation(string dateConsultation){
    this->dateConsultation = dateConsultation;
}
string Patient::getDureeConsultation(){
    return this->dureeConsultation;
}
void Patient::setDureeConsultation(string dureeConsultation){
    this->dureeConsultation = dureeConsultation;
}
int Patient::getPriorite(){
    return this->priorite;
}
void Patient::setPriorite(int priorite){
    this->priorite = priorite;
}
string Patient::getMedecin(){
    return this->medecin;
}
void Patient::setMedecin(string medecin){
    this->medecin = medecin;
}
QList<int> Patient::getlistesMedecins(){
    return this->listesMedecins;
}
void Patient::setlistesMedecins( QList<int> listesMedecins){
    this->listesMedecins = listesMedecins;
}
string Patient::getCommentaires(){
    return this->commentaires;
}
void Patient::setCommentaires(string commentaires){
    this->commentaires = commentaires;
}
/*int Patient::getIdConsult(){
    return this->idConsult;
}
void Patient::setIdConsult(int idConsult){
    this->idConsult = idConsult;
}*/
