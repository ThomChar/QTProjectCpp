/********************************************************************************
** Form generated from reading UI file 'supprimerpatient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERPATIENT_H
#define UI_SUPPRIMERPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SupprimerPatient
{
public:
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *SupprimerPatient)
    {
        if (SupprimerPatient->objectName().isEmpty())
            SupprimerPatient->setObjectName(QString::fromUtf8("SupprimerPatient"));
        SupprimerPatient->resize(412, 192);
        pushButton_2 = new QPushButton(SupprimerPatient);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 150, 111, 28));
        QFont font;
        font.setPointSize(9);
        pushButton_2->setFont(font);
        pushButton_2->setAutoDefault(true);
        label = new QLabel(SupprimerPatient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 10, 171, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        pushButton = new QPushButton(SupprimerPatient);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 150, 111, 28));
        pushButton->setFont(font);
        label_2 = new QLabel(SupprimerPatient);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 70, 311, 31));
        label_2->setFont(font);
        label_3 = new QLabel(SupprimerPatient);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 100, 181, 31));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(SupprimerPatient);

        pushButton_2->setDefault(true);
        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(SupprimerPatient);
    } // setupUi

    void retranslateUi(QDialog *SupprimerPatient)
    {
        SupprimerPatient->setWindowTitle(QApplication::translate("SupprimerPatient", "Dialog", nullptr));
        pushButton_2->setText(QApplication::translate("SupprimerPatient", "Annuler", nullptr));
        label->setText(QApplication::translate("SupprimerPatient", "Supprimer Patient", nullptr));
        pushButton->setText(QApplication::translate("SupprimerPatient", "Supprimer", nullptr));
        label_2->setText(QApplication::translate("SupprimerPatient", "Etes-vous s\303\273r de vouloir supprimer le Patient :", nullptr));
        label_3->setText(QApplication::translate("SupprimerPatient", "nomPatient prenomPatient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerPatient: public Ui_SupprimerPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERPATIENT_H
