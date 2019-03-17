#ifndef MODELTABLETYPEMEDECIN_H
#define MODELTABLETYPEMEDECIN_H
#include <QAbstractTableModel>
#include <typepersonnel.h>
#include <requetebd.h>

class modelTableTypeMedecin: public QAbstractTableModel
{
     Q_OBJECT

private :
    QList<typePersonnel>listeTypesPersonnel;
    QList<Patient> ::iterator it_vectTypesPer1;

public:
    modelTableTypeMedecin(QObject *parent, QList<typePersonnel> listeTypesPersonnel);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // MODELTABLETYPEMEDECIN_H
