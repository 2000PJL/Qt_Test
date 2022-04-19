#include "led.h"
#include "ui_led.h"
#include<fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include<qmessagebox.h>
#include <QCloseEvent>



#define TEST_MAGIC 'x' //定义幻数
#define TEST_MAX_NR 2 //定义命令的最大序数
#define LED1 _IO(TEST_MAGIC, 0)
#define LED2 _IO(TEST_MAGIC, 1)
#define LED3 _IO(TEST_MAGIC, 2)
#define LED4 _IO(TEST_MAGIC, 3)

int fd;

Led::Led(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Led)
{
    ui->setupUi(this);
    fd=-1;
    fd = ::open("/dev/Led", O_RDWR);
    if (fd < 0)
    {
        qDebug("open led dev fail!!");
    }

}

Led::~Led()
{
    if(fd>0)
    {
        ::close(fd);
        fd=-1;
    }
    delete ui;
}

void Led::on_openLed_Button_clicked()
{
    if(fd<0)
        return;

    ::ioctl(fd,LED1,0);
    ::ioctl(fd,LED2,0);
    ::ioctl(fd,LED3,0);
    ::ioctl(fd,LED4,0);
}

void Led::on_closeLed_Button_clicked()
{
    if(fd<0)
        return;

    ::ioctl(fd,LED1,1);
    ::ioctl(fd,LED2,1);
    ::ioctl(fd,LED3,1);
    ::ioctl(fd,LED4,1);
}

void Led::on_open_Button_clicked()
{
    if (!(QMessageBox::information(this,tr("开灯"),tr("是否开灯"),tr("是"),tr("否"))))
        {
        if(fd<0)
            return;
            ::ioctl(fd,LED1,0);
            ::ioctl(fd,LED2,0);
            ::ioctl(fd,LED3,0);
            ::ioctl(fd,LED4,0);
        }

}

void Led::on_close_Button_clicked()
{
    if (!(QMessageBox::information(this,tr("退出系统"),tr("你确认退出本系统吗？"),tr("是"),tr("否"))))
        {
            ::ioctl(fd,LED1,1);
            ::ioctl(fd,LED2,1);
            ::ioctl(fd,LED3,1);
            ::ioctl(fd,LED4,1);
            QApplication* app;
            app->closeAllWindows();
        }

}

void Led::on_Led_comboBox_currentIndexChanged(int index)
{
    if(fd<0)
        return;
    switch(index){
    case 0:
        ::ioctl(fd,LED1,0);
        ::ioctl(fd,LED2,0);
        ::ioctl(fd,LED3,0);
        ::ioctl(fd,LED4,0);
        break;
    case 1:
        ::ioctl(fd,LED1,0);
        ::ioctl(fd,LED2,1);
        ::ioctl(fd,LED3,1);
        ::ioctl(fd,LED4,1);
        break;
    case 2:
        ::ioctl(fd,LED1,1);
        ::ioctl(fd,LED2,0);
        ::ioctl(fd,LED3,1);
        ::ioctl(fd,LED4,1);
        break;
    case 3:
        ::ioctl(fd,LED1,1);
        ::ioctl(fd,LED2,1);
        ::ioctl(fd,LED3,0);
        ::ioctl(fd,LED4,1);
        break;
    case 4:
        ::ioctl(fd,LED1,1);
        ::ioctl(fd,LED2,1);
        ::ioctl(fd,LED3,1);
        ::ioctl(fd,LED4,0);
        break;
    case 5:
        ::ioctl(fd,LED1,1);
        ::ioctl(fd,LED2,1);
        ::ioctl(fd,LED3,1);
        ::ioctl(fd,LED4,1);
        break;
    default:
        break;
    }
}
