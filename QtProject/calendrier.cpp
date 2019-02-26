#include "calendrier.h"
#include "ui_calendrier.h"

Calendrier::Calendrier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendrier)
{
    ui->setupUi(this);
    this->setWindowTitle("Calendrier");
    this->setFixedSize( this->size());

    //Evenements
    //evenement pour quitter application
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(close()));
    //evenement pour  valider date selectionnee
    QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(validerDate()));
}

Calendrier::~Calendrier()
{
    delete ui;
}

void Calendrier::validerDate(){
    this->close();
}

/**
 * Methode permettant de recuperer valeur du calendrier et de la renvoyer dans l editText
 * @brief calendar::getCalendrier
 */
QCalendarWidget* Calendrier::getCalendrier(){
    return ui->calendarWidget;
}
