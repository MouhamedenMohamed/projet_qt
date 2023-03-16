#include "admininterface.h"
#include "ui_admininterface.h"
#include "mainwindow.h"
#include "userinterface.h"
#include "usersmanagement.h"

/**
 * @brief AdminInterface::AdminInterface
 * @param parent
 */
AdminInterface::AdminInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminInterface)
{
    ui->setupUi(this);
}

/**
 * @brief AdminInterface::~AdminInterface
 */
AdminInterface::~AdminInterface()
{
    delete ui;
}
/**
 * @brief AdminInterface::on_pushButton_adminAddUser_clicked permet à l'admin d'ajouter un user
 *
 */
void AdminInterface::on_pushButton_adminAddUser_clicked()
{
    AdminAddUser *addUser=new AdminAddUser(this);
    addUser->show();


}


void AdminInterface::on_pushButton_admin_deconnexion_clicked()
{
    MainWindow *mainWindows= new MainWindow();
    hide();
    mainWindows->show();

}


void AdminInterface::on_pushButton_adminShowDb_clicked()
{


   // Ui::UserInterface *userInterface=new UserInterface();
}


void AdminInterface::on_pushButton_adminShowUsersList_clicked()
{


}


void AdminInterface::on_pushButton_adminGestionUsers_clicked()
{
    UsersManagement *userM= new UsersManagement();
            userM->show();

}

