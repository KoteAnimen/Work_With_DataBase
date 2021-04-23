#include "addrecord.h"
#include "ui_addrecord.h"
#include "QDebug"


addRecord::addRecord(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addRecord)
{
    ui->setupUi(this);

    query.prepare("SELECT  TypeProduct FROM dbo.ListProduct");
    query.exec();
    while (query.next()) {
            ui->typeProduct->addItem(query.value(0).toString(), 0);
    }

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
    query.prepare("Insert INTO dbo.ListDataMatrix (IdDataMatrix, TypeProduct, ReadTime) VALUES(?, ?, ?)");
    query.addBindValue(ui->id->text());
    query.addBindValue(ui->typeProduct->currentText());
    query.addBindValue(ui->dateTimeEdit->dateTime());
    query.exec();
    this->hide();
}

