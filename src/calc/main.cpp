#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <exception>

extern "C" {
bool validate_string(const char* str);
double calculate(const char* infixExpression);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Qt Калькулятор");
    mainWindow.resize(400, 300);

    QWidget *centralWidget = new QWidget(&mainWindow);
    QVBoxLayout *layout = new QVBoxLayout;

    QLineEdit *lineEdit = new QLineEdit(centralWidget);
    lineEdit->setPlaceholderText("Введите выражение");
    layout->addWidget(lineEdit);

    QPushButton *computeButton = new QPushButton("Вычислить", centralWidget);
    layout->addWidget(computeButton);

    centralWidget->setLayout(layout);
    mainWindow.setCentralWidget(centralWidget);

    QObject::connect(computeButton, &QPushButton::clicked, [&]() {
        QString expression = lineEdit->text();

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
    });

    mainWindow.show();

    return app.exec();
}
