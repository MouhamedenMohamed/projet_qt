#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include "userinterface.h"
#include<init.h>
//#include <QDebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




}

MainWindow::~MainWindow()
{
    delete ui;
    mydb.close();
}

/**
 * @brief MainWindow::on_pushButton_login_clicked
 */
//void MainWindow::on_pushButton_login_clicked()
//{
//    MainWindow main;
//    main.connect();
//    //On recupere les données de connexion saisies par l'utilisateur
//    QString username=ui->lineEdit_username->text();
//    QString password=ui->lineEdit_password->text();
//    QSqlQuery query;

//    //Si admin
//    if(username=="admin" && password=="password"){
//        QMessageBox::information(this, "Login Admin succeed","Id and password correct");
//        adminInterface=new AdminInterface(this);
//        hide();
//        adminInterface->show();

//    }else{

//        //Autres utilisateurs simples existant dans la base de données users
//        if(!mydb.isOpen()) {
//            qDebug()<<"Database not opened..";
//            return;
//        }
//        query.prepare("select *from users where username=:username AND password=:password");
//        query.bindValue(":username", username);
//        query.bindValue(":password", password);

//        if (!query.exec() || !query.next()) {
//            qWarning() << "Nom d'utilisateur ou mot de passe incorrect";
//            QMessageBox::warning(this, "Login failed","Id or password are not correct");

//        }else{
//            QMessageBox::information(this, "Login user succeed","Id and password correct");
//            hide();
//            userInterface=new UserInterface(this);
//            userInterface->show();
//        }

//    }

//}


void MainWindow::on_pushButton_clicked()
{
    init init;
    init.setModal(true);
    init.exec();
}

