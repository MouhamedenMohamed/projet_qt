#ifndef USERINTERFACEWITHMENU_H
#define USERINTERFACEWITHMENU_H

#include <QMainWindow>

namespace Ui {
class UserInterfaceWithMenu;
}

class UserInterfaceWithMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterfaceWithMenu(QWidget *parent = nullptr);
    ~UserInterfaceWithMenu();

private slots:
    void on_actionAjouter_une_nouvelle_BD_triggered();

    void on_actionCr_er_une_nouvelle_BD_triggered();

    void on_tableView_activated(const QModelIndex &index);

    void on_listView_DB_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_ListeBD_clicked();

private:
    Ui::UserInterfaceWithMenu *ui;
};

#endif // USERINTERFACEWITHMENU_H
