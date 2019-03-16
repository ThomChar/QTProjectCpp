/********************************************************************************
** Form generated from reading UI file 'supprimerpersonnel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERPERSONNEL_H
#define UI_SUPPRIMERPERSONNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SupprimerPersonnel
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *SupprimerPersonnel)
    {
        if (SupprimerPersonnel->objectName().isEmpty())
            SupprimerPersonnel->setObjectName(QString::fromUtf8("SupprimerPersonnel"));
        SupprimerPersonnel->resize(456, 200);
        label_2 = new QLabel(SupprimerPersonnel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 70, 311, 31));
        QFont font;
        font.setPointSize(9);
        label_2->setFont(font);
        label_3 = new QLabel(SupprimerPersonnel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 100, 181, 31));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(SupprimerPersonnel);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 150, 111, 28));
        pushButton_2->setFont(font);
        pushButton_2->setAutoDefault(true);
        label = new QLabel(SupprimerPersonnel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 10, 171, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        pushButton = new QPushButton(SupprimerPersonnel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 150, 111, 28));
        pushButton->setFont(font);

        retranslateUi(SupprimerPersonnel);

        pushButton_2->setDefault(true);
        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(SupprimerPersonnel);
    } // setupUi

    void retranslateUi(QDialog *SupprimerPersonnel)
    {
        SupprimerPersonnel->setWindowTitle(QApplication::translate("SupprimerPersonnel", "Dialog", nullptr));
        label_2->setText(QApplication::translate("SupprimerPersonnel", "Etes-vous s\303\273r de vouloir supprimer le Personnel :", nullptr));
        label_3->setText(QApplication::translate("SupprimerPersonnel", "nomPersonnel prenomPersonnel", nullptr));
        pushButton_2->setText(QApplication::translate("SupprimerPersonnel", "Annuler", nullptr));
        label->setText(QApplication::translate("SupprimerPersonnel", "Supprimer Personnel", nullptr));
        pushButton->setText(QApplication::translate("SupprimerPersonnel", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerPersonnel: public Ui_SupprimerPersonnel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERPERSONNEL_H
