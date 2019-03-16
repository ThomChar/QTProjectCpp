#include "modifierpersonnel.h"
#include "ui_modifierpersonnel.h"

ModifierPersonnel::ModifierPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierPersonnel)
{
    ui->setupUi(this);
}

ModifierPersonnel::~ModifierPersonnel()
{
    delete ui;
}
