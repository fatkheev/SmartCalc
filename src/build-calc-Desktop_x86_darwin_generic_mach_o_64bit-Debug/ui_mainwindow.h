/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *leftLayout;
    QLineEdit *expr_input;
    QGridLayout *gridLayout;
    QPushButton *button_6;
    QPushButton *button_7;
    QPushButton *button_8;
    QPushButton *button_4;
    QPushButton *button_0;
    QPushButton *button_9;
    QPushButton *button_dot;
    QPushButton *button_add;
    QPushButton *button_5;
    QPushButton *button_1;
    QPushButton *button_multiply;
    QPushButton *button_equals;
    QPushButton *button_divide;
    QPushButton *button_3;
    QPushButton *button_2;
    QPushButton *button_subtract;
    QVBoxLayout *rightLayout;
    QPushButton *buttonPlot;
    QLineEdit *lineEdit_xMin;
    QLineEdit *lineEdit_xMax;
    QLineEdit *lineEdit_yMin;
    QLineEdit *lineEdit_yMax;
    QCustomPlot *plotWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(821, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftLayout = new QVBoxLayout();
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        expr_input = new QLineEdit(centralwidget);
        expr_input->setObjectName(QString::fromUtf8("expr_input"));

        leftLayout->addWidget(expr_input);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button_6 = new QPushButton(centralwidget);
        button_6->setObjectName(QString::fromUtf8("button_6"));

        gridLayout->addWidget(button_6, 1, 2, 1, 1);

        button_7 = new QPushButton(centralwidget);
        button_7->setObjectName(QString::fromUtf8("button_7"));

        gridLayout->addWidget(button_7, 0, 0, 1, 1);

        button_8 = new QPushButton(centralwidget);
        button_8->setObjectName(QString::fromUtf8("button_8"));

        gridLayout->addWidget(button_8, 0, 1, 1, 1);

        button_4 = new QPushButton(centralwidget);
        button_4->setObjectName(QString::fromUtf8("button_4"));

        gridLayout->addWidget(button_4, 1, 0, 1, 1);

        button_0 = new QPushButton(centralwidget);
        button_0->setObjectName(QString::fromUtf8("button_0"));

        gridLayout->addWidget(button_0, 3, 0, 1, 1);

        button_9 = new QPushButton(centralwidget);
        button_9->setObjectName(QString::fromUtf8("button_9"));

        gridLayout->addWidget(button_9, 0, 2, 1, 1);

        button_dot = new QPushButton(centralwidget);
        button_dot->setObjectName(QString::fromUtf8("button_dot"));

        gridLayout->addWidget(button_dot, 3, 1, 1, 1);

        button_add = new QPushButton(centralwidget);
        button_add->setObjectName(QString::fromUtf8("button_add"));

        gridLayout->addWidget(button_add, 3, 2, 1, 1);

        button_5 = new QPushButton(centralwidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));

        gridLayout->addWidget(button_5, 1, 1, 1, 1);

        button_1 = new QPushButton(centralwidget);
        button_1->setObjectName(QString::fromUtf8("button_1"));

        gridLayout->addWidget(button_1, 2, 0, 1, 1);

        button_multiply = new QPushButton(centralwidget);
        button_multiply->setObjectName(QString::fromUtf8("button_multiply"));

        gridLayout->addWidget(button_multiply, 1, 3, 1, 1);

        button_equals = new QPushButton(centralwidget);
        button_equals->setObjectName(QString::fromUtf8("button_equals"));

        gridLayout->addWidget(button_equals, 3, 3, 1, 1);

        button_divide = new QPushButton(centralwidget);
        button_divide->setObjectName(QString::fromUtf8("button_divide"));

        gridLayout->addWidget(button_divide, 0, 3, 1, 1);

        button_3 = new QPushButton(centralwidget);
        button_3->setObjectName(QString::fromUtf8("button_3"));

        gridLayout->addWidget(button_3, 2, 2, 1, 1);

        button_2 = new QPushButton(centralwidget);
        button_2->setObjectName(QString::fromUtf8("button_2"));

        gridLayout->addWidget(button_2, 2, 1, 1, 1);

        button_subtract = new QPushButton(centralwidget);
        button_subtract->setObjectName(QString::fromUtf8("button_subtract"));

        gridLayout->addWidget(button_subtract, 2, 3, 1, 1);


        leftLayout->addLayout(gridLayout);


        horizontalLayout->addLayout(leftLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setObjectName(QString::fromUtf8("rightLayout"));
        buttonPlot = new QPushButton(centralwidget);
        buttonPlot->setObjectName(QString::fromUtf8("buttonPlot"));

        rightLayout->addWidget(buttonPlot);

        lineEdit_xMin = new QLineEdit(centralwidget);
        lineEdit_xMin->setObjectName(QString::fromUtf8("lineEdit_xMin"));

        rightLayout->addWidget(lineEdit_xMin);

        lineEdit_xMax = new QLineEdit(centralwidget);
        lineEdit_xMax->setObjectName(QString::fromUtf8("lineEdit_xMax"));

        rightLayout->addWidget(lineEdit_xMax);

        lineEdit_yMin = new QLineEdit(centralwidget);
        lineEdit_yMin->setObjectName(QString::fromUtf8("lineEdit_yMin"));

        rightLayout->addWidget(lineEdit_yMin);

        lineEdit_yMax = new QLineEdit(centralwidget);
        lineEdit_yMax->setObjectName(QString::fromUtf8("lineEdit_yMax"));

        rightLayout->addWidget(lineEdit_yMax);

        plotWidget = new QCustomPlot(centralwidget);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));

        rightLayout->addWidget(plotWidget);


        horizontalLayout->addLayout(rightLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 821, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        button_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        button_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button_multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        button_equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        button_divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        button_subtract->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        buttonPlot->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        lineEdit_xMin->setPlaceholderText(QCoreApplication::translate("MainWindow", "xMin", nullptr));
        lineEdit_xMax->setPlaceholderText(QCoreApplication::translate("MainWindow", "xMax", nullptr));
        lineEdit_yMin->setPlaceholderText(QCoreApplication::translate("MainWindow", "yMin", nullptr));
        lineEdit_yMax->setPlaceholderText(QCoreApplication::translate("MainWindow", "yMax", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
