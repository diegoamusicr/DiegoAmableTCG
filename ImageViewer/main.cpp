#include "mainwindow.h"
#include <QApplication>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{  
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    return a.exec();
}
