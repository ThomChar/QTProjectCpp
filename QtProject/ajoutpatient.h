#ifndef AJOUTPATIENT_H
#define AJOUTPATIENT_H

#include <QDialog>

namespace Ui {
class ajoutPatient;
}

class ajoutPatient : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutPatient(QWidget *parent = nullptr);
    ~ajoutPatient();

private slots:
    void ajouterPatient();

private:
    Ui::ajoutPatient *ui;
    //methodes de verifications à ajouter
};

#endif // AJOUTPATIENT_H
