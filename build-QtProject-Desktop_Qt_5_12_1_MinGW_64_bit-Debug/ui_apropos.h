/********************************************************************************
** Form generated from reading UI file 'apropos.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APROPOS_H
#define UI_APROPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_aPropos
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *aPropos)
    {
        if (aPropos->objectName().isEmpty())
            aPropos->setObjectName(QString::fromUtf8("aPropos"));
        aPropos->resize(690, 139);
        label = new QLabel(aPropos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 381, 111));
        label->setPixmap(QPixmap(QString::fromUtf8("ressources/logoPolytechTours.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(aPropos);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(410, 30, 221, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_3 = new QLabel(aPropos);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(410, 70, 281, 51));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        label_3->setFont(font1);

        retranslateUi(aPropos);

        QMetaObject::connectSlotsByName(aPropos);
    } // setupUi

    void retranslateUi(QDialog *aPropos)
    {
        aPropos->setWindowTitle(QApplication::translate("aPropos", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("aPropos", "Version 1.0", nullptr));
        label_3->setText(QApplication::translate("aPropos", "CHARLET Thomas et HILLERITEAU R\303\251mi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aPropos: public Ui_aPropos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APROPOS_H
