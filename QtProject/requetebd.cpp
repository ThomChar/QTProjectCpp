#include "requetebd.h"
#include "patient.h"
#include "compte.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

RequeteBD::RequeteBD(QSqlDatabase db)
{
    this->db = db;
}

QSqlDatabase RequeteBD::getDB(){
    return this->db;
}

bool RequeteBD::verificationLogin(QSqlDatabase db, QString login, QString password){
    bool connexion = false;

    QString querys = "SELECT * FROM TCompte";
       QSqlQuery SqlQuery = QSqlQuery( db );
       SqlQuery.exec( querys );

       while (SqlQuery.next())
       {
           int field_idx3   = SqlQuery.record().indexOf("login");
           int field_idx4   = SqlQuery.record().indexOf("mdp");
           QString log = SqlQuery.record().value(field_idx3).toString();
           QString mdp = SqlQuery.record().value(field_idx4).toString();

           if(login == log && password == mdp){ // à relier avec la fonction pour controler l'identifiant user
              connexion = true;
           }
        }
    return connexion;
}

/**
 * Requete permettant d'ajouter un Patient à la base de donnée
 * @brief RequeteBD::addPatient
 * @param db
 * @param patient
 */
void RequeteBD::addPatient(QSqlDatabase db, Patient patient){
    //Ajout du Patient
    QSqlQuery SqlQuery = QSqlQuery( db );
    //Faire le choix d'ajouter ou non le nouveau patient
    SqlQuery.prepare( "INSERT INTO TPatient (idPatient ,dateCreation, nom, prenom, adresse, ville, cp, tel, email, dateConsultation, dureeConsultation, priorite, commentaire)"
                      "VALUES(:idPatient ,:dateCreation, :nom, :prenom, :adresse, :ville, :cp, :tel, :email, :dateConsultation, :dureeConsultation, :priorite, :commentaire)");
    SqlQuery.bindValue(":idPatient", patient.getNumId());
    SqlQuery.bindValue(":dateCreation", patient.getDateCreation().c_str());
    SqlQuery.bindValue(":nom", patient.getNom().c_str());
    SqlQuery.bindValue(":prenom", patient.getPrenom().c_str());
    SqlQuery.bindValue(":adresse", patient.getAdresse().c_str());
    SqlQuery.bindValue(":ville", patient.getVille().c_str());
    SqlQuery.bindValue(":cp", patient.getCodePostal().c_str());
    SqlQuery.bindValue(":tel", patient.getNumTelephone().c_str());
    SqlQuery.bindValue(":email", patient.getEmail().c_str());
    SqlQuery.bindValue(":dateConsultation", patient.getDateConsultation().c_str());
    SqlQuery.bindValue(":dureeConsultation", patient.getDureeConsultation().c_str());
    SqlQuery.bindValue(":priorite", patient.getPriorite());
    SqlQuery.bindValue(":commentaire", patient.getCommentaires().c_str());
    //SqlQuery.bindValue(":idConsult", patient.getIdConsult());

    SqlQuery.exec();

   // Obteir l'ID de la personne ayant effectuée la consultation
   QStringList nomPrenom = QString::fromStdString(patient.getMedecin()).split(" ");
   string nom = nomPrenom.value(0).toStdString();
   string prenom = nomPrenom.value(1).toStdString();
   int idRessource = getIdPersonnel(db, nom, prenom);
    //Déterminer idConsult
   //patient.setIdConsult(this->getListeConsults(db).last().getIdConsult()+1);

   //Ajoute une Consultation
   QSqlQuery SqlQuery3 = QSqlQuery( db );
   SqlQuery3.prepare( "INSERT INTO TConsult (idConsult,idPatient,idRessource)"
                     "VALUES(:idConsult ,:idPatient, :idRessource)");
   SqlQuery3.bindValue(":idConsult", this->getListeConsults(db).last().getIdConsult()+1);
   SqlQuery3.bindValue(":idPatient", patient.getNumId());
   SqlQuery3.bindValue(":idRessource", idRessource);
   SqlQuery3.exec();

}

int RequeteBD::getIdPersonnel(QSqlDatabase db, string nom, string prenom){
    /*QSqlQuery SqlQuery2 = QSqlQuery( db );
    SqlQuery2.prepare( "select idRessource from TRessource"
                      "where nom = :nom and prenom =:prenom");
    SqlQuery2.bindValue(":nom", nom.c_str());
    SqlQuery2.bindValue(":prenom", prenom.c_str());
    SqlQuery2.exec();
    int idPersonnel   = SqlQuery2.record().indexOf("idRessource");
    SqlQuery2.record().value(idPersonnel).toInt()*/
    QList<Personnel> listePersonnels = getListePersonnel(db);
    int idPersonnel = 0;
    for (int i = 0;i<listePersonnels.size();i++){
        if(listePersonnels[i].getNom() == nom and listePersonnels[i].getPrenom() == prenom){
            idPersonnel = listePersonnels[i].getNumId();
        }
    }
    return idPersonnel;
}

QString RequeteBD::getNomPrenomPersonnelConsult(QSqlDatabase db, int idPatient){
    QSqlQuery SqlQuery = QSqlQuery( db );
    /*SqlQuery.prepare( "select * from TPatient TP NATURAL JOIN TConsult TC"
                      "LEFT JOIN TRessource TR ON TC.idRessource = TR.idRessource ");
                      "WHERE idPatient=:idPatient ");*/

    QList<Consult> listeConsult = getListeConsults(db);
    int idRessource = 0;
    for (int i = 0;i<listeConsult.size();i++){
        if(listeConsult[i].getIdPatient() == idPatient){
            idRessource = listeConsult[i].getIdRessource();
        }
    }

    /*SqlQuery.prepare( "SELECT idRessource FROM TConsult\
                      WHERE idPatient = ? ");
    SqlQuery.bindValue(":idPatient", idPatient);
    SqlQuery.exec();
     int field   = SqlQuery.record().indexOf("idRessource");
     idRessource = SqlQuery.record().value(field).toInt();*/
     //qDebug()<< idRessource;
     /*QSqlQuery SqlQuery2 = QSqlQuery( db );
     SqlQuery2.prepare( "select nom, prenom from TRessource"
                       "where idRessource = :idRessource ");
     SqlQuery2.bindValue(":idRessource", idRessource);
     SqlQuery2.exec();*/

     QString nom;
     QString prenom;
     QList<Personnel> listePersonnel = getListePersonnel(db);
     for (int i = 0;i<listePersonnel.size();i++){
         if(listePersonnel[i].getNumId() == idRessource){
             nom = QString::fromStdString(listePersonnel[i].getNom());
             prenom = QString::fromStdString(listePersonnel[i].getPrenom());
         }
     }

    QString medecin = nom + " " + prenom;
    //qDebug() <<medecin;
    /*int field_idx_2   = SqlQuery2.record().indexOf("TR.nom");
    int field_idx_3   = SqlQuery2.record().indexOf("TR.prenom");
    QString nom = SqlQuery2.record().value(field_idx_2).toString();
    QString prenom = SqlQuery2.record().value(field_idx_3).toString();*/
    /*int field_idx   = SqlQuery.record().indexOf("TR.nom");
    int field_idx_2   = SqlQuery.record().indexOf("TR.prenom");
    QString nom = SqlQuery.record().value(field_idx).toString();
    QString prenom = SqlQuery.record().value(field_idx_2).toString();*/
    //qDebug() <<nom + prenom;
    return medecin;
}

/**
 * Requete permettant de supprimer un Patient à la base de donnée
 * @brief RequeteBD::supprimerPatient
 * @param db
 * @param numId
 */
void RequeteBD::removePatient(QSqlDatabase db, int numId){
    //Supprimer les consultations liées au Patient
    QSqlQuery SqlQuery = QSqlQuery( db );
    SqlQuery.prepare("DELETE FROM TConsult WHERE idPatient = :idPatient");
    SqlQuery.bindValue(":idPatient", numId);
    SqlQuery.exec();
    //Supprimer le Patient
    QSqlQuery SqlQuery2 = QSqlQuery( db );
    SqlQuery2.prepare("DELETE FROM TPatient WHERE idPatient = :idPatient");
    SqlQuery2.bindValue(":idPatient", numId);
    SqlQuery2.exec();
}

/**
 * Requete permettant de modifier un Patient à la base de donnée
 * @brief RequeteBD::modifierPatient
 * @param db
 * @param patient
 */
void RequeteBD::modifierPatient(QSqlDatabase db, Patient patient /*,int pastIdPersonnel*/){
    QSqlQuery SqlQuery = QSqlQuery( db );
    SqlQuery.prepare( "UPDATE TPatient SET dateCreation = :dateCreation, nom = :nom, prenom = :prenom, adresse = :adresse, ville = :ville,"
                      "cp = :cp, tel = :tel, email = :email, dateConsultation = :dateConsultation, dureeConsultation = :dureeConsultation,"
                      "priorite = :priorite, commentaire = :commentaire WHERE idPatient = :idPatient");
    SqlQuery.bindValue(":dateCreation", patient.getDateCreation().c_str());
    SqlQuery.bindValue(":nom", patient.getNom().c_str());
    SqlQuery.bindValue(":prenom", patient.getPrenom().c_str());
    SqlQuery.bindValue(":adresse", patient.getAdresse().c_str());
    SqlQuery.bindValue(":ville", patient.getVille().c_str());
    SqlQuery.bindValue(":cp", patient.getCodePostal().c_str());
    SqlQuery.bindValue(":tel", patient.getNumTelephone().c_str());
    SqlQuery.bindValue(":email", patient.getEmail().c_str());
    SqlQuery.bindValue(":dateConsultation", patient.getDateConsultation().c_str());
    SqlQuery.bindValue(":dureeConsultation", patient.getDureeConsultation().c_str());
    SqlQuery.bindValue(":priorite", patient.getPriorite());
    SqlQuery.bindValue(":commentaire", patient.getCommentaires().c_str());
    SqlQuery.bindValue(":idPatient", patient.getNumId());
    SqlQuery.exec();

    //Modification du medecin ayant effectué la consultation si nécessaire
    QStringList nomPrenom = QString::fromStdString(patient.getMedecin()).split(" ");
    string nom = nomPrenom.value(0).toStdString();
    string prenom = nomPrenom.value(1).toStdString();
    int idRessource = getIdPersonnel(db, nom, prenom);
    //qDebug()<<patient.getPriorite();
    //qDebug()<<pastIdPersonnel;
    //qDebug()<<idRessource;
    QSqlQuery SqlQuery3 = QSqlQuery( db );
    SqlQuery3.prepare( "UPDATE TConsult SET idRessource = :idRessource WHERE idPatient = :idPatient ");
     SqlQuery3.bindValue(":idRessource", idRessource);
     //SqlQuery3.bindValue(":pastIdRessource", pastIdPersonnel);
     SqlQuery3.bindValue(":idPatient", patient.getNumId());
     SqlQuery3.exec();

     qDebug()<<getNomPrenomPersonnelConsult(db, patient.getNumId());

}

QString RequeteBD::getNomPatient(QSqlDatabase db, int numId){
    QSqlQuery SqlQuery = QSqlQuery( db );
    SqlQuery.prepare("SELECT nom FROM TPatient WHERE idPatient = :idPatient");
    SqlQuery.bindValue(":idPatient", numId);
    SqlQuery.exec();
    int field_idx   = SqlQuery.record().indexOf("nom");
    QString nom = SqlQuery.record().value(field_idx).toString();
    //qDebug() << nom;
    return SqlQuery.record().value(field_idx).toString();
}
/**
 * Requete permettant d'obtenir un Patient de la base de donnée
 * @brief RequeteBD::getPatient
 * @param db
 * @param numId
 */
Patient RequeteBD::getPatient(QSqlDatabase db, int numId){
   /* QSqlQuery SqlQuery = QSqlQuery( db );
    SqlQuery.prepare("SELECT * FROM TPatient WHERE idPatient = :idPatient");
    SqlQuery.bindValue(":idPatient", numId);
    SqlQuery.exec();
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

    int idPatient = numId;
    QString dateCreation = SqlQuery.record().value(field_idx2).toString();
    QString nom = SqlQuery.record().value(field_idx3).toString();
    QString prenom = SqlQuery.record().value(field_idx4).toString();
    QString adresse = SqlQuery.record().value(field_idx5).toString();
    QString ville = SqlQuery.record().value(field_idx6).toString();
    QString cp = SqlQuery.record().value(field_idx7).toString();
    QString tel = SqlQuery.record().value(field_idx8).toString();
    QString email = SqlQuery.record().value(field_idx9).toString();
    QString dateConsultation = SqlQuery.record().value(field_idx10).toString();
    QString dureeConsultation = SqlQuery.record().value(field_idx11).toString();
    int priorite = SqlQuery.record().value(field_idx12).toInt();
    QString commentaire = SqlQuery.record().value(field_idx13).toString();*/

    QList<Patient> listePatients = this->getListePatients(db);
    int indicePatient = 0;
    for (int i = 0;i<listePatients.size();i++){
        if(listePatients[i].getNumId()== numId){
            indicePatient = i;
        }
    }
    //qDebug() << QString::number(listePatients[indicePatient].getNumId())<< ", " << QString::fromStdString(listePatients[indicePatient].getNom()) ;

    //Patient patient(idPatient ,dateCreation.toStdString(), nom.toStdString(), prenom.toStdString(), adresse.toStdString(), ville.toStdString(), cp.toStdString(), tel.toStdString(), email.toStdString(), dateConsultation.toStdString(), dureeConsultation.toStdString(), priorite,"Tom Hille", commentaire.toStdString());
    //qDebug() << idPatient << ", " << dateCreation << ", " << nom << ", " << prenom << ", "<< adresse << ", " << ville << ", " << cp << ", "<< tel << ", " << email << ", " << dateConsultation << ", " << dureeConsultation << ", " << priorite << ", " << dateConsultation << ", " << commentaire ;
    return listePatients[indicePatient];
}

/**
 * Requete permettant d'obtenir la liste des Patients de la base de donnée
 * @brief RequeteBD::getListePatients
 * @param db
 */
QList<Patient> RequeteBD::getListePatients(QSqlDatabase db){

    QString querys = "SELECT * FROM TPatient";
    QList<Patient> listePatients;
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
           int idPatient = SqlQuery.record().value(field_idx).toInt();
           QString dateCreation = SqlQuery.record().value(field_idx2).toString();
           QString nom = SqlQuery.record().value(field_idx3).toString();
           QString prenom = SqlQuery.record().value(field_idx4).toString();
           QString adresse = SqlQuery.record().value(field_idx5).toString();
           QString ville = SqlQuery.record().value(field_idx6).toString();
           QString cp = SqlQuery.record().value(field_idx7).toString();
           QString tel = SqlQuery.record().value(field_idx8).toString();
           QString email = SqlQuery.record().value(field_idx9).toString();
           QString dateConsultation = SqlQuery.record().value(field_idx10).toString();
           QString dureeConsultation = SqlQuery.record().value(field_idx11).toString();
           int priorite = SqlQuery.record().value(field_idx12).toInt();
           QString commentaire = SqlQuery.record().value(field_idx13).toString();

           QString medecin = getNomPrenomPersonnelConsult(db,idPatient);
           Patient patient(idPatient ,dateCreation.toStdString(), nom.toStdString(), prenom.toStdString(), adresse.toStdString(), ville.toStdString(), cp.toStdString(), tel.toStdString(), email.toStdString(), dateConsultation.toStdString(), dureeConsultation.toStdString(), priorite,medecin.toStdString(), commentaire.toStdString());
           //Patient patient(idPatient ,dateCreation.toStdString(), nom.toStdString(), prenom.toStdString(), adresse.toStdString(), ville.toStdString(), cp.toStdString(), tel.toStdString(), email.toStdString(), dateConsultation.toStdString(), dureeConsultation.toStdString(), priorite,medecin.toStdString(), commentaire.toStdString());
           //qDebug() << idPatient << ", " << dateCreation << ", " << nom << ", " << prenom << ", "<< adresse << ", " << ville << ", " << cp << ", "<< tel << ", " << email << ", " << dateConsultation << ", " << dureeConsultation << ", " << priorite << ", " << dateConsultation << ", " << commentaire ;
           listePatients.push_back(patient);
       };

       return listePatients;
}

QList<Consult> RequeteBD::getListeConsults(QSqlDatabase db){

    QString querys = "SELECT * FROM TConsult";
    QList<Consult> listeConsults;
       QSqlQuery SqlQuery = QSqlQuery( db );
       SqlQuery.exec( querys );

       while (SqlQuery.next())
       {
           int field_idx   = SqlQuery.record().indexOf("idConsult");
           int field_idx2   = SqlQuery.record().indexOf("idPatient");
           int field_idx3   = SqlQuery.record().indexOf("idRessource");
           int idConsult = SqlQuery.record().value(field_idx).toInt();
           int idPatient = SqlQuery.record().value(field_idx2).toInt();
           int idRessource = SqlQuery.record().value(field_idx3).toInt();

           Consult consult(idConsult ,idPatient, idRessource);
           //qDebug() << idPatient << ", " << dateCreation << ", " << nom << ", " << prenom << ", "<< adresse << ", " << ville << ", " << cp << ", "<< tel << ", " << email << ", " << dateConsultation << ", " << dureeConsultation << ", " << priorite << ", " << dateConsultation << ", " << commentaire ;
           listeConsults.push_back(consult);
       };

       return listeConsults;
}

QList<Compte> RequeteBD::getListeComptes(QSqlDatabase db){

    QString querys = "SELECT * FROM TCompte";
    QList<Compte> listeComptes;
       QSqlQuery SqlQuery = QSqlQuery( db );
       SqlQuery.exec( querys );

       while (SqlQuery.next())
       {
           int field_idx   = SqlQuery.record().indexOf("idCompte");
           int field_idx2   = SqlQuery.record().indexOf("login");
           int field_idx3   = SqlQuery.record().indexOf("mdp");
           int field_idx4   = SqlQuery.record().indexOf("idRessource");
           int idCompte = SqlQuery.record().value(field_idx).toInt();
           QString login = SqlQuery.record().value(field_idx2).toString();
           QString mdp = SqlQuery.record().value(field_idx3).toString();
           int idRessource = SqlQuery.record().value(field_idx4).toInt();

           Compte compte(idCompte ,login.toStdString(), mdp.toStdString(), idRessource);
           //qDebug() << idPatient << ", " << dateCreation << ", " << nom << ", " << prenom << ", "<< adresse << ", " << ville << ", " << cp << ", "<< tel << ", " << email << ", " << dateConsultation << ", " << dureeConsultation << ", " << priorite << ", " << dateConsultation << ", " << commentaire ;
           listeComptes.push_back(compte);
       };

       return listeComptes;
}

/**
 * Requete permettant d'ajouter un Personnel à la base de donnée
 * @brief RequeteBD::addPersonnel
 * @param db
 * @param personnel
 */
void RequeteBD::addPersonnel(QSqlDatabase db, Personnel personnel, int idType, int idCompte){
    QSqlQuery SqlQuery = QSqlQuery( db );
    SqlQuery.prepare( "INSERT INTO TPatient (idRessource ,dateCreation, nom, prenom, adresse, ville, cp, tel, email, dateConsultation, dureeConsultation, priorite, commentaire)"
                      "VALUES(:idRessource ,:dateCreation, :nom, :prenom, :adresse, :ville, :cp, :tel, :email, :idType)");
    SqlQuery.bindValue(":idRessource", personnel.getNumId());
    SqlQuery.bindValue(":dateCreation", personnel.getDateCreation().c_str());
    SqlQuery.bindValue(":nom", personnel.getNom().c_str());
    SqlQuery.bindValue(":prenom", personnel.getPrenom().c_str());
    SqlQuery.bindValue(":adresse", personnel.getAdresse().c_str());
    SqlQuery.bindValue(":ville", personnel.getVille().c_str());
    SqlQuery.bindValue(":cp", personnel.getCodePostal().c_str());
    SqlQuery.bindValue(":tel", personnel.getNumTelephone().c_str());
    SqlQuery.bindValue(":email", personnel.getEmail().c_str());
    SqlQuery.bindValue(":idType", idType);

    SqlQuery.exec();

    if(idCompte!=0){
        QSqlQuery SqlQuery2 = QSqlQuery( db );
        SqlQuery.prepare( "INSERT INTO TCompte (idCompte ,idRessource, login, mdp)"
                          "VALUES(:idCompte ,:idRessource, :login, :mdp)");
        SqlQuery.bindValue(":idCompte", idCompte);
        SqlQuery.bindValue(":idRessource", personnel.getNumId());
        SqlQuery.bindValue(":login", personnel.getLogin().c_str());
        SqlQuery.bindValue(":mdp", personnel.getPassword().c_str());
        SqlQuery2.exec();
    }

}
/**
 * Requete permettant de supprimer un Personnel de la base de donnée
 * @brief RequeteBD::supprimerPersonnel
 * @param db
 * @param numId
 */
void RequeteBD::removePersonnel(QSqlDatabase db, int idRessource, int idCompte){

    QSqlQuery SqlQuery = QSqlQuery( db );
    QSqlQuery SqlQuery2 = QSqlQuery( db );

    SqlQuery.prepare("DELETE FROM 'TPersonnel' WHERE 'idPersonnel' = :idPersonnel");
    SqlQuery.bindValue(":idPersonnel", idRessource);
    SqlQuery.exec();

    SqlQuery2.prepare("DELETE FROM 'TCompte' WHERE 'idCompte' = :idCompte");
    SqlQuery2.bindValue(":idCompte", idCompte);
    SqlQuery2.exec();
}
/**
 * Requete permettant de supprimer un Personnel de la base de donnée
 * @brief RequeteBD::modifierPersonnel
 * @param db
 * @param numId
 */
void RequeteBD::modifierPersonnel(QSqlDatabase db, Personnel personnel, int idType, int idCompte){
    QSqlQuery SqlQuery = QSqlQuery( db );
    SqlQuery.prepare( "UPDATE TPatient"
                      "SET (dateCreation = ':dateCreation', nom = ':nom', prenom = ':prenom', adresse = ':adresse', ville = ':ville',"
                      "cp = ':cp', tel = ':tel', email = ':email', idType = ':idType')"
                      "WHERE 'idPersonnel' = :idPersonnel");
    SqlQuery.bindValue(":idPersonnel", personnel.getNumId());
    SqlQuery.bindValue(":dateCreation", personnel.getDateCreation().c_str());
    SqlQuery.bindValue(":nom", personnel.getNom().c_str());
    SqlQuery.bindValue(":prenom", personnel.getPrenom().c_str());
    SqlQuery.bindValue(":adresse", personnel.getAdresse().c_str());
    SqlQuery.bindValue(":ville", personnel.getVille().c_str());
    SqlQuery.bindValue(":cp", personnel.getCodePostal().c_str());
    SqlQuery.bindValue(":tel", personnel.getNumTelephone().c_str());
    SqlQuery.bindValue(":email", personnel.getEmail().c_str());
    SqlQuery.bindValue(":idType", idType);

    if(idCompte!=0){
    QSqlQuery SqlQuery2 = QSqlQuery( db );
    SqlQuery2.prepare( "UPDATE TCompte"
                      "SET (login = ':login', mdp = ':mdp')"
                      "WHERE 'idCompte' = :idCompte");

    SqlQuery2.bindValue(":idCompte", idCompte);
    SqlQuery2.bindValue(":login", personnel.getLogin().c_str());
    SqlQuery2.bindValue(":mdp", personnel.getPassword().c_str());
    SqlQuery2.exec();
    }
    SqlQuery.exec();
}
/**
 * Requete permettant d'obtenir un Personnel de la base de donnée
 * @brief RequeteBD::getPersonnel
 * @param db
 * @param numId
 */
Personnel RequeteBD::getPersonnel(QSqlDatabase db, int numId){
    QSqlQuery SqlQuery = QSqlQuery( db );
    SqlQuery.prepare("SELECT * FROM TRessource TR"
                     "NATURAL JOIN Ttype TT"
                     "LEFT JOIN Tcompte TC ON TC.idRessource = TR.idRessource"
                     "where TR.idRessource = :idPersonnel");
    SqlQuery.bindValue(":idPersonnel", numId);
    SqlQuery.exec();
    int field_idx   = SqlQuery.record().indexOf("idRessource");
    int field_idx2   = SqlQuery.record().indexOf("dateCreation");
    int field_idx3   = SqlQuery.record().indexOf("nom");
    int field_idx4   = SqlQuery.record().indexOf("prenom");
    int field_idx5   = SqlQuery.record().indexOf("adresse");
    int field_idx6   = SqlQuery.record().indexOf("ville");
    int field_idx7   = SqlQuery.record().indexOf("cp");
    int field_idx8   = SqlQuery.record().indexOf("tel");
    int field_idx9   = SqlQuery.record().indexOf("email");
    int field_idx10   = SqlQuery.record().indexOf("label");
    int field_idx11   = SqlQuery.record().indexOf("login");
    int field_idx12   = SqlQuery.record().indexOf("mdp");

    int idPersonnel = SqlQuery.record().value(field_idx).toInt();
    QString dateCreation = SqlQuery.record().value(field_idx2).toString();
    QString nom = SqlQuery.record().value(field_idx3).toString();
    QString prenom = SqlQuery.record().value(field_idx4).toString();
    QString adresse = SqlQuery.record().value(field_idx5).toString();
    QString ville = SqlQuery.record().value(field_idx6).toString();
    QString cp = SqlQuery.record().value(field_idx7).toString();
    QString tel = SqlQuery.record().value(field_idx8).toString();
    QString email = SqlQuery.record().value(field_idx9).toString();
    QString typeMedecin = SqlQuery.record().value(field_idx10).toString();
    QString login = SqlQuery.record().value(field_idx11).toString();
    QString mdp = SqlQuery.record().value(field_idx12).toString();
    Personnel personnel(idPersonnel,dateCreation.toStdString(), nom.toStdString(), prenom.toStdString(), adresse.toStdString(), ville.toStdString(), cp.toStdString(), tel.toStdString(), email.toStdString(),typeMedecin.toStdString(),login.toStdString(),mdp.toStdString());
    return personnel;
}

int RequeteBD::getIdCompte(QSqlDatabase db, int idRessource){
    QSqlQuery SqlQuery = QSqlQuery( db );
    SqlQuery.prepare("SELECT * FROM TCompte TC where TC.idRessource = :idRessource");
    SqlQuery.bindValue(":idRessource", idRessource);
    SqlQuery.exec();
    int field_idx   = SqlQuery.record().indexOf("idCompte");
    int idCompte= SqlQuery.record().value(field_idx).toInt();
    return idCompte;
}

int getIdType(QSqlDatabase db, QString typeMedecin){
    QSqlQuery SqlQuery = QSqlQuery( db );
    SqlQuery.prepare("SELECT * FROM TType TT where TT.typeMedecin = :typeMedecin");
    SqlQuery.bindValue(":typeMedecin", typeMedecin);
    SqlQuery.exec();
    int field_idx   = SqlQuery.record().indexOf("idType");
    int idType= SqlQuery.record().value(field_idx).toInt();
    return idType;
}

/**
 * Requete permettant d'afficher tout le Personnel de la base de donnée
 * @brief RequeteBD::getListePersonnel
 * @param db
 */
QList<Personnel> RequeteBD::getListePersonnel(QSqlDatabase db){
    QString querys = "SELECT * FROM TRessource TR NATURAL JOIN TType TT LEFT JOIN TCompte TC ON TC.idRessource = TR.idRessource";
    QList<Personnel> listePersonnels;
       QSqlQuery SqlQuery = QSqlQuery( db );
       SqlQuery.exec( querys );

       while (SqlQuery.next())
       {
           int field_idx   = SqlQuery.record().indexOf("idRessource");
           int field_idx2   = SqlQuery.record().indexOf("dateCreation");
           int field_idx3   = SqlQuery.record().indexOf("nom");
           int field_idx4   = SqlQuery.record().indexOf("prenom");
           int field_idx5   = SqlQuery.record().indexOf("adresse");
           int field_idx6   = SqlQuery.record().indexOf("ville");
           int field_idx7   = SqlQuery.record().indexOf("cp");
           int field_idx8   = SqlQuery.record().indexOf("tel");
           int field_idx9   = SqlQuery.record().indexOf("email");
           int field_idx10   = SqlQuery.record().indexOf("label");
           int field_idx11   = SqlQuery.record().indexOf("login");
           int field_idx12   = SqlQuery.record().indexOf("mdp");

           int idPersonnel = SqlQuery.record().value(field_idx).toInt();
           QString dateCreation = SqlQuery.record().value(field_idx2).toString();
           QString nom = SqlQuery.record().value(field_idx3).toString();
           QString prenom = SqlQuery.record().value(field_idx4).toString();
           QString adresse = SqlQuery.record().value(field_idx5).toString();
           QString ville = SqlQuery.record().value(field_idx6).toString();
           QString cp = SqlQuery.record().value(field_idx7).toString();
           QString tel = SqlQuery.record().value(field_idx8).toString();
           QString email = SqlQuery.record().value(field_idx9).toString();
           QString typeMedecin = SqlQuery.record().value(field_idx10).toString();
           QString login = SqlQuery.record().value(field_idx11).toString();
           QString mdp = SqlQuery.record().value(field_idx12).toString();

           Personnel personnel(idPersonnel,dateCreation.toStdString(), nom.toStdString(), prenom.toStdString(), adresse.toStdString(), ville.toStdString(), cp.toStdString(), tel.toStdString(), email.toStdString(),typeMedecin.toStdString(),login.toStdString(),mdp.toStdString());
           //qDebug() << idPersonnel << ", " << dateCreation << ", " << nom << ", " << prenom << ", "<< adresse << ", " << ville << ", " << cp << ", "<< tel << ", " << email << ", " << typeMedecin << ", " << login << ", " << mdp ;
           listePersonnels.push_back(personnel);
       };

    return listePersonnels;
}

