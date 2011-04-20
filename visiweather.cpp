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


void Visiweather::on_Quit_clicked()
{

}
