#ifndef SUPPRIMERPERSONNEL_H
#define SUPPRIMERPERSONNEL_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class SupprimerPersonnel;
}

class SupprimerPersonnel : public QDialog
{
    Q_OBJECT
public:
    SupprimerPersonnel(QWidget *parent, int idPersonnel, QString nomPersonnel, QString prenomPersonnel);
    ~SupprimerPersonnel();

private:
    Ui::SupprimerPersonnel *ui;
    int idPersonnel;
    string nomPersonnel;
    string prenomPersonnel;

private slots:
    void supprimerPersonnel();
    void annuler();
};

#endif // SUPPRIMERPERSONNEL_H
