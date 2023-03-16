#include "init.h"
#include "ui_init.h"
#include<bdd_mainpage.h>

init::init(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::init)
{
    ui->setupUi(this);
}

init::~init()
{
    delete ui;
}

void init::on_pushButton_bdd_clicked()
{
    //here the functions
    bdd_mainpage bdd;
    bdd.setModal(true);
    bdd.exec();

}

