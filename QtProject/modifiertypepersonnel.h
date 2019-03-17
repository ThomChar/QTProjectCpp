#ifndef MODIFIERTYPEPERSONNEL_H
#define MODIFIERTYPEPERSONNEL_H

#include <QDialog>

namespace Ui {
class modifierTypePersonnel;
}

class modifierTypePersonnel : public QDialog
{
    Q_OBJECT

public:
    modifierTypePersonnel(QWidget *parent, int idType);
    ~modifierTypePersonnel();

private:
    Ui::modifierTypePersonnel *ui;
    int idType;
    QString label;
private slots:
    void modificationPersonnel();
    void annuler();
};

#endif // MODIFIERTYPEPERSONNEL_H
