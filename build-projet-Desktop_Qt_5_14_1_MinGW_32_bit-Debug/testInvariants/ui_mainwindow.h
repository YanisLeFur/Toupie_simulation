/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *plot;
    QPushButton *Energie_button;
    QPushButton *Clear_Button;
    QPushButton *Prod_mixt_button_2;
    QPushButton *LA_a_button_3;
    QPushButton *LA_k_button;
    QPushButton *Scale_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(10, 20, 751, 471));
        Energie_button = new QPushButton(centralwidget);
        Energie_button->setObjectName(QString::fromUtf8("Energie_button"));
        Energie_button->setGeometry(QRect(140, 520, 101, 24));
        Clear_Button = new QPushButton(centralwidget);
        Clear_Button->setObjectName(QString::fromUtf8("Clear_Button"));
        Clear_Button->setGeometry(QRect(700, 520, 80, 24));
        Prod_mixt_button_2 = new QPushButton(centralwidget);
        Prod_mixt_button_2->setObjectName(QString::fromUtf8("Prod_mixt_button_2"));
        Prod_mixt_button_2->setGeometry(QRect(280, 520, 101, 24));
        LA_a_button_3 = new QPushButton(centralwidget);
        LA_a_button_3->setObjectName(QString::fromUtf8("LA_a_button_3"));
        LA_a_button_3->setGeometry(QRect(420, 520, 101, 24));
        LA_k_button = new QPushButton(centralwidget);
        LA_k_button->setObjectName(QString::fromUtf8("LA_k_button"));
        LA_k_button->setGeometry(QRect(560, 520, 101, 24));
        Scale_button = new QPushButton(centralwidget);
        Scale_button->setObjectName(QString::fromUtf8("Scale_button"));
        Scale_button->setGeometry(QRect(20, 520, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Energie_button->setText(QCoreApplication::translate("MainWindow", "Energie", nullptr));
        Clear_Button->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        Prod_mixt_button_2->setText(QCoreApplication::translate("MainWindow", "produit mixte", nullptr));
        LA_a_button_3->setText(QCoreApplication::translate("MainWindow", "LA_a", nullptr));
        LA_k_button->setText(QCoreApplication::translate("MainWindow", "LA_k", nullptr));
        Scale_button->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
