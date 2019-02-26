#include "modeltablepatient.h"
#include <QFont>
#include <QBrush>

modelTablePatient::modelTablePatient(QObject *parent): QAbstractTableModel(parent)
{

}

int modelTablePatient::rowCount(const QModelIndex & /*parent*/) const
{
   return 2;

}

int modelTablePatient::columnCount(const QModelIndex & /*parent*/) const
{
    return 6;// return 6; /* nom, prénom, date de rendez-vous, numéro d’identiﬁcation, lien modifier, bouton supprimer*/
}

QVariant modelTablePatient::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole)
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);

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
