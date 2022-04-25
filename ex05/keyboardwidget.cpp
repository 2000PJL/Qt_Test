#include "keyboardwidget.h"
#include "ui_keyboardwidget.h"
#include <QDebug>
#include <QApplication>
#include <QKeyEvent>

#define WIDGET_SHOW_HIDE_TIME   50

KeyBoardWidget::KeyBoardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyBoardWidget)
{
    ui->setupUi(this);

    setWindowFlags((Qt::FramelessWindowHint) | Qt::Tool | Qt::WindowStaysOnTopHint);
    setFocusPolicy(Qt::NoFocus);


    connect(&timer, SIGNAL(timeout()), this, SLOT(slt_timeout()));
    connect(&widgetShowTimer, SIGNAL(timeout()), this, SLOT(slt_widgetShowTimeout()));
    connect(&widgetHideTimer, SIGNAL(timeout()), this, SLOT(slt_widgetHideTimeout()));


    activeWindow = QApplication::activeWindow();
    fucosWidget = QApplication::focusWidget();
    connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(slt_focusChanged()));

    buttonList1.append(ui->keyBtn1_1);
    buttonList1.append(ui->keyBtn1_2);
    buttonList1.append(ui->keyBtn1_3);
    buttonList1.append(ui->keyBtn1_4);
    buttonList1.append(ui->keyBtn1_5);
    buttonList1.append(ui->keyBtn1_6);
    buttonList1.append(ui->keyBtn1_7);
    buttonList1.append(ui->keyBtn1_8);
    buttonList1.append(ui->keyBtn1_9);
    buttonList1.append(ui->keyBtn1_10);
    buttonList1.append(ui->keyBtn1_11);
    buttonList1.append(ui->keyBtn1_12);
    buttonList1.append(ui->keyBtn1_13);
    buttonList1.append(ui->keyBtn1_14);
    buttonList1.append(ui->keyBtn1_15);
    buttonList1.append(ui->keyBtn1_16);
    buttonList1.append(ui->keyBtn1_17);
    buttonList1.append(ui->keyBtn1_18);
    buttonList1.append(ui->keyBtn1_19);
    buttonList1.append(ui->keyBtn1_20);
    buttonList1.append(ui->keyBtn1_21);
    buttonList1.append(ui->keyBtn1_22);
    buttonList1.append(ui->keyBtn1_23);
    buttonList1.append(ui->keyBtn1_24);
    buttonList1.append(ui->keyBtn1_25);
    buttonList1.append(ui->keyBtn1_26);

    for (int i = 0; i < buttonList1.count(); i++)
    {
        static_cast<KeyPushButton *>(buttonList1.at(i))->mainWidget = this;
    }


    buttonList2.append(ui->keyBtn2_1);
    buttonList2.append(ui->keyBtn2_2);
    buttonList2.append(ui->keyBtn2_3);
    buttonList2.append(ui->keyBtn2_4);
    buttonList2.append(ui->keyBtn2_5);
    buttonList2.append(ui->keyBtn2_6);
    buttonList2.append(ui->keyBtn2_7);
    buttonList2.append(ui->keyBtn2_8);
    buttonList2.append(ui->keyBtn2_9);
    buttonList2.append(ui->keyBtn2_10);
    buttonList2.append(ui->keyBtn2_11);
    buttonList2.append(ui->keyBtn2_12);
    buttonList2.append(ui->keyBtn2_13);
    buttonList2.append(ui->keyBtn2_14);
    buttonList2.append(ui->keyBtn2_15);
    buttonList2.append(ui->keyBtn2_16);
    buttonList2.append(ui->keyBtn2_17);
    buttonList2.append(ui->keyBtn2_18);
    buttonList2.append(ui->keyBtn2_19);
    buttonList2.append(ui->keyBtn2_20);
    buttonList2.append(ui->keyBtn2_21);
    buttonList2.append(ui->keyBtn2_22);
    buttonList2.append(ui->keyBtn2_23);
    buttonList2.append(ui->keyBtn2_24);
    buttonList2.append(ui->keyBtn2_25);
    buttonList2.append(ui->keyBtn2_26);
    buttonList2.append(ui->keyBtn2_27);

    for (int i = 0; i < buttonList2.count(); i++)
    {
        static_cast<KeyPushButton *>(buttonList2.at(i))->mainWidget = this;
    }

    ui->hideBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/hidekey.png);}"
                               "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/hidekeypress.png);}");

    ui->zimuDeleteBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/deletekey.png);}"
                                     "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/deletekeypress.png);}");

    ui->zimuShiftBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/shiftkey.png);}"
                                    "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/shiftkey.png);}");

    ui->numDeleteBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/deletekey.png);}"
                                    "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/deletekeypress.png);}");

    ui->numShiftBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/rightkey.png);}");

    zimuShiftActive = false;
    numShiftActive = false;
}

KeyBoardWidget::~KeyBoardWidget()
{
    delete ui;
}

void KeyBoardWidget::mouseMoveEvent(QMouseEvent *event)
{
    //if (event->buttons() && Qt::LeftButton)
   // {

       //move(0, QPoint(event->globalPos() - m_currentPos).y());
   //     this->repaint();
      //  event->accept();
    //}
    QWidget::mouseMoveEvent(event);
}

void KeyBoardWidget::slt_timeout()
{
    timer.stop();
    for(int i = 0; i < buttonPressList.count(); i++)
        buttonPressList.at(i)->setStyleSheet(BTN_NORMAL_STYLE + BTN_PRESSED_STYLE);
    buttonPressList.clear();
}

void KeyBoardWidget::on_changeWidgetBtn_clicked()
{
    ui->changeWidgetBtn->setStyleSheet(BTN_FIXPRESSED_STYLE);
    buttonPressList.append(ui->changeWidgetBtn);
    timer.stop();
    timer.start(150);

    int index = ui->stackedWidget->currentIndex();
    if (index == 0)
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->changeWidgetBtn->setText("abc");
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->changeWidgetBtn->setText("&&123");
    }

}

void KeyBoardWidget::on_douhaoBtn_clicked()
{
    ui->douhaoBtn->setStyleSheet(BTN_FIXPRESSED_STYLE);
    buttonPressList.append((ui->douhaoBtn));
    timer.stop();
    timer.start(150);

    int keyCode = ',';
    QString text = ",";
    QKeyEvent	*key = new QKeyEvent(QEvent::KeyPress, keyCode, Qt::NoModifier, text);
    QApplication::postEvent(QApplication::focusWidget(), key);
}

void KeyBoardWidget::on_dotBtn_clicked()
{
    ui->dotBtn->setStyleSheet(BTN_FIXPRESSED_STYLE);
    buttonPressList.append((ui->dotBtn));
    timer.stop();
    timer.start(150);

    int keyCode = '.';
    QString text = ".";
    QKeyEvent	*key = new QKeyEvent(QEvent::KeyPress, keyCode, Qt::NoModifier, text);
    QApplication::postEvent(QApplication::focusWidget(), key);
}

void KeyBoardWidget::on_baspBtn_clicked()
{
    int keyCode = ' ';
    QString text = " ";
    QKeyEvent	*key = new QKeyEvent(QEvent::KeyPress, keyCode, Qt::NoModifier, text);
    QApplication::postEvent(QApplication::focusWidget(), key);
}

void KeyBoardWidget::on_hideBtn_clicked()
{
    if (fucosWidget != NULL)
    {
        fucosWidget->clearFocus();
        fucosWidget = NULL;
    }
   // this->hide();
   // move(0,480);
   // this->update();
    timeoutount = 0;
    widgetHideTimer.start(WIDGET_SHOW_HIDE_TIME);
}

void KeyBoardWidget::slt_widgetHideTimeout()
{
    if (hideAction == 0)
    {
        if (timeoutount == 0)
        {
            move(0, 292);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 1)
        {
            move(0, 300);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 2)
        {
            move(0, 312);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 3)
        {
            move(0, 336);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 4)
        {
            move(0, 384);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 5)
        {
            move(0, 480);
            repaint();
            timeoutount++;
        }
        else
        {
            timeoutount = 0;
            widgetHideTimer.stop();
            setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
            setVisible(false);
            setVisible(true);
        }
    }
    else
    {
        if (timeoutount == 0)
        {
            move(0, -4);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 1)
        {
            move(0, -12);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 2)
        {
            move(0, -24);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 3)
        {
            move(0, -48);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 4)
        {
            move(0, -96);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 5)
        {
            move(0, 480);
            repaint();
            timeoutount++;
        }
        else
        {
            timeoutount = 0;
            widgetHideTimer.stop();
            setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
            setVisible(false);
            setVisible(true);
        }
    }

}


void KeyBoardWidget::on_zimuShiftBtn_clicked()
{
    int keyCode = 0;
    QString text;

    if (!zimuShiftActive)
    {
        zimuShiftActive = true;
        ui->zimuShiftBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/shiftkeypress.png);}"
                                        "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/shiftkeypress.png);}");


        for(int i =0; i < buttonList1.count(); i++)
        {
            text = buttonList1.at(i)->text();
            keyCode = text.toLatin1()[0];
            keyCode -= 32;
            text = (char) keyCode;
            buttonList1.at(i)->setText(text);
        }
    }
    else
    {
        zimuShiftActive = false;
        ui->zimuShiftBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/shiftkey.png);}"
                                        "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/shiftkey.png);}");

        for(int i =0; i < buttonList1.count(); i++)
        {
            text = buttonList1.at(i)->text();
            keyCode = text.toLatin1()[0];
            keyCode += 32;
             text = (char) keyCode;
             buttonList1.at(i)->setText(text);
        }
    }
}

void KeyBoardWidget::on_zimuDeleteBtn_clicked()
{
    QKeyEvent	* key = new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, NULL, NULL);
    QApplication::postEvent(QApplication::focusWidget(), key);
}

void KeyBoardWidget::on_numShiftBtn_clicked()
{
    if (!numShiftActive)
    {
        numShiftActive = true;
        ui->numShiftBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/rightkeypress.png);}"
                                        "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/rightkeypress.png);}");

        buttonList2.at(10)->setText("~");
        buttonList2.at(11)->setText("`");
        buttonList2.at(12)->setText("^");
        buttonList2.at(13)->setText("&&");
        buttonList2.at(14)->setText("*");
        buttonList2.at(15)->setText("|");
        buttonList2.at(16)->setText("/");
        buttonList2.at(17)->setText("\\");
        buttonList2.at(18)->setText("[");
        buttonList2.at(19)->setText("]");
        buttonList2.at(20)->setText("{");
        buttonList2.at(21)->setText("}");
        buttonList2.at(22)->setText("?");
        buttonList2.at(23)->setText("(");
        buttonList2.at(24)->setText(")");
        buttonList2.at(25)->setText("-");
        buttonList2.at(26)->setText("+");

    }
    else
    {
        numShiftActive = false;
        ui->numShiftBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/rightkey.png);}"
                                        "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/rightkey.png);}");


        buttonList2.at(10)->setText("@");
        buttonList2.at(11)->setText("#");
        buttonList2.at(12)->setText("$");
        buttonList2.at(13)->setText("%");
        buttonList2.at(14)->setText("(");
        buttonList2.at(15)->setText(")");
        buttonList2.at(16)->setText("-");
        buttonList2.at(17)->setText("=");
        buttonList2.at(18)->setText("_");
        buttonList2.at(19)->setText("+");
        buttonList2.at(20)->setText("!");
        buttonList2.at(21)->setText(";");
        buttonList2.at(22)->setText(":");
        buttonList2.at(23)->setText("\"");
        buttonList2.at(24)->setText("/");
        buttonList2.at(25)->setText("<");
        buttonList2.at(26)->setText(">");
        }
}

void KeyBoardWidget::on_numDeleteBtn_clicked()
{
    QKeyEvent	* key = new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, NULL, NULL);
    QApplication::postEvent(QApplication::focusWidget(), key);
}

void KeyBoardWidget::slt_widgetShowTimeout()
{//96 48 24 12 4 0
    if (showAction == 0)
    {
        if (timeoutount == 0)
        {
            move(0, 384);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 1)
        {
            move(0, 336);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 2)
        {
            move(0, 312);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 3)
        {
            move(0, 300);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 4)
        {
            move(0, 292);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 5)
        {
            move(0, 288);
            repaint();
            timeoutount++;
        }
        else
        {
            timeoutount = 0;
            widgetShowTimer.stop();
            hideAction = 0;
        }
    }
    else
    {
        if (timeoutount == 0)
        {
            move(0, -96);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 1)
        {
            move(0, -48);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 2)
        {
            move(0, -24);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 3)
        {
            move(0, -12);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 4)
        {
            move(0, -4);
            repaint();
            timeoutount++;
        }
        else if (timeoutount == 5)
        {
            move(0, 0);
            repaint();
            timeoutount++;
        }
        else
        {
            timeoutount = 0;
            widgetShowTimer.stop();
            hideAction = 1;
        }
    }

}

void KeyBoardWidget::slt_focusChanged()
{
    QWidget * l_fucosWidget = QApplication::focusWidget();
    QWidget * l_activeWindow = QApplication::activeWindow();
    QPoint point;

    if (l_fucosWidget != NULL)
    {
        // QMetaProperty property;
        //  if (l_fucosWidget->inherits("QLineEdit") || l_fucosWidget->inherits("QTextEdit")
        //          || property.isEditable(static_cast<const QObject *>(l_fucosWidget)))
         point = l_fucosWidget->mapToGlobal(QPoint(0, 0));
         if (point.y() <= 248)
         {
             showAction = 0;
             ui->hideBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/hidekey.png);}"
                                        "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/hidekeypress.png);}");

         }
         else
         {
             showAction = 1;
             ui->hideBtn->setStyleSheet("QPushButton{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(255, 255, 255);background-image: url(:/images/hidekey1.png);}"
                                        "QPushButton::pressed{border-radius:4px;  border: 1px solid #c8c8c8;background-color: rgb(75, 175, 77);background-image: url(:/images/hidekeypress1.png);}");
         }

        if (l_fucosWidget->testAttribute(Qt::WA_InputMethodEnabled))
        {
            setWindowFlags(windowFlags()  | Qt::WindowStaysOnTopHint);
            setVisible(false);
            setVisible(true);
            if (l_activeWindow != activeWindow)
            {
                timeoutount = 0;
                widgetShowTimer.start(WIDGET_SHOW_HIDE_TIME);

            }
            else
            {
               // if (!this->isVisible())
                if (pos().y() == 480)
                {
                    timeoutount = 0;
                    widgetShowTimer.start(WIDGET_SHOW_HIDE_TIME);
                }
            }
        }
        else
        {
            move(0,480);

           // hide();
        }
    }
    else
    {
//        setWindowFlags(Qt::Tool);
//        if (point.x() <=240)
//            move(0,280);
//        else
//            move(0,0);
//        show();
    }

    fucosWidget = l_fucosWidget;
    activeWindow = l_activeWindow;
}
