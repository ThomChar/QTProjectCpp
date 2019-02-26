#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <QDialog>

namespace Ui {
class Calendrier;
}

class Calendrier : public QDialog
{
    Q_OBJECT

public:
    explicit Calendrier(QWidget *parent = nullptr);
    ~Calendrier();

private:
    Ui::Calendrier *ui;
};

#endif // CALENDRIER_H
