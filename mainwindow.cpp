#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.setDatabaseName("Driver={SQL Server};Server=DESKTOP-CR5MEE4\\SQLEXPRESS;Trusted_Connection=Yes;Database=UsedDataMatrix;");
    db.setUserName("DESKTOP-CR5MEE4\\Kote_Animen");
    db.setPassword("");
    if(!db.open())
    {
        QMessageBox box;
        box.setText(QSqlError(db.lastError()).text());
        box.exec();
    }
    add = new addRecord();
    model = new QSqlTableModel(this);
    model->setTable("dbo.ListDataMatrix");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Data Matrix"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type Product"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Read Time"));
    ui->tableView->setModel(model);
    model->select();
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::time);
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddRecord_clicked()
{    
    add->show();
}

void MainWindow::time()
{
    ui->tableView->setModel(model);
    model->select();
}

void MainWindow::on_ShowCountRecords_clicked()
{
    query.prepare("SELECT COUNT(IdDataMatrix) FROM dbo.ListDataMatrix");
    query.bindValue(0, "IdDataMatrix");
    query.exec();
    if (query.next())
    {
        QMessageBox box;
        box.setWindowTitle("Количество записей в таблице");
        box.setText(QString::number(query.value(0).toInt()));
        box.exec();
    }
}
