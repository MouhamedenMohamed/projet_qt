#include "login.h"
#include "ui_login.h"
#include<profile.h>
#include<adminboard.h>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    //implementer la fonction se connecter


    QString username,password;
    int count=0;
    password=ui->lineEdit_password->text();
    username=ui->lineEdit_nom->text();
    QSqlQuery qry;
      if(qry.exec("select * from users where username ='"+username+"' and password='"+password+"'" ))
      {

          while(qry.next()){
              qDebug()<<(qry.value(1));
              qDebug()<<(qry.value(2));
              qDebug()<<(qry.value(3));

              count++;
          }
              if(count==1){
//                  ui->etats->setText("USERNAME AND PASSWORD ARE CORRECT");



                  //Todo
                  //implementer les differentes page pour les utilisateurs differentes

                  if(username=="admin" && password =="password"){
                      adminboard admin;
                      admin.setModal(true);
                      admin.exec();
                  }
                  else{
                      profile profile;
                      profile.setModal(true);
                      profile.exec();
                  }
              }
              if(count>1){
                  ui->etats->setText("DUPLICATE USERNAME AND PASSWORD ");
              }
              if(count<1) {
                  ui->etats->setText("USERNAME AND PASSWORD ARE NOT CORRECT ");
              }
       }
}

