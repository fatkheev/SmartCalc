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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QGroupBox *groupBox;
    QVBoxLayout *leftLayout;
    QLineEdit *expr_input;
    QLineEdit *x_value_input;
    QWidget *widget;
    QGridLayout *Digits_2;
    QPushButton *CButton;
    QPushButton *button_open_bracket;
    QPushButton *button_del;
    QPushButton *button_close_bracket;
    QPushButton *button_x;
    QWidget *widget1;
    QGridLayout *Digits;
    QPushButton *button_7;
    QPushButton *button_dot;
    QPushButton *button_add;
    QPushButton *button_8;
    QPushButton *button_0;
    QPushButton *button_9;
    QPushButton *button_pow;
    QPushButton *button_multiply;
    QPushButton *button_6;
    QPushButton *button_2;
    QPushButton *button_divide;
    QPushButton *button_5;
    QPushButton *button_4;
    QPushButton *button_1;
    QPushButton *button_3;
    QPushButton *button_subtract;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_equals;
    QGridLayout *More;
    QWidget *widget2;
    QGridLayout *gridLayout_10;
    QPushButton *button_atan;
    QPushButton *button_tan;
    QPushButton *button_sin;
    QPushButton *button_cos;
    QPushButton *button_asin;
    QPushButton *button_acos;
    QWidget *widget3;
    QGridLayout *gridLayout_11;
    QPushButton *button_mod;
    QPushButton *button_sqrt;
    QPushButton *button_ln;
    QPushButton *button_log;
    QPushButton *button_credit;
    QGroupBox *groupBox1;
    QVBoxLayout *Plotter;
    QPushButton *buttonPlot;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_yMin;
    QLineEdit *lineEdit_xMin;
    QLineEdit *lineEdit_xMax;
    QLineEdit *lineEdit_yMax;
    QCustomPlot *plotWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 797);
        MainWindow->setMinimumSize(QSize(600, 300));
        MainWindow->setMaximumSize(QSize(1200, 900));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(1400, 1000));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(360, 16777215));
        leftLayout = new QVBoxLayout(groupBox);
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        expr_input = new QLineEdit(groupBox);
        expr_input->setObjectName(QString::fromUtf8("expr_input"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(expr_input->sizePolicy().hasHeightForWidth());
        expr_input->setSizePolicy(sizePolicy);
        expr_input->setMinimumSize(QSize(0, 35));
        expr_input->setStyleSheet(QString::fromUtf8("color: black;\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #ededed;\n"
"selection-background-color: #eeeeee;"));

        leftLayout->addWidget(expr_input);

        x_value_input = new QLineEdit(groupBox);
        x_value_input->setObjectName(QString::fromUtf8("x_value_input"));
        x_value_input->setStyleSheet(QString::fromUtf8("color: black;\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #ededed;\n"
"selection-background-color: #eeeeee;"));

        leftLayout->addWidget(x_value_input);

        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0px;"));
        Digits_2 = new QGridLayout(widget);
        Digits_2->setObjectName(QString::fromUtf8("Digits_2"));
        Digits_2->setContentsMargins(10, 10, 10, 10);
        CButton = new QPushButton(widget);
        CButton->setObjectName(QString::fromUtf8("CButton"));
        CButton->setMinimumSize(QSize(0, 0));
        CButton->setMaximumSize(QSize(16777215, 40));
        CButton->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"\n"
"              border-radius: 20px;\n"
"              background-color: #fffdaa;\n"
"              padding: 10px;\n"
"              color: black;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #fffc8b;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #fffb66;\n"
"          }"));

        Digits_2->addWidget(CButton, 1, 0, 1, 4);

        button_open_bracket = new QPushButton(widget);
        button_open_bracket->setObjectName(QString::fromUtf8("button_open_bracket"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_open_bracket->sizePolicy().hasHeightForWidth());
        button_open_bracket->setSizePolicy(sizePolicy1);
        button_open_bracket->setMinimumSize(QSize(0, 0));
        button_open_bracket->setMaximumSize(QSize(16777215, 32));
        button_open_bracket->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 8px;\n"
"\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));
        button_open_bracket->setIconSize(QSize(16, 16));

        Digits_2->addWidget(button_open_bracket, 2, 0, 1, 1);

        button_del = new QPushButton(widget);
        button_del->setObjectName(QString::fromUtf8("button_del"));
        sizePolicy1.setHeightForWidth(button_del->sizePolicy().hasHeightForWidth());
        button_del->setSizePolicy(sizePolicy1);
        button_del->setMinimumSize(QSize(0, 0));
        button_del->setMaximumSize(QSize(16777215, 32));
        button_del->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 8px;\n"
"\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));
        button_del->setIconSize(QSize(16, 16));

        Digits_2->addWidget(button_del, 2, 3, 1, 1);

        button_close_bracket = new QPushButton(widget);
        button_close_bracket->setObjectName(QString::fromUtf8("button_close_bracket"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(button_close_bracket->sizePolicy().hasHeightForWidth());
        button_close_bracket->setSizePolicy(sizePolicy2);
        button_close_bracket->setMinimumSize(QSize(0, 0));
        button_close_bracket->setMaximumSize(QSize(74, 32));
        button_close_bracket->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 8px;\n"
"\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));
        button_close_bracket->setIconSize(QSize(16, 16));

        Digits_2->addWidget(button_close_bracket, 2, 1, 1, 1);

        button_x = new QPushButton(widget);
        button_x->setObjectName(QString::fromUtf8("button_x"));
        sizePolicy1.setHeightForWidth(button_x->sizePolicy().hasHeightForWidth());
        button_x->setSizePolicy(sizePolicy1);
        button_x->setMinimumSize(QSize(0, 0));
        button_x->setMaximumSize(QSize(74, 32));
        button_x->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 8px;\n"
"\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));
        button_x->setIconSize(QSize(16, 16));

        Digits_2->addWidget(button_x, 2, 2, 1, 1);


        leftLayout->addWidget(widget);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 0px;"));
        Digits = new QGridLayout(widget1);
        Digits->setObjectName(QString::fromUtf8("Digits"));
        Digits->setContentsMargins(10, 10, 10, 10);
        button_7 = new QPushButton(widget1);
        button_7->setObjectName(QString::fromUtf8("button_7"));
        sizePolicy2.setHeightForWidth(button_7->sizePolicy().hasHeightForWidth());
        button_7->setSizePolicy(sizePolicy2);
        button_7->setMinimumSize(QSize(54, 39));
        button_7->setMaximumSize(QSize(74, 25));
        button_7->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_7, 1, 0, 1, 1);

        button_dot = new QPushButton(widget1);
        button_dot->setObjectName(QString::fromUtf8("button_dot"));
        sizePolicy1.setHeightForWidth(button_dot->sizePolicy().hasHeightForWidth());
        button_dot->setSizePolicy(sizePolicy1);
        button_dot->setMinimumSize(QSize(54, 39));
        button_dot->setMaximumSize(QSize(16777215, 25));
        button_dot->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_dot, 5, 1, 1, 1);

        button_add = new QPushButton(widget1);
        button_add->setObjectName(QString::fromUtf8("button_add"));
        sizePolicy1.setHeightForWidth(button_add->sizePolicy().hasHeightForWidth());
        button_add->setSizePolicy(sizePolicy1);
        button_add->setMinimumSize(QSize(54, 39));
        button_add->setMaximumSize(QSize(16777215, 25));
        button_add->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        Digits->addWidget(button_add, 1, 3, 1, 1);

        button_8 = new QPushButton(widget1);
        button_8->setObjectName(QString::fromUtf8("button_8"));
        sizePolicy1.setHeightForWidth(button_8->sizePolicy().hasHeightForWidth());
        button_8->setSizePolicy(sizePolicy1);
        button_8->setMinimumSize(QSize(54, 39));
        button_8->setMaximumSize(QSize(74, 25));
        button_8->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_8, 1, 1, 1, 1);

        button_0 = new QPushButton(widget1);
        button_0->setObjectName(QString::fromUtf8("button_0"));
        sizePolicy1.setHeightForWidth(button_0->sizePolicy().hasHeightForWidth());
        button_0->setSizePolicy(sizePolicy1);
        button_0->setMinimumSize(QSize(54, 39));
        button_0->setMaximumSize(QSize(16777215, 25));
        button_0->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_0, 5, 0, 1, 1);

        button_9 = new QPushButton(widget1);
        button_9->setObjectName(QString::fromUtf8("button_9"));
        sizePolicy1.setHeightForWidth(button_9->sizePolicy().hasHeightForWidth());
        button_9->setSizePolicy(sizePolicy1);
        button_9->setMinimumSize(QSize(54, 39));
        button_9->setMaximumSize(QSize(16777215, 25));
        button_9->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_9, 1, 2, 1, 1);

        button_pow = new QPushButton(widget1);
        button_pow->setObjectName(QString::fromUtf8("button_pow"));
        sizePolicy1.setHeightForWidth(button_pow->sizePolicy().hasHeightForWidth());
        button_pow->setSizePolicy(sizePolicy1);
        button_pow->setMinimumSize(QSize(54, 39));
        button_pow->setMaximumSize(QSize(16777215, 25));
        button_pow->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        Digits->addWidget(button_pow, 5, 2, 1, 1);

        button_multiply = new QPushButton(widget1);
        button_multiply->setObjectName(QString::fromUtf8("button_multiply"));
        sizePolicy1.setHeightForWidth(button_multiply->sizePolicy().hasHeightForWidth());
        button_multiply->setSizePolicy(sizePolicy1);
        button_multiply->setMinimumSize(QSize(54, 39));
        button_multiply->setMaximumSize(QSize(16777215, 25));
        button_multiply->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        Digits->addWidget(button_multiply, 4, 3, 1, 1);

        button_6 = new QPushButton(widget1);
        button_6->setObjectName(QString::fromUtf8("button_6"));
        sizePolicy1.setHeightForWidth(button_6->sizePolicy().hasHeightForWidth());
        button_6->setSizePolicy(sizePolicy1);
        button_6->setMinimumSize(QSize(54, 39));
        button_6->setMaximumSize(QSize(16777215, 25));
        button_6->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_6, 2, 2, 1, 1);

        button_2 = new QPushButton(widget1);
        button_2->setObjectName(QString::fromUtf8("button_2"));
        sizePolicy1.setHeightForWidth(button_2->sizePolicy().hasHeightForWidth());
        button_2->setSizePolicy(sizePolicy1);
        button_2->setMinimumSize(QSize(54, 39));
        button_2->setMaximumSize(QSize(16777215, 25));
        button_2->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_2, 4, 1, 1, 1);

        button_divide = new QPushButton(widget1);
        button_divide->setObjectName(QString::fromUtf8("button_divide"));
        sizePolicy1.setHeightForWidth(button_divide->sizePolicy().hasHeightForWidth());
        button_divide->setSizePolicy(sizePolicy1);
        button_divide->setMinimumSize(QSize(54, 39));
        button_divide->setMaximumSize(QSize(16777215, 25));
        button_divide->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        Digits->addWidget(button_divide, 5, 3, 1, 1);

        button_5 = new QPushButton(widget1);
        button_5->setObjectName(QString::fromUtf8("button_5"));
        sizePolicy1.setHeightForWidth(button_5->sizePolicy().hasHeightForWidth());
        button_5->setSizePolicy(sizePolicy1);
        button_5->setMinimumSize(QSize(54, 39));
        button_5->setMaximumSize(QSize(16777215, 25));
        button_5->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_5, 2, 1, 1, 1);

        button_4 = new QPushButton(widget1);
        button_4->setObjectName(QString::fromUtf8("button_4"));
        sizePolicy1.setHeightForWidth(button_4->sizePolicy().hasHeightForWidth());
        button_4->setSizePolicy(sizePolicy1);
        button_4->setMinimumSize(QSize(54, 39));
        button_4->setMaximumSize(QSize(16777215, 25));
        button_4->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_4, 2, 0, 1, 1);

        button_1 = new QPushButton(widget1);
        button_1->setObjectName(QString::fromUtf8("button_1"));
        sizePolicy1.setHeightForWidth(button_1->sizePolicy().hasHeightForWidth());
        button_1->setSizePolicy(sizePolicy1);
        button_1->setMinimumSize(QSize(54, 39));
        button_1->setMaximumSize(QSize(16777215, 25));
        button_1->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_1, 4, 0, 1, 1);

        button_3 = new QPushButton(widget1);
        button_3->setObjectName(QString::fromUtf8("button_3"));
        sizePolicy1.setHeightForWidth(button_3->sizePolicy().hasHeightForWidth());
        button_3->setSizePolicy(sizePolicy1);
        button_3->setMinimumSize(QSize(54, 39));
        button_3->setMaximumSize(QSize(16777215, 25));
        button_3->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 15px;\n"
"              background-color: #3c4043;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #55595d;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #696f73;\n"
"          }"));

        Digits->addWidget(button_3, 4, 2, 1, 1);

        button_subtract = new QPushButton(widget1);
        button_subtract->setObjectName(QString::fromUtf8("button_subtract"));
        sizePolicy1.setHeightForWidth(button_subtract->sizePolicy().hasHeightForWidth());
        button_subtract->setSizePolicy(sizePolicy1);
        button_subtract->setMinimumSize(QSize(54, 39));
        button_subtract->setMaximumSize(QSize(16777215, 25));
        button_subtract->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        Digits->addWidget(button_subtract, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Digits->addItem(horizontalSpacer, 7, 0, 1, 4);

        button_equals = new QPushButton(widget1);
        button_equals->setObjectName(QString::fromUtf8("button_equals"));
        button_equals->setMinimumSize(QSize(64, 44));
        button_equals->setMaximumSize(QSize(16777215, 25));
        button_equals->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 18px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 20px;\n"
"              background-color: #8fffa1;\n"
"              padding: 10px;\n"
"              color: black;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #aaffb7;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #b8ffc3;\n"
"          }"));

        Digits->addWidget(button_equals, 6, 0, 1, 4);


        leftLayout->addWidget(widget1);

        More = new QGridLayout();
        More->setObjectName(QString::fromUtf8("More"));
        widget2 = new QWidget(groupBox);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 10px;"));
        gridLayout_10 = new QGridLayout(widget2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(10, 10, 10, 10);
        button_atan = new QPushButton(widget2);
        button_atan->setObjectName(QString::fromUtf8("button_atan"));
        button_atan->setMinimumSize(QSize(54, 34));
        button_atan->setMaximumSize(QSize(16777215, 30));
        button_atan->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_10->addWidget(button_atan, 1, 2, 1, 1);

        button_tan = new QPushButton(widget2);
        button_tan->setObjectName(QString::fromUtf8("button_tan"));
        button_tan->setMinimumSize(QSize(54, 34));
        button_tan->setMaximumSize(QSize(16777215, 30));
        button_tan->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_10->addWidget(button_tan, 0, 2, 1, 1);

        button_sin = new QPushButton(widget2);
        button_sin->setObjectName(QString::fromUtf8("button_sin"));
        button_sin->setMinimumSize(QSize(54, 34));
        button_sin->setMaximumSize(QSize(16777215, 30));
        button_sin->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_10->addWidget(button_sin, 0, 0, 1, 1);

        button_cos = new QPushButton(widget2);
        button_cos->setObjectName(QString::fromUtf8("button_cos"));
        button_cos->setMinimumSize(QSize(54, 34));
        button_cos->setMaximumSize(QSize(16777215, 30));
        button_cos->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_10->addWidget(button_cos, 0, 1, 1, 1);

        button_asin = new QPushButton(widget2);
        button_asin->setObjectName(QString::fromUtf8("button_asin"));
        button_asin->setMinimumSize(QSize(54, 34));
        button_asin->setMaximumSize(QSize(16777215, 30));
        button_asin->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_10->addWidget(button_asin, 1, 0, 1, 1);

        button_acos = new QPushButton(widget2);
        button_acos->setObjectName(QString::fromUtf8("button_acos"));
        button_acos->setMinimumSize(QSize(54, 34));
        button_acos->setMaximumSize(QSize(16777215, 30));
        button_acos->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_10->addWidget(button_acos, 1, 1, 1, 1);


        More->addWidget(widget2, 0, 0, 1, 1);

        widget3 = new QWidget(groupBox);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget3->sizePolicy().hasHeightForWidth());
        widget3->setSizePolicy(sizePolicy3);
        widget3->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 10px;"));
        gridLayout_11 = new QGridLayout(widget3);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_11->setContentsMargins(10, 10, 10, 10);
        button_mod = new QPushButton(widget3);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(button_mod);
        button_mod->setObjectName(QString::fromUtf8("button_mod"));
        sizePolicy3.setHeightForWidth(button_mod->sizePolicy().hasHeightForWidth());
        button_mod->setSizePolicy(sizePolicy3);
        button_mod->setMinimumSize(QSize(54, 34));
        button_mod->setMaximumSize(QSize(16777215, 30));
        button_mod->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_11->addWidget(button_mod, 0, 0, 1, 1);

        button_sqrt = new QPushButton(widget3);
        buttonGroup->addButton(button_sqrt);
        button_sqrt->setObjectName(QString::fromUtf8("button_sqrt"));
        sizePolicy3.setHeightForWidth(button_sqrt->sizePolicy().hasHeightForWidth());
        button_sqrt->setSizePolicy(sizePolicy3);
        button_sqrt->setMinimumSize(QSize(54, 34));
        button_sqrt->setMaximumSize(QSize(16777215, 30));
        button_sqrt->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_11->addWidget(button_sqrt, 0, 1, 1, 1);

        button_ln = new QPushButton(widget3);
        buttonGroup->addButton(button_ln);
        button_ln->setObjectName(QString::fromUtf8("button_ln"));
        sizePolicy3.setHeightForWidth(button_ln->sizePolicy().hasHeightForWidth());
        button_ln->setSizePolicy(sizePolicy3);
        button_ln->setMinimumSize(QSize(54, 34));
        button_ln->setMaximumSize(QSize(16777215, 30));
        button_ln->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_11->addWidget(button_ln, 1, 0, 1, 1);

        button_log = new QPushButton(widget3);
        buttonGroup->addButton(button_log);
        button_log->setObjectName(QString::fromUtf8("button_log"));
        sizePolicy3.setHeightForWidth(button_log->sizePolicy().hasHeightForWidth());
        button_log->setSizePolicy(sizePolicy3);
        button_log->setMinimumSize(QSize(54, 34));
        button_log->setMaximumSize(QSize(16777215, 30));
        button_log->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 10px;\n"
"              min-width: 30px;\n"
"              min-height: 10px;\n"
"              border-radius: 10px;\n"
"              background-color: #5f6368;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #74797f;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #898d93;\n"
"          }"));

        gridLayout_11->addWidget(button_log, 1, 1, 1, 1);


        More->addWidget(widget3, 1, 0, 1, 1);


        leftLayout->addLayout(More);

        button_credit = new QPushButton(groupBox);
        buttonGroup->addButton(button_credit);
        button_credit->setObjectName(QString::fromUtf8("button_credit"));
        sizePolicy3.setHeightForWidth(button_credit->sizePolicy().hasHeightForWidth());
        button_credit->setSizePolicy(sizePolicy3);
        button_credit->setMinimumSize(QSize(50, 35));
        button_credit->setMaximumSize(QSize(16777215, 30));
        button_credit->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 30px;\n"
"              min-height: 15px;\n"
"              border-radius: 10px;\n"
"              background-color: #5684be;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #4072b0;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #376399;\n"
"          }"));

        leftLayout->addWidget(button_credit);


        horizontalLayout->addWidget(groupBox);

        groupBox1 = new QGroupBox(centralwidget);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        Plotter = new QVBoxLayout(groupBox1);
        Plotter->setObjectName(QString::fromUtf8("Plotter"));
        buttonPlot = new QPushButton(groupBox1);
        buttonPlot->setObjectName(QString::fromUtf8("buttonPlot"));
        buttonPlot->setMinimumSize(QSize(60, 40));
        buttonPlot->setMaximumSize(QSize(16777215, 30));
        buttonPlot->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"              font-size: 12px;\n"
"              min-width: 40px;\n"
"              min-height: 20px;\n"
"              border-radius: 15px;\n"
"              background-color: #949494;\n"
"              padding: 10px;\n"
"              color: white;\n"
"margin: 0px 0px 0px 0px\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #a2a2a2;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #b7b7b7;\n"
"          }"));

        Plotter->addWidget(buttonPlot);

        gridWidget = new QWidget(groupBox1);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setMaximumSize(QSize(16777215, 80));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_yMin = new QLineEdit(gridWidget);
        lineEdit_yMin->setObjectName(QString::fromUtf8("lineEdit_yMin"));
        lineEdit_yMin->setStyleSheet(QString::fromUtf8("color: black;\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #ededed;\n"
"selection-background-color: #eeeeee;"));

        gridLayout->addWidget(lineEdit_yMin, 0, 1, 1, 1);

        lineEdit_xMin = new QLineEdit(gridWidget);
        lineEdit_xMin->setObjectName(QString::fromUtf8("lineEdit_xMin"));
        lineEdit_xMin->setStyleSheet(QString::fromUtf8("color: black;\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #ededed;\n"
"selection-background-color: #eeeeee;"));

        gridLayout->addWidget(lineEdit_xMin, 0, 0, 1, 1);

        lineEdit_xMax = new QLineEdit(gridWidget);
        lineEdit_xMax->setObjectName(QString::fromUtf8("lineEdit_xMax"));
        lineEdit_xMax->setStyleSheet(QString::fromUtf8("color: black;\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #ededed;\n"
"selection-background-color: #eeeeee;"));

        gridLayout->addWidget(lineEdit_xMax, 1, 0, 1, 1);

        lineEdit_yMax = new QLineEdit(gridWidget);
        lineEdit_yMax->setObjectName(QString::fromUtf8("lineEdit_yMax"));
        lineEdit_yMax->setStyleSheet(QString::fromUtf8("color: black;\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #ededed;\n"
"selection-background-color: #eeeeee;"));

        gridLayout->addWidget(lineEdit_yMax, 1, 1, 1, 1);


        Plotter->addWidget(gridWidget);

        plotWidget = new QCustomPlot(groupBox1);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));

        Plotter->addWidget(plotWidget);


        horizontalLayout->addWidget(groupBox1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MathosHa Calculator", nullptr));
        expr_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        x_value_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 X", nullptr));
        CButton->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        button_open_bracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        button_del->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        button_close_bracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        button_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        button_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        button_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        button_multiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        button_divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button_subtract->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        button_equals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        button_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        button_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        button_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        button_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        button_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        button_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        button_mod->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272 \320\276\321\202 \320\264\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        button_sqrt->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202\320\275\321\213\320\271 \320\272\320\276\321\200\320\265\320\275\321\214", nullptr));
        button_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        button_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        button_credit->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        buttonPlot->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        lineEdit_yMin->setPlaceholderText(QCoreApplication::translate("MainWindow", "yMin", nullptr));
        lineEdit_xMin->setPlaceholderText(QCoreApplication::translate("MainWindow", "xMin", nullptr));
        lineEdit_xMax->setPlaceholderText(QCoreApplication::translate("MainWindow", "xMax", nullptr));
        lineEdit_yMax->setPlaceholderText(QCoreApplication::translate("MainWindow", "yMax", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
