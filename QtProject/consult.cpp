#include "consult.h"

Consult::Consult()
{

}
Consult::Consult(int idConsult ,int idPatient,int idRessource){
    this->idConsult = idConsult;
    this->idPatient = idPatient;
    this->idRessource = idRessource;
}
void Consult::setIdConsult(int idConsult){
    this->idConsult = idConsult;
}
int Consult::getIdConsult(){
    return this->idConsult;
}
void Consult::setIdPatient(int idPatient){
    this->idConsult = idPatient;
}
int Consult::getIdPatient(){
    return this->idPatient;
}
void Consult::setIdRessource(int idRessource){
    this->idConsult = idRessource;
}
int Consult::getIdRessource(){
    return this->idRessource;
}
