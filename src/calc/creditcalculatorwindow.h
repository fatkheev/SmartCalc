#ifndef CREDITCALCULATORWINDOW_H
#define CREDITCALCULATORWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include <QPushButton>
#include <QList>

class CreditCalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CreditCalculatorWindow(QWidget *parent = nullptr);

private slots:
    void calculate();
    void showAllRows();
    void handleBackButton();
    void insertTableRow(int row, double monthlyPayment, double principalPayment, double interestPayment, double balanceOwed);

signals:
    void switchToMainCalculator();

private:
    QLineEdit *loanInput;
    QLineEdit *monthsInput;
    QLineEdit *rateInput;
    QComboBox *typeCombo;
    QTableWidget *table;
    QPushButton *showAllButton;
    QList<int> hiddenRows;
    int showAllButtonRow;
};

#endif // CREDITCALCULATORWINDOW_H
