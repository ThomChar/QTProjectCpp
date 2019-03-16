#ifndef MODIFIERPERSONNEL_H
#define MODIFIERPERSONNEL_H

#include <QDialog>

namespace Ui {
class ModifierPersonnel;
}

class ModifierPersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierPersonnel(QWidget *parent = nullptr);
    ~ModifierPersonnel();

private:
    Ui::ModifierPersonnel *ui;
};

#endif // MODIFIERPERSONNEL_H
