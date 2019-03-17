#include "typepersonnel.h"

typePersonnel::typePersonnel()
{

}

typePersonnel::typePersonnel(int idType, string label){
    this->idType = idType;
    this->label = label;
}

int typePersonnel::getIdType(){
    return this->idType;
}
void typePersonnel::setIdType(int idType){
    this->idType = idType;
}
string typePersonnel::getLabel(){
    return this->label;
}
void typePersonnel::setLabel(string label){
    this->label = label;
}
