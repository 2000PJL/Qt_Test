#ifndef ex06_H
#define ex06_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class ex06;
}

class ex06 : public QWidget
{
    Q_OBJECT

public:
    explicit ex06(QWidget *parent = 0);
    ~ex06();

private slots:
    void tableView_Init();
    void slt_timeout1();
    char* getCurrentDateTime();
    void slt_serialportRead();
    void sleep(int msec);
    void table_add_row(float temp, float hum, int distance, unsigned int adc_val);
    float compressTemp(float currentTemp);
    float compressHum(float currentHum);
    double compressDist(double currentDist);
    unsigned int compressADC(unsigned int currentADC);

    void on_GetDataButton_clicked();
    void on_connectWIFIButton_clicked();
    void on_connectServeButton_clicked();

    void on_pushButton_clicked();

    void on_lmdButton_clicked();

    void on_ChangeEButton_clicked();

private:
    Ui::ex06 *ui;
    QTimer* timer;
    QStandardItemModel *showDataTableModel;
    enum ATCmdType
    {
        AT_CWMODE,
        AT_CWJAP,
        AT_CWQAP,
        AT_CIPSTART,
        AT_CIPMODE,
        AT_CIPSEND,
        AT_CIPCLOSE
    };
    ATCmdType cmdType;
    int dht11_fd;
    int sr04_fd;
    int adc_fd;


};

#endif // ex06_H
