#include "mainwindow.h"
#include "creditcalculatorwindow.h"

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
//        qApp->setStyleSheet("QLineEdit { border: 2px solid transparent; background-color: #eeeeee; border-radius: 5px; color: black; placeholder-text-color: dark-gray; }");


    MainWindow w;
    w.show();
    return a.exec();
}
