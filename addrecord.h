#ifndef ADDRECORD_H
#define ADDRECORD_H

#include <QMainWindow>

namespace Ui {
class addRecord;
}

class addRecord : public QMainWindow
{
    Q_OBJECT

public:
    explicit addRecord(QWidget *parent = nullptr);
    ~addRecord();

private slots:
    void on_Cancel_clicked();

private:
    Ui::addRecord *ui;
};

#endif // ADDRECORD_H
