#include "c_init_bd.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <iostream>

using namespace std;

c_init_bd::c_init_bd()
{
}

QSqlDatabase c_init_bd::getDataBase(){
    return this->db;
}

bool c_init_bd::Creation_BD()
{
    bool b_test;
    this->db = QSqlDatabase::addDatabase("QSQLITE");

    if(db.isValid())
    {
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");

        if(QFile::exists("base_tmp.sqli"))
            QFile::remove("base_tmp.sqli");

        db.setDatabaseName("base_tmp.sqli");
        db.open();

        QSqlQuery query(db);
        if(!db.isOpen())
        {
            qDebug() << db.lastError().text();
            qDebug() << "Erreur à louverture de la base !\n";
            return false;
        }

        b_test=query.exec("create table TCompte "
                          "(idCompte integer primary key, "
                          "idRessource integer, "
                          "login varchar(50), "
                          "mdp varchar(50))");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Table TCompte non crée !\n";
            return false;
        }

        b_test=query.exec("create table TConsult "
                          "(idConsult integer primary key, "
                          "idPatient integer, "
                          "idRessource integer)");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Table TConsult non crée !\n";
            return false;
        }

        b_test=query.exec("create table TPatient "
                          "(idPatient integer primary key, "
                          "DateCreation date, "
                          "nom varchar(50), "
                          "prenom varchar(50), "
                          "adresse varchar(50), "
                          "ville varchar(50), "
                          "cp integer, "
                          "tel integer, "
                          "email varchar(50), "
                          "dateConsultation date, "
                          "dureeConsultation int, "
                          "priorite integer, "
                          "commentaire varchar(50))");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Table TPatient non crée !\n";
            return false;
        }

        b_test=query.exec("create table TRessource "
                          "(idRessource integer primary key, "
                          "DateCreation date, "
                          "nom varchar(50), "
                          "prenom varchar(50), "
                          "adresse varchar(50), "
                          "ville varchar(50), "
                          "cp integer, "
                          "tel integer, "
                          "email varchar(50), "
                          "idType integer)");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Table TRessource non crée !\n";
            return false;
        }

        b_test=query.exec("create table TType "
                          "(idType integer primary key, "
                          "Label varchar(50))");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Table TType non crée !\n";
            return false;
        }

        b_test=query.exec("INSERT INTO TCompte (idCompte, idRessource, login, mdp) VALUES "
                          "(1, 1, 'admin', 'password')");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Insertion de données dans TCompte impossible !\n";
            return false;
        }

        b_test=query.exec("INSERT INTO TConsult "
                          "SELECT '1' AS 'idConsult', '1' AS 'idPatient', '11' AS 'idRessource'"
                                  "UNION SELECT 2, 2, 3 "
                                  "UNION SELECT 3, 3, 5 "
                                  "UNION SELECT 4, 4, 6 "
                                  "UNION SELECT 5, 5, 2 "
                                  "UNION SELECT 6, 6, 4 ");
                                  //"UNION SELECT 7, 7, 12 "
                                  //"UNION SELECT 8, 8, 8 "
                                  //"UNION SELECT 9, 9, 9 "
                                  //"UNION SELECT 10, 10, 8");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Insertion de données dans TConsult impossible !\n";
            return false;
        }


        b_test=query.exec("INSERT INTO TPatient "
                          "SELECT '1' AS 'idPatient','01/06/2013' AS 'dateCreation', 'Ricardo' AS 'nom', 'Jacques' AS 'prenom', '3 rue des justices' AS 'adresse', 'Tours' AS 'ville', '37200' AS 'cp', '247558963' AS 'tel', 'email1@gmail.com' AS 'email', '01/06/2013' AS 'dateConsultation', 90 AS 'dureeConsultation', '2' AS 'priorite', 'Dépressif' AS 'commentaire'"
                                  "UNION SELECT 2, '01/06/2013', 'Pirouette', 'Stéphanie', '15 rue des dames', 'Paris' ,37390,247542942, 'email2@gmail.com', '01/06/2013', 50, 2, 'Chanceaux'"
                                  "UNION SELECT 3, '01/06/2013', 'Puisser', 'Albert', '15 rue des chevaux','Paris', 37250,247642892,'email3@gmail.com', '01/06/2013', 45, 3, 'Verigné'"
                                  "UNION SELECT 4, '01/06/2013', 'Tujais', 'Téo', '15 rue de l''arbre', 'Monts', 37450, 247845889,'email4@gmail.com', '01/06/2013', 20, 4, ''"
                                  "UNION SELECT 5, '01/06/2013', 'Kistran', 'Flavien', '89 impasse des rangs', 'Mettray', 37620, 247895623,'email5@gmail.com', '01/06/2013', 80, 1, 'En forme.'"
                                  "UNION SELECT 6, '01/06/2013', 'Qing', 'Xue', '14 rue Jean Jaures', 'Tours', 37200, 247555588,'email6@gmail.com', '01/06/2013', 60, 3, 'Aucun.'");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Insertion de données dans TPatient impossible !\n";
            return false;
        }

        //Test Implémentation et résupération d'objets

       /* QString querys = "SELECT * FROM TPatient";
           QSqlQuery SqlQuery = QSqlQuery( db );
           SqlQuery.exec( querys );

           while (SqlQuery.next())
           {
               int field_idx   = SqlQuery.record().indexOf("idPatient");
               int field_idx2   = SqlQuery.record().indexOf("dateCreation");
               int field_idx3   = SqlQuery.record().indexOf("nom");
               int field_idx4   = SqlQuery.record().indexOf("prenom");
               int field_idx5   = SqlQuery.record().indexOf("adresse");
               int field_idx6   = SqlQuery.record().indexOf("ville");
               int field_idx7   = SqlQuery.record().indexOf("cp");
               int field_idx8   = SqlQuery.record().indexOf("tel");
               int field_idx9   = SqlQuery.record().indexOf("email");
               int field_idx10   = SqlQuery.record().indexOf("dateConsultation");
               int field_idx11   = SqlQuery.record().indexOf("dureeConsultation");
               int field_idx12   = SqlQuery.record().indexOf("priorite");
               int field_idx13   = SqlQuery.record().indexOf("commentaire");
               QString idPatient = SqlQuery.record().value(field_idx).toString();
               QString dateCreation = SqlQuery.record().value(field_idx2).toString();
               QString nom = SqlQuery.record().value(field_idx3).toString();
               QString prenom = SqlQuery.record().value(field_idx4).toString();
               QString adresse = SqlQuery.record().value(field_idx5).toString();
               QString ville = SqlQuery.record().value(field_idx6).toString();
               QString cp = SqlQuery.record().value(field_idx7).toString();
               QString tel = SqlQuery.record().value(field_idx8).toString();
               QString email = SqlQuery.record().value(field_idx9).toString();
               QString dateConsulation = SqlQuery.record().value(field_idx10).toString();
               QString dureeConsultation = SqlQuery.record().value(field_idx11).toString();
               QString priorite = SqlQuery.record().value(field_idx12).toString();
               QString commentaire = SqlQuery.record().value(field_idx13).toString();

               qDebug() << idPatient << ", " << dateCreation << ", " << nom << ", " << prenom << ", "<< adresse << ", " << ville << ", " << cp << ", "<< tel << ", " << email << ", " << dateConsulation << ", " << dureeConsultation << ", " << priorite << ", " << dateConsulation << ", " << commentaire ;
           };*/


        b_test=query.exec("INSERT INTO TRessource "
                          "SELECT '1' AS 'idRessource','01/06/2013' AS 'dateCreation', 'Admin' AS 'nom', 'Admin' AS 'prenom', '3 rue des justices' AS 'adresse', 'Tours' AS 'ville', '37200' AS 'cp', '247558963' AS 'tel', 'email1' AS 'email', '7' AS 'idType'"
                                  "UNION SELECT 2, '02/06/2013', 'Dubois', 'Jean', '3 rue des justices', 'Tours', '37200', '247558963', 'email2', 1 "
                                  "UNION SELECT 3, '03/06/2013', 'De La Roche', 'Julie', '3 rue des justices', 'Tours', '37200', '247558963', 'email3', 1 "
                                  "UNION SELECT 4, '04/06/2013', 'Ducroix', 'Lisa', '3 rue des justices', 'Tours', '37200', '247558963', 'email4', 2 "
                                  "UNION SELECT 5, '04/06/2013', 'Boulanger', 'Stéphane', '3 rue des justices', 'Tours', '37200', '247558963', 'email5', 3 "
                                  "UNION SELECT 6, '05/06/2013', 'Bijet', 'Paul', '3 rue des justices', 'Tours', '37200', '247558963', 'email6', 3 "
                                  "UNION SELECT 7, '05/06/2013', 'durant', 'Mélanie', '3 rue des justices', 'Tours', '37200', '247558963', 'email7', 4 "
                                  "UNION SELECT 8, '05/06/2013', 'Tortue', 'Adeline', '3 rue des justices', 'Tours', '37200', '247558963', 'email8', 4 "
                                  "UNION SELECT 9, '05/06/2013', 'guillet', 'Sonia', '3 rue des justices', 'Tours', '37200', '247558963', 'email9', 4 "
                                  "UNION SELECT 10, '05/06/2013', 'Boulot', 'Marie', '3 rue des justices', 'Tours', '37200', '247558963', 'email10', 4 "
                                  "UNION SELECT 11, '10/06/2013', 'Titan', 'Geoffrey', '3 rue des justices', 'Tours', '37200', '247558963', 'email11', 5 "
                                  "UNION SELECT 12, '11/06/2013', 'Dupont', 'Christophe', '3 rue des justices', 'Tours', '37200', '247558963', 'email12', 6");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Insertion de données dans TRessource impossible !\n";
            return false;
        }

        b_test=query.exec("INSERT INTO TType "
                          "SELECT '1' AS 'idType', 'Médecin A' AS 'label'"
                                  "UNION SELECT 2, 'Médecin B' "
                                  "UNION SELECT 3, 'Radiologue' "
                                  "UNION SELECT 4, 'Infirmière' "
                                  "UNION SELECT 5, 'Kinésithérapeute' "
                                  "UNION SELECT 6, 'Psychologue' "
                                  "UNION SELECT 7, 'Informaticien'");
        if(!b_test)
        {
            qDebug() << query.lastError().text();
            qDebug() << "Insertion de données dans TType impossible !\n";
            return false;
        }

        //Pour fermer la base de donnée
        /*db.close();
        db.removeDatabase("QSQLITE");*/

        return true;

    }
    else
    {
        qDebug() << db.lastError().text();
        qDebug() << "Erreur à création de la base !\n";
        return false;
    }
}

bool c_init_bd::Fermeture_BD()
{
    bool fermer = true;
    //Pour fermer la base de donnée
    db.close();
    db.removeDatabase("QSQLITE");
    return fermer;
}
