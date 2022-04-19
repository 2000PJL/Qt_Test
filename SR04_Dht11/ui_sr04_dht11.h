/********************************************************************************
** Form generated from reading UI file 'sr04_dht11.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SR04_DHT11_H
#define UI_SR04_DHT11_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SR04_Dht11
{
public:
    QPushButton *GetDataBuButton;
    QTableView *tableView;

    void setupUi(QWidget *SR04_Dht11)
    {
        if (SR04_Dht11->objectName().isEmpty())
            SR04_Dht11->setObjectName(QStringLiteral("SR04_Dht11"));
        SR04_Dht11->resize(784, 492);
        GetDataBuButton = new QPushButton(SR04_Dht11);
        GetDataBuButton->setObjectName(QStringLiteral("GetDataBuButton"));
        GetDataBuButton->setGeometry(QRect(240, 360, 261, 71));
        tableView = new QTableView(SR04_Dht11);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 20, 691, 321));

        retranslateUi(SR04_Dht11);

        QMetaObject::connectSlotsByName(SR04_Dht11);
    } // setupUi

    void retranslateUi(QWidget *SR04_Dht11)
    {
        SR04_Dht11->setWindowTitle(QApplication::translate("SR04_Dht11", "SR04_Dht11", 0));
        GetDataBuButton->setText(QApplication::translate("SR04_Dht11", "\350\216\267\345\217\226\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class SR04_Dht11: public Ui_SR04_Dht11 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SR04_DHT11_H
