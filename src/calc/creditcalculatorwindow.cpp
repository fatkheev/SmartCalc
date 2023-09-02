#include "creditcalculatorwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>

CreditCalculatorWindow::CreditCalculatorWindow(QWidget *parent) : QMainWindow(parent) {
    this->setWindowTitle("Кредитный калькулятор");
    this->resize(1200, 600);

    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // Левая панель
    QVBoxLayout *leftLayout = new QVBoxLayout();

    QLabel *loanLabel = new QLabel("Сумма кредита:");
    QLineEdit *loanInput = new QLineEdit();
    QLabel *monthsLabel = new QLabel("Количество месяцев:");
    QLineEdit *monthsInput = new QLineEdit();
    QLabel *rateLabel = new QLabel("Процентная ставка:");
    QLineEdit *rateInput = new QLineEdit();
    QLabel *typeLabel = new QLabel("Тип платежа:");
    QComboBox *typeCombo = new QComboBox();
    typeCombo->addItem("Аннуитетный");
    typeCombo->addItem("Дифференцированный");

    QPushButton *calculateButton = new QPushButton("Рассчитать");
    QPushButton *backButton = new QPushButton("Вернуться в калькулятор");

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

    connect(backButton, &QPushButton::clicked, this, &CreditCalculatorWindow::handleBackButton);

    // Правая панель
    QTableWidget *table = new QTableWidget();
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels(QStringList() << "№" << "Месяц" << "Сумма платежа" << "Платеж по основному долгу" << "Платеж по процентам");

    for (int i = 0; i < table->columnCount(); ++i) {
        table->resizeColumnToContents(i);
    }

    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(table);

    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
}

void CreditCalculatorWindow::handleBackButton() {
    emit switchToMainCalculator();
    this->close();
}
