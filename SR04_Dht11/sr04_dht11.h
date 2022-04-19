#ifndef SR04_DHT11_H
#define SR04_DHT11_H

#include <QWidget>
#include <QTimer>
#include <QStringListModel>



#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QStandardItemModel>
#include <QFile>
#include <QDebug>
#include <QSocketNotifier>
#include <QSqlDatabase>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <cstdio>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class SR04_Dht11;
}

class SR04_Dht11 : public QWidget
{
    Q_OBJECT

public:
    explicit SR04_Dht11(QWidget *parent = 0);
    ~SR04_Dht11();

private slots:
    void on_GetDataBuButton_clicked();

    void slt_timeout();
    void tableView_Init();
    char *getCurrentDateTime();
    void database_Init();


private:
    Ui::SR04_Dht11 *ui;
    int fd1;
    int fd2;
    QTimer *timer;
    int count;
    QStandardItemModel *showDataTableModel;
    QSqlDatabase database;
    char *time1;
//    int dataIndex;
//    double hum;
//    double temp;

};

#endif // SR04_DHT11_H
