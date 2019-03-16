#ifndef MODELTABLEPATIENT_H
#define MODELTABLEPATIENT_H
#include <QAbstractTableModel>
#include <patient.h>
#include <requetebd.h>

class modelTablePatient: public QAbstractTableModel
{
    Q_OBJECT

private :
    QList<Patient>listePatients;
    QList<Patient> ::iterator it_vectPatients1;

public:
    modelTablePatient(QObject *parent, QList<Patient> listePatients);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

};

#endif // MODELTABLEPATIENT_H
