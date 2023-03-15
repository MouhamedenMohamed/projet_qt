#ifndef USERSMANAGEMENT_H
#define USERSMANAGEMENT_H
#include <QtSql>

#include <QDialog>

namespace Ui {
class UsersManagement;
}

class UsersManagement : public QDialog
{
    Q_OBJECT

public:
    explicit UsersManagement(QWidget *parent = nullptr);
    ~UsersManagement();

private slots:
    void on_pushButton_adminShowUsersList_clicked();

private:
    Ui::UsersManagement *ui;
};

#endif // USERSMANAGEMENT_H
