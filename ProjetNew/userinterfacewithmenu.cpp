#include "userinterfacewithmenu.h"
#include "ui_userinterfacewithmenu.h"
#include <QFileDialog>
#include <QSqlDatabase>
#include <QListWidgetItem>
#include  <QMessageBox>
#include <QStringListModel>
#include <QSqlTableModel>
#include <QSqlQuery>

UserInterfaceWithMenu::UserInterfaceWithMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterfaceWithMenu)
{
    ui->setupUi(this);
}

UserInterfaceWithMenu::~UserInterfaceWithMenu()
{
    delete ui;
}

void UserInterfaceWithMenu::on_actionAjouter_une_nouvelle_BD_triggered()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(
    this,
    tr("Sélectionner une ou plusieurs bases de données"),
    QDir::homePath(),
    tr("Fichiers de base de données (*.db *.sqlite *.sqlite3);;Tous les fichiers (*)"));


    //On affiche le nom de la BD dans la listView sans le chemin vers cette bas(le "C:/...)
    if (!fileNames.isEmpty())
    {
        QStringList baseNames;
        foreach (QString fileName, fileNames)
        {
            QFileInfo fileInfo(fileName);
            baseNames << fileInfo.fileName();
        }

        QStringListModel* model = new QStringListModel(baseNames);
        ui->listView_DB->setModel(model);
    }
}


void UserInterfaceWithMenu::on_actionCr_er_une_nouvelle_BD_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Enregistrer une nouvelle base de données"),
        QDir::homePath(),
        tr("Fichiers de base de données (*.db *.sqlite *.sqlite3)"));

    if (!fileName.isEmpty())
    {
        QFileInfo fileInfo(fileName);
        QString baseName = fileInfo.fileName();

        // Enregistrer la base de données

        QStringListModel* model = qobject_cast<QStringListModel*>(ui->listView_DB->model());

        if (model)
        {
            QStringList baseNames = model->stringList();
            baseNames << baseName;
            model->setStringList(baseNames);
        }
        else
        {
            QStringList baseNames;
            baseNames << baseName;
            model = new QStringListModel(baseNames);
            ui->listView_DB->setModel(model);
        }
    }


}


void UserInterfaceWithMenu::on_tableView_activated(const QModelIndex &index)
{

}


void UserInterfaceWithMenu::on_listView_DB_activated(const QModelIndex &index)
{
    QString dbName = ui->listView_DB->model()->data(index, Qt::DisplayRole).toString();

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbName);

        if (!db.open())
        {
            // Traitement de l'erreur d'ouverture de la base de données
            return;
        }

        QSqlQuery query(db);
        query.exec("SELECT name FROM sqlite_master WHERE type='table' ORDER BY name ASC");

        QSqlTableModel* model = new QSqlTableModel(this, db);
        model->setTable("sqlite_master");
        model->setFilter("type='table'");
        model->setSort(0, Qt::AscendingOrder);
        model->select();

        ui->tableView_DB->setModel(model);


        db.close();

}



void UserInterfaceWithMenu::on_pushButton_ListeBD_clicked()
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
        ui->listView_DB->setModel(modal);
        mydb.close();

    }else{
        qDebug()<<"Database not opened..";
    }
}

