#include "creditcalculatorwindow.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <cmath>

#include "style.h"

CreditCalculatorWindow::CreditCalculatorWindow(QWidget *parent)
    : QMainWindow(parent), showAllButtonRow(-1) {
  this->setWindowTitle("Кредитный калькулятор");

  QScreen *screen = QGuiApplication::primaryScreen();
  QRect screenGeometry = screen->geometry();
  int height = (screenGeometry.height() * 80) / 100;
  int width = (screenGeometry.width() * 80) / 100;
  this->resize(width, height);

  QWidget *centralWidget = new QWidget(this);
  centralWidget->setStyleSheet(mainWidgetStyle);
  QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

  QVBoxLayout *leftLayout = new QVBoxLayout();
  leftLayout->setAlignment(Qt::AlignLeft);

  // Для увеличения размера шрифта
  QString biggerFont = "font-size: 24px;";

  QLabel *loanLabel = new QLabel("Сумма кредита:");
  loanLabel->setStyleSheet(biggerFont);
  loanInput = new QLineEdit();
  loanInput->setStyleSheet(lineEditStyle + biggerFont);

  QLabel *monthsLabel = new QLabel("Количество месяцев:");
  monthsLabel->setStyleSheet(biggerFont);
  monthsInput = new QLineEdit();
  monthsInput->setStyleSheet(lineEditStyle + biggerFont);

  QLabel *rateLabel = new QLabel("Процентная ставка:");
  rateLabel->setStyleSheet(biggerFont);
  rateInput = new QLineEdit();
  rateInput->setStyleSheet(lineEditStyle + biggerFont);

  QLabel *typeLabel = new QLabel("Тип платежа:");
  typeLabel->setStyleSheet(biggerFont);
  typeCombo = new QComboBox();
  typeCombo->setStyleSheet(comboBoxStyle);
  typeCombo->addItem("Аннуитетный");
  typeCombo->addItem("Дифференцированный");

  QLabel *monthlyPaymentLabel = new QLabel("Ежемесячный платеж:");
  monthlyPaymentLabel->setStyleSheet(biggerFont);
  resultMonthlyPayment = new QLabel("0");
  resultMonthlyPayment->setStyleSheet(biggerFont);

  QLabel *accruedInterestLabel = new QLabel("Начисленные проценты:");
  accruedInterestLabel->setStyleSheet(biggerFont);
  resultAccruedInterest = new QLabel("0");
  resultAccruedInterest->setStyleSheet(biggerFont);

  QLabel *totalPaymentLabel = new QLabel("Долг + проценты:");
  totalPaymentLabel->setStyleSheet(biggerFont);
  resultTotalPayment = new QLabel("0");
  resultTotalPayment->setStyleSheet(biggerFont);

  QPushButton *calculateButton = new QPushButton("Рассчитать");
  calculateButton->setStyleSheet(buttonStyleGreen);

  QPushButton *backButton = new QPushButton("Вернуться в калькулятор");
  backButton->setStyleSheet(otherButtonStyle);

  connect(calculateButton, &QPushButton::clicked, this,
          &CreditCalculatorWindow::calculate);
  connect(backButton, &QPushButton::clicked, this,
          &CreditCalculatorWindow::handleBackButton);

  leftLayout->addWidget(loanLabel);
  leftLayout->addWidget(loanInput);
  leftLayout->addWidget(monthsLabel);
  leftLayout->addWidget(monthsInput);
  leftLayout->addWidget(rateLabel);
  leftLayout->addWidget(rateInput);
  leftLayout->addWidget(typeLabel);
  leftLayout->addWidget(typeCombo);
  leftLayout->addWidget(monthlyPaymentLabel);
  leftLayout->addWidget(resultMonthlyPayment);
  leftLayout->addWidget(accruedInterestLabel);
  leftLayout->addWidget(resultAccruedInterest);
  leftLayout->addWidget(totalPaymentLabel);
  leftLayout->addWidget(resultTotalPayment);
  leftLayout->addWidget(calculateButton);
  leftLayout->addWidget(backButton);

  connect(calculateButton, &QPushButton::clicked, this,
          &CreditCalculatorWindow::calculate);
  connect(backButton, &QPushButton::clicked, this,
          &CreditCalculatorWindow::handleBackButton);

  table = new QTableWidget();
  table->setColumnCount(6);
  table->setHorizontalHeaderLabels(QStringList() << "№ п/п"
                                                 << "Месяц платежа"
                                                 << "Сумма платежа"
                                                 << "Платеж по основному долгу"
                                                 << "Платеж по процентам"
                                                 << "Остаток долга");

  for (int i = 0; i < table->columnCount(); ++i) {
    table->resizeColumnToContents(i);
  }

  mainLayout->addLayout(leftLayout);
  mainLayout->addWidget(table);

  centralWidget->setLayout(mainLayout);
  this->setCentralWidget(centralWidget);
}

void CreditCalculatorWindow::insertTableRow(int row, double monthlyPayment,
                                            double principalPayment,
                                            double interestPayment,
                                            double balanceOwed) {
  table->insertRow(row);
  table->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
  table->setItem(row, 1,
                 new QTableWidgetItem(QString("Месяц %1").arg(row + 1)));
  table->setItem(row, 2,
                 new QTableWidgetItem(QString::number(monthlyPayment, 'f', 2)));
  table->setItem(
      row, 3, new QTableWidgetItem(QString::number(principalPayment, 'f', 2)));
  table->setItem(
      row, 4, new QTableWidgetItem(QString::number(interestPayment, 'f', 2)));
  table->setItem(row, 5,
                 new QTableWidgetItem(QString::number(balanceOwed, 'f', 2)));
}

void CreditCalculatorWindow::calculate() {
  double loanAmount = round(loanInput->text().toDouble() * 100) / 100;
  int months = monthsInput->text().toInt();
  double annualRate = round(rateInput->text().toDouble() * 100) / 100;
  double monthlyRate = annualRate / 12.0 / 100.0;
  QString paymentType = typeCombo->currentText();

  disconnect(table, &QTableWidget::cellClicked, nullptr, nullptr);
  table->setRowCount(0);
  hiddenRows.clear();
  if (showAllButtonRow != -1) {
    table->removeRow(showAllButtonRow);
    showAllButtonRow = -1;
  }

  if (paymentType == "Аннуитетный") {
    double annuityCoefficient = monthlyRate * pow(1 + monthlyRate, months) /
                                (pow(1 + monthlyRate, months) - 1);
    double monthlyPayment =
        round((annuityCoefficient * loanAmount) * 100) / 100;
    double balanceOwed = loanAmount;

    resultMonthlyPayment->setText(QString::number(monthlyPayment, 'f', 2));
    double totalPaid = monthlyPayment * months;
    double accruedInterest = totalPaid - loanAmount;
    resultAccruedInterest->setText(QString::number(accruedInterest, 'f', 2));
    resultTotalPayment->setText(QString::number(totalPaid, 'f', 2));

    for (int i = 0; i < months; ++i) {
      double interestPayment = round((balanceOwed * monthlyRate) * 100) / 100;
      double principalPayment = monthlyPayment - interestPayment;
      balanceOwed = round((balanceOwed - principalPayment) * 100) / 100;

      insertTableRow(i, monthlyPayment, principalPayment, interestPayment,
                     balanceOwed);
    }
  } else if (paymentType == "Дифференцированный") {
    double principalPayment = loanAmount / months;
    double balanceOwed = loanAmount;

    double minPayment = (loanAmount / months) + loanAmount * monthlyRate;
    double maxPayment =
        (loanAmount / months) + loanAmount / months * monthlyRate;

    resultMonthlyPayment->setText(QString::number(minPayment, 'f', 2) +
                                  " ... " +
                                  QString::number(maxPayment, 'f', 2));

    double totalInterestPaid =
        (minPayment + maxPayment) * months / 2 - loanAmount;
    resultAccruedInterest->setText(QString::number(totalInterestPaid, 'f', 2));
    resultTotalPayment->setText(
        QString::number(loanAmount + totalInterestPaid, 'f', 2));

    for (int i = 0; i < months; ++i) {
      double interestPayment = balanceOwed * monthlyRate;
      double monthlyPayment = principalPayment + interestPayment;
      balanceOwed = balanceOwed - principalPayment;

      if (balanceOwed < 0) balanceOwed = 0;

      insertTableRow(i, monthlyPayment, principalPayment, interestPayment,
                     balanceOwed);
    }
  }

  if (months > 120) {
    for (int i = 5; i < months - 5; ++i) {
      table->hideRow(i);
      hiddenRows.push_back(i);
    }
    table->insertRow(5);
    showAllButtonRow = 5;
    QTableWidgetItem *showAllItem = new QTableWidgetItem("Показать все строки");
    showAllItem->setTextAlignment(Qt::AlignCenter);
    table->setItem(showAllButtonRow, 0, showAllItem);
    table->setSpan(showAllButtonRow, 0, 1, table->columnCount());

    connect(table, &QTableWidget::cellClicked, [=](int row, int) {
      if (row == showAllButtonRow) {
        showAllRows();
      }
    });
  }
}

void CreditCalculatorWindow::showAllRows() {
  for (int row : hiddenRows) {
    table->showRow(row);
  }
  table->removeRow(showAllButtonRow);
  hiddenRows.clear();
  showAllButtonRow = -1;
}

void CreditCalculatorWindow::handleBackButton() {
  emit switchToMainCalculator();
  this->close();
}
