#include "mainwindow.h"
#include <QApplication>

#include "hstorylist.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // 连接信号槽，确保最后一个窗口关闭时退出应用程序
        QObject::connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    return a.exec();
}
