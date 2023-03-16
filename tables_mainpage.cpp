#include "tables_mainpage.h"
#include "ui_tables_mainpage.h"
#include<mainwindow.h>

tables_mainpage::tables_mainpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tables_mainpage)
{
    ui->setupUi(this);
}

tables_mainpage::~tables_mainpage()
{
    delete ui;
}

void tables_mainpage::on_pushButton_add_clicked()
{
  MainWindow main;
  main.connect();
 QSqlQuery query;
 QString table_name =ui->lineEdit_table_name->text();
 query.prepare("insert into tables(name) values(:value1)");
 query.bindValue(":value1", table_name);

  if (!query.exec()) {
        qDebug() << "Failed to insert data:" << query.lastError().text();
   }
}


void tables_mainpage::on_pushButton_del_clicked()
{

}


void tables_mainpage::on_pushButton_read_clicked()
{

}


void tables_mainpage::on_pushButton_clicked()
{
    MainWindow main;
//    main.connect();
    QSqlQuery* query =new QSqlQuery(main.db_actuel);
    QSqlQueryModel *modal= new QSqlQueryModel();
    query->prepare("SELECT name FROM tables");
    query->exec();
    modal->setQuery(*query);
    ui->listView_tables->setModel(modal);
}

