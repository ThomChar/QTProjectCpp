/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionPatient;
    QAction *actionPersonnel_de_soins;
    QAction *actionA_propos;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QFrame *line;
    QTableView *tableView;
    QToolButton *toolButton;
    QPushButton *pushButton;
    QLineEdit *lineEdit_5;
    QToolButton *toolButton_2;
    QLabel *label_6;
    QWidget *tab_2;
    QLabel *label;
    QFrame *line_2;
    QTreeView *treeView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAjouter;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(830, 545);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("ressources/quitter_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuitter->setIcon(icon);
        actionPatient = new QAction(MainWindow);
        actionPatient->setObjectName(QString::fromUtf8("actionPatient"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("ressources/Patient_icon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPatient->setIcon(icon1);
        actionPersonnel_de_soins = new QAction(MainWindow);
        actionPersonnel_de_soins->setObjectName(QString::fromUtf8("actionPersonnel_de_soins"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("ressources/Personnel2_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPersonnel_de_soins->setIcon(icon2);
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QString::fromUtf8("actionA_propos"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 821, 451));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tabWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(520, 10, 121, 21));
        QFont font1;
        font1.setPointSize(9);
        label_4->setFont(font1);
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(70, 80, 161, 22));
        lineEdit_4->setFont(font1);
        lineEdit_4->setMouseTracking(true);
        lineEdit_4->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_4->setDragEnabled(false);
        lineEdit_4->setReadOnly(false);
        lineEdit_4->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_4->setClearButtonEnabled(true);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 10, 101, 21));
        label_3->setFont(font1);
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(350, 10, 161, 22));
        lineEdit_2->setFont(font1);
        lineEdit_2->setClearButtonEnabled(true);
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(650, 10, 161, 22));
        lineEdit_3->setFont(font1);
        lineEdit_3->setClearButtonEnabled(true);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 161, 21));
        label_2->setFont(font1);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 61, 21));
        label_5->setFont(font1);
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 10, 161, 22));
        lineEdit->setFont(font1);
        lineEdit->setClearButtonEnabled(true);
        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 110, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 130, 801, 281));
        tableView->setMaximumSize(QSize(801, 281));
        tableView->setSelectionMode(QAbstractItemView::NoSelection);
        tableView->setGridStyle(Qt::SolidLine);
        tableView->setSortingEnabled(false);
        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(230, 80, 31, 21));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("ressources/calender_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon3);
        toolButton->setAutoRaise(true);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(650, 80, 161, 21));
        QFont font2;
        font2.setPointSize(10);
        pushButton->setFont(font2);
        pushButton->setAutoDefault(false);
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(350, 80, 161, 22));
        lineEdit_5->setFont(font1);
        lineEdit_5->setMouseTracking(true);
        lineEdit_5->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_5->setDragEnabled(false);
        lineEdit_5->setReadOnly(false);
        lineEdit_5->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_5->setClearButtonEnabled(true);
        toolButton_2 = new QToolButton(tab);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(510, 80, 31, 21));
        toolButton_2->setIcon(icon3);
        toolButton_2->setAutoRaise(true);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(240, 50, 181, 21));
        label_6->setFont(font1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 141, 21));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        label->setFont(font3);
        line_2 = new QFrame(tab_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 30, 801, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        treeView = new QTreeView(tab_2);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 50, 801, 361));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 830, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAjouter = new QMenu(menuFile);
        menuAjouter->setObjectName(QString::fromUtf8("menuAjouter"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFile->addAction(menuAjouter->menuAction());
        menuFile->addAction(actionQuitter);
        menuAjouter->addAction(actionPatient);
        menuAjouter->addAction(actionPersonnel_de_soins);
        menu->addAction(actionA_propos);
        mainToolBar->addAction(actionPatient);
        mainToolBar->addAction(actionPersonnel_de_soins);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", nullptr));
        actionPatient->setText(QApplication::translate("MainWindow", "Patient", nullptr));
        actionPersonnel_de_soins->setText(QApplication::translate("MainWindow", "Personnel de soins", nullptr));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Prenom du Patient", nullptr));
        lineEdit_4->setInputMask(QString());
        lineEdit_4->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Nom du Patient", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_3->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Date de RDV (apr\303\250s le)", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Num. ID", nullptr));
        lineEdit->setText(QString());
        toolButton->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Rechercher", nullptr));
        lineEdit_5->setInputMask(QString());
        lineEdit_5->setText(QString());
        toolButton_2->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Date de RDV (avant le)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Recherche de Patient", nullptr));
        label->setText(QApplication::translate("MainWindow", "Personnels Actifs :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Planification", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fichier", nullptr));
        menuAjouter->setTitle(QApplication::translate("MainWindow", "Ajouter", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
