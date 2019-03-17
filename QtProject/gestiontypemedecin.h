#ifndef GESTIONTYPEMEDECIN_H
#define GESTIONTYPEMEDECIN_H

#include <QDialog>
#include "modeltabletypemedecin.h"
#include "supprimertypepersonnel.h"
#include "modifiertypepersonnel.h"

namespace Ui {
class gestionTypeMedecin;
}

class gestionTypeMedecin : public QDialog
{
    Q_OBJECT

public:
    explicit gestionTypeMedecin(QWidget *parent = nullptr);
    ~gestionTypeMedecin();

private:
    Ui::gestionTypeMedecin *ui;
    modelTableTypeMedecin *modelTypePers;
    QList<typePersonnel> listeTypesPers;
    supprimerTypePersonnel * supTypePersWindow;
    modifierTypePersonnel * modTypePersWindow;

private slots:
    void annuler();
    void valider();
    void ajouterTypePersonnel();
    void suppressionTypePersonnel();
    void modificationTypePersonnel();
};

#endif // GESTIONTYPEMEDECIN_H
