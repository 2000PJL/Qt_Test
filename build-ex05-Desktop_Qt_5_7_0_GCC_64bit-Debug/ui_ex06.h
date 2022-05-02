/********************************************************************************
** Form generated from reading UI file 'ex06.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EX06_H
#define UI_EX06_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ex06
{
public:
    QGroupBox *groupBox;
    QPushButton *connectWIFIButton;
    QPushButton *connectServeButton;
    QLineEdit *ssidEdit;
    QLineEdit *passwordEdit;
    QLineEdit *serverIPEdit;
    QLineEdit *serverportEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QTableView *tableView;
    QGroupBox *groupBox_3;
    QPushButton *GetDataButton;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QGroupBox *groupBox_4;
    QLineEdit *lmdEdit;
    QPushButton *lmdButton;
    QLabel *label_5;

    void setupUi(QWidget *ex06)
    {
        if (ex06->objectName().isEmpty())
            ex06->setObjectName(QStringLiteral("ex06"));
        ex06->resize(821, 519);
        groupBox = new QGroupBox(ex06);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 371, 311));
        connectWIFIButton = new QPushButton(groupBox);
        connectWIFIButton->setObjectName(QStringLiteral("connectWIFIButton"));
        connectWIFIButton->setGeometry(QRect(30, 250, 121, 41));
        connectServeButton = new QPushButton(groupBox);
        connectServeButton->setObjectName(QStringLiteral("connectServeButton"));
        connectServeButton->setGeometry(QRect(190, 250, 151, 41));
        ssidEdit = new QLineEdit(groupBox);
        ssidEdit->setObjectName(QStringLiteral("ssidEdit"));
        ssidEdit->setGeometry(QRect(160, 40, 201, 41));
        passwordEdit = new QLineEdit(groupBox);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setGeometry(QRect(160, 90, 201, 41));
        serverIPEdit = new QLineEdit(groupBox);
        serverIPEdit->setObjectName(QStringLiteral("serverIPEdit"));
        serverIPEdit->setGeometry(QRect(160, 140, 201, 41));
        serverportEdit = new QLineEdit(groupBox);
        serverportEdit->setObjectName(QStringLiteral("serverportEdit"));
        serverportEdit->setGeometry(QRect(160, 190, 201, 41));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 91, 51));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 101, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 101, 41));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 190, 101, 51));
        groupBox_2 = new QGroupBox(ex06);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 120, 391, 371));
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 30, 371, 421));
        groupBox_3 = new QGroupBox(ex06);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 320, 371, 171));
        GetDataButton = new QPushButton(groupBox_3);
        GetDataButton->setObjectName(QStringLiteral("GetDataButton"));
        GetDataButton->setGeometry(QRect(20, 130, 151, 31));
        textEdit = new QTextEdit(groupBox_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 351, 101));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 130, 111, 31));
        groupBox_4 = new QGroupBox(ex06);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(400, 10, 391, 101));
        lmdEdit = new QLineEdit(groupBox_4);
        lmdEdit->setObjectName(QStringLiteral("lmdEdit"));
        lmdEdit->setGeometry(QRect(20, 30, 141, 61));
        QFont font;
        font.setPointSize(20);
        lmdEdit->setFont(font);
        lmdButton = new QPushButton(groupBox_4);
        lmdButton->setObjectName(QStringLiteral("lmdButton"));
        lmdButton->setGeometry(QRect(240, 30, 121, 61));
        QFont font1;
        font1.setPointSize(25);
        lmdButton->setFont(font1);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 30, 59, 61));
        QFont font2;
        font2.setPointSize(30);
        label_5->setFont(font2);

        retranslateUi(ex06);

        QMetaObject::connectSlotsByName(ex06);
    } // setupUi

    void retranslateUi(QWidget *ex06)
    {
        ex06->setWindowTitle(QApplication::translate("ex06", "ex06", 0));
        groupBox->setTitle(QApplication::translate("ex06", "WIFI\350\256\276\347\275\256", 0));
        connectWIFIButton->setText(QApplication::translate("ex06", "\350\277\236\346\216\245WIFI", 0));
        connectServeButton->setText(QApplication::translate("ex06", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", 0));
        ssidEdit->setText(QApplication::translate("ex06", "HONOR 9X", 0));
        passwordEdit->setText(QApplication::translate("ex06", "1985343015", 0));
        serverIPEdit->setText(QApplication::translate("ex06", "192.168.137.1", 0));
        serverportEdit->setText(QApplication::translate("ex06", "19853", 0));
        label->setText(QApplication::translate("ex06", "WIFI\345\220\215\345\255\227:", 0));
        label_2->setText(QApplication::translate("ex06", "WIFI\345\257\206\347\240\201:", 0));
        label_3->setText(QApplication::translate("ex06", "\346\234\215\345\212\241\345\231\250IP:", 0));
        label_4->setText(QApplication::translate("ex06", "\346\234\215\345\212\241\345\231\250Port:", 0));
        groupBox_2->setTitle(QApplication::translate("ex06", "WIFI\346\224\266\345\217\221\346\225\260\346\215\256\344\277\241\346\201\257", 0));
        groupBox_3->setTitle(QApplication::translate("ex06", "\346\234\254\345\234\260\346\225\260\346\215\256", 0));
        GetDataButton->setText(QApplication::translate("ex06", "\351\207\207\351\233\206\346\225\260\346\215\256", 0));
        pushButton->setText(QApplication::translate("ex06", "\346\270\205\351\231\244\346\225\260\346\215\256", 0));
        groupBox_4->setTitle(QApplication::translate("ex06", "SDT\347\256\227\346\263\225\347\201\265\346\225\217\345\272\246\350\260\203\350\212\202", 0));
        lmdEdit->setText(QApplication::translate("ex06", "100", 0));
        lmdButton->setText(QApplication::translate("ex06", "\350\260\203\350\212\202", 0));
        label_5->setText(QApplication::translate("ex06", "%", 0));
    } // retranslateUi

};

namespace Ui {
    class ex06: public Ui_ex06 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EX06_H
