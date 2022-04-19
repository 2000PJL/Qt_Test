#include "dht11.h"
#include <QApplication>
#define  DEVICE_NODE "/dev/humidity"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Dht11 w;
    w.show();

    return a.exec();
}
