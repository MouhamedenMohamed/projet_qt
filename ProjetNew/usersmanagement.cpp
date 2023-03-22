#include "usersmanagement.h"
#include "ui_usersmanagement.h"
#include "adminadduser.h"

UsersManagement::UsersManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsersManagement)
{
    ui->setupUi(this);
}

UsersManagement::~UsersManagement()
{
    delete ui;
}

void UsersManagement::on_pushButton_adminShowUsersList_clicked()
{
    QSqlDatabase mydb;
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/usersdb.db");

   if(mydb.open()){
        qDebug()<<"connected to database";
        QSqlQueryModel *modal= new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from users");
        query.exec();
        modal->setQuery(query);
        ui->tableView_admin->setModel(modal);
        mydb.close();

    }else{
        qDebug()<<"Database not opened..";
    }

}



void UsersManagement::on_pushButton_2_clicked()
{
    AdminAddUser *admAddU=new AdminAddUser();
    admAddU->show();
}

