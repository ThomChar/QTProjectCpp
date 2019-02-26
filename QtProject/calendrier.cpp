#include "calendrier.h"
#include "ui_calendrier.h"

Calendrier::Calendrier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendrier)
{
    ui->setupUi(this);
}

Calendrier::~Calendrier()
{
    delete ui;
}
