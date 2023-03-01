#include "firstpage.h"
#include "ui_firstpage.h"
#include <login.h>

firstpage::firstpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstpage)
{
    ui->setupUi(this);
}

firstpage::~firstpage()
{
    delete ui;
}

void firstpage::on_pushButton_clicked()
{
login login;
login.setModal(true);
login.exec();
}

