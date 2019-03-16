#ifndef CONSULT_H
#define CONSULT_H


class Consult
{

private:
    int idConsult;
    int idPatient;
    int idRessource;
public:
    Consult();
    Consult(int idConsult ,int idPatient,int idRessource);
    void setIdConsult(int idConsult);
    int getIdConsult();
    void setIdPatient(int idPatient);
    int getIdPatient();
    void setIdRessource(int idRessource);
    int getIdRessource();
};

#endif // CONSULT_H
