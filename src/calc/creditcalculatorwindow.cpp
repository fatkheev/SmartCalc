#include "creditcalculatorwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include <cmath>

CreditCalculatorWindow::CreditCalculatorWindow(QWidget *parent) : QMainWindow(parent), showAllButtonRow(-1) {
    this->setWindowTitle("Кредитный калькулятор");
    this->resize(1400, 600);

    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    QVBoxLayout *leftLayout = new QVBoxLayout();

    QLabel *loanLabel = new QLabel("Сумма кредита:");
    loanInput = new QLineEdit();
    QLabel *monthsLabel = new QLabel("Количество месяцев:");
    monthsInput = new QLineEdit();
    QLabel *rateLabel = new QLabel("Процентная ставка:");
    rateInput = new QLineEdit();
    QLabel *typeLabel = new QLabel("Тип платежа:");
    typeCombo = new QComboBox();
    typeCombo->addItem("Аннуитетный");
    typeCombo->addItem("Дифференцированный");

    QPushButton *calculateButton = new QPushButton("Рассчитать");
    QPushButton *backButton = new QPushButton("Вернуться в калькулятор");

    connect(calculateButton, &QPushButton::clicked, this, &CreditCalculatorWindow::calculate);
    connect(backButton, &QPushButton::clicked, this, &CreditCalculatorWindow::handleBackButton);

    leftLayout->addWidget(loanLabel);
    leftLayout->addWidget(loanInput);
    leftLayout->addWidget(monthsLabel);
    leftLayout->addWidget(monthsInput);
    leftLayout->addWidget(rateLabel);
    leftLayout->addWidget(rateInput);
    leftLayout->addWidget(typeLabel);
    leftLayout->addWidget(typeCombo);
    leftLayout->addWidget(calculateButton);
    leftLayout->addWidget(backButton);

    table = new QTableWidget();
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels(QStringList() << "№ п/п" << "Месяц платежа" << "Сумма платежа" << "Платеж по основному долгу" << "Платеж по процентам" << "Остаток долга");

    for (int i = 0; i < table->columnCount(); ++i) {
        table->resizeColumnToContents(i);
    }

    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(table);

    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
}

void CreditCalculatorWindow::calculate() {
    double loanAmount = round(loanInput->text().toDouble() * 100) / 100;
    int months = monthsInput->text().toInt();
    double annualRate = round(rateInput->text().toDouble() * 100) / 100;
    double monthlyRate = annualRate / 12.0 / 100.0;
    QString paymentType = typeCombo->currentText();

    disconnect(table, &QTableWidget::cellClicked, nullptr, nullptr); // Отключаем предыдущий обработчик события
    table->setRowCount(0);
    hiddenRows.clear();
    if (showAllButtonRow != -1) { // Удаляем строку с кнопкой "Показать все строки", если она существует
        table->removeRow(showAllButtonRow);
        showAllButtonRow = -1;
    }

    if (paymentType == "Аннуитетный") {
        double annuityCoefficient = monthlyRate * pow(1 + monthlyRate, months) / (pow(1 + monthlyRate, months) - 1);
        double monthlyPayment = round((annuityCoefficient * loanAmount) * 100) / 100;
        double balanceOwed = loanAmount;

        for (int i = 0; i < months; ++i) {
            double interestPayment = round((balanceOwed * monthlyRate) * 100) / 100;
            double principalPayment = monthlyPayment - interestPayment;

            balanceOwed = round((balanceOwed - principalPayment) * 100) / 100;

            table->insertRow(table->rowCount());
            table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem(QString::number(i + 1)));
            table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem(QString("Month %1").arg(i + 1)));
            table->setItem(table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(monthlyPayment, 'f', 2)));
            table->setItem(table->rowCount() - 1, 3, new QTableWidgetItem(QString::number(principalPayment, 'f', 2)));
            table->setItem(table->rowCount() - 1, 4, new QTableWidgetItem(QString::number(interestPayment, 'f', 2)));
            table->setItem(table->rowCount() - 1, 5, new QTableWidgetItem(QString::number(balanceOwed, 'f', 2)));
        }
    } else if (paymentType == "Дифференцированный") {
        double principalPayment = loanAmount / months;
        double balanceOwed = loanAmount;

        for (int i = 0; i < months; ++i) {
            double interestPayment = balanceOwed * monthlyRate;
            double monthlyPayment = principalPayment + interestPayment;
            balanceOwed = balanceOwed - principalPayment;

            table->insertRow(table->rowCount());
            table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem(QString::number(i + 1)));
            table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem(QString("Month %1").arg(i + 1)));
            table->setItem(table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(round(monthlyPayment * 100) / 100, 'f', 2)));
            table->setItem(table->rowCount() - 1, 3, new QTableWidgetItem(QString::number(round(principalPayment * 100) / 100, 'f', 2)));
            table->setItem(table->rowCount() - 1, 4, new QTableWidgetItem(QString::number(round(interestPayment * 100) / 100, 'f', 2)));
            table->setItem(table->rowCount() - 1, 5, new QTableWidgetItem(QString::number(round(balanceOwed * 100) / 100, 'f', 2)));

        }
    }

    if (months > 120) {
        // Скрываем все строки, кроме первых и последних пяти месяцев
        for (int i = 5; i < months - 5; ++i) {
            table->hideRow(i);
            hiddenRows.push_back(i);
        }

        // Добавляем строку с кнопкой "Показать все строки" после пятого месяца
        table->insertRow(5);
        showAllButtonRow = 5;
        QTableWidgetItem *showAllItem = new QTableWidgetItem("Показать все строки");
        showAllItem->setTextAlignment(Qt::AlignCenter);
        table->setItem(showAllButtonRow, 0, showAllItem);
        table->setSpan(showAllButtonRow, 0, 1, table->columnCount());

        // Подключаем событие, чтобы показать все строки при клике
        connect(table, &QTableWidget::cellClicked, [=](int row, int) {
            if (row == showAllButtonRow) {
                showAllRows();
            }
        });
    }
}


void CreditCalculatorWindow::showAllRows() {
    for (const auto& row : hiddenRows) {
        table->showRow(row);
    }
    if (showAllButtonRow != -1) {
        table->hideRow(showAllButtonRow);
    }
    hiddenRows.clear();
}

void CreditCalculatorWindow::handleBackButton() {
    emit switchToMainCalculator();
    this->close();
}
