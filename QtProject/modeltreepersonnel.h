#ifndef MODELTREEPERSONNEL_H
#define MODELTREEPERSONNEL_H
#include <QStandardItemModel>
#include "personnel.h"

class modelTreePersonnel : public QStandardItemModel
{
    Q_OBJECT

    private :
        QList<Personnel> listePersonnel;
        QList<QString> typesRessources;

    public:
        modelTreePersonnel(QObject *parent, QList<QString> typesRessources, QList<Personnel> listePersonnel);
        void setTree();
};

#endif // MODELTREEPERSONNEL_H
