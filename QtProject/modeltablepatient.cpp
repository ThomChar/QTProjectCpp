#include "modeltablepatient.h"
#include <QFont>
#include <QBrush>

modelTablePatient::modelTablePatient(QObject *parent, QList<Patient> listePatients): QAbstractTableModel(parent)
{
    //Création de Patients test
    /*Patient patient1("01/03/04","Nom1" ,"Prenom1", "a", "Tours", "37200", "", "", "01/03/04", "01:00", 1,"Tom Hille", "");
    patient1.setNumId(1);
    Patient patient2("01/03/04","Nom2" ,"Prenom2", "a", "Tours", "37200", "", "", "02/03/04", "01:00", 1,"Tom Hille","");
    patient2.setNumId(2);
    Patient patient3("01/03/04","Nom3" ,"Prenom3", "a", "Tours", "37200", "", "", "03/03/04", "01:00", 1,"Tom Hille","");
    patient3.setNumId(3);
    Patient patient4("01/03/04","Nom4" ,"Prenom4", "a", "Tours", "37200", "", "", "04/03/04", "01:00", 1,"Tom Hille","");
    patient4.setNumId(4);*/

    this->listePatients = listePatients;
    //test allocation des Patients à listePatients
    /*listePatients.push_back(patient1);
    listePatients.push_back(patient2);
    listePatients.push_back(patient3);
    listePatients.push_back(patient4);*/
}

int modelTablePatient::rowCount(const QModelIndex & /*parent*/) const
{
   return static_cast<int>(listePatients.size());

}

int modelTablePatient::columnCount(const QModelIndex & /*parent*/) const
{
    return 6;// return 6; /* nom, prénom, date de rendez-vous, numéro d’identiﬁcation, lien modifier, bouton supprimer*/
}

QVariant modelTablePatient::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    /*if (role == Qt::DisplayRole)
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);*/
    if (role == Qt::DisplayRole){
    switch (col) {
            case 0:
                return QString::number(listePatients.value(row).getNumId());
            case 1:
                return QString::fromStdString(listePatients.value(row).getNom());
            case 2:
                return QString::fromStdString(listePatients.value(row).getPrenom());
            case 3:
                return QString::fromStdString(listePatients.value(row).getDateConsultation());
            default:
                return QString("Row%1, Column%2 vide").arg(index.row() + 1)
                        .arg(index.column() +1);
                /*return nullptr;*/

               }
    }
    /*switch (role) {
       case Qt::DisplayRole:
           if (row == 0 && col == 1) return QString("<--left");
           if (row == 1 && col == 1) return QString("right-->");

           return QString("Row%1, Column%2")
                   .arg(row + 1)
                   .arg(col +1);*/
       /*case Qt::FontRole:
           if (row == 0 && col == 0) { //change font only for cell(0,0)
               QFont boldFont;
               boldFont.setBold(true);
               return boldFont;
           }
           break;*/
      /* case Qt::BackgroundRole:
           if (row == 1 && col == 2)  //change background only for cell(1,2)
               return QBrush(Qt::red);
           break;
       case Qt::TextAlignmentRole:
           if (row == 1 && col == 1) //change text alignment only for cell(1,1)
               return Qt::AlignRight + Qt::AlignVCenter;
           break;
       case Qt::CheckStateRole:
           if (row == 1 && col == 0) //add a checkbox to cell(1,0)
               return Qt::Checked;
           break;
       }*/
       return QVariant();

}


QVariant modelTablePatient::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Num ID");
        case 1:
            return QString("Nom");
        case 2:
            return QString("Prenom");
        case 3:
            return QString("Date RDV");
        case 4:
            return QString("Modifier");
        case 5:
            return QString("Supprimer");
        }
    }
    return QVariant();
}
