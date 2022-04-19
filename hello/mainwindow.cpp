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

void MainWindow::on_btnOpen_clicked()
{
    ui->textEdit->setText("hello Rochin 210");
}

void MainWindow::on_btnClose_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_actionOpen_triggered()
{
    on_btnOpen_clicked();
}

void MainWindow::on_actionClose_triggered()
{
    on_btnClose_clicked();
}
