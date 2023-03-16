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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase getDb(){return mydb;}

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    UserInterface *userInterface;
    AdminInterface *adminInterface;
    QSqlDatabase mydb;
};
#endif // MAINWINDOW_H
