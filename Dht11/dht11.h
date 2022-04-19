#ifndef DHT11_H
#define DHT11_H

#include <QWidget>
#include <QMainWindow>
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define GEC6818_GET_DHTDATA _IOR('K',0,unsigned int)

namespace Ui {
class Dht11;
}

class Dht11 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dht11(QWidget *parent = 0);
    ~Dht11();

private slots:
    void on_pushButton_clicked();
    void slt_timeout();

private:
    Ui::Dht11 *ui;
    int fd;

};

#endif // DHT11_H
