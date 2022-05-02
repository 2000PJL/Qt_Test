#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>
#include <QTimer>

const QString BTN_NORMAL_STYLE = "QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);color: rgb(46,46,46);}";
const QString BTN_PRESSED_STYLE = "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);color: rgb(255,255,255);}";
const QString BTN_FIXPRESSED_STYLE = "QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);color: rgb(255,255,255);}";

class KeyPushButton : public QPushButton
{
    Q_OBJECT

public:
    KeyPushButton(QWidget *parent = 0);
    QWidget	*mainWidget;


signals:
    void sig_pressedKey();

protected:
    void mousePressEvent(QMouseEvent *e);




private slots:
//    void slt_getKeyPress();
    void slt_timeout();

private:
    QTimer timer;

};

#endif // PUSHBUTTON_H
