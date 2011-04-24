#include "visiweather.h"
#include "ui_visiweather.h"

Visiweather::Visiweather(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Visiweather)
{
    ui->setupUi(this);
}

Visiweather::~Visiweather()
{
    delete ui;
}

QString Visiweather::get_concat()
{
   new_label= ui->lineEdit->text();
   new_label += " a été choisie";
   return new_label;
}

void Visiweather::ville_choisie()
{
    ui->labelVilleOk->setText(get_concat());
}

void Visiweather::fonctionner_en_hors_connex()
{

}
