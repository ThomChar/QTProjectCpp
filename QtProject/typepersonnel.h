#ifndef TYPEPERSONNEL_H
#define TYPEPERSONNEL_H
#include <string>

using namespace std;

class typePersonnel
{

private:
    int idType;
    string label;

public:
    typePersonnel();
    typePersonnel(int idType, string label);
    int getIdType();
    void setIdType(int idType);
    string getLabel();
    void setLabel(string label);
};
#endif // TYPEPERSONNEL_H
