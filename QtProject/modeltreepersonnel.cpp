#include "modeltreepersonnel.h"
#include <QAbstractItemModel>
#include <QTreeView>
//#include <QObject>
#include <QTreeView>

modelTreePersonnel::modelTreePersonnel(QObject *parent, QList<QString> typesRessources, QList<Personnel> listePersonnel) : QStandardItemModel(parent)
{
    this->listePersonnel = listePersonnel;
    this->typesRessources = typesRessources;
}

void modelTreePersonnel::setTree()
{
    // vider le modèle
    this->clear();

    // ajouter les types de ressources
    for(int indiceTypeRessource = 0; indiceTypeRessource < typesRessources.size(); indiceTypeRessource++)
    {
        QStandardItem * item = new QStandardItem( typesRessources[indiceTypeRessource]);
        this->appendRow(item);
    }

    // ajouter le personnel
    for(int indicePersonnel = 0; indicePersonnel < listePersonnel.size(); indicePersonnel++)
    {
        Personnel personnel = listePersonnel[indicePersonnel];
        QString name = QString::fromStdString(personnel.getNom() + " " + personnel.getPrenom());
        QStandardItem * item = new QStandardItem(name);

        // on retrouve la fonction de l'employé
        QList<QStandardItem *> children = this->findItems(QString::fromStdString(personnel.getTypeMedecin()));

        if(!children.isEmpty())
        {
            QStandardItem * typeRessource = children.first();

            // on ajoute l'employé dans la branche de sa fonction
            if(typeRessource != nullptr)
                typeRessource->appendRow(item);
            else {
                this->appendRow(item);
            }
        }
    }
}
