#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addrecord.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>

#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QSqlTableModel *model;
    QTimer *timer;
    QSqlQuery query;


public slots:
    void time();

private slots:
    void on_AddRecord_clicked();

    void on_ShowCountRecords_clicked();

private:
    Ui::MainWindow *ui;
    addRecord *add;
};
#endif // MAINWINDOW_H
