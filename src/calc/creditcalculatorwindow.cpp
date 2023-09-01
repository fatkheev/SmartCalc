#include "creditcalculatorwindow.h"
#include <QVBoxLayout>

CreditCalculatorWindow::CreditCalculatorWindow(QWidget *parent) : QMainWindow(parent) {
    this->setWindowTitle("Кредитный калькулятор");
    this->resize(1200, 600);
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *backButton = new QPushButton("Вернуться в калькулятор", this);
    layout->addWidget(backButton);
    connect(backButton, &QPushButton::clicked, this, &CreditCalculatorWindow::handleBackButton);

    centralWidget->setLayout(layout);
    this->setCentralWidget(centralWidget);
}

void CreditCalculatorWindow::handleBackButton() {
    emit switchToMainCalculator();
    this->close();
}
