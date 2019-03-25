#include "modeltablepatient.h"
#include <QFont>
#include <QBrush>

modelTablePatient::modelTablePatient(QObject *parent, QList<Patient> listePatients): QAbstractTableModel(parent)
{
    this->listePatients = listePatients;
}

int modelTablePatient::rowCount(const QModelIndex & /*parent*/) const
{
   return static_cast<int>(listePatients.size());

}

int modelTablePatient::columnCount(const QModelIndex & /*parent*/) const
{
    return 4;
}

QVariant modelTablePatient::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::DisplayRole){
    switch (col) {
            case 0:
                return QString::number(listePatients.value(row).getNumId());
            case 1:
                return QString::fromStdString(listePatients.value(row).getNom());
            case 2:
                return QString::fromStdString(listePatients.value(row).getPrenom());
            case 3: {
                QString ee = listePatients.value(row).getDateConsultation().toString("dd/MM/yyyy");
                return ee; }
            default:
                return QString("Row%1, Column%2 vide").arg(index.row() + 1)
                        .arg(index.column() +1);

               }
    }
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
        }
    }
    return QVariant();
}
