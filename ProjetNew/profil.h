#ifndef PROFIL_H
#define PROFIL_H

#include <QDialog>

namespace Ui {
class Profil;
}

class Profil : public QDialog
{
    Q_OBJECT

public:
    explicit Profil(QWidget *parent = nullptr);
    ~Profil();

private:
    Ui::Profil *ui;
};

#endif // PROFIL_H
