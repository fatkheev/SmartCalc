#include "style.h"

#include <QString>

QString mainWidgetStyle =
    "QWidget {"
    "background-color: #3d3d3d;"  // серый цвет фона
    "}";

QString buttonStyleGreen =
    "QPushButton {"
    "background-color: #4CAF50;"
    "border: none;"
    "color: white;"
    "padding: 15px 32px;"
    "border-radius: 12px;"
    "}"
    "QPushButton:pressed {"
    "background-color: #45a049;"
    "}";

QString buttonStyleYellow =
    "QPushButton {"
    "background-color: yellow;"
    "border: none;"
    "color: black;"
    "padding: 15px 32px;"
    "border-radius: 12px;"
    "}"
    "QPushButton:pressed {"
    "background-color: #45a049;"
    "}";

QString otherButtonStyle =
    "QPushButton {"
    "background-color: lightgray;"  // светло-серый цвет
    "border: none;"
    "color: black;"  // цвет текста
    "padding: 15px 32px;"
    "border-radius: 12px;"
    "}"
    "QPushButton:pressed {"
    "background-color: darkgray;"  // темно-серый цвет при нажатии
    "}";

QString smallerButtonStyle =
    "QPushButton {"
    "background-color: lightgray;"
    "border: none;"
    "color: black;"
    "padding: 8px 16px;"  // Уменьшенная высота и ширина
    "border-radius: 12px;"
    "}"
    "QPushButton:pressed {"
    "background-color: darkgray;"  // темно-серый цвет при нажатии
    "}";

QString smallerButtonYellow =
    "QPushButton {"
    "background-color: yellow;"
    "border: none;"
    "color: black;"
    "padding: 8px 16px;"  // Уменьшенная высота и ширина
    "border-radius: 12px;"
    "}"
    "QPushButton:pressed {"
    "background-color: #f2e600;"  // цвет при нажатии
    "}";

QString lineEditStyle =
    "QLineEdit {"
    "color: black;"
    "border: 2px solid gray;"
    "border-radius: 10px;"
    "padding: 0 8px;"
    "background: white;"
    "selection-background-color: darkgray;"
    "}";

QString comboBoxStyle = R"(
QComboBox {
    border: 1px solid gray;
    border-radius: 3px;
    padding: 1px 18px 1px 3px;
    min-width: 6em;
    color: black;
}

QComboBox:editable {
    background: white;
}

QComboBox:!editable, QComboBox::drop-down:editable {
     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,
                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);
}

QComboBox:!editable:on, QComboBox::drop-down:editable:on {
    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,
                                stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);
}

QComboBox:on { /* shift the text when the popup opens */
    padding-top: 3px;
    padding-left: 4px;
}

QComboBox::drop-down {
    subcontrol-origin: padding;
    subcontrol-position: top right;
    width: 15px;
    border-left-width: 1px;
    border-left-color: darkgray;
    border-left-style: solid;
    border-top-right-radius: 3px;
    border-bottom-right-radius: 3px;
}

QComboBox::down-arrow {
    image: url(:/strelka.png);
    width: 17px;
    height: 17px;
}

QComboBox::down-arrow:on { /* shift the arrow when popup is open */
    top: 1px;
    left: 1px;
}
)";
