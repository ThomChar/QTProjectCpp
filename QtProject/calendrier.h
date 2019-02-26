#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <QDialog>
#include <QCalendarWidget>

namespace Ui {
class Calendrier;
}

class Calendrier : public QDialog
{
    Q_OBJECT

public:
    explicit Calendrier(QWidget *parent = nullptr);
    QCalendarWidget* getCalendrier();
    ~Calendrier();

private slots:
    void validerDate();

private:
    Ui::Calendrier *ui;
};

#endif // CALENDRIER_H
