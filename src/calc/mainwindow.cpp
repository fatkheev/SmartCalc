

extern "C" {
    bool validate_string(const char* str);
    double calculate(const char* infixExpression);
}

#include <QFile>
#include <QTextStream>
#include "mainwindow.h"

#include "qcustomplot.h"
#include <cmath>
#include "qcustomplot.h"

#include "ui_mainwindow.h"

#include "creditcalculatorwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Для кнопки C
    connect(ui->CButton, &QPushButton::clicked, [=](){ ui->expr_input->clear(); });

    // Для кнопки (
    connect(ui->button_open_bracket, &QPushButton::clicked, [=](){ append_to_input("("); });

    // Для кнопки )
    connect(ui->button_close_bracket, &QPushButton::clicked, [=](){ append_to_input(")"); });

    // Для кнопки x
    connect(ui->button_x, &QPushButton::clicked, [=](){ append_to_input("x"); });

    // Для кнопки del
    connect(ui->button_del, &QPushButton::clicked, [=](){
        QString current_text = ui->expr_input->text();
        current_text.chop(1);  // Удалить последний символ
        ui->expr_input->setText(current_text);
    });


    // Кнопки цифр
    connect(ui->button_0, &QPushButton::clicked, [=](){ append_to_input("0"); });
    connect(ui->button_1, &QPushButton::clicked, [=](){ append_to_input("1"); });
    connect(ui->button_2, &QPushButton::clicked, [=](){ append_to_input("2"); });
    connect(ui->button_3, &QPushButton::clicked, [=](){ append_to_input("3"); });
    connect(ui->button_4, &QPushButton::clicked, [=](){ append_to_input("4"); });
    connect(ui->button_5, &QPushButton::clicked, [=](){ append_to_input("5"); });
    connect(ui->button_6, &QPushButton::clicked, [=](){ append_to_input("6"); });
    connect(ui->button_7, &QPushButton::clicked, [=](){ append_to_input("7"); });
    connect(ui->button_8, &QPushButton::clicked, [=](){ append_to_input("8"); });
    connect(ui->button_9, &QPushButton::clicked, [=](){ append_to_input("9"); });
    connect(ui->button_dot, &QPushButton::clicked, [=](){ append_to_input("."); });
    connect(ui->button_pow, &QPushButton::clicked, [=](){ append_to_input("^"); });

    // Операции
    connect(ui->button_add, &QPushButton::clicked, [=](){ append_to_input("+"); });
    connect(ui->button_subtract, &QPushButton::clicked, [=](){ append_to_input("-"); });
    connect(ui->button_multiply, &QPushButton::clicked, [=](){ append_to_input("*"); });
    connect(ui->button_divide, &QPushButton::clicked, [=](){ append_to_input("/"); });

    // Тригонометрия
    connect(ui->button_sin, &QPushButton::clicked, [=](){ append_to_input("sin("); });
    connect(ui->button_cos, &QPushButton::clicked, [=](){ append_to_input("cos("); });
    connect(ui->button_tan, &QPushButton::clicked, [=](){ append_to_input("tan("); });
    connect(ui->button_asin, &QPushButton::clicked, [=](){ append_to_input("asin("); });
    connect(ui->button_acos, &QPushButton::clicked, [=](){ append_to_input("acos("); });
    connect(ui->button_atan, &QPushButton::clicked, [=](){ append_to_input("atan("); });

    // Дополнительные функции
    connect(ui->button_sqrt, &QPushButton::clicked, [=](){ append_to_input("sqrt("); });
    connect(ui->button_ln, &QPushButton::clicked, [=](){ append_to_input("ln("); });
    connect(ui->button_log, &QPushButton::clicked, [=](){ append_to_input("log("); });
    connect(ui->button_mod, &QPushButton::clicked, [=](){ append_to_input("%"); });

    // Подключение кнопки График
    connect(ui->buttonPlot, &QPushButton::clicked, this, &MainWindow::plot_graph);
    //Подключение кнопки "="
    connect(ui->button_equals, &QPushButton::clicked, this, &MainWindow::calculate_expression);

    connect(ui->button_credit, &QPushButton::clicked, this, &MainWindow::openCreditCalculator);

}

// Это деструктор?
MainWindow::~MainWindow()
{
    delete ui;
}

// Поле ввода
void MainWindow::append_to_input(QString text) {
    QString current_text = ui->expr_input->text();
    QString new_text = current_text + text;
    ui->expr_input->setText(new_text);
}

// Подключение сишной функции калькулятора
void MainWindow::calculate_expression() {
    // Проверка на пустое поле ввода
    if (ui->expr_input->text().isEmpty()) {
        return;
    }

    QString xValue = ui->x_value_input->text();
    QString expression = replaceXWithValue(ui->expr_input->text(), xValue);

    if (validate_string(expression.toStdString().c_str())) {
        double result = calculate(expression.toStdString().c_str());
        ui->expr_input->setText(QString::number(result));
    } else {
        ui->expr_input->setText("Ошибка");
    }
}

// Функция отрисовки графика
void plotFunction(QCustomPlot *customPlot, const QString &function,
                  double xMin, double xMax, double yMin, double yMax) {
    // Подготовка данных
    QVector<double> x(401), y(401); // initialize with entries 0..400
    for (int i = 0; i < 401; ++i) {
        x[i] = xMin + (xMax - xMin) * i / 400.0;
        // Use the calculate function for y[i]
        QString current_expr = function;
        current_expr.replace("x", QString::number(x[i]));
        y[i] = calculate(current_expr.toStdString().c_str());
    }

    // создать график и присвоить ему данные:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);

    // установка области видисости графика
    customPlot->xAxis->setRange(xMin, xMax);
    customPlot->yAxis->setRange(yMin, yMax);
    customPlot->replot();
}

// Функция установки поля видимости
void MainWindow::plot_graph() {
    QString expression = ui->expr_input->text();
    double xMin = (ui->lineEdit_xMin->text().isEmpty()) ? -5.0 : ui->lineEdit_xMin->text().toDouble();
    double xMax = (ui->lineEdit_xMax->text().isEmpty()) ? 5.0 : ui->lineEdit_xMax->text().toDouble();
    double yMin = (ui->lineEdit_yMin->text().isEmpty()) ? -5.0 : ui->lineEdit_yMin->text().toDouble();
    double yMax = (ui->lineEdit_yMax->text().isEmpty()) ? 5.0 : ui->lineEdit_yMax->text().toDouble();

    plotFunction(ui->plotWidget, expression, xMin, xMax, yMin, yMax);
}

// Подмена значения X
QString MainWindow::replaceXWithValue(const QString &expression, const QString &xValue) {
    QString modifiedExpression = expression;
    modifiedExpression.replace("x", xValue);
    return modifiedExpression;
}

void MainWindow::openCreditCalculator() {
    this->hide();
    CreditCalculatorWindow *creditWindow = new CreditCalculatorWindow(this);
    connect(creditWindow, &CreditCalculatorWindow::switchToMainCalculator,
            this, &MainWindow::show);
    connect(creditWindow, &QObject::destroyed, this, &MainWindow::show);
    creditWindow->show();
}
