#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <firstpage.h>
#include <inscrire.h>
#include<login.h>

#include<adminboard.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     login log;
     log.connOpen();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
  QString username,password;
  int count=0;

  if(!mydb.isOpen()){
      qDebug()<<"Faild";
      return ;
  }





}


void MainWindow::on_pushButton_2_clicked()
{
//    firstpage fp;
//    fp.setModal(true);
//    fp.exec();

    inscrire ins;
    ins.setModal(true);
    ins.exec();

}


void MainWindow::on_pushButton_3_clicked()
{
    login log;
    log.setModal(true);
    log.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    adminboard admin;
    admin.setModal(true);
    admin.exec();
}

