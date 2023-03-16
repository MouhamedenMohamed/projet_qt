#ifndef TABLES_MAINPAGE_H
#define TABLES_MAINPAGE_H

#include <QDialog>

namespace Ui {
class tables_mainpage;
}

class tables_mainpage : public QDialog
{
    Q_OBJECT

public:
    explicit tables_mainpage(QWidget *parent = nullptr);
    ~tables_mainpage();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_read_clicked();

    void on_pushButton_clicked();

private:
    Ui::tables_mainpage *ui;
};

#endif // TABLES_MAINPAGE_H
