#include "bdd_mainpage.h"
#include "ui_bdd_mainpage.h"
#include<mainwindow.h>
#include<tables_mainpage.h>

bdd_mainpage::bdd_mainpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bdd_mainpage)
{
    ui->setupUi(this);
}

bdd_mainpage::~bdd_mainpage()
{
    delete ui;
}

void bdd_mainpage::on_pushButton_add_clicked()
{
    MainWindow main;
    main.connect();
 QSqlQuery query;
 QString dbname =ui->lineEdit_dbname->text();
 query.prepare("insert into db(name) values(:value1)");
 query.bindValue(":value1", dbname);

  if (!query.exec()) {
        qDebug() << "Failed to insert data:" << query.lastError().text();
   }
main.addnewBd(dbname);
}


void bdd_mainpage::on_pushButton_del_clicked()
{
    MainWindow main;
    main.connect();
 QSqlQuery query;
 QString dbname =ui->lineEdit_dbname->text();
 query.prepare("delete from db where name =:name");
 query.bindValue(":name", dbname);
 query.exec();

}


void bdd_mainpage::on_pushButton_read_clicked()
{
MainWindow main;
QString dbname =ui->lineEdit_dbname->text();
main.open_new_db(dbname);

tables_mainpage tables;
tables.setModal(true);
tables.exec();
}


void bdd_mainpage::on_pushButton_clicked()
{
        MainWindow main;
        main.connect();
        QSqlQuery* query =new QSqlQuery(main.mydb);
        QSqlQueryModel *modal= new QSqlQueryModel();
        query->prepare("SELECT name,id FROM db");
        query->exec();
        modal->setQuery(*query);
        ui->listView_db->setModel(modal);
}

