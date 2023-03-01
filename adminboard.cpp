#include "adminboard.h"
#include "ui_adminboard.h"
#include<login.h>

adminboard::adminboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminboard)
{
    ui->setupUi(this);
}

adminboard::~adminboard()
{
    delete ui;
}

void adminboard::on_load_table_clicked()
{
    login conn;
     conn.connOpen();
    QSqlQueryModel * model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(conn.mydb);
    qry->prepare("select * from users");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    conn.connClose();
    qDebug() <<(model->rowCount());
}

