#ifndef CREDITCALCULATORWINDOW_H
#define CREDITCALCULATORWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class CreditCalculatorWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit CreditCalculatorWindow(QWidget *parent = nullptr);

signals:
    void switchToMainCalculator();

private slots:
    void handleBackButton();
};

#endif // CREDITCALCULATORWINDOW_H