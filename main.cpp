#include "Image_Processing.hpp"

extern std::string InputImage_Folder;
extern std::string OutputImage_Folder;

#include "mainwindow.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    MainWindow w;
    w.show();
    return a.exec();

}
