#include "visiweather.h"
#include "ui_visiweather.h"
#include "InterfaceAnime.qml"
#include <QDeclarativeView>
#include <QDeclarativeEngine>
 #include <QDeclarativeContext>
 #include <QDeclarativeComponent>
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
        QDeclarativeView view;
         view.setSource(QUrl::fromLocalFile("InterfaceAnime.qml"));
         view.show();
}
