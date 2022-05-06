#include "ex06.h"
#include "ui_ex06.h"
#include "QtSerialPort"
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QStandardItemModel>
#include <QFile>
#include <QDebug>
#include <QSocketNotifier>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <cstdio>


#define GEC6818_GET_DHTDATA _IOR('K', 0, unsigned int)
#define GEC6818_C7_STA _IOR('K', 1, unsigned long)
#define GEC6818_C8_STA _IOW('K', 2, unsigned long)
#define GEC6818_ADC_IN0 _IOR('A', 1, unsigned long)
#define GEC6818_ADC_IN1 _IOR('A', 2, unsigned long)

char kk[30];

double lmd = 1;
double SDT_MAX_DOUBLE     = 220.00*lmd;
double Temp_E             = 0.4*lmd;
double Hum_E              = 1.0*lmd;
double Dist_E             = 10*lmd;
int ADC_E              = 5*lmd;

float up_gateTemp = -SDT_MAX_DOUBLE;
float down_gateTemp = SDT_MAX_DOUBLE;
float up_gateHum = -SDT_MAX_DOUBLE;
float down_gateHum = SDT_MAX_DOUBLE;
double up_gateDist = -SDT_MAX_DOUBLE;
double down_gateDist = SDT_MAX_DOUBLE;
float up_gateADC = -SDT_MAX_DOUBLE;
float down_gateADC = SDT_MAX_DOUBLE;

float now_up, now_down;   //当前数据的上斜率和下斜率
float last_read_temp;		//当前数据的前一个数据
float last_read_hum;
double last_read_dist;
unsigned int last_read_adc;
int transFlagFirst = 1;

unsigned char sensor_data[4];
float temp = 0.0, hum = 0.0;
int distance = 0;
int adc_val = 0.0;
char sr04_str[10];


QSerialPort serialPort;
int fd;
int dataIndex=0;
char *time1;

ex06::ex06(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ex06)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(slt_timeout1()));
    serialPort.setPortName("/dev/ttySAC2");
    tableView_Init();
    if(!serialPort.open(QIODevice::ReadWrite))
    {
        qDebug("open ttySAC2 fail");
    }else{
        qDebug("open ttySAC2 success");
        serialPort.setParity(QSerialPort::NoParity);
        serialPort.setDataBits(QSerialPort::Data8);
        serialPort.setStopBits(QSerialPort::OneStop);
        serialPort.setBaudRate(QSerialPort::Baud115200);
        connect(&serialPort,&QSerialPort::readyRead,this,&ex06::slt_serialportRead);
    }


}

ex06::~ex06()
{
    delete ui;
}


void ex06::tableView_Init()
{
    dataIndex = 0;
    showDataTableModel = new QStandardItemModel();

    showDataTableModel->setColumnCount(2);
    showDataTableModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("序号")));
    showDataTableModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("温度")));
    showDataTableModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("湿度")));
    showDataTableModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("距离")));
    showDataTableModel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("光强")));
    showDataTableModel->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("时间")));

    ui->tableView->setModel(showDataTableModel);

    //表头信息显示居左
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView->setColumnWidth(0,60);
    ui->tableView->setColumnWidth(1,80);
    ui->tableView->setColumnWidth(2,80);
    ui->tableView->setColumnWidth(3,70);
    ui->tableView->setColumnWidth(4,70);
    ui->tableView->setColumnWidth(5,180);
    ui->tableView->verticalHeader()->hide();
}




void ex06::table_add_row(float temp, float hum, int distance, int adc_val)
{
    time1 = getCurrentDateTime();
    showDataTableModel->setItem(dataIndex, 0, new QStandardItem(QString::number(dataIndex+1)));
    showDataTableModel->setItem(dataIndex, 1, new QStandardItem(QString::number(temp,'f',2)));
    showDataTableModel->setItem(dataIndex, 2, new QStandardItem(QString::number(hum,'f',2)));
    showDataTableModel->setItem(dataIndex, 3, new QStandardItem(QString::number(distance)));
    showDataTableModel->setItem(dataIndex, 4, new QStandardItem(QString::number(adc_val)));
    showDataTableModel->setItem(dataIndex, 5, new QStandardItem(time1));
    dataIndex++;

    sprintf(kk,"#,%d,%.2f,%.2f,%d,$",distance,temp,hum,adc_val);
    ui->textEdit->append(kk);

}





void ex06::on_GetDataButton_clicked()
{
   static char checked=1;
   if(checked)
   {
     dht11_fd = open("/dev/dht11_dev",O_RDWR);
     if(dht11_fd < 0)
     {
         qDebug("open dht11_dev failed!!!");
         //return;
     }
     sr04_fd = -1;
     sr04_fd = ::open("/dev/sr04", O_RDWR);
     if(sr04_fd < 0)
     {
         qDebug("Failed to open /dev/sr04!");
     }
     adc_fd = -1;
     adc_fd = ::open("/dev/adc_drv", O_RDWR);
     if (adc_fd < 0)
     {
         qDebug("Failed to open adc dev!");
     }
     ui->GetDataButton->setText("停止采集数据");
     checked = !checked;
     if (!timer->isActive())
         timer->start(2000);

   }
   else
   {

     ::close(dht11_fd);
     ::close(adc_fd);
     ::close(sr04_fd);
     ui->GetDataButton->setText("采集数据");
     checked = !checked;
     if (timer->isActive())
       timer->stop();
   }
}




char* ex06::getCurrentDateTime()
{
    time_t t = time(0);
    static char dateTime[64];
    strftime(dateTime, sizeof(dateTime), "%Y/%m/%d %H:%M:%S",localtime(&t));
    return dateTime;
}

void ex06::slt_serialportRead()
{
    QString str(serialPort.readAll());
    qDebug()<<"serial data is "<<str;
    if(str.count() <= 0)return;

    if(cmdType == AT_CWJAP && str.indexOf("WIFI CONNECTED") >= 0)
    {
        ui->connectWIFIButton->setText("已连接");
    }else if((cmdType == AT_CWQAP && str.indexOf("WIFI OK")) || str.indexOf("WIFI DISCONNECTED") >= 0)
    {
        ui->connectWIFIButton->setText("连接WIFI");
    }

    if(cmdType == AT_CIPSTART && str.indexOf("CONNECT") >= 0 && str.indexOf("OK"))
    {
        ui->connectServeButton->setText("已连接");
    }else if(cmdType == AT_CIPCLOSE && str.indexOf("WIFI OK") >= 0)
    {
         ui->connectServeButton->setText("连接服务器");
    }
}

void ex06::on_connectWIFIButton_clicked()
{
    if(ui->connectWIFIButton->text()=="连接WIFI")
    {
        cmdType = AT_CWMODE;
        serialPort.write("AT+CWMODE=1\r\n");//set esp8266 to station mode
        sleep(1000);
        QString str = "AT+CWJAP=\""+ui->ssidEdit->text()+"\",\""+ui->passwordEdit->text()+"\""+"\r\n";
        cmdType = AT_CWJAP;
        serialPort.write(str.toLocal8Bit());
        //ui->connectWIFIButton->setText("已连接");
    }else{
        QString str = "AT+CWQAP";
        cmdType = AT_CWQAP;
        serialPort.write(str.toLocal8Bit());
        //ui->connectWIFIButton->setText("连接WIFI");
    }
}

void ex06::sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

void ex06::on_connectServeButton_clicked()
{
    if(ui->connectServeButton->text()=="连接服务器")
    {
        QString str = "AT+CIPSTART=\"TCP\",\""+ui->serverIPEdit->text()+"\","+ui->serverportEdit->text()+"\r\n";
        cmdType = AT_CIPSTART;
        serialPort.write(str.toLocal8Bit());
        sleep(1000);
        cmdType = AT_CIPMODE;
        serialPort.write("AT+CIPMODE=1\r\n");
        sleep(1000);
        cmdType = AT_CIPSEND;
        serialPort.write("AT+CIPSEND\r\n");

    }else{
        serialPort.write("+++");
        sleep(1000);
        cmdType = AT_CIPCLOSE;
        serialPort.write("AT+CIPCLOSE\r\n");
    }
}


void ex06::slt_timeout1()
{

    ioctl(dht11_fd, GEC6818_GET_DHTDATA, &sensor_data[0]);
    ioctl(adc_fd, GEC6818_ADC_IN1, &adc_val);
    ioctl(sr04_fd, GEC6818_C7_STA, &distance);

    temp = sensor_data[0] + sensor_data[1] * 0.01;
    hum = sensor_data[2] + sensor_data[3] * 0.01;
    adc_val = adc_val * 100 / 4096;

    if(adc_val>100)
    {
        adc_val = 100;
    }

    qDebug("temperature = %.2lf C, humidity = %.2lf, distance = %dcm, adc_vol: %d%%\n", temp,hum,distance,adc_val);

    static float currentTemp = temp;
    static float currentHum = hum;
    static double currentDist = distance;
    static unsigned int currentADC = adc_val;

    //判断，当 esp8266 的透传功能正常时，写入串口，转发到 tcp server
    if ( ui->connectServeButton->text() == "已连接")
    {
        if(transFlagFirst)//only for first transmission
        {
            table_add_row(currentTemp, currentHum, currentDist, currentADC);
            transFlagFirst = 0;
        }

        if(currentTemp != ex06::compressTemp(temp))
        {
            currentTemp = ex06::compressTemp(temp);
//            strWiFi = "temp:" +QString::number(currentTemp,'f',2)+" C"+"\r\n";
//            serialPort.write(strWiFi.toLocal8Bit());
            table_add_row(currentTemp, currentHum, currentDist, currentADC);
            serialPort.write(kk);
        }
        if(currentHum != ex06::compressHum(hum))
        {
            currentHum = ex06::compressHum(hum);
//            strWiFi = "hum:" + QString::number(currentHum,'f',2) + "%" +"\r\n";
//            serialPort.write(strWiFi.toLocal8Bit());
            table_add_row(currentTemp, currentHum, currentDist, currentADC);
            serialPort.write(kk);
        }
        if(currentDist != ex06::compressDist(distance))
        {
            currentDist = ex06::compressDist(distance);
//            strWiFi = "distance:" + QString::number(currentDist,'f',2) + "cm" +"\r\n";
//            serialPort.write(strWiFi.toLocal8Bit());
            table_add_row(currentTemp, currentHum, currentDist, currentADC);
            serialPort.write(kk);
        }
        if(currentADC != ex06::compressADC(adc_val))
        {
            currentADC = ex06::compressADC(adc_val);
//            strWiFi = "adc:" + QString::number(currentADC,'f',2) + "%" +"\r\n";
//            serialPort.write(strWiFi.toLocal8Bit());
            table_add_row(currentTemp, currentHum, currentDist, currentADC);
            serialPort.write(kk);
        }

    }



}

void ex06::on_pushButton_clicked()
{
    ui->textEdit->clear();
    showDataTableModel->removeColumns(0,showDataTableModel->rowCount());
    tableView_Init();

}


float ex06::compressTemp(float currentTemp)
{
    static float last_stored_temp = currentTemp;	//最近保存的点
    now_up = float(currentTemp-last_stored_temp-Temp_E) / 1.0;
    if(now_up > up_gateTemp)
        up_gateTemp = now_up;

    now_down = float(currentTemp-last_stored_temp+Temp_E) / 1.0;
    if(now_down < down_gateTemp)
        down_gateTemp = now_down;

    if(up_gateTemp >= down_gateTemp)
    {
        last_stored_temp = last_read_temp;
        //初始化两扇门为当前点与上个点的斜率
        up_gateTemp = float(currentTemp-last_stored_temp-Temp_E) / 1.0;
        down_gateTemp = float(currentTemp-last_stored_temp+Temp_E) / 1.0;
        last_read_temp = currentTemp;
    }
    return last_stored_temp;
}

float ex06::compressHum(float currentHum)
{
    static float last_stored_hum = currentHum;	//最近保存的点
    now_up = float(currentHum-last_stored_hum-Hum_E) / 1.0;
    if(now_up > up_gateHum)
        up_gateHum = now_up;

    now_down = float(currentHum-last_stored_hum+Hum_E) / 1.0;
    if(now_down < down_gateHum)
        down_gateHum = now_down;

    if(up_gateHum >= down_gateHum)
    {
        last_stored_hum = last_read_hum;
        //初始化两扇门为当前点与上个点的斜率
        up_gateHum = float(currentHum-last_stored_hum-Hum_E) / 1.0;
        down_gateHum = float(currentHum-last_stored_hum+Hum_E) / 1.0;
        last_read_hum = currentHum;
    }
    return last_stored_hum;
}

double ex06::compressDist(double currentDist)
{
    static double last_stored_dist = currentDist;	//最近保存的点
    now_up = double(currentDist-last_stored_dist-Dist_E) / 1.0;
    if(now_up > up_gateDist)
        up_gateDist = now_up;

    now_down = double(currentDist-last_stored_dist+Dist_E) / 1.0;
    if(now_down < down_gateDist)
        down_gateDist = now_down;

    if(up_gateDist >= down_gateDist)
    {
        last_stored_dist = last_read_dist;
        //初始化两扇门为当前点与上个点的斜率
        up_gateDist = double(currentDist-last_stored_dist-Dist_E) / 1.0;
        down_gateDist = double(currentDist-last_stored_dist+Dist_E) / 1.0;
        last_read_dist = currentDist;
    }
    return last_stored_dist;
}

unsigned int ex06::compressADC(unsigned int currentADC)
{
    static unsigned int last_stored_adc = currentADC;	//最近保存的点
    now_up = float(currentADC-last_stored_adc-ADC_E) / 1.0;
    if(now_up > up_gateADC)
        up_gateADC = now_up;

    now_down = float(currentADC-last_stored_adc+ADC_E) / 1.0;
    if(now_down < down_gateADC)
        down_gateADC = now_down;

    if(up_gateADC >= down_gateADC)
    {
        last_stored_adc = last_read_adc;
        //初始化两扇门为当前点与上个点的斜率
        up_gateADC = float(currentADC-last_stored_adc-ADC_E) / 1.0;
        down_gateADC = float(currentADC-last_stored_adc+ADC_E) / 1.0;
        last_read_adc = currentADC;
    }
    return last_stored_adc;
}



void ex06::on_ChangeEButton_clicked()
{
    Temp_E = ui->TempEdit->text().toDouble();
    Hum_E = ui->HumEdit->text().toDouble();
    Dist_E = ui->DistEdit->text().toDouble();
    ADC_E = ui->ADCEdit->text().toInt();
}
