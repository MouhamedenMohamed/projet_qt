#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include "userinterface.h"
//#include <QDebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/usersdb.db");

   if(mydb.open()){
        qDebug()<<"connected to database";

    }else{
        qDebug()<<"Database not opened..";
    }



}

MainWindow::~MainWindow()
{
    delete ui;
    mydb.close();
}

/**
 * @brief MainWindow::on_pushButton_login_clicked
 */
void MainWindow::on_pushButton_login_clicked()
{
    //On recupere les données de connexion saisies par l'utilisateur
    QString idUser=ui->lineEdit_id->text();
    QString password=ui->lineEdit_password->text();
    QSqlQuery query;

    //Si admin
    if(idUser=="admin" && password=="password"){
        QMessageBox::information(this, "Login Admin succeed","Id and password correct");
        adminInterface=new AdminInterface(this);
        hide();
        adminInterface->show();

    }else{

        //Autres utilisateurs simples existant dans la base de données users
        if(!mydb.isOpen()) {
            qDebug()<<"Database not opened..";
            return;
        }
        query.prepare("select *from users where id=:idUser AND password=:password");
        query.bindValue(":idUser", idUser);
        query.bindValue(":password", password);

        if (!query.exec() || !query.next()) {
            qWarning() << "Nom d'utilisateur ou mot de passe incorrect";
            QMessageBox::warning(this, "Login failed","Id or password not correct");

        }else{
            QMessageBox::information(this, "Login user succeed","Id and password correct");
            hide();
            userInterface=new UserInterface(this);
            userInterface->show();
        }

    }

}

