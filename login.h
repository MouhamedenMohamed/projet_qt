#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QSqlDatabase>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    void connClose()
    {
        mydb.close();
    }
    void connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
       mydb.setDatabaseName("/home/mouhameden/Desktop/qtsqlite.db");
       if(!mydb.open())
          qDebug()<<("Failed to open database");
       else
           qDebug()<<("Connected . . . . .");

    }

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
