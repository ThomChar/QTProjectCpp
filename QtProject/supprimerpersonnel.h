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
    SupprimerPersonnel(QWidget *parent, QString nomPrenomPersonnel);
    ~SupprimerPersonnel();

private:
    Ui::SupprimerPersonnel *ui;
    /*string nom;
    string prenom;*/
    QString nomPrenom;

private slots:
    void supprimerPersonnel();
    void annuler();
};

#endif // SUPPRIMERPERSONNEL_H
