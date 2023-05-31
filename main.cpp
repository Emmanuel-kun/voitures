 #include <QApplication>
#include <QPushButton>
#include "pages/mainwindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainWindow main;
    main.show();
    return QApplication::exec();
}
