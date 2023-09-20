#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void append_to_input(QString text);
  void calculate_expression();
  void plot_graph();
  void openCreditCalculator();
  void checkInputLength();
  void validateInputField();

 private:
  Ui::MainWindow *ui;
  QString replaceXWithValue(const QString &expression, const QString &xValue);
  void handleFocusChange();
  bool eventFilter(QObject *target, QEvent *event) override;
  QMovie *catMovie;
  QTimer *timer;
  QTimer *updateTimer;
};
#endif  // MAINWINDOW_H
