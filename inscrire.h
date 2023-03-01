#ifndef INSCRIRE_H
#define INSCRIRE_H
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QSqlDatabase>
#include <QDialog>

namespace Ui {
class inscrire;
}

class inscrire : public QDialog
{
    Q_OBJECT

public:
    explicit inscrire(QWidget *parent = nullptr);
    ~inscrire();

private slots:
    void on_pushButton_clicked();

private:
    Ui::inscrire *ui;
        QSqlDatabase mydb;
};

#endif // INSCRIRE_H
