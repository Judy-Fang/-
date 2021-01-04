#include "Mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QTranslator translator;
    translator.load(":/qm/Language.qm");

    QApplication a(argc, argv);
    a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
