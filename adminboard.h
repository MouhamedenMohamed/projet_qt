#ifndef ADMINBOARD_H
#define ADMINBOARD_H
#include<QSqlQueryModel>
#include <QDialog>

namespace Ui {
class adminboard;
}

class adminboard : public QDialog
{
    Q_OBJECT

public:
    explicit adminboard(QWidget *parent = nullptr);
    ~adminboard();

private slots:
    void on_load_table_clicked();

private:
    Ui::adminboard *ui;
};

#endif // ADMINBOARD_H
