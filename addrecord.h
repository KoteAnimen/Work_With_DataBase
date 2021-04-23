#ifndef ADDRECORD_H
#define ADDRECORD_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class addRecord;
}

class addRecord : public QMainWindow
{
    Q_OBJECT

public:
    explicit addRecord(QWidget *parent = nullptr);
    ~addRecord();
    QSqlQuery query;

private slots:
    void on_Cancel_clicked();

    void on_AddRecord_clicked();    

private:
    Ui::addRecord *ui;
};

#endif // ADDRECORD_H
