#include "addrecord.h"
#include "ui_addrecord.h"

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
