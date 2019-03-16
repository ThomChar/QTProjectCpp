#ifndef SUPPRIMERPATIENT_H
#define SUPPRIMERPATIENT_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class SupprimerPatient;
}

class SupprimerPatient : public QDialog
{
    Q_OBJECT

public:
    SupprimerPatient(QWidget *parent, int idPatient, QString nomPatient, QString prenomPatient);
    ~SupprimerPatient();

private:
    Ui::SupprimerPatient *ui;
    int idPatient;
    string nomPatient;
    string prenomPatient;

private slots:
    void supprimerPatient();
    void annuler();

};

#endif // SUPPRIMERPATIENT_H
