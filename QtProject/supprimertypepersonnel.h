#ifndef SUPPRIMERTYPEPERSONNEL_H
#define SUPPRIMERTYPEPERSONNEL_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class supprimerTypePersonnel;
}

class supprimerTypePersonnel : public QDialog
{
    Q_OBJECT

public:
    supprimerTypePersonnel(QWidget *parent, int idType, QString label);
    supprimerTypePersonnel(QWidget *parent, int idType, string label);
    ~supprimerTypePersonnel();

private:
    Ui::supprimerTypePersonnel *ui;
    int idType;
    QString label;

private slots:
    void suppressionTypePersonnel();
    void annuler();
};

#endif // SUPPRIMERTYPEPERSONNEL_H
