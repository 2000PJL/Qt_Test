#ifndef LED_H
#define LED_H

#include <QMainWindow>

namespace Ui {
class Led;
}

class Led : public QMainWindow
{
    Q_OBJECT

public:
    explicit Led(QWidget *parent = 0);
    ~Led();

private slots:
    void on_openLed_Button_clicked();

    void on_closeLed_Button_clicked();

    void on_open_Button_clicked();

    void on_close_Button_clicked();

    void on_Led_comboBox_currentIndexChanged(int index);

private:
    Ui::Led *ui;
};

#endif // LED_H
