/********************************************************************************
** Form generated from reading UI file 'ex05.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EX05_H
#define UI_EX05_H

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

class Ui_ex05
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

    void setupUi(QWidget *ex05)
    {
        if (ex05->objectName().isEmpty())
            ex05->setObjectName(QStringLiteral("ex05"));
        ex05->resize(821, 519);
        groupBox = new QGroupBox(ex05);
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
        groupBox_2 = new QGroupBox(ex05);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 10, 391, 461));
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 30, 371, 421));
        groupBox_3 = new QGroupBox(ex05);
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

        retranslateUi(ex05);

        QMetaObject::connectSlotsByName(ex05);
    } // setupUi

    void retranslateUi(QWidget *ex05)
    {
        ex05->setWindowTitle(QApplication::translate("ex05", "ex05", 0));
        groupBox->setTitle(QApplication::translate("ex05", "WIFI\350\256\276\347\275\256", 0));
        connectWIFIButton->setText(QApplication::translate("ex05", "\350\277\236\346\216\245WIFI", 0));
        connectServeButton->setText(QApplication::translate("ex05", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", 0));
        ssidEdit->setText(QApplication::translate("ex05", "HONOR 9X", 0));
        passwordEdit->setText(QApplication::translate("ex05", "1985343015", 0));
        serverIPEdit->setText(QApplication::translate("ex05", "192.168.137.1", 0));
        serverportEdit->setText(QApplication::translate("ex05", "19853", 0));
        label->setText(QApplication::translate("ex05", "WIFI\345\220\215\345\255\227:", 0));
        label_2->setText(QApplication::translate("ex05", "WIFI\345\257\206\347\240\201:", 0));
        label_3->setText(QApplication::translate("ex05", "\346\234\215\345\212\241\345\231\250IP:", 0));
        label_4->setText(QApplication::translate("ex05", "\346\234\215\345\212\241\345\231\250Port:", 0));
        groupBox_2->setTitle(QApplication::translate("ex05", "WIFI\346\224\266\345\217\221\346\225\260\346\215\256\344\277\241\346\201\257", 0));
        groupBox_3->setTitle(QApplication::translate("ex05", "\346\234\254\345\234\260\346\225\260\346\215\256", 0));
        GetDataButton->setText(QApplication::translate("ex05", "\351\207\207\351\233\206\346\225\260\346\215\256", 0));
        pushButton->setText(QApplication::translate("ex05", "\346\270\205\351\231\244\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class ex05: public Ui_ex05 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EX05_H
