#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <QDialog>
#include "adminadduser.h"
#include "usersmanagement.h"

namespace Ui {
class AdminInterface;
}

class AdminInterface : public QDialog
{
    Q_OBJECT

public:
    explicit AdminInterface(QWidget *parent = nullptr);
    ~AdminInterface();

private slots:
    void on_pushButton_adminAddUser_clicked();

    void on_pushButton_admin_deconnexion_clicked();

    void on_pushButton_adminShowDb_clicked();

    void on_pushButton_clicked();

    void on_pushButton_adminShowUsersList_clicked();

    void on_pushButton_adminGestionUsers_clicked();

private:
    Ui::AdminInterface *ui;
    UsersManagement *userM;
};

#endif // ADMININTERFACE_H
