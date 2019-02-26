/********************************************************************************
** Form generated from reading UI file 'calendrier.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDRIER_H
#define UI_CALENDRIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Calendrier
{
public:
    QCalendarWidget *calendarWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Calendrier)
    {
        if (Calendrier->objectName().isEmpty())
            Calendrier->setObjectName(QString::fromUtf8("Calendrier"));
        Calendrier->setWindowModality(Qt::ApplicationModal);
        Calendrier->resize(411, 300);
        calendarWidget = new QCalendarWidget(Calendrier);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 10, 391, 236));
        pushButton = new QPushButton(Calendrier);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 260, 171, 31));
        pushButton_2 = new QPushButton(Calendrier);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 260, 171, 31));

        retranslateUi(Calendrier);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(Calendrier);
    } // setupUi

    void retranslateUi(QDialog *Calendrier)
    {
        Calendrier->setWindowTitle(QApplication::translate("Calendrier", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Calendrier", "Ok", nullptr));
        pushButton_2->setText(QApplication::translate("Calendrier", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calendrier: public Ui_Calendrier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDRIER_H
