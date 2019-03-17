#include "modeltabletypemedecin.h"


modelTableTypeMedecin::modelTableTypeMedecin(QObject *parent, QList<typePersonnel> listeTypesPersonnel): QAbstractTableModel(parent)
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

    this->listeTypesPersonnel = listeTypesPersonnel;
    //test allocation des Patients à listePatients
    /*listePatients.push_back(patient1);
    listePatients.push_back(patient2);
    listePatients.push_back(patient3);
    listePatients.push_back(patient4);*/
}

int modelTableTypeMedecin::rowCount(const QModelIndex & /*parent*/) const
{
   return static_cast<int>(listeTypesPersonnel.size());

}

int modelTableTypeMedecin::columnCount(const QModelIndex & /*parent*/) const
{
    return 2; /* nom, prénom, date de rendez-vous, numéro d’identiﬁcation, lien modifier, bouton supprimer*/
}

QVariant modelTableTypeMedecin::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::DisplayRole){
    switch (col) {
            case 0:
                return QString::number(listeTypesPersonnel.value(row).getIdType());
            case 1:
                return QString::fromStdString(listeTypesPersonnel.value(row).getLabel());
            default:
                return QString("Row%1, Column%2 vide").arg(index.row() + 1)
                        .arg(index.column() +1);
               }
    }
       return QVariant();

}


QVariant modelTableTypeMedecin::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("ID Type");
        case 1:
            return QString("Label");
        }
    }
    return QVariant();
}
