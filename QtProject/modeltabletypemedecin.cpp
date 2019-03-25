#include "modeltabletypemedecin.h"


modelTableTypeMedecin::modelTableTypeMedecin(QObject *parent, QList<typePersonnel> listeTypesPersonnel): QAbstractTableModel(parent)
{
    this->listeTypesPersonnel = listeTypesPersonnel;
}

int modelTableTypeMedecin::rowCount(const QModelIndex & /*parent*/) const
{
   return static_cast<int>(listeTypesPersonnel.size());

}

int modelTableTypeMedecin::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
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
