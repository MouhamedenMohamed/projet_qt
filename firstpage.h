#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QDialog>

namespace Ui {
class firstpage;
}

class firstpage : public QDialog
{
    Q_OBJECT

public:
    explicit firstpage(QWidget *parent = nullptr);
    ~firstpage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::firstpage *ui;
};

#endif // FIRSTPAGE_H
