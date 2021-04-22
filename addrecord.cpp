#include "addrecord.h"
#include "ui_addrecord.h"
#include "QDebug"


addRecord::addRecord(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addRecord)
{
    ui->setupUi(this);

}

addRecord::~addRecord()
{
    delete ui;
}

void addRecord::on_Cancel_clicked()
{
    this->hide();
}

void addRecord::on_AddRecord_clicked()
{
    query.prepare("Insert INTO dbo.ListDataMatrix (IdDataMatrix, ReadTime) VALUES(?, ?)");
    query.addBindValue(ui->id->text());
    query.addBindValue(ui->dateTimeEdit->dateTime());
    query.exec();
    this->hide();
}
