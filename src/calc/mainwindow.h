#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QFocusEvent>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QSplitter>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <cmath>
#include <QComboBox>
#include <QList>
#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QGuiApplication>
#include <QScreen>
#include <QLabel>


#include <QFormLayout>

extern "C" {
bool validate_string(const char* str);
double calculate(const char* infixExpression);
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
