#ifndef COMPTE_H
#define COMPTE_H
#include<string>

using namespace std;

class Compte
{
private:
    int idCompte;
    string login;
    string mdp;
    int idRessource;
public:
    Compte();
    Compte(int idCompte, string login, string mdp, int idRessource);
    int getIdCompte();
    void setIdCompte(int idCompte);
    string getLogin();
    void setLogin(string login);
    string getMdp();
    void setMdp(string mdp);
    int getIdRessource();
    void setIdRessource(int idRessource);
};

#endif // COMPTE_H
