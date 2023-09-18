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
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *leftLayout;
    QLineEdit *expr_input;
    QLineEdit *x_value_input;
    QGridLayout *Operations;
    QPushButton *button_x;
    QPushButton *button_open_bracket;
    QPushButton *button_del;
    QPushButton *button_close_bracket;
    QPushButton *CButton;
    QGridLayout *Digits;
    QPushButton *button_add;
    QPushButton *button_1;
    QPushButton *button_5;
    QPushButton *button_8;
    QPushButton *button_3;
    QPushButton *button_subtract;
    QPushButton *button_4;
    QPushButton *button_2;
    QPushButton *button_6;
    QPushButton *button_equals;
    QPushButton *button_9;
    QPushButton *button_7;
    QPushButton *button_0;
    QPushButton *button_dot;
    QPushButton *button_multiply;
    QPushButton *button_divide;
    QPushButton *button_pow;
    QGridLayout *More;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_11;
    QPushButton *button_ln;
    QPushButton *button_credit;
    QPushButton *button_sqrt;
    QPushButton *button_log;
    QPushButton *button_mod;
    QGridLayout *gridLayout_10;
    QPushButton *button_sin;
    QPushButton *button_acos;
    QPushButton *button_atan;
    QPushButton *button_asin;
    QPushButton *button_tan;
    QPushButton *button_cos;
    QGridLayout *gridLayout_7;
    QVBoxLayout *Plotter;
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
        MainWindow->resize(1450, 1102);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftLayout = new QVBoxLayout();
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        expr_input = new QLineEdit(centralwidget);
        expr_input->setObjectName(QString::fromUtf8("expr_input"));

        leftLayout->addWidget(expr_input);

        x_value_input = new QLineEdit(centralwidget);
        x_value_input->setObjectName(QString::fromUtf8("x_value_input"));

        leftLayout->addWidget(x_value_input);

        Operations = new QGridLayout();
        Operations->setObjectName(QString::fromUtf8("Operations"));
        Operations->setContentsMargins(0, 0, -1, 100);
        button_x = new QPushButton(centralwidget);
        button_x->setObjectName(QString::fromUtf8("button_x"));
        button_x->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Operations->addWidget(button_x, 1, 2, 1, 1);

        button_open_bracket = new QPushButton(centralwidget);
        button_open_bracket->setObjectName(QString::fromUtf8("button_open_bracket"));
        button_open_bracket->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Operations->addWidget(button_open_bracket, 1, 0, 1, 1);

        button_del = new QPushButton(centralwidget);
        button_del->setObjectName(QString::fromUtf8("button_del"));
        button_del->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Operations->addWidget(button_del, 1, 3, 1, 1);

        button_close_bracket = new QPushButton(centralwidget);
        button_close_bracket->setObjectName(QString::fromUtf8("button_close_bracket"));
        button_close_bracket->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Operations->addWidget(button_close_bracket, 1, 1, 1, 1);

        CButton = new QPushButton(centralwidget);
        CButton->setObjectName(QString::fromUtf8("CButton"));
        CButton->setEnabled(true);
        CButton->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Operations->addWidget(CButton, 0, 0, 1, 4);


        leftLayout->addLayout(Operations);

        Digits = new QGridLayout();
        Digits->setObjectName(QString::fromUtf8("Digits"));
        button_add = new QPushButton(centralwidget);
        button_add->setObjectName(QString::fromUtf8("button_add"));
        button_add->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_add, 0, 3, 1, 1);

        button_1 = new QPushButton(centralwidget);
        button_1->setObjectName(QString::fromUtf8("button_1"));
        button_1->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_1, 3, 0, 1, 1);

        button_5 = new QPushButton(centralwidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));
        button_5->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_5, 1, 1, 1, 1);

        button_8 = new QPushButton(centralwidget);
        button_8->setObjectName(QString::fromUtf8("button_8"));
        button_8->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_8, 0, 1, 1, 1);

        button_3 = new QPushButton(centralwidget);
        button_3->setObjectName(QString::fromUtf8("button_3"));
        button_3->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_3, 3, 2, 1, 1);

        button_subtract = new QPushButton(centralwidget);
        button_subtract->setObjectName(QString::fromUtf8("button_subtract"));
        button_subtract->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_subtract, 1, 3, 1, 1);

        button_4 = new QPushButton(centralwidget);
        button_4->setObjectName(QString::fromUtf8("button_4"));
        button_4->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_4, 1, 0, 1, 1);

        button_2 = new QPushButton(centralwidget);
        button_2->setObjectName(QString::fromUtf8("button_2"));
        button_2->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_2, 3, 1, 1, 1);

        button_6 = new QPushButton(centralwidget);
        button_6->setObjectName(QString::fromUtf8("button_6"));
        button_6->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_6, 1, 2, 1, 1);

        button_equals = new QPushButton(centralwidget);
        button_equals->setObjectName(QString::fromUtf8("button_equals"));
        button_equals->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_equals, 5, 0, 1, 4);

        button_9 = new QPushButton(centralwidget);
        button_9->setObjectName(QString::fromUtf8("button_9"));
        button_9->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_9, 0, 2, 1, 1);

        button_7 = new QPushButton(centralwidget);
        button_7->setObjectName(QString::fromUtf8("button_7"));
        button_7->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_7, 0, 0, 1, 1);

        button_0 = new QPushButton(centralwidget);
        button_0->setObjectName(QString::fromUtf8("button_0"));
        button_0->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_0, 4, 0, 1, 1);

        button_dot = new QPushButton(centralwidget);
        button_dot->setObjectName(QString::fromUtf8("button_dot"));
        button_dot->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_dot, 4, 1, 1, 1);

        button_multiply = new QPushButton(centralwidget);
        button_multiply->setObjectName(QString::fromUtf8("button_multiply"));
        button_multiply->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_multiply, 3, 3, 1, 1);

        button_divide = new QPushButton(centralwidget);
        button_divide->setObjectName(QString::fromUtf8("button_divide"));
        button_divide->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_divide, 4, 3, 1, 1);

        button_pow = new QPushButton(centralwidget);
        button_pow->setObjectName(QString::fromUtf8("button_pow"));
        button_pow->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 40px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        Digits->addWidget(button_pow, 4, 2, 1, 1);


        leftLayout->addLayout(Digits);

        More = new QGridLayout();
        More->setObjectName(QString::fromUtf8("More"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));

        More->addLayout(gridLayout_9, 2, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        button_ln = new QPushButton(centralwidget);
        button_ln->setObjectName(QString::fromUtf8("button_ln"));
        button_ln->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_11->addWidget(button_ln, 1, 0, 1, 2);

        button_credit = new QPushButton(centralwidget);
        button_credit->setObjectName(QString::fromUtf8("button_credit"));
        button_credit->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_11->addWidget(button_credit, 4, 0, 1, 2);

        button_sqrt = new QPushButton(centralwidget);
        button_sqrt->setObjectName(QString::fromUtf8("button_sqrt"));
        button_sqrt->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_11->addWidget(button_sqrt, 0, 0, 1, 2);

        button_log = new QPushButton(centralwidget);
        button_log->setObjectName(QString::fromUtf8("button_log"));
        button_log->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_11->addWidget(button_log, 2, 0, 1, 2);

        button_mod = new QPushButton(centralwidget);
        button_mod->setObjectName(QString::fromUtf8("button_mod"));
        button_mod->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_11->addWidget(button_mod, 3, 0, 1, 2);


        More->addLayout(gridLayout_11, 3, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, 0, -1, 0);
        button_sin = new QPushButton(centralwidget);
        button_sin->setObjectName(QString::fromUtf8("button_sin"));
        button_sin->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_10->addWidget(button_sin, 0, 0, 1, 1);

        button_acos = new QPushButton(centralwidget);
        button_acos->setObjectName(QString::fromUtf8("button_acos"));
        button_acos->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_10->addWidget(button_acos, 1, 1, 1, 1);

        button_atan = new QPushButton(centralwidget);
        button_atan->setObjectName(QString::fromUtf8("button_atan"));
        button_atan->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_10->addWidget(button_atan, 1, 2, 1, 1);

        button_asin = new QPushButton(centralwidget);
        button_asin->setObjectName(QString::fromUtf8("button_asin"));
        button_asin->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_10->addWidget(button_asin, 1, 0, 1, 1);

        button_tan = new QPushButton(centralwidget);
        button_tan->setObjectName(QString::fromUtf8("button_tan"));
        button_tan->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_10->addWidget(button_tan, 0, 2, 1, 1);

        button_cos = new QPushButton(centralwidget);
        button_cos->setObjectName(QString::fromUtf8("button_cos"));
        button_cos->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #f0f0f0;\n"
"              padding: 10px;\n"
"              color: black;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #e0e0e0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #d0d0d0;\n"
"          }"));

        gridLayout_10->addWidget(button_cos, 0, 1, 1, 1);


        More->addLayout(gridLayout_10, 1, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));

        More->addLayout(gridLayout_7, 0, 0, 1, 1);


        leftLayout->addLayout(More);


        horizontalLayout->addLayout(leftLayout);

        Plotter = new QVBoxLayout();
        Plotter->setObjectName(QString::fromUtf8("Plotter"));
        buttonPlot = new QPushButton(centralwidget);
        buttonPlot->setObjectName(QString::fromUtf8("buttonPlot"));

        Plotter->addWidget(buttonPlot);

        lineEdit_xMin = new QLineEdit(centralwidget);
        lineEdit_xMin->setObjectName(QString::fromUtf8("lineEdit_xMin"));

        Plotter->addWidget(lineEdit_xMin);

        lineEdit_xMax = new QLineEdit(centralwidget);
        lineEdit_xMax->setObjectName(QString::fromUtf8("lineEdit_xMax"));

        Plotter->addWidget(lineEdit_xMax);

        lineEdit_yMin = new QLineEdit(centralwidget);
        lineEdit_yMin->setObjectName(QString::fromUtf8("lineEdit_yMin"));

        Plotter->addWidget(lineEdit_yMin);

        lineEdit_yMax = new QLineEdit(centralwidget);
        lineEdit_yMax->setObjectName(QString::fromUtf8("lineEdit_yMax"));

        Plotter->addWidget(lineEdit_yMax);

        plotWidget = new QCustomPlot(centralwidget);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));

        Plotter->addWidget(plotWidget);


        horizontalLayout->addLayout(Plotter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1450, 24));
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
        x_value_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "x=", nullptr));
        button_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        button_open_bracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        button_del->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        button_close_bracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        CButton->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        button_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button_subtract->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button_equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        button_multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        button_divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        button_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        button_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        button_credit->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        button_sqrt->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202\320\275\321\213\320\271 \320\272\320\276\321\200\320\265\320\275\321\214", nullptr));
        button_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        button_mod->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272 \320\276\321\202 \320\264\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        button_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        button_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        button_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        button_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        button_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        button_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
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
