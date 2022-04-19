#include "dht11.h"
#include "ui_dht11.h"
#include<fcntl.h>
#include<unistd.h>
#include<math.h>

QTimer timer;

Dht11::Dht11(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dht11)
{
    fd=-1;
    fd=::open("/dev/dht11_dev",O_RDWR);
    if(fd<0)
        qDebug("Failed to open humidity dev!");

    ui->setupUi(this);
}

Dht11::~Dht11()
{
    if(fd>0)
        ::close(fd);
    delete ui;
}

void Dht11::on_pushButton_clicked()
{

    if(fd<0)
        return;
    if(timer.isActive())
    {
        timer.stop();
        ui->pushButton->setText("获取");

    }
    else{
        ui->pushButton->setText("停止获取");
        printf("获取温湿度数据中\r\n");
        connect(&timer,SIGNAL(timeout()),this,SLOT(slt_timeout()));
        timer.start(2000);
    }

}
void Dht11::slt_timeout()
{
    double temp,hum;
    unsigned char data[4];
    if(ioctl(fd,GEC6818_GET_DHTDATA,&data)!=0)
    {
        perror("GEC6818_GET_DHTDATA error");
        printf("not ouput,I don't know why");
    }else{
        ioctl(fd,GEC6818_GET_DHTDATA,&data);
        temp=data[0]+data[1]*0.01;
        hum=data[2];
        ui->temperatureLabel->setText(QString::number(temp)+"℃");
        ui->humidityLabel->setText(QString::number(hum)+"."+QString::number(data[3])+"%");
        printf("温度%.2f℃,湿度:%.2f%%\r\n",temp,hum);
    }

}

