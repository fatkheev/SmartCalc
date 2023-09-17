

extern "C" {
    bool validate_string(const char* str);
    double calculate(const char* infixExpression);
}

#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "style.cpp"
#include "qcustomplot.h"
#include <cmath>
#include "qcustomplot.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAppStyles();

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

    // Операции
    connect(ui->button_add, &QPushButton::clicked, [=](){ append_to_input("+"); });
    connect(ui->button_subtract, &QPushButton::clicked, [=](){ append_to_input("-"); });
    connect(ui->button_multiply, &QPushButton::clicked, [=](){ append_to_input("*"); });
    connect(ui->button_divide, &QPushButton::clicked, [=](){ append_to_input("/"); });

    // Connect equals button to calculate_expression slot
    connect(ui->buttonPlot, &QPushButton::clicked, this, &MainWindow::plot_graph);
    connect(ui->button_equals, &QPushButton::clicked, this, &MainWindow::calculate_expression);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::append_to_input(QString text) {
    QString current_text = ui->expr_input->text();
    QString new_text = current_text + text;
    ui->expr_input->setText(new_text);
}

void MainWindow::calculate_expression() {
    QString expression = ui->expr_input->text();
    double result = calculate(expression.toStdString().c_str());
    ui->expr_input->setText(QString::number(result));
}



void plotFunction(QCustomPlot *customPlot, const QString &function,
                  double xMin, double xMax, double yMin, double yMax) {
    // Prepare data
    QVector<double> x(401), y(401); // initialize with entries 0..400
    for (int i = 0; i < 401; ++i) {
        x[i] = xMin + (xMax - xMin) * i / 400.0;
        // Use the calculate function for y[i]

QString current_expr = function;
current_expr.replace("x", QString::number(x[i]));
y[i] = calculate(current_expr.toStdString().c_str());

    }

    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);

    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(xMin, xMax);
    customPlot->yAxis->setRange(yMin, yMax);
    customPlot->replot();
}


void MainWindow::plot_graph() {
    QString expression = ui->expr_input->text();
    double xMin = ui->lineEdit_xMin->text().toDouble();
    double xMax = ui->lineEdit_xMax->text().toDouble();
    double yMin = ui->lineEdit_yMin->text().toDouble();
    double yMax = ui->lineEdit_yMax->text().toDouble();

    plotFunction(ui->plotWidget, expression, xMin, xMax, yMin, yMax);
}
