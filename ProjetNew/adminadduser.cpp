#include "adminadduser.h"
#include "ui_adminadduser.h"
#include <QFile>
#include <QDomDocument>
#include <QtXml>
#include <qsqldatabase.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>


/**
 * @brief AdminAddUser::AdminAddUser
 * @param parent
 */
AdminAddUser::AdminAddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminAddUser)
{
    ui->setupUi(this);
}


/**
 * @brief AdminAddUser::~AdminAddUser
 */
AdminAddUser::~AdminAddUser()
{
    delete ui;
}

/**
 * @brief AdminAddUser::on_pushButton_AdminAddUserSave_clicked
 */
void AdminAddUser::on_pushButton_AdminAddUserSave_clicked()
{
    //On recupere les info saisies par l'admin
    QString userFName=ui->lineEdit_AdminAddUserFname->text();
    QString userLName=ui->lineEdit_AdminAddUserLName->text();
    QString userId=ui->lineEdit_adminAddUserId->text();
    QString userPassword=ui->lineEdit_AdminAddUserPassword->text();


    //ouverture de la BDD users puis ajout des informations

    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/usersdb.db");

    if(mydb.open()){
        qDebug()<<"connected to users database";
        QSqlQuery query;
        query.prepare("INSERT INTO users (id, password, fname, lname) VALUES (:userId, :userPassword, :userFName, :userLName)");
        query.bindValue(":userId",userId);
        query.bindValue(":userPassword",userPassword);
        query.bindValue(":userFName",userFName);
        query.bindValue(":userLName",userLName);
        query.exec();
        QMessageBox::information(this, "Enregistrement utilisateur","Ajout utilisateur avec succès!");
        hide();


    }else{
        qDebug()<<"Database users not opened..";
        QMessageBox::warning(this, "Erreur enregistrement","Erreur enregistrement ou erreur connexion à la DB");
    }

    mydb.close();

    //On enregistre les donnees dans la BDD
}

