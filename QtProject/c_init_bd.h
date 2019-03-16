#ifndef C_INIT_BD_H
#define C_INIT_BD_H

#include <QSqlDatabase>

class c_init_bd
{

private:
     QSqlDatabase db;
public:
    c_init_bd();
    bool Creation_BD(void);
    bool Fermeture_BD(void);
    QSqlDatabase getDataBase();
};

#endif // C_INIT_BD_H
