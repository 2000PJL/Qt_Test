#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->setText("");
    ui->textBrowser->setText("欢迎你，彭俊龙228");
}

void MainWindow::on_action_O_triggered()
{
    on_pushButton_clicked();
}

void MainWindow::on_action_C_triggered()
{
    on_pushButton_2_clicked();
}
