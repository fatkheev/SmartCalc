#include "mainwindow.h"

#include <QFile>
#include <QString>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile("style.qss");
        if (styleFile.open(QFile::ReadOnly)) {
            QString styleSheet = styleFile.readAll();
            a.setStyleSheet(styleSheet);
            styleFile.close();
        }

    MainWindow w;
    w.show();
    return a.exec();
}
