#include "profil.h"
#include "ui_profil.h"

Profil::Profil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profil)
{
    ui->setupUi(this);
}

Profil::~Profil()
{
    delete ui;
}
