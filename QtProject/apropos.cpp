#include "apropos.h"
#include "ui_apropos.h"

aPropos::aPropos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aPropos)
{
    ui->setupUi(this);
    this->setWindowTitle("A propos");
    this->setFixedSize( this->size());
}

aPropos::~aPropos()
{
    delete ui;
}
