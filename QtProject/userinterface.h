#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QDialog>
//#include "mainwindow.h"
#include <QtSql>
namespace Ui {
class UserInterface;
}

class UserInterface : public QDialog
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = nullptr);
    ~UserInterface();

private slots:
    void on_pushButton_user_deconnexion_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_2_affichageDB_clicked();

    void on_listView_dataBases_activated(const QModelIndex &index);

    void on_tableView_tables_activated(const QModelIndex &index);

private:
    Ui::UserInterface *ui;

};

#endif // USERINTERFACE_H
