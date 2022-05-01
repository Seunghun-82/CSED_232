#include "mainwindow.h"
#include <QMenuBar>
#include <QApplication>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
