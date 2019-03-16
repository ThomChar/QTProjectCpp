/********************************************************************************
** Form generated from reading UI file 'modifierpersonnel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERPERSONNEL_H
#define UI_MODIFIERPERSONNEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_ModifierPersonnel
{
public:
    QFrame *line_3;
    QLineEdit *lineEdit;
    QFrame *line_2;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_5;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_11;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QToolButton *toolButton;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QLineEdit *lineEdit_9;
    QLabel *label_9;
    QPushButton *pushButton;
    QLabel *label_14;
    QLineEdit *lineEdit_11;
    QFrame *line;
    QLineEdit *lineEdit_8;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *label_6;
    QFrame *line_4;
    QLabel *label_16;
    QLineEdit *lineEdit_10;
    QLabel *label_12;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_2;

    void setupUi(QDialog *ModifierPersonnel)
    {
        if (ModifierPersonnel->objectName().isEmpty())
            ModifierPersonnel->setObjectName(QString::fromUtf8("ModifierPersonnel"));
        ModifierPersonnel->resize(547, 521);
        line_3 = new QFrame(ModifierPersonnel);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 450, 531, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(ModifierPersonnel);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 70, 211, 22));
        line_2 = new QFrame(ModifierPersonnel);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 310, 531, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        comboBox_2 = new QComboBox(ModifierPersonnel);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(80, 360, 251, 22));
        lineEdit_5 = new QLineEdit(ModifierPersonnel);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(80, 240, 181, 22));
        label_4 = new QLabel(ModifierPersonnel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 110, 121, 21));
        QFont font;
        font.setPointSize(9);
        label_4->setFont(font);
        lineEdit_2 = new QLineEdit(ModifierPersonnel);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 110, 141, 22));
        label_11 = new QLabel(ModifierPersonnel);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 400, 131, 21));
        label_11->setFont(font);
        label_3 = new QLabel(ModifierPersonnel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 111, 21));
        label_3->setFont(font);
        pushButton_2 = new QPushButton(ModifierPersonnel);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 480, 161, 31));
        pushButton_2->setFont(font);
        toolButton = new QToolButton(ModifierPersonnel);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(330, 70, 31, 21));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/calender_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setAutoRaise(true);
        lineEdit_6 = new QLineEdit(ModifierPersonnel);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(370, 240, 171, 22));
        label_7 = new QLabel(ModifierPersonnel);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 240, 91, 21));
        label_7->setFont(font);
        lineEdit_9 = new QLineEdit(ModifierPersonnel);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(370, 430, 171, 22));
        label_9 = new QLabel(ModifierPersonnel);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 360, 111, 21));
        label_9->setFont(font);
        pushButton = new QPushButton(ModifierPersonnel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 480, 161, 31));
        pushButton->setFont(font);
        label_14 = new QLabel(ModifierPersonnel);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(270, 280, 91, 21));
        label_14->setFont(font);
        lineEdit_11 = new QLineEdit(ModifierPersonnel);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(370, 280, 171, 22));
        line = new QFrame(ModifierPersonnel);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 150, 531, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit_8 = new QLineEdit(ModifierPersonnel);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(80, 430, 141, 22));
        label_8 = new QLabel(ModifierPersonnel);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 170, 231, 16));
        label_8->setFont(font);
        label_5 = new QLabel(ModifierPersonnel);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 200, 61, 21));
        label_5->setFont(font);
        label_13 = new QLabel(ModifierPersonnel);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 280, 81, 21));
        label_13->setFont(font);
        label_10 = new QLabel(ModifierPersonnel);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 330, 161, 16));
        label_10->setFont(font);
        label_6 = new QLabel(ModifierPersonnel);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 240, 61, 21));
        label_6->setFont(font);
        line_4 = new QFrame(ModifierPersonnel);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 40, 531, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_16 = new QLabel(ModifierPersonnel);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 430, 111, 21));
        label_16->setFont(font);
        lineEdit_10 = new QLineEdit(ModifierPersonnel);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(80, 280, 181, 22));
        label_12 = new QLabel(ModifierPersonnel);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(270, 430, 81, 21));
        label_12->setFont(font);
        label = new QLabel(ModifierPersonnel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 521, 41));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        lineEdit_3 = new QLineEdit(ModifierPersonnel);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(400, 110, 141, 22));
        lineEdit_4 = new QLineEdit(ModifierPersonnel);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(80, 200, 461, 22));
        lineEdit_4->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_2 = new QLabel(ModifierPersonnel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 111, 21));
        label_2->setFont(font);

        retranslateUi(ModifierPersonnel);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(ModifierPersonnel);
    } // setupUi

    void retranslateUi(QDialog *ModifierPersonnel)
    {
        ModifierPersonnel->setWindowTitle(QApplication::translate("ModifierPersonnel", "Dialog", nullptr));
        lineEdit->setText(QString());
        comboBox_2->setItemText(0, QApplication::translate("ModifierPersonnel", "ex: m\303\251decin A", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("ModifierPersonnel", "m\303\251decin A", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("ModifierPersonnel", "m\303\251decin B", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("ModifierPersonnel", "radiologue", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("ModifierPersonnel", "infirmi\303\250re", nullptr));
        comboBox_2->setItemText(5, QApplication::translate("ModifierPersonnel", "kin\303\251sith\303\251rapeute", nullptr));
        comboBox_2->setItemText(6, QApplication::translate("ModifierPersonnel", "psychologue", nullptr));
        comboBox_2->setItemText(7, QApplication::translate("ModifierPersonnel", "informaticien", nullptr));

        lineEdit_5->setText(QString());
        label_4->setText(QApplication::translate("ModifierPersonnel", "Prenom Personnel", nullptr));
        lineEdit_2->setText(QString());
        label_11->setText(QApplication::translate("ModifierPersonnel", "Pour informaticien :", nullptr));
        label_3->setText(QApplication::translate("ModifierPersonnel", "Nom Personnel", nullptr));
        pushButton_2->setText(QApplication::translate("ModifierPersonnel", "Annuler", nullptr));
        toolButton->setText(QString());
        lineEdit_6->setText(QString());
        label_7->setText(QApplication::translate("ModifierPersonnel", "Code Postale", nullptr));
        lineEdit_9->setText(QString());
        label_9->setText(QApplication::translate("ModifierPersonnel", "Type", nullptr));
        pushButton->setText(QApplication::translate("ModifierPersonnel", "Ajouter", nullptr));
        label_14->setText(QApplication::translate("ModifierPersonnel", "email (Facul)", nullptr));
        lineEdit_11->setText(QString());
        lineEdit_8->setText(QString());
        label_8->setText(QApplication::translate("ModifierPersonnel", "Coordonn\303\251es du Personnel (Facul) :", nullptr));
        label_5->setText(QApplication::translate("ModifierPersonnel", "Adresse", nullptr));
        label_13->setText(QApplication::translate("ModifierPersonnel", "Tel.(Facul)", nullptr));
        label_10->setText(QApplication::translate("ModifierPersonnel", "Informations Personnel :", nullptr));
        label_6->setText(QApplication::translate("ModifierPersonnel", "Ville", nullptr));
        label_16->setText(QApplication::translate("ModifierPersonnel", "Login", nullptr));
        lineEdit_10->setText(QString());
        label_12->setText(QApplication::translate("ModifierPersonnel", "Password", nullptr));
        label->setText(QApplication::translate("ModifierPersonnel", "Formulaire de Modification d'un Personnel de Soins", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_4->setText(QString());
        label_2->setText(QApplication::translate("ModifierPersonnel", "Date de cr\303\251ation ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifierPersonnel: public Ui_ModifierPersonnel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERPERSONNEL_H
