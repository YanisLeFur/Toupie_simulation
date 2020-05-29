/********************************************************************************
** Form generated from reading UI file 'comparaison.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPARAISON_H
#define UI_COMPARAISON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Comparaison
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_psi;
    QPushButton *button_theta;
    QPushButton *button_phi;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_psi_point;
    QPushButton *button_theta_point;
    QPushButton *button_phi_point;
    QPushButton *button_clear;
    QCustomPlot *plot1;
    QCustomPlot *plot2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Comparaison)
    {
        if (Comparaison->objectName().isEmpty())
            Comparaison->setObjectName(QString::fromUtf8("Comparaison"));
        Comparaison->resize(800, 600);
        centralwidget = new QWidget(Comparaison);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 470, 801, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button_psi = new QPushButton(horizontalLayoutWidget);
        button_psi->setObjectName(QString::fromUtf8("button_psi"));

        horizontalLayout->addWidget(button_psi);

        button_theta = new QPushButton(horizontalLayoutWidget);
        button_theta->setObjectName(QString::fromUtf8("button_theta"));

        horizontalLayout->addWidget(button_theta);

        button_phi = new QPushButton(horizontalLayoutWidget);
        button_phi->setObjectName(QString::fromUtf8("button_phi"));

        horizontalLayout->addWidget(button_phi);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 510, 801, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        button_psi_point = new QPushButton(horizontalLayoutWidget_2);
        button_psi_point->setObjectName(QString::fromUtf8("button_psi_point"));

        horizontalLayout_2->addWidget(button_psi_point);

        button_theta_point = new QPushButton(horizontalLayoutWidget_2);
        button_theta_point->setObjectName(QString::fromUtf8("button_theta_point"));

        horizontalLayout_2->addWidget(button_theta_point);

        button_phi_point = new QPushButton(horizontalLayoutWidget_2);
        button_phi_point->setObjectName(QString::fromUtf8("button_phi_point"));

        horizontalLayout_2->addWidget(button_phi_point);

        button_clear = new QPushButton(horizontalLayoutWidget_2);
        button_clear->setObjectName(QString::fromUtf8("button_clear"));

        horizontalLayout_2->addWidget(button_clear);

        plot1 = new QCustomPlot(centralwidget);
        plot1->setObjectName(QString::fromUtf8("plot1"));
        plot1->setGeometry(QRect(0, 0, 391, 461));
        plot2 = new QCustomPlot(centralwidget);
        plot2->setObjectName(QString::fromUtf8("plot2"));
        plot2->setGeometry(QRect(410, 0, 391, 461));
        Comparaison->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Comparaison);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Comparaison->setMenuBar(menubar);
        statusbar = new QStatusBar(Comparaison);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Comparaison->setStatusBar(statusbar);

        retranslateUi(Comparaison);

        QMetaObject::connectSlotsByName(Comparaison);
    } // setupUi

    void retranslateUi(QMainWindow *Comparaison)
    {
        Comparaison->setWindowTitle(QCoreApplication::translate("Comparaison", "Comparaison", nullptr));
        button_psi->setText(QCoreApplication::translate("Comparaison", "psi", nullptr));
        button_theta->setText(QCoreApplication::translate("Comparaison", "theta", nullptr));
        button_phi->setText(QCoreApplication::translate("Comparaison", "phi", nullptr));
        button_psi_point->setText(QCoreApplication::translate("Comparaison", "psi_point", nullptr));
        button_theta_point->setText(QCoreApplication::translate("Comparaison", "theta_point", nullptr));
        button_phi_point->setText(QCoreApplication::translate("Comparaison", "phi_point", nullptr));
        button_clear->setText(QCoreApplication::translate("Comparaison", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Comparaison: public Ui_Comparaison {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPARAISON_H
