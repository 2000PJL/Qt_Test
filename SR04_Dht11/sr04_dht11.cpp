#include "sr04_dht11.h"
#include "ui_sr04_dht11.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#define GEC6818_GET_DHTDATA  _IOR('K', 0, unsigned int) //注册宏
#define GEC6818_C7_STA _IOR('K', 1, unsigned long) //这个是ioctl命令，这里定义必须与驱动程序定义一样
#define GEC6818_C8_STA _IOW('K', 2, unsigned long)


unsigned char sensor_data[4];
double hum;
double temp;
unsigned int distance = 0;
unsigned int distance_temp = 0;
char sr04_str[10];
int dataIndex;



QStringList Qlist;

SR04_Dht11::SR04_Dht11(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SR04_Dht11)
{
     ui->setupUi(this);
     tableView_Init();
     //database_Init();
     fd1 = -1;
     fd1 = ::open("/dev/dht11_dev", O_RDWR);
     if(fd1< 0)
     {
         qDebug("Failed to open /dev/dht11_dev!");
     }
     fd2 = -1;
     fd2 = ::open("/dev/sr04", O_RDWR);
     if(fd2< 0)
     {
         qDebug("Failed to open /dev/sr04!");
     }

     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this, SLOT(slt_timeout()));
    }

    SR04_Dht11::~SR04_Dht11()
    {
    if (fd1 > 0)
    {
        ::close(fd1);
        fd1 = -1;
    }
    if (fd2 > 0)
    {
        ::close(fd2);
        fd2 = -1;
    }
    delete ui;
}

void SR04_Dht11::on_GetDataBuButton_clicked()
{
    static int btn_value =0;

    if(btn_value==0)
    {
      ui->GetDataBuButton->setText("停止获取数据");
      btn_value = 1;
      if (fd1 < 0)
          return;
      if (!timer->isActive())
          timer->start(2000);
    }
    else
    {
      ui->GetDataBuButton->setText("获取数据");
      btn_value = 0;
      if (fd1 < 0)
          return;
      if (timer->isActive())
          timer->stop();
    }
}

void SR04_Dht11::tableView_Init()
{
    showDataTableModel = new QStandardItemModel();

    showDataTableModel->setColumnCount(2);
    showDataTableModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("序号")));
    showDataTableModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("温度")));
    showDataTableModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("湿度")));
    showDataTableModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("距离")));
    showDataTableModel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("时间")));

    ui->tableView->setModel(showDataTableModel);

    //表头信息显示居左
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView->setColumnWidth(0,140);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);
    ui->tableView->setColumnWidth(3,200);
    ui->tableView->setColumnWidth(4,225);
    ui->tableView->verticalHeader()->hide();
}

void SR04_Dht11::database_Init()
{
    // connect database
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("PJL.db");
        database.setUserName("PJL");
        database.setPassword("PJL198534");
    }
//     open database
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug() << "database opened!";

        QSqlQuery sql_query;
        // create table

        QString create_sql = "create table if not exists tb_ten (id int primary key, temp float, hum float, dist int,time datetime)";
        sql_query.prepare(create_sql);

        if(!sql_query.exec())
        {
            qDebug() << "Error: Fail to create table." << sql_query.lastError();
        }
        else
        {
            qDebug("Table created!");

        }
    }

}


void SR04_Dht11::slt_timeout()
{

    ioctl(fd1, GEC6818_GET_DHTDATA, &sensor_data[0]);
    ioctl(fd2, GEC6818_C7_STA, &distance);

    temp   = sensor_data[0] + sensor_data[1] * 0.01;
    hum = sensor_data[2] + sensor_data[3] * 0.01;
    time1 = getCurrentDateTime();

    showDataTableModel->setItem(dataIndex, 0, new QStandardItem(QString::number(dataIndex+1)));
    showDataTableModel->setItem(dataIndex, 1, new QStandardItem(QString::number(temp)));
    showDataTableModel->setItem(dataIndex, 2, new QStandardItem(QString::number(hum,'f',2)));
    showDataTableModel->setItem(dataIndex, 3, new QStandardItem(QString::number(distance)));
    showDataTableModel->setItem(dataIndex, 4, new QStandardItem(time1));
    dataIndex++;
//    if(database.open())
//    {
//     QSqlQuery sql_query;
//     QString insert_sql = "insert into tb_ten values (?, ?, ?, ?, ?)";
//     sql_query.prepare(insert_sql);
//     sql_query.addBindValue(dataIndex);
//     sql_query.addBindValue(temp);
//     sql_query.addBindValue(hum);
//     sql_query.addBindValue(distance);
//     sql_query.addBindValue(time1);

//     if(!sql_query.exec())
//     {
//         qDebug() << sql_query.lastError();
//     }
//     else
//     {
//         dataIndex++;
//         qDebug() << "inserted data!";
//     }
//    }
//    else
//    {
//     qDebug() << "database not opened!";
//    }



}

char* SR04_Dht11::getCurrentDateTime()
{
    time_t t = time(0);
    static char dateTime[64];
    strftime(dateTime, sizeof(dateTime), "%Y/%m/%d %H:%M:%S",localtime(&t));
    return dateTime;
}
