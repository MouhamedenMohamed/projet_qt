#ifndef BDD_MAINPAGE_H
#define BDD_MAINPAGE_H

#include <QDialog>

namespace Ui {
class bdd_mainpage;
}

class bdd_mainpage : public QDialog
{
    Q_OBJECT

public:
    explicit bdd_mainpage(QWidget *parent = nullptr);
    ~bdd_mainpage();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_read_clicked();

    void on_pushButton_clicked();

private:
    Ui::bdd_mainpage *ui;
};

#endif // BDD_MAINPAGE_H
