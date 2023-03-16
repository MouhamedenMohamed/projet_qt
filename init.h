#ifndef INIT_H
#define INIT_H

#include <QDialog>

namespace Ui {
class init;
}

class init : public QDialog
{
    Q_OBJECT

public:
    explicit init(QWidget *parent = nullptr);
    ~init();

private slots:
    void on_pushButton_bdd_clicked();

private:
    Ui::init *ui;
};

#endif // INIT_H
