#include "verifierformat.h"
#include <QString>
#include <QList>
#include <QRegExp>
#include <QMessageBox>

verifierFormat::verifierFormat()
{

}


/** Methode permettant de controler le format d'une date (verification simple pour commencer, on pourrait faire attention -> jours/mois)
 * @brief ajoutPatient::verifierDate
 * @param date
 * @return
 */
bool verifierFormat::verifierDate(QString date){
    bool valide = true;
    QRegExp rx("[0-3][0-9]/[0-1][0-9]/[0-9]{4}"); // règle de base

    // règles pour mois de février
    QRegExp rx1("[0-2][0-9]/[0-0][2-2]/[0-9]{4}"); // règle pour mois de février

    // règles pour mois 10,11,12
    QRegExp rx2_1("[0-3][0-1]/[1-1][0-2]/[0-9]{4}"); // règle pour jour 30 et 31 des mois 10,11,12
    QRegExp rx2_2("[0-2][0-9]/[1-1][0-2]/[0-9]{4}"); // règle pour les autres jours des mois 10,11,12

    // règles pour mois 3 à 9
    QRegExp rx3_1("[0-3][0-1]/[0-0][3-9]/[0-9]{4}"); // règle pour jour 30 et 31 des mois 3 à 9
    QRegExp rx3_2("[0-2][0-9]/[0-0][3-9]/[0-9]{4}"); // règle pour les autres jours des mois 3 à 9

    // règles pour mois de janvier
    QRegExp rx4_1("[0-3][0-1]/[0-0][1-1]/[0-9]{4}"); // règle pour jour 30 et 31 de janvier
    QRegExp rx4_2("[0-2][0-9]/[0-0][1-1]/[0-9]{4}"); // règle pour les autres jours de janvier

    //Verifications
        if(!rx1.exactMatch(date)){
            if(!rx2_1.exactMatch(date)){
                if(!rx2_2.exactMatch(date)){
                    if(!rx3_1.exactMatch(date)){
                        if(!rx3_2.exactMatch(date)){
                            if(!rx4_1.exactMatch(date)){
                                if(!rx4_2.exactMatch(date)){
                                     valide = false;
                                }
                            }
                        }
                     }
                }
            }
        }
    return valide;
}
bool verifierFormat::verifierNomPropre(QString nomPropre){
    bool valide = true;
    QRegExp rx("[À-ŸA-Z]{1}[à-ÿa-z]{0,39}");
    if(!rx.exactMatch(nomPropre)){
        valide = false;
    }
    return valide;
}
bool verifierFormat::verifierAdresse(QString adresse){
    bool valide = true;
    if(adresse == ""){
        valide = false;
    }
    return valide;
}
bool verifierFormat::verifierCodePostale(QString cdepostal){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(cdepostal)|| cdepostal == ""){
        valide = false;
    }
    return valide;
}
bool verifierFormat::verifierDureeConsult(QString dureeConsult){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(dureeConsult) || dureeConsult == ""){
        valide = false;
    }
    return valide;
}
bool verifierFormat::verifierNumPrio(QString numPrio){
    bool valide = true;
    QRegExp rx("[1-5]");
    if(!rx.exactMatch(numPrio) || numPrio == ""){
        valide = false;
    }
    return valide;
}
bool verifierFormat::verifierNumTel(QString numTel){
    bool valide = true;
    QRegExp rx("[0-9]*");
    if(!rx.exactMatch(numTel)){
        valide = false;
    }
    return valide;
}
bool verifierFormat::verifierEmail(QString email){
    bool valide = true;
    QRegExp rx("[a-z]*.[a-z]*@[a-z]*.fr");
    QRegExp rx1("[a-z]*@[a-z]*.fr");
    QRegExp rx2("[a-z]*@[a-z]*.com");
    QRegExp rx3("[a-z]*.[a-z]*@[a-z]*.com");
    if(!rx.exactMatch(email) && email != ""){
        if(!rx1.exactMatch(email)){
            if(!rx2.exactMatch(email)){
                if(!rx3.exactMatch(email)){
                    valide = false;
                }
            }
        }
    }
    return valide;
}
bool verifierFormat::verifierMedecin(QString medecin){
    bool valide = true;
    QRegExp rx("ex: Anne Marie");
    if(rx.exactMatch(medecin)){
        valide = false;
    }
    return valide;
}

 bool verifierFormat::verifierlisteMedecins(QList<Personnel>listePersonnel){
    bool valide = true;
    if(listePersonnel.isEmpty()){
        valide = false;
    }
    return valide;
}

 bool verifierFormat::verifierAdressePersonnel(QString adresse){
     bool valide = true;
     if(adresse == ""){}
       /*  valide = false;
     }*/ //adresse facultative dans ce formulaire
     return valide;
 }
 bool verifierFormat::verifierVille(QString ville){
     bool valide = true;
     QRegExp rx("[À-ŸA-Z]{1}[à-ÿa-z]{0,39}");
     if(!rx.exactMatch(ville) && ville !=""){
         valide = false;
     }
     return valide;
 }
 bool verifierFormat::verifierCodePostalePersonnel(QString cdepostal){
     bool valide = true;
     QRegExp rx("[0-9]*");
     if(!rx.exactMatch(cdepostal) && cdepostal !=""){
         valide = false;
     }
     return valide;
 }
 bool verifierFormat::verifierTypeMedecin(QString typeMedecin){
     bool valide = true;
     QRegExp rx("ex: médecin A");
     if(rx.exactMatch(typeMedecin)){
         valide = false;
     }
     return valide;
 }
 bool verifierFormat::verifierLogin(QString login, QString type){
     bool valide = true;
     if(type != "Informaticien" && login != ""){
         valide = false;
     }else if(type == "Informaticien" && login == ""){
         valide = false;
     }
     return valide;
 }
 bool verifierFormat::verifierPassword(QString password, QString type){
     bool valide = true;
     if(type != "Informaticien" && password != ""){
         valide = false;
     }else if(type == "Informaticien" && password == ""){
         valide = false;
     }
     return valide;
 }
 bool verifierFormat::verifierNumTelPersonnel(QString numTel){
     bool valide = true;
     QRegExp rx("[0-9]*");
     if(!rx.exactMatch(numTel) && numTel !=""){
         valide = false;
     }
     return valide;
 }

 /** Methode permettant de controler si une date est après une autre
  * @brief ajoutPersonnel::verifierDate
  * @param date
  * @return
  */
 bool verifierFormat::verifierDates(QString dateBefore, QString dateAfter){
     bool valide = true;
     QStringList date1 = dateBefore.split("/");
     QStringList date2 = dateAfter.split("/");

     int date1_jour = date1[0].toInt();
     int date1_mois = date1[1].toInt();
     int date1_annee = date1[2].toInt();

     int date2_jour = date2[0].toInt();
     int date2_mois = date2[1].toInt();
     int date2_annee = date2[2].toInt();

     if(date2_annee < date1_annee)
         valide = false;
     else if(date2_annee == date1_annee)
     {
         if(date2_mois < date1_mois)
             valide = false;
         else if(date2_mois == date1_mois)
         {
             if(date2_jour < date1_jour)
                 valide = false;
         }
     }

     return valide;
 }

 bool verifierFormat::verifierNomPropreMainWindow(QString nomPropre){
     bool valide = true;
     QRegExp rx("[À-ŸA-Zà-ÿa-z]*");
     if(!rx.exactMatch(nomPropre)){
         valide = false;
     }
     return valide;
 }

 bool verifierFormat::verifierNumID(QString numId){
     bool valide = true;
     QRegExp rx("[0-9]*");
     if(!rx.exactMatch(numId)){
         valide = false;
     }
     return valide;
 }

 bool verifierFormat::verificationsAjoutPatient(QString dateCreation, QString nom, QString prenom, QString adresse, QString ville, QString cdepostal,
                                                QString dateConsult, QString dureeConsult, QString numPrio, QString tel, QString email, QList <Personnel> listePersonnelsTraitant){

     bool verifier = true;

     //Verifications
     if (!verifierFormat().verifierDate(dateCreation)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Date de création incorrect<br>"
                        "(JJ/MM/AAAA)</p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNomPropre(nom)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Nom du Patient incorrect<br>"
                        "(1 Majuscule + minuscules)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNomPropre(prenom)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Prénom du Patient incorrect<br>"
                        "(1 Majuscule + minuscules)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierAdresse(adresse)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Champ Adresse ne peut pas être vide<br>"
                        "(veuillez saisir une adresse)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNomPropre(ville)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Ville incorrect<br>"
                        "(1 Majuscule + minuscules)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierCodePostale(cdepostal)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Code Postale incorrect<br>"
                        "(uniquement des chiffres)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierDate(dateConsult)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Date de RDV incorrect<br>"
                        "(JJ/MM/AAAA)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierDureeConsult(dureeConsult)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Durée de Consultation incorrect<br>"
                        "01:00 (en minutes)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNumPrio(numPrio)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Num. Prioritaire incorrect<br>"
                        "de 1 à 5 (5 le plus prioritaire)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNumTel(tel)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Num. de Téléphone incorrect<br>"
                        "(uniquement des chiffres)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierEmail(email)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Email incorrect<br>"
                        "(prenom.nom@email.fr ou prenom.nom@email.com)<br></p>");
         msgBox.exec();
         verifier= false;
     }/*else if (!verifierFormat().verifierMedecin(ui->comboBox->currentText())){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Champ médecin ne peut être vide"
                        "(veuillez saisir un autre médecin que l'exemple)<br></p>");
         msgBox.exec();
         verifier= false;
     }*/else if (!verifierFormat().verifierlisteMedecins(listePersonnelsTraitant)){
             QMessageBox msgBox;
             msgBox.setWindowTitle("Warning");
             msgBox.setText("<p align='center'>Attention ! <br>"
                            "Champ médecin ne peut être vide"
                            "(veuillez chosir au moins un médecin dans l'arbre)<br></p>");
             msgBox.exec();
             verifier= false;
         }
     return verifier;
 }

 bool verifierFormat::verificationsAjoutPersonnel(QString dateCreation, QString nom, QString prenom, QString adresse, QString ville, QString cdepostal,
                                                  QString typeMedecin, QString login, QString password, QString tel, QString email){
     bool verifier = true;
     if (!verifierFormat().verifierDate(dateCreation)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Date de création incorrect<br>"
                        "(JJ/MM/AAAA)</p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNomPropre(nom)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Nom du Patient incorrect<br>"
                        "(1 Majuscule + minuscules)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNomPropre(prenom)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Prénom du Patient incorrect<br>"
                        "(1 Majuscule + minuscules)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierAdressePersonnel(adresse)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Champ Adresse ne peut pas être vide<br>"
                        "(veuillez saisir une adresse)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierVille(ville)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Ville incorrect<br>"
                        "(1 Majuscule + minuscules)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierCodePostalePersonnel(cdepostal)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Code Postale incorrect<br>"
                        "(uniquement des chiffres)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierTypeMedecin(typeMedecin)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Type Médecin incorrect<br>"
                        "Faire un autre choix que l'exemple<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierLogin(login,typeMedecin)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du Login incorrect<br>"
                        "(si type Informaticien, veuillez saisir un login sinon ne pas compléter ce champ)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierPassword(password,typeMedecin)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du Password incorrect<br>"
                        "si type Informaticien, veuillez saisir un password sinon ne pas compléter ce champ<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNumTel(tel)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Num. de Téléphone incorrect<br>"
                        "(uniquement des chiffres)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierEmail(email)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Email incorrect<br>"
                        "(prenom.nom@email.fr ou prenom.nom@email.com)<br></p>");
         msgBox.exec();
         verifier= false;
     }

     return verifier;
 }

 bool verifierFormat::verificationsModifPersonnel(QString dateCreation, QString nom, QString prenom, QString adresse, QString ville, QString cdepostal,
                                                  QString typeMedecin, QString login, QString password, QString tel, QString email){
     bool verifier = true;

     if (!verifierFormat().verifierDate(dateCreation)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Date de création incorrect<br>"
                        "(JJ/MM/AAAA)</p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNomPropre(nom)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Nom du Patient incorrect<br>"
                        "(1 Majuscule + minuscules)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNomPropre(prenom)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Prénom du Patient incorrect<br>"
                        "(1 Majuscule + minuscules)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierAdressePersonnel(adresse)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Champ Adresse ne peut pas être vide<br>"
                        "(veuillez saisir une adresse)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierVille(ville)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Ville incorrect<br>"
                        "(1 Majuscule + minuscules)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierCodePostalePersonnel(cdepostal)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Code Postale incorrect<br>"
                        "(uniquement des chiffres)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierTypeMedecin(typeMedecin)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Type Médecin incorrect<br>"
                        "Faire un autre choix que l'exemple<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (typeMedecin!="Informaticien" and !verifierFormat().verifierLogin(login,typeMedecin)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du Login incorrect<br>"
                        "(si type Informaticien, veuillez saisir un login sinon ne pas compléter ce champ)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (typeMedecin!="Informaticien" and !verifierFormat().verifierPassword(password,typeMedecin)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du Password incorrect<br>"
                        "si type Informaticien, veuillez saisir un password sinon ne pas compléter ce champ<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierNumTelPersonnel(tel)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Num. de Téléphone incorrect<br>"
                        "(uniquement des chiffres)<br></p>");
         msgBox.exec();
         verifier= false;
     }else if (!verifierFormat().verifierEmail(email)){
         QMessageBox msgBox;
         msgBox.setWindowTitle("Warning");
         msgBox.setText("<p align='center'>Attention ! <br>"
                        "Format du champ Email incorrect<br>"
                        "(prenom.nom@email.fr ou prenom.nom@email.com)<br></p>");
         msgBox.exec();
         verifier= false;
     }
  return verifier;
}
