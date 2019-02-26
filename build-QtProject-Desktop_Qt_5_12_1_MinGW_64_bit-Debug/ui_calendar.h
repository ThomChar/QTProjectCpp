/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calendar
{
public:
    QCalendarWidget *calendarWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *calendar)
    {
        if (calendar->objectName().isEmpty())
            calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setWindowModality(Qt::ApplicationModal);
        calendar->resize(409, 295);
        calendarWidget = new QCalendarWidget(calendar);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 10, 392, 236));
        pushButton = new QPushButton(calendar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 260, 171, 28));
        pushButton_2 = new QPushButton(calendar);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 260, 171, 28));

        retranslateUi(calendar);

        QMetaObject::connectSlotsByName(calendar);
    } // setupUi

    void retranslateUi(QWidget *calendar)
    {
        calendar->setWindowTitle(QApplication::translate("calendar", "Form", nullptr));
        pushButton->setText(QApplication::translate("calendar", "Ok", nullptr));
        pushButton_2->setText(QApplication::translate("calendar", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calendar: public Ui_calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
