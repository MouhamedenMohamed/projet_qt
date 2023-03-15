#include "userinterface.h"
#include "ui_userinterface.h"
#include "mainwindow.h"


UserInterface::UserInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    QStringList options;
    options << "Option 1";
    QComboBox comboBox;
    comboBox.addItems(options);
    ui->label_espaceUser->setText("Bienvenue dans votre espace utilisateur");

}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::on_pushButton_user_deconnexion_clicked()
{
    MainWindow *mainWindows= new MainWindow();
    hide();
    mainWindows->show();

}


void UserInterface::on_comboBox_activated(int index)
{
    QStringList options;
    //options << "Option 1" << "Option 2" << "Option 3";

    ui->comboBox->addItems(options);

    QString option_selectionnee = ui->comboBox->currentText();
}

/**
 * @brief UserInterface::on_pushButton_2_affichageDB_clicked
 * Affiche la liste des bases de données du profil
 */
void UserInterface::on_pushButton_2_affichageDB_clicked()
{
    QSqlDatabase mydb;
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/mydb.db");

   if(mydb.open()){
        qDebug()<<"connected to database";
        QSqlQueryModel *modal= new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select dbname from mydatabases");
        query.exec();
        modal->setQuery(query);
        ui->listView_dataBases->setModel(modal);
        mydb.close();

    }else{
        qDebug()<<"Database not opened..";
    }



}

/**
 * @brief UserInterface::on_listView_dataBases_activated
 * @param index
 *
 * Affiche la liste des tables de la base de données selectionnée
 */
void UserInterface::on_listView_dataBases_activated(const QModelIndex &index)
{
    QString bdd=ui->listView_dataBases->model()->data(index).toString();

    QSqlDatabase mydb;
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/"+ bdd);

    if(mydb.open()){
         qDebug()<<"connected to database";
         QSqlQueryModel *modal= new QSqlQueryModel();
         QSqlQuery query;
         query.prepare("select * from employeesDbTablesList");
         query.exec();
         modal->setQuery(query);
         ui->tableView_tables->setModel(modal);
         mydb.close();

     }else{
         qDebug()<<"Database not opened..";
     }

}


void UserInterface::on_tableView_tables_activated(const QModelIndex &index)
{
    QString bdd=ui->tableView_tables->model()->data(index).toString();

    QSqlDatabase mydb;
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/sqlite3/employeesdb.db");

    if(mydb.open()){
         qDebug()<<"connected to database";
         QSqlQueryModel *modal= new QSqlQueryModel();
         QSqlQuery query;
         query.prepare("select * from employees");
         query.exec();
         modal->setQuery(query);
         ui->tableView_tables->setModel(modal);
         mydb.close();

     }else{
         qDebug()<<"Database not opened..";
     }

}

