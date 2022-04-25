#ifndef KEYBOARDWIDGET_H
#define KEYBOARDWIDGET_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>

namespace Ui {
class KeyBoardWidget;
}

class KeyBoardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KeyBoardWidget(QWidget *parent = 0);
    ~KeyBoardWidget();

    QList <QPushButton *> buttonList1;
    QList <QPushButton *> buttonList2;

    QWidget *activeWindow;
    QWidget *fucosWidget;
    QPoint m_currentPos;
protected:
    void mouseMoveEvent(QMouseEvent *);
private slots:
    void on_changeWidgetBtn_clicked();

    void on_douhaoBtn_clicked();

    void on_dotBtn_clicked();

    void on_baspBtn_clicked();

    void on_hideBtn_clicked();

    void on_zimuShiftBtn_clicked();

    void on_zimuDeleteBtn_clicked();

    void on_numShiftBtn_clicked();

    void on_numDeleteBtn_clicked();

    void slt_focusChanged();

     void slt_timeout();
     void slt_widgetShowTimeout();
     void slt_widgetHideTimeout();
private:

    Ui::KeyBoardWidget *ui;
    QTimer timer;
    QTimer widgetShowTimer;
    QTimer widgetHideTimer;
    int timeoutount;
    int showAction;
    int hideAction;
    QList <QPushButton *> buttonPressList;

    bool zimuShiftActive;
    bool numShiftActive;
};

#endif // KEYBOARDWIDGET_H
