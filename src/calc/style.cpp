#include <QApplication>

void setAppStyles() {
    // Set the style for buttons
    QString button_style = R"(
        QPushButton {
            font-size: 18px;
            min-width: 40px;
            min-height: 40px;
            border-radius: 20px;
            background-color: #f0f0f0;
            padding: 10px;
            color: black;
        }
        QPushButton:hover {
            background-color: #e0e0e0;
        }
        QPushButton:pressed {
            background-color: #d0d0d0;
        }
    )";
    qApp->setStyleSheet(button_style);
}
