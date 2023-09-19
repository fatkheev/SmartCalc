

extern "C" {
    bool validate_string(const char* str);
    double calculate(const char* infixExpression);
}

#include <QFile>
#include <QTextStream>
#include "mainwindow.h"

#include "qcustomplot.h"
#include <cmath>

#include "ui_mainwindow.h"
#include "creditcalculatorwindow.h"

// Кот
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QCursor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qApp->setStyleSheet("QLineEdit { border: 2px solid transparent; background-color: #eeeeee; border-radius: 5px; color: black; placeholder-text-color: dark-gray; }");

    // Запрещаем ввод с физической клавиатуры
    ui->expr_input->setReadOnly(true);
    ui->x_value_input->setReadOnly(true);
    ui->lineEdit_xMin->setReadOnly(true);
    ui->lineEdit_xMax->setReadOnly(true);
    ui->lineEdit_yMin->setReadOnly(true);
    ui->lineEdit_yMax->setReadOnly(true);

    // Разрешаем ввод значений области видимости только цифры
    connect(ui->lineEdit_xMin, &QLineEdit::textChanged, this, &MainWindow::validateInputField);
    connect(ui->lineEdit_xMax, &QLineEdit::textChanged, this, &MainWindow::validateInputField);
    connect(ui->lineEdit_yMin, &QLineEdit::textChanged, this, &MainWindow::validateInputField);
    connect(ui->lineEdit_yMax, &QLineEdit::textChanged, this, &MainWindow::validateInputField);



    // Устанавливаем синюю рамку для активного поля
    ui->expr_input->setStyleSheet("border: 2px solid transparent;");
    ui->x_value_input->setStyleSheet("border: 2px solid transparent;");

    // Устанавливаем начальные стили для полей
    ui->expr_input->setStyleSheet("border: 2px solid transparent;");
    ui->x_value_input->setStyleSheet("border: 2px solid transparent;");
    ui->lineEdit_xMin->setStyleSheet("border: 2px solid transparent;");
    ui->lineEdit_xMax->setStyleSheet("border: 2px solid transparent;");
    ui->lineEdit_yMin->setStyleSheet("border: 2px solid transparent;");
    ui->lineEdit_yMax->setStyleSheet("border: 2px solid transparent;");

    // Установите фильтры событий для полей ввода
    ui->expr_input->installEventFilter(this);
    ui->x_value_input->installEventFilter(this);
    ui->lineEdit_xMin->installEventFilter(this);
    ui->lineEdit_xMax->installEventFilter(this);
    ui->lineEdit_yMin->installEventFilter(this);
    ui->lineEdit_yMax->installEventFilter(this);

    // Задание размеров основного окна
        QScreen *screen = QGuiApplication::primaryScreen();
        QRect screenGeometry = screen->availableGeometry();
        int height = std::min(797, static_cast<int>(0.8 * screenGeometry.height()));
        int width = std::min(1200, static_cast<int>(0.8 * screenGeometry.width()));
        this->setFixedSize(width, height);

        // Для кнопки C
        connect(ui->CButton, &QPushButton::clicked, [=](){
            ui->expr_input->clear();
            ui->x_value_input->clear();
            ui->lineEdit_xMin->clear();
            ui->lineEdit_xMax->clear();
            ui->lineEdit_yMin->clear();
            ui->lineEdit_yMax->clear();
        });

    // Для кнопки (
    connect(ui->button_open_bracket, &QPushButton::clicked, [=](){ append_to_input("("); });

    // Для кнопки )
    connect(ui->button_close_bracket, &QPushButton::clicked, [=](){ append_to_input(")"); });

    // Для кнопки x
    connect(ui->button_x, &QPushButton::clicked, [=](){ append_to_input("x"); });

    // Для кнопки del
    connect(ui->button_del, &QPushButton::clicked, [=](){
        QLineEdit *activeField = nullptr;
        if (ui->x_value_input->hasFocus()) {
            activeField = ui->x_value_input;
        } else if (ui->lineEdit_xMin->hasFocus()) {
            activeField = ui->lineEdit_xMin;
        } else if (ui->lineEdit_xMax->hasFocus()) {
            activeField = ui->lineEdit_xMax;
        } else if (ui->lineEdit_yMin->hasFocus()) {
            activeField = ui->lineEdit_yMin;
        } else if (ui->lineEdit_yMax->hasFocus()) {
            activeField = ui->lineEdit_yMax;
        } else {
            activeField = ui->expr_input;
        }

        QString current_text = activeField->text();
        current_text.chop(1);  // Удалить последний символ
        activeField->setText(current_text);
    });

    // Сигнал проверки количества символов в поле ввода
    connect(ui->expr_input, &QLineEdit::textChanged, this, &MainWindow::checkInputLength);

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
    connect(ui->button_pow, &QPushButton::clicked, [=](){ append_to_input("^"); });

    // Операции
    connect(ui->button_add, &QPushButton::clicked, [=](){ append_to_input("+"); });
    connect(ui->button_subtract, &QPushButton::clicked, [=](){ append_to_input("-"); });
    connect(ui->button_multiply, &QPushButton::clicked, [=](){ append_to_input("*"); });
    connect(ui->button_divide, &QPushButton::clicked, [=](){ append_to_input("/"); });

    // Тригонометрия
    connect(ui->button_sin, &QPushButton::clicked, [=](){ append_to_input("sin("); });
    connect(ui->button_cos, &QPushButton::clicked, [=](){ append_to_input("cos("); });
    connect(ui->button_tan, &QPushButton::clicked, [=](){ append_to_input("tan("); });
    connect(ui->button_asin, &QPushButton::clicked, [=](){ append_to_input("asin("); });
    connect(ui->button_acos, &QPushButton::clicked, [=](){ append_to_input("acos("); });
    connect(ui->button_atan, &QPushButton::clicked, [=](){ append_to_input("atan("); });

    // Дополнительные функции
    connect(ui->button_sqrt, &QPushButton::clicked, [=](){ append_to_input("sqrt("); });
    connect(ui->button_ln, &QPushButton::clicked, [=](){ append_to_input("ln("); });
    connect(ui->button_log, &QPushButton::clicked, [=](){ append_to_input("log("); });
    connect(ui->button_mod, &QPushButton::clicked, [=](){ append_to_input("%"); });

    // Подключение кнопки График
    connect(ui->buttonPlot, &QPushButton::clicked, this, &MainWindow::plot_graph);
    //Подключение кнопки "="
    connect(ui->button_equals, &QPushButton::clicked, this, &MainWindow::calculate_expression);

    connect(ui->button_credit, &QPushButton::clicked, this, &MainWindow::openCreditCalculator);

    // Начало кода анимации котика
        QWidget *widget = new QWidget(this);

        QLabel *label = new QLabel(widget);
        label->setStyleSheet("background: transparent; border: none;");

        QMovie *catMovie = new QMovie(":/cat.gif");

        // Отдаление котика от курсора
        const int newWidth = 200;  // ширина
        const int newHeight = 200; // высота
        QObject::connect(catMovie, &QMovie::frameChanged, [=]() {
            QPixmap scaledPixmap = catMovie->currentPixmap().scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            label->setPixmap(scaledPixmap);
            widget->setFixedSize(scaledPixmap.size());
        });

        label->setMovie(catMovie);
        catMovie->start();

        // Следуем за курсором с задержкой
        QTimer *timer = new QTimer(this);
        QObject::connect(timer, &QTimer::timeout, [=]() {
            QPoint globalMousePos = QCursor::pos();
            // Вычисляем координаты для widget так, чтобы он был рядом с курсором
            QPoint targetPos = globalMousePos - QPoint(newWidth - 100, newHeight - 100);
            QPoint currentPos = widget->pos();
            QPoint newPos = currentPos + 0.05 * (targetPos - currentPos); // "скользящее" следование
            widget->move(newPos);
        });
        timer->start(16);  // Обновляем положение каждые 16 мс

        // Обновление экрана
        QTimer *updateTimer = new QTimer(this);
        QObject::connect(updateTimer, &QTimer::timeout, [=]() {
            this->update();
        });
        updateTimer->start(8);  // Обновляем экран каждые 8 мс (в два раза выстрее самой анимации, это убирает рамку)

        widget->show();
        // Конец кода анимации котика

}

// Это деструктор?
MainWindow::~MainWindow()
{
    delete ui;
}

// Функция проверки количества символов в поле ввода
void MainWindow::checkInputLength() {
    if (ui->expr_input->text().length() > 255) {
        ui->expr_input->setText("Ошибка: превышен лимит символов");
    }
}

// Поле ввода
void MainWindow::append_to_input(QString text) {
    QLineEdit *activeField = nullptr;

    if (ui->x_value_input->hasFocus()) {
        activeField = ui->x_value_input;
    } else if (ui->lineEdit_xMin->hasFocus()) {
        activeField = ui->lineEdit_xMin;
    } else if (ui->lineEdit_xMax->hasFocus()) {
        activeField = ui->lineEdit_xMax;
    } else if (ui->lineEdit_yMin->hasFocus()) {
        activeField = ui->lineEdit_yMin;
    } else if (ui->lineEdit_yMax->hasFocus()) {
        activeField = ui->lineEdit_yMax;
    } else {
        activeField = ui->expr_input;
    }

    QString current_text = activeField->text();
    QString new_text = current_text + text;
    activeField->setText(new_text);
}

// Подключение сишной функции калькулятора
void MainWindow::calculate_expression() {
    // Проверка на пустое поле ввода
    if (ui->expr_input->text().isEmpty()) {
        return;
    }

    QString xValue = ui->x_value_input->text();
    QString expression = replaceXWithValue(ui->expr_input->text(), xValue);

    if (validate_string(expression.toStdString().c_str())) {
        double result = calculate(expression.toStdString().c_str());
        ui->expr_input->setText(QString::number(result));
    } else {
        ui->expr_input->setText("Ошибка");
    }
}

// Функция отрисовки графика
void plotFunction(QCustomPlot *customPlot, const QString &function,
                  double xMin, double xMax, double yMin, double yMax) {
    // Подготовка данных
    QVector<double> x(401), y(401); // Создаю массивы данных
    for (int i = 0; i < 401; ++i) {
        x[i] = xMin + (xMax - xMin) * i / 400.0; // Заполняю массив x[i] значениями, которые равномерно распределены между xMin и xMax

        // Обработка отрицательных значений x
        QString xValueStr = QString::number(x[i]);
        if (xValueStr.startsWith("-")) {
            xValueStr = "(" + xValueStr + ")";
        }

        // Использую сишную функцию calculate для вычисления y[i]
        QString current_expr = function;
        current_expr.replace("x", xValueStr); // Заменяю x
        y[i] = calculate(current_expr.toStdString().c_str());
    }

    // создать график и присвоить ему данные:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);

    // установка области видимости графика
    customPlot->xAxis->setRange(xMin, xMax);
    customPlot->yAxis->setRange(yMin, yMax);
    customPlot->replot();
}

// Функция установки поля видимости
void MainWindow::plot_graph() {
    QString expression = ui->expr_input->text();
    double xMin = (ui->lineEdit_xMin->text().isEmpty()) ? -5.0 : ui->lineEdit_xMin->text().toDouble();
    double xMax = (ui->lineEdit_xMax->text().isEmpty()) ? 5.0 : ui->lineEdit_xMax->text().toDouble();
    double yMin = (ui->lineEdit_yMin->text().isEmpty()) ? -5.0 : ui->lineEdit_yMin->text().toDouble();
    double yMax = (ui->lineEdit_yMax->text().isEmpty()) ? 5.0 : ui->lineEdit_yMax->text().toDouble();

    plotFunction(ui->plotWidget, expression, xMin, xMax, yMin, yMax);
}

// Подмена значения X
QString MainWindow::replaceXWithValue(const QString &expression, const QString &xValue) {
    QString modifiedExpression = expression;
    QString valueToReplace = xValue;

    // Если xValue отрицательное, обернуть его в скобки
    if (xValue.startsWith("-")) {
        valueToReplace = "(" + xValue + ")";
    }

    modifiedExpression.replace("x", valueToReplace);
    return modifiedExpression;
}

// Кнопка возврата к основному калькулятору
void MainWindow::openCreditCalculator() {
    this->hide();
    auto creditWindow = new CreditCalculatorWindow(this); // Qt будет управлять памятью
    connect(creditWindow, &CreditCalculatorWindow::switchToMainCalculator,
            this, &MainWindow::show);
    connect(creditWindow, &QObject::destroyed, this, &MainWindow::show);
    creditWindow->show();
}

// Для фокусирования на поле ввода
bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    if ((target == ui->expr_input ||
         target == ui->x_value_input ||
         target == ui->lineEdit_xMin ||
         target == ui->lineEdit_xMax ||
         target == ui->lineEdit_yMin ||
         target == ui->lineEdit_yMax) && event->type() == QEvent::FocusIn) {
        handleFocusChange();
    }
    return QMainWindow::eventFilter(target, event);
}

void MainWindow::handleFocusChange()
{
    // Сбросить стили для всех полей ввода
    ui->expr_input->setStyleSheet("border: 2px solid transparent;");
    ui->x_value_input->setStyleSheet("border: 2px solid transparent;");
    ui->lineEdit_xMin->setStyleSheet("border: 2px solid transparent;");
    ui->lineEdit_xMax->setStyleSheet("border: 2px solid transparent;");
    ui->lineEdit_yMin->setStyleSheet("border: 2px solid transparent;");
    ui->lineEdit_yMax->setStyleSheet("border: 2px solid transparent;");

    // Установить синий бордюр для активного поля ввода
    if (ui->expr_input->hasFocus()) {
        ui->expr_input->setStyleSheet("border: 2px solid blue;");
    } else if (ui->x_value_input->hasFocus()) {
        ui->x_value_input->setStyleSheet("border: 2px solid blue;");
    } else if (ui->lineEdit_xMin->hasFocus()) {
        ui->lineEdit_xMin->setStyleSheet("border: 2px solid blue;");
    } else if (ui->lineEdit_xMax->hasFocus()) {
        ui->lineEdit_xMax->setStyleSheet("border: 2px solid blue;");
    } else if (ui->lineEdit_yMin->hasFocus()) {
        ui->lineEdit_yMin->setStyleSheet("border: 2px solid blue;");
    } else if (ui->lineEdit_yMax->hasFocus()) {
        ui->lineEdit_yMax->setStyleSheet("border: 2px solid blue;");
    }
}

// Разрешаем ввод значений области видимости только цифры
void MainWindow::validateInputField()
{
    QLineEdit *senderLineEdit = qobject_cast<QLineEdit *>(sender());
    if (!senderLineEdit) return;

    QString text = senderLineEdit->text();

    // Удалить все символы, которые не являются цифрами, точками или знаками минуса
    for (int i = 0; i < text.length(); i++) {
        if (!text[i].isDigit() && text[i] != '.' && text[i] != '-') {
            text.remove(i, 1);
            i--;
        }
    }

    // Убедимся, что знак минуса находится только в начале
    int minusIndex = text.indexOf('-');
    while (minusIndex > 0) {
        text.remove(minusIndex, 1);
        minusIndex = text.indexOf('-', minusIndex);
    }

    // Удаляем дополнительные минусы, если они есть
    while (text.count('-') > 1) {
        text.remove(text.lastIndexOf('-'), 1);
    }

    // Есть только одна точка
    int firstDotIndex = text.indexOf('.');
    int secondDotIndex = text.indexOf('.', firstDotIndex + 1);
    while (secondDotIndex >= 0) {
        text.remove(secondDotIndex, 1);
        secondDotIndex = text.indexOf('.', firstDotIndex + 1);
    }

    senderLineEdit->setText(text);
}
