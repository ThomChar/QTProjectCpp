#ifndef MODELTABLEPATIENT_H
#define MODELTABLEPATIENT_H
#include <QAbstractTableModel>

class modelTablePatient: public QAbstractTableModel
{
    Q_OBJECT
public:
    modelTablePatient(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // MODELTABLEPATIENT_H
