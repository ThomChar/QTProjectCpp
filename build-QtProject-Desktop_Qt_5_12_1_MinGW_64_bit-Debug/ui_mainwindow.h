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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
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
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_10;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *recherche;
    QHBoxLayout *numPatient;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *prenomPatient;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *nomPatient;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_5;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_4;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_16;
    QPushButton *pushButton;
    QFrame *line;
    QHBoxLayout *horizontalLayout_10;
    QTableView *tableView;
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
        MainWindow->resize(870, 608);
        MainWindow->setAutoFillBackground(false);
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
        verticalLayout_9 = new QVBoxLayout(centralWidget);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
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
        verticalLayout_11 = new QVBoxLayout(tab);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 120));
        widget->setMaximumSize(QSize(1000, 16777215));
        verticalLayout_18 = new QVBoxLayout(widget);
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        recherche = new QHBoxLayout();
        recherche->setSpacing(6);
        recherche->setObjectName(QString::fromUtf8("recherche"));
        recherche->setContentsMargins(-1, 10, -1, 10);
        numPatient = new QHBoxLayout();
        numPatient->setSpacing(6);
        numPatient->setObjectName(QString::fromUtf8("numPatient"));
        numPatient->setContentsMargins(-1, -1, -1, 10);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setPointSize(9);
        label_5->setFont(font1);

        numPatient->addWidget(label_5);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setFont(font1);
        lineEdit->setClearButtonEnabled(true);

        numPatient->addWidget(lineEdit);


        recherche->addLayout(numPatient);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        recherche->addItem(horizontalSpacer);

        prenomPatient = new QHBoxLayout();
        prenomPatient->setSpacing(6);
        prenomPatient->setObjectName(QString::fromUtf8("prenomPatient"));
        prenomPatient->setContentsMargins(-1, -1, -1, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        prenomPatient->addWidget(label_3);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font1);
        lineEdit_2->setClearButtonEnabled(true);

        prenomPatient->addWidget(lineEdit_2);


        recherche->addLayout(prenomPatient);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        recherche->addItem(horizontalSpacer_3);

        nomPatient = new QHBoxLayout();
        nomPatient->setSpacing(6);
        nomPatient->setObjectName(QString::fromUtf8("nomPatient"));
        nomPatient->setContentsMargins(-1, -1, -1, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        nomPatient->addWidget(label_4);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFont(font1);
        lineEdit_3->setClearButtonEnabled(true);

        nomPatient->addWidget(lineEdit_3);


        recherche->addLayout(nomPatient);


        verticalLayout_18->addLayout(recherche);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, -1, 0);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(-1, -1, -1, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        verticalLayout_13->addWidget(label_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, -1, -1, 0);
        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font1);
        lineEdit_5->setMouseTracking(true);
        lineEdit_5->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_5->setDragEnabled(false);
        lineEdit_5->setReadOnly(false);
        lineEdit_5->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_5->setClearButtonEnabled(true);

        horizontalLayout_7->addWidget(lineEdit_5);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("ressources/calender_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon3);
        toolButton_2->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_2);


        verticalLayout_13->addLayout(horizontalLayout_7);


        horizontalLayout_6->addLayout(verticalLayout_13);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout_15->addWidget(label_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, -1, -1, 0);
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font1);
        lineEdit_4->setMouseTracking(true);
        lineEdit_4->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_4->setDragEnabled(false);
        lineEdit_4->setReadOnly(false);
        lineEdit_4->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_4->setClearButtonEnabled(true);

        horizontalLayout_9->addWidget(lineEdit_4);

        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setIcon(icon3);
        toolButton->setAutoRaise(true);

        horizontalLayout_9->addWidget(toolButton);


        verticalLayout_15->addLayout(horizontalLayout_9);


        horizontalLayout_6->addLayout(verticalLayout_15);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(-1, 24, 0, -1);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font2;
        font2.setPointSize(10);
        pushButton->setFont(font2);
        pushButton->setAutoDefault(false);

        verticalLayout_16->addWidget(pushButton);


        horizontalLayout_6->addLayout(verticalLayout_16);


        verticalLayout_18->addLayout(horizontalLayout_6);


        verticalLayout_11->addWidget(widget);

        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, -1, -1, 0);
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEnabled(true);
        tableView->setMaximumSize(QSize(8010, 2810));
        tableView->setSelectionMode(QAbstractItemView::NoSelection);
        tableView->setGridStyle(Qt::SolidLine);
        tableView->setSortingEnabled(false);

        horizontalLayout_10->addWidget(tableView);


        verticalLayout_11->addLayout(horizontalLayout_10);

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

        verticalLayout_10->addWidget(tabWidget);


        verticalLayout_9->addLayout(verticalLayout_10);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 870, 26));
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
        label_5->setText(QApplication::translate("MainWindow", "Num. ID", nullptr));
        lineEdit->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Nom du Patient", nullptr));
        lineEdit_2->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Prenom du Patient", nullptr));
        lineEdit_3->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Date de RDV (avant le)", nullptr));
        lineEdit_5->setInputMask(QString());
        lineEdit_5->setText(QString());
        toolButton_2->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Date de RDV (apr\303\250s le)", nullptr));
        lineEdit_4->setInputMask(QString());
        lineEdit_4->setText(QString());
        toolButton->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Rechercher", nullptr));
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
