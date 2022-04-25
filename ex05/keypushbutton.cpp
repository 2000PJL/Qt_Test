#include "keypushbutton.h"
#include "keyboardwidget.h"
#include <QKeyEvent>
#include <QApplication>




KeyPushButton::KeyPushButton(QWidget *parent) : QPushButton(parent)
{
    mainWidget = NULL;
    setStyleSheet(BTN_NORMAL_STYLE + BTN_PRESSED_STYLE);

    connect(&timer, SIGNAL(timeout()), this, SLOT(slt_timeout()));
}


void KeyPushButton::mousePressEvent(QMouseEvent *e)
{
   if (mainWidget == NULL)
   {
       QPushButton::mousePressEvent(e);
       return;
   }
   else //取键值
   {
       setStyleSheet(BTN_FIXPRESSED_STYLE);
       timer.stop();
       timer.start(150);

       QString text = this->text();
       if (text == "&&")
           text = "&";
         int  keyCode = text.toLatin1()[0];
         text = (char) keyCode;
         QKeyEvent* key = new QKeyEvent(QEvent::KeyPress, keyCode, Qt::NoModifier, text);
         QApplication::postEvent(QApplication::focusWidget(), key);
   }

   static_cast<KeyBoardWidget *>(mainWidget)->m_currentPos = mapToParent(e->pos());

}




void KeyPushButton::slt_timeout()
{
    timer.stop();

     setStyleSheet(BTN_NORMAL_STYLE + BTN_PRESSED_STYLE);
}
