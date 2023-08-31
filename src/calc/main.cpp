#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QWidget>
#include <QSplitter>
#include <cmath>
#include "qcustomplot.h"

extern "C" {
bool validate_string(const char* str);
double calculate(const char* infixExpression);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Qt Калькулятор");
    mainWindow.resize(1200, 600);

    QWidget *mainWidget = new QWidget(&mainWindow);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);

    QSplitter *splitter = new QSplitter(Qt::Horizontal, mainWidget);

    QWidget *calculatorWidget = new QWidget(splitter);
    QVBoxLayout *calculatorLayout = new QVBoxLayout(calculatorWidget);

    QLineEdit *lineEdit = new QLineEdit(calculatorWidget);
    lineEdit->setPlaceholderText("Введите выражение");
    calculatorLayout->addWidget(lineEdit);

    auto closeParenthesisIfNeeded = [](QString expression) -> QString {
        int openCount = expression.count('(');
        int closeCount = expression.count(')');
        for (int i = 0; i < openCount - closeCount; i++) {
            expression.append(')');
        }
        return expression;
    };

    QGroupBox *basicBox = new QGroupBox("Основные операции");
    QGridLayout *basicLayout = new QGridLayout;
    QStringList basicButtons = {"7", "8", "9", "+",
                                "4", "5", "6", "-",
                                "1", "2", "3", "*",
                                "0", "C", "/", "="};

    for (int i = 0; i < basicButtons.size(); ++i) {
        QPushButton *btn = new QPushButton(basicButtons[i], calculatorWidget);
        basicLayout->addWidget(btn, i / 4, i % 4);
        QObject::connect(btn, &QPushButton::clicked, [lineEdit, btn, &closeParenthesisIfNeeded]() {
            if (btn->text() == "C") {
                lineEdit->clear();
            } else if (btn->text() == "=") {
                QString expression = closeParenthesisIfNeeded(lineEdit->text());

                if (!validate_string(expression.toStdString().c_str())) {
                    lineEdit->setText("Ошибка");
                    return;
                }

                try {
                    double result = calculate(expression.toStdString().c_str());
                    lineEdit->setText(QString::number(result));
                } catch (...) {
                    lineEdit->setText("Ошибка");
                }
            } else {
                lineEdit->insert(btn->text());
            }
        });
    }
    basicBox->setLayout(basicLayout);

    QGroupBox *trigBox = new QGroupBox("Тригонометрия");
    QGridLayout *trigLayout = new QGridLayout;
    QStringList trigButtons = {"sin", "cos", "tan",
                               "asin", "acos", "atan"};

    for (int i = 0; i < trigButtons.size(); ++i) {
        QPushButton *btn = new QPushButton(trigButtons[i], calculatorWidget);
        trigLayout->addWidget(btn, i / 3, i % 3);
        QObject::connect(btn, &QPushButton::clicked, [lineEdit, btn]() {
            lineEdit->insert(btn->text() + "(");
        });
    }
    trigBox->setLayout(trigLayout);

    QGroupBox *extraBox = new QGroupBox("Дополнительные функции");
    QVBoxLayout *extraLayout = new QVBoxLayout;
    QStringList extraButtons = {"sqrt", "ln", "log", "mod"};

    for (const QString &btnText : extraButtons) {
        QPushButton *btn = new QPushButton(btnText, calculatorWidget);
        extraLayout->addWidget(btn);
        QObject::connect(btn, &QPushButton::clicked, [lineEdit, btn]() {
            if(btn->text() == "mod") {
                lineEdit->insert(btn->text());
            } else {
                lineEdit->insert(btn->text() + "(");
            }
        });
    }
    extraBox->setLayout(extraLayout);

    calculatorLayout->addWidget(basicBox);
    calculatorLayout->addWidget(trigBox);
    calculatorLayout->addWidget(extraBox);

    calculatorWidget->setLayout(calculatorLayout);
    splitter->addWidget(calculatorWidget);

    QWidget *graphWidget = new QWidget(splitter);
    QVBoxLayout *graphLayout = new QVBoxLayout(graphWidget);

    QCustomPlot *plot = new QCustomPlot(graphWidget);
    QLineEdit *graphExpression = new QLineEdit(graphWidget);
    graphExpression->setPlaceholderText("Введите функцию для графика");
    QPushButton *plotButton = new QPushButton("График", graphWidget);

QObject::connect(plotButton, &QPushButton::clicked, [&]() {
    plot->clearGraphs();
    QString baseExpr = graphExpression->text();

    int numPoints = 2000;
    QVector<double> x(numPoints), y(numPoints);
    double step = (2 * M_PI) / numPoints;
    double tanLimit = 20.0;  // предельное значение для tan(x)

    QVector<QVector<double>> allXs, allYs;
    QVector<double> currentXs, currentYs;

    for(int i=0; i<numPoints; i++) {
        x[i] = i * step - 0.1 * M_PI;
        if (std::abs(x[i]) < 1e-15) {
            x[i] = 0.0;
        }

        QString currentExpr = baseExpr;
        currentExpr.replace("x", "%1");
        currentExpr = currentExpr.arg(x[i]);
        y[i] = calculate(currentExpr.toStdString().c_str());

        if (baseExpr.contains("tan", Qt::CaseInsensitive)) {
            if (y[i] > tanLimit) {
                y[i] = tanLimit;
                if (!currentXs.isEmpty()) {
                    allXs.append(currentXs);
                    allYs.append(currentYs);
                    currentXs.clear();
                    currentYs.clear();
                }
                continue;
            } else if (y[i] < -tanLimit) {
                y[i] = -tanLimit;
                if (!currentXs.isEmpty()) {
                    allXs.append(currentXs);
                    allYs.append(currentYs);
                    currentXs.clear();
                    currentYs.clear();
                }
                continue;
            }
        }

        currentXs.append(x[i]);
        currentYs.append(y[i]);
    }

    if (!currentXs.isEmpty()) {
        allXs.append(currentXs);
        allYs.append(currentYs);
    }

    for (int i = 0; i < allXs.size(); i++) {
        plot->addGraph();
        plot->graph(i)->setData(allXs[i], allYs[i]);
    }

    plot->xAxis->setRange(-10 * M_PI, 10 * M_PI);
    plot->yAxis->setRange(-2, 2);
    plot->rescaleAxes(true);
    plot->replot();
});

    graphLayout->addWidget(graphExpression);
    graphLayout->addWidget(plotButton);
    graphLayout->addWidget(plot);
    graphWidget->setLayout(graphLayout);
    splitter->addWidget(graphWidget);
    graphWidget->hide();

    mainLayout->addWidget(splitter);

    QPushButton *toggleGraphButton = new QPushButton("Построить график", mainWidget);
    mainLayout->addWidget(toggleGraphButton);

    QObject::connect(toggleGraphButton, &QPushButton::clicked, [&]() {
        if (graphWidget->isVisible()) {
            graphWidget->hide();
            toggleGraphButton->setText("Построить график");
        } else {
            graphWidget->show();
            toggleGraphButton->setText("Скрыть график");
        }
    });

    mainWidget->setLayout(mainLayout);
    mainWindow.setCentralWidget(mainWidget);
    mainWindow.show();

    return app.exec();
}
