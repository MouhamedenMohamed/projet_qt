#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userinterface.h"
#include "admininterface.h"
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    QSqlDatabase db_actuel;
    void connect(){

        if(!mydb.isOpen()){
            mydb=QSqlDatabase::addDatabase("QSQLITE");
            //mydb.setDatabaseName("/home/mouhameden/Documents/PolytechTours/S8/C++/BDDs/init.db");
            mydb.setDatabaseName("C:/sqlite3/mydb.db");
            mydb.open();
           if(mydb.isOpen()){
                qDebug()<<"connected to database init";

            }else{
                qDebug()<<"Database not opened..";
            }
        }
    }
public:
    void addnewBd(QString bdname){
        QSqlDatabase newdb;
        QString chemin = "/home/mouhameden/Documents/PolytechTours/S8/C++/BDDs/"+bdname+".db";
        newdb=QSqlDatabase::addDatabase("QSQLITE");
        newdb.setDatabaseName(chemin);
        newdb.open();
        newdb.close();

    }

public:
    void open_new_db(QString bdname){

                QString chemin = "/home/mouhameden/Documents/PolytechTours/S8/C++/BDDs/"+bdname+".db";
                db_actuel=QSqlDatabase::addDatabase("QSQLITE");
                db_actuel.setDatabaseName(chemin);
                db_actuel.open();
                if(db_actuel.isOpen()){
                     qDebug()<<"connected to database "+bdname;

                 }else{
                     qDebug()<<"Database  "+bdname+ "is not opened..";
                 }

    }
public:
    void connClose(){
        mydb.close();
    }
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase getDb()
    {return mydb;}

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    UserInterface *userInterface;
    AdminInterface *adminInterface;
//    QSqlDatabase mydb;
};
#endif // MAINWINDOW_H
