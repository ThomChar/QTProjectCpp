#ifndef AJOUTPERSONNEL_H
#define AJOUTPERSONNEL_H

#include <QDialog>

namespace Ui {
class ajoutPersonnel;
}

class ajoutPersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutPersonnel(QWidget *parent = nullptr);
    ~ajoutPersonnel();

private slots:
    void ajouterPersonnel();

private:
    Ui::ajoutPersonnel *ui;
};

#endif // AJOUTPERSONNEL_H
