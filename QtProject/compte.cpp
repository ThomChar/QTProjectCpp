#include "compte.h"

Compte::Compte()
{

}

Compte::Compte(int idCompte, string login, string mdp, int idRessource){
    this->idCompte = idCompte;
    this->login = login;
    this->mdp = mdp;
    this->idRessource = idRessource;
}
int Compte::getIdCompte(){
    return this->idCompte;
}
void Compte::setIdCompte(int idCompte){
    this->idCompte = idCompte;
}
string Compte::getLogin(){
     return this->login;
}
void Compte::setLogin(string login){
    this->login = login;
}
string Compte::getMdp(){
     return this->mdp;
}
void Compte::setMdp(string mdp){
    this->mdp = mdp;
}
int Compte::getIdRessource(){
     return this->idRessource;
}
void Compte::setIdRessource(int idRessource){
    this->idRessource = idRessource;
}
