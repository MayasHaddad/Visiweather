#include "visiweather.h"
#include "ui_visiweather.h"
Visiweather::Visiweather(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Visiweather),
    view(NULL)
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
   if (new_label != "")
   new_label += " a été choisie";
   return new_label;
}

void Visiweather::ville_choisie()
{
    ui->labelVilleOk->setText(get_concat());
}
void Visiweather::fermer_qml_view()
{
   // view->hide();
    delete view;
    view=NULL;
}

void Visiweather::fonctionner_en_hors_connex()
{
    //if(!view){
        view= new QDeclarativeView();
        QObject::connect(view,SIGNAL(close()),this,SLOT(fermer_qml_view()));
   // }
         view->setSource(QUrl::fromLocalFile("InterfaceAnime.qml"));
         view->show();
}
