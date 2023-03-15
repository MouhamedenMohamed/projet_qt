#include "inscrire.h"
#include "ui_inscrire.h"
#include<login.h>
inscrire::inscrire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inscrire)
{
    ui->setupUi(this);
    login log;
    log.connOpen();
}

inscrire::~inscrire()
{
    delete ui;
}


void inscrire::on_pushButton_clicked()
{

    QString username,password;
    password=ui->lineEdit_password->text();
    username=ui->lineEdit_nom->text();
    QSqlQuery qry;
    qry.prepare("insert into users(id,password) values ('"+username+"','"+password+"')");
    if(qry.exec()){
        ui->label->setText("l'utilisateur a ete ajoutee avec succes");
    }
}

