#ifndef ADMINADDUSER_H
#define ADMINADDUSER_H

#include <QDialog>

namespace Ui {
class AdminAddUser;
}

class AdminAddUser : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAddUser(QWidget *parent = nullptr);
    ~AdminAddUser();

private slots:
    void on_pushButton_AdminAddUserSave_clicked();

private:
    Ui::AdminAddUser *ui;
};

#endif // ADMINADDUSER_H
