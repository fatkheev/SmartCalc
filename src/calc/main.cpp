#include "qcustomplot.h"
#include "creditcalculatorwindow.h"
#include "mainwindow.h"
#include "style.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

//    QGroupBox *basicBox = new QGroupBox("Основная панель");
//    QGridLayout *basicLayout = new QGridLayout;

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Qt Калькулятор");
    mainWindow.resize(1200, 600);

    QWidget *mainWidget = new QWidget(&mainWindow);
    mainWidget->setStyleSheet(mainWidgetStyle);  // Задаем стиль
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);

    QSplitter *splitter = new QSplitter(Qt::Horizontal, mainWidget);

    QWidget *calculatorWidget = new QWidget(splitter);
    QVBoxLayout *calculatorLayout = new QVBoxLayout(calculatorWidget);

    QLineEdit *lineEdit = new QLineEdit(calculatorWidget);
    lineEdit->setStyleSheet(lineEditStyle);
    lineEdit->setPlaceholderText("Введите выражение");
    QLineEdit *xValueLineEdit = new QLineEdit(calculatorWidget);
    xValueLineEdit->setStyleSheet(lineEditStyle);
    xValueLineEdit->setPlaceholderText("x =");

    calculatorLayout->addWidget(lineEdit);
    calculatorLayout->addWidget(xValueLineEdit);

    QObject::connect(lineEdit, &QLineEdit::textChanged, [lineEdit]() {
        if (lineEdit->text().length() > 255) {
            lineEdit->setText("Ошибка: превышен лимит символов");
        }
    });

    auto closeParenthesisIfNeeded = [](QString expression) -> QString {
        int openCount = expression.count('(');
        int closeCount = expression.count(')');
        for (int i = 0; i < openCount - closeCount; i++) {
            expression.append(')');
        }
        return expression;
    };

    auto calculatorButtonClicked = [lineEdit, xValueLineEdit, &closeParenthesisIfNeeded](QPushButton *btn) {
            if (btn->text() == "C") {
                lineEdit->clear();
            } else if (btn->text() == "=") {
                if (lineEdit->text().isEmpty()) {
                    return;
                }
                QString expression = closeParenthesisIfNeeded(lineEdit->text());

                if (!xValueLineEdit->text().isEmpty()) {
                    QString xValue = xValueLineEdit->text();
                    expression.replace("x", xValue);
                }

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
            } else if (btn->text() == "<") {
                QString currentText = lineEdit->text();
                currentText.chop(1);  // Удаление последнего символа
                lineEdit->setText(currentText);
            } else {
                lineEdit->insert(btn->text());
            }

    };

    QGroupBox *upperBox = new QGroupBox("Верхняя панель");
    QGroupBox *lowerBox = new QGroupBox("Нижняя панель");
    upperBox->setStyleSheet("QGroupBox { border: 2px solid gray; border-radius: 9px; }");
    lowerBox->setStyleSheet("QGroupBox { border: 2px solid gray; border-radius: 9px; }");

    QGridLayout *upperLayout = new QGridLayout;
    QGridLayout *lowerLayout = new QGridLayout;
    upperLayout->setContentsMargins(10, 30, 10, 10);  // left, top, right, bottom
    lowerLayout->setContentsMargins(10, 30, 10, 10);  // left, top, right, bottom


    QStringList upperButtons = {"C", "x", "^", "<", "(", ")"};
    QStringList lowerButtons = {"7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "*", "=", "0", "."};

    for (int i = 0; i < upperButtons.size(); ++i) {
        QPushButton *btn = new QPushButton(upperButtons[i], calculatorWidget);
        btn->setStyleSheet(smallerButtonStyle);
        if (upperButtons[i] == "C") {
            btn->setStyleSheet(smallerButtonYellow);
        } else {
            btn->setStyleSheet(smallerButtonStyle);
        }
        upperLayout->addWidget(btn, i / 4, i % 4);
        QObject::connect(btn, &QPushButton::clicked, [btn, &calculatorButtonClicked](){ calculatorButtonClicked(btn); });
    }

    for (int i = 0; i < lowerButtons.size(); ++i) {
        QPushButton *btn = new QPushButton(lowerButtons[i], calculatorWidget);
        if (lowerButtons[i] == "=") {
            btn->setStyleSheet(buttonStyleGreen);
        } else {
            btn->setStyleSheet(otherButtonStyle);
        }
        lowerLayout->addWidget(btn, i / 4, i % 4);
        QObject::connect(btn, &QPushButton::clicked, [btn, &calculatorButtonClicked](){ calculatorButtonClicked(btn); });
    }

    upperBox->setLayout(upperLayout);
    lowerBox->setLayout(lowerLayout);

    calculatorLayout->addWidget(upperBox);
    calculatorLayout->addWidget(lowerBox);

//    basicBox->setLayout(basicLayout);

    QGroupBox *trigBox = new QGroupBox("Тригонометрия");
    QGridLayout *trigLayout = new QGridLayout;
    trigBox->setStyleSheet("QGroupBox { border: 2px solid gray; border-radius: 9px; }");
    trigLayout->setContentsMargins(10, 30, 10, 10);
    QStringList trigButtons = {"sin", "cos", "tan",
                               "asin", "acos", "atan"};

    for (int i = 0; i < trigButtons.size(); ++i) {
        QPushButton *btn = new QPushButton(trigButtons[i], calculatorWidget);
        btn->setStyleSheet(smallerButtonStyle);
        trigLayout->addWidget(btn, i / 3, i % 3);
        QObject::connect(btn, &QPushButton::clicked, [lineEdit, btn]() {
            lineEdit->insert(btn->text() + "(");
        });
    }
    trigBox->setLayout(trigLayout);

    QGroupBox *extraBox = new QGroupBox("Дополнительные функции");
    QVBoxLayout *extraLayout = new QVBoxLayout;
    extraBox->setStyleSheet("QGroupBox { border: 2px solid gray; border-radius: 9px; }");
    extraLayout->setContentsMargins(10, 30, 10, 10);
    QStringList extraButtons = {"sqrt", "ln", "log", "mod"};

    for (const QString &btnText : extraButtons) {
        QPushButton *btn = new QPushButton(btnText, calculatorWidget);
        btn->setStyleSheet(smallerButtonStyle);
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

//    calculatorLayout->addWidget(basicBox);
    calculatorLayout->addWidget(trigBox);
    calculatorLayout->addWidget(extraBox);

    calculatorWidget->setLayout(calculatorLayout);
    splitter->addWidget(calculatorWidget);

QWidget *graphWidget = new QWidget(splitter);
    QVBoxLayout *graphLayout = new QVBoxLayout(graphWidget);

QHBoxLayout *xRangeLayout = new QHBoxLayout;
QHBoxLayout *yRangeLayout = new QHBoxLayout;

QLineEdit *xMinLineEdit = new QLineEdit(graphWidget);
xMinLineEdit->setStyleSheet(lineEditStyle);
QLineEdit *xMaxLineEdit = new QLineEdit(graphWidget);
xMaxLineEdit->setStyleSheet(lineEditStyle);
QLineEdit *yMinLineEdit = new QLineEdit(graphWidget);
yMinLineEdit->setStyleSheet(lineEditStyle);
QLineEdit *yMaxLineEdit = new QLineEdit(graphWidget);
yMaxLineEdit->setStyleSheet(lineEditStyle);

QLabel *xMinLabel = new QLabel("x Min:", graphWidget);
QLabel *xMaxLabel = new QLabel("x Max:", graphWidget);
QLabel *yMinLabel = new QLabel("y Min:", graphWidget);
QLabel *yMaxLabel = new QLabel("y Max:", graphWidget);

xRangeLayout->addWidget(xMinLabel);
xRangeLayout->addWidget(xMinLineEdit);
xRangeLayout->addWidget(xMaxLabel);
xRangeLayout->addWidget(xMaxLineEdit);

yRangeLayout->addWidget(yMinLabel);
yRangeLayout->addWidget(yMinLineEdit);
yRangeLayout->addWidget(yMaxLabel);
yRangeLayout->addWidget(yMaxLineEdit);

graphLayout->addLayout(xRangeLayout);
graphLayout->addLayout(yRangeLayout);


    QCustomPlot *plot = new QCustomPlot(graphWidget);
    graphLayout->addWidget(plot);
    QPushButton *plotButton = new QPushButton("График", graphWidget);
    plotButton->setStyleSheet(smallerButtonStyle);
    QObject::connect(plotButton, &QPushButton::clicked, [&]() {

        // Чтение и установка диапазонов осей x и y
        double xMin = xMinLineEdit->text().isEmpty() ? -M_PI : xMinLineEdit->text().toDouble();
        double xMax = xMaxLineEdit->text().isEmpty() ? M_PI : xMaxLineEdit->text().toDouble();
        double yMin = yMinLineEdit->text().isEmpty() ? -2 : yMinLineEdit->text().toDouble();
        double yMax = yMaxLineEdit->text().isEmpty() ? 2 : yMaxLineEdit->text().toDouble();

        plot->clearGraphs();
        QString baseExpr = lineEdit->text();  // Используем lineEdit вместо graphExpression

        int numPoints = 2000;
        QVector<double> x(numPoints), y(numPoints);
        double step = (xMax - xMin) / numPoints;
        double tanLimit = 20.0;  // предельное значение для tan(x)

        QVector<QVector<double>> allXs, allYs;
        QVector<double> currentXs, currentYs;

        for(int i = 0; i < numPoints; i++) {
            x[i] = i * step + xMin;
            if (std::abs(x[i]) < 1e-15) {
                x[i] = 0.0;
            }

            QString currentExpr = baseExpr;
            QString formattedX;

            // Проверяем, является ли x[i] отрицательным числом
            if (x[i] < 0) {
                // Если да, оборачиваем его в скобки
                formattedX = QString("(%1)").arg(x[i]);
            } else {
                // Иначе, оставляем как есть
                formattedX = QString("%1").arg(x[i]);
            }

            currentExpr.replace("x", formattedX);

            y[i] = calculate(currentExpr.toStdString().c_str());

            // Добавляем проверку на "разрыв" только для tan
            if (baseExpr.contains("tan")) {
                if (std::abs(y[i]) > tanLimit) {
                    if (!currentXs.isEmpty()) {
                        allXs.append(currentXs);
                        allYs.append(currentYs);
                    }
                    currentXs.clear();
                    currentYs.clear();
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

        plot->xAxis->setRange(xMin, xMax);
        plot->yAxis->setRange(yMin, yMax);
        plot->replot();
    });

    graphLayout->addWidget(plotButton);
    graphLayout->addWidget(plot);
    graphWidget->setLayout(graphLayout);
    splitter->addWidget(graphWidget);

    QList<int> sizes;
    sizes << 300 << 900; // Здесь 300 и 900 - это ширины виджетов в пикселях.
    splitter->setSizes(sizes);

    mainLayout->addWidget(splitter);

    QPushButton *toggleCreditCalculatorButton = new QPushButton("Кредитный калькулятор", mainWidget);
    toggleCreditCalculatorButton->setStyleSheet(smallerButtonStyle);
    mainLayout->addWidget(toggleCreditCalculatorButton);

    mainWidget->setLayout(mainLayout);
    mainWindow.setCentralWidget(mainWidget);

    CreditCalculatorWindow creditCalculator;
    QObject::connect(&creditCalculator, &CreditCalculatorWindow::switchToMainCalculator, [&]() {
        creditCalculator.hide();
        mainWindow.show();
    });

    QObject::connect(toggleCreditCalculatorButton, &QPushButton::clicked, [&]() {
        mainWindow.hide();
        creditCalculator.show();
    });

    mainWindow.show();

    return app.exec();
}
