#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    add = new addRecord();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddRecord_clicked()
{
    add->show();
}
