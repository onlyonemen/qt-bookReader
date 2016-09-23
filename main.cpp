#include "mainwindow.h"
#include "bookform.h"
#include "bookwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    BookForm b;
//    b.show();
    BookWindow b;
    b.show();

    return a.exec();
}
