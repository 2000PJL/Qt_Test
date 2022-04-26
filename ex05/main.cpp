#include "ex05.h"
#include <QApplication>

#include "keyboardwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ex05 w;
    w.show();

    KeyBoardWidget k;
    k.move(0,400);



    return a.exec();
}
