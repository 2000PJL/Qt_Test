#include "sr04_dht11.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SR04_Dht11 w;
    w.show();

    return a.exec();
}
