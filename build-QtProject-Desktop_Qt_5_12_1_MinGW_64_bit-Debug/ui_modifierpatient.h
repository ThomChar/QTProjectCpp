/********************************************************************************
** Form generated from reading UI file 'modifierpatient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERPATIENT_H
#define UI_MODIFIERPATIENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_modifierPatient
{
public:
    QTextEdit *textEdit;
    QLabel *label_12;
    QLabel *label_10;
    QLineEdit *lineEdit_11;
    QFrame *line_4;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_7;
    QLabel *label;
    QLabel *label_13;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_2;
    QFrame *line_2;
    QToolButton *toolButton;
    QLabel *label_2;
    QToolButton *toolButton_2;
    QFrame *line;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLabel *label_11;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QLabel *label_3;
    QFrame *line_3;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QLabel *label_16;
    QSpinBox *spinBox;
    QToolButton *leftArrow_toolButton;
    QToolButton *rightArrow_toolButton;
    QTreeView *PersonnelBD_treeView;
    QTreeView *PersonnelTraitant_treeView;

    void setupUi(QDialog *modifierPatient)
    {
        if (modifierPatient->objectName().isEmpty())
            modifierPatient->setObjectName(QString::fromUtf8("modifierPatient"));
        modifierPatient->resize(554, 824);
        textEdit = new QTextEdit(modifierPatient);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 660, 531, 111));
        label_12 = new QLabel(modifierPatient);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(270, 400, 101, 21));
        QFont font;
        font.setPointSize(9);
        label_12->setFont(font);
        label_10 = new QLabel(modifierPatient);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 330, 191, 16));
        label_10->setFont(font);
        lineEdit_11 = new QLineEdit(modifierPatient);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(370, 280, 171, 22));
        line_4 = new QFrame(modifierPatient);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 40, 531, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(modifierPatient);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 110, 131, 21));
        label_4->setFont(font);
        label_8 = new QLabel(modifierPatient);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 170, 171, 16));
        label_8->setFont(font);
        label_7 = new QLabel(modifierPatient);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 240, 91, 21));
        label_7->setFont(font);
        label_6 = new QLabel(modifierPatient);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 240, 61, 21));
        label_6->setFont(font);
        comboBox_2 = new QComboBox(modifierPatient);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(370, 400, 171, 22));
        lineEdit_7 = new QLineEdit(modifierPatient);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(120, 360, 211, 22));
        label = new QLabel(modifierPatient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 471, 41));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label_13 = new QLabel(modifierPatient);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 280, 81, 21));
        label_13->setFont(font);
        lineEdit_6 = new QLineEdit(modifierPatient);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(370, 240, 171, 22));
        lineEdit_10 = new QLineEdit(modifierPatient);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(80, 280, 181, 22));
        lineEdit_2 = new QLineEdit(modifierPatient);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 110, 141, 22));
        line_2 = new QFrame(modifierPatient);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 310, 531, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        toolButton = new QToolButton(modifierPatient);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(330, 360, 31, 21));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/calender_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setAutoRaise(true);
        label_2 = new QLabel(modifierPatient);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 111, 21));
        label_2->setFont(font);
        toolButton_2 = new QToolButton(modifierPatient);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(330, 70, 31, 21));
        toolButton_2->setIcon(icon);
        toolButton_2->setAutoRaise(true);
        line = new QFrame(modifierPatient);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 150, 531, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(modifierPatient);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 70, 211, 22));
        lineEdit->setMouseTracking(true);
        lineEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_3 = new QLineEdit(modifierPatient);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(400, 110, 141, 22));
        label_11 = new QLabel(modifierPatient);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 400, 101, 21));
        label_11->setFont(font);
        label_5 = new QLabel(modifierPatient);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 200, 61, 21));
        label_5->setFont(font);
        lineEdit_5 = new QLineEdit(modifierPatient);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(80, 240, 181, 22));
        lineEdit_4 = new QLineEdit(modifierPatient);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(80, 200, 461, 22));
        pushButton = new QPushButton(modifierPatient);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 790, 161, 28));
        pushButton->setFont(font);
        label_3 = new QLabel(modifierPatient);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 101, 21));
        label_3->setFont(font);
        line_3 = new QFrame(modifierPatient);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 610, 531, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_14 = new QLabel(modifierPatient);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(270, 280, 91, 21));
        label_14->setFont(font);
        label_15 = new QLabel(modifierPatient);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 630, 161, 16));
        label_15->setFont(font);
        pushButton_2 = new QPushButton(modifierPatient);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 790, 161, 28));
        pushButton_2->setFont(font);
        label_9 = new QLabel(modifierPatient);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 360, 111, 21));
        label_9->setFont(font);
        label_16 = new QLabel(modifierPatient);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 440, 111, 21));
        label_16->setFont(font);
        spinBox = new QSpinBox(modifierPatient);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(120, 400, 141, 22));
        leftArrow_toolButton = new QToolButton(modifierPatient);
        leftArrow_toolButton->setObjectName(QString::fromUtf8("leftArrow_toolButton"));
        leftArrow_toolButton->setGeometry(QRect(290, 520, 31, 22));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/leftArrow_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftArrow_toolButton->setIcon(icon1);
        rightArrow_toolButton = new QToolButton(modifierPatient);
        rightArrow_toolButton->setObjectName(QString::fromUtf8("rightArrow_toolButton"));
        rightArrow_toolButton->setGeometry(QRect(290, 490, 31, 22));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rightArrow_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightArrow_toolButton->setIcon(icon2);
        PersonnelBD_treeView = new QTreeView(modifierPatient);
        PersonnelBD_treeView->setObjectName(QString::fromUtf8("PersonnelBD_treeView"));
        PersonnelBD_treeView->setGeometry(QRect(70, 470, 201, 141));
        PersonnelTraitant_treeView = new QTreeView(modifierPatient);
        PersonnelTraitant_treeView->setObjectName(QString::fromUtf8("PersonnelTraitant_treeView"));
        PersonnelTraitant_treeView->setGeometry(QRect(340, 470, 201, 141));

        retranslateUi(modifierPatient);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(modifierPatient);
    } // setupUi

    void retranslateUi(QDialog *modifierPatient)
    {
        modifierPatient->setWindowTitle(QApplication::translate("modifierPatient", "Dialog", nullptr));
        label_12->setText(QApplication::translate("modifierPatient", "Priorit\303\251 (1 \303\240 5)", nullptr));
        label_10->setText(QApplication::translate("modifierPatient", "Informations Consultation :", nullptr));
        lineEdit_11->setText(QString());
        label_4->setText(QApplication::translate("modifierPatient", "Prenom du Patient", nullptr));
        label_8->setText(QApplication::translate("modifierPatient", "Coordonn\303\251es du Patient :", nullptr));
        label_7->setText(QApplication::translate("modifierPatient", "Code Postale", nullptr));
        label_6->setText(QApplication::translate("modifierPatient", "Ville", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("modifierPatient", "1", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("modifierPatient", "2", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("modifierPatient", "3", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("modifierPatient", "4", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("modifierPatient", "5", nullptr));

        lineEdit_7->setText(QString());
        label->setText(QApplication::translate("modifierPatient", "Formulaire de Modification d'un  Patient", nullptr));
        label_13->setText(QApplication::translate("modifierPatient", "Tel.(Facul)", nullptr));
        lineEdit_6->setText(QString());
        lineEdit_10->setText(QString());
        lineEdit_2->setText(QString());
        toolButton->setText(QString());
        label_2->setText(QApplication::translate("modifierPatient", "Date de cr\303\251ation", nullptr));
        toolButton_2->setText(QString());
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit_3->setText(QString());
        label_11->setText(QApplication::translate("modifierPatient", "Dur\303\251e Consul.", nullptr));
        label_5->setText(QApplication::translate("modifierPatient", "Adresse", nullptr));
        lineEdit_5->setText(QString());
        lineEdit_4->setText(QString());
        pushButton->setText(QApplication::translate("modifierPatient", "Modifier", nullptr));
        label_3->setText(QApplication::translate("modifierPatient", "Nom du Patient", nullptr));
        label_14->setText(QApplication::translate("modifierPatient", "email (Facul)", nullptr));
        label_15->setText(QApplication::translate("modifierPatient", "Commentaires (Facul) :", nullptr));
        pushButton_2->setText(QApplication::translate("modifierPatient", "Annuler", nullptr));
        label_9->setText(QApplication::translate("modifierPatient", "Jour Consul.", nullptr));
        label_16->setText(QApplication::translate("modifierPatient", "Personnel(s) li\303\251(s)", nullptr));
        leftArrow_toolButton->setText(QApplication::translate("modifierPatient", "...", nullptr));
        rightArrow_toolButton->setText(QApplication::translate("modifierPatient", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modifierPatient: public Ui_modifierPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERPATIENT_H
