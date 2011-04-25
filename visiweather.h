#ifndef VISIWEATHER_H
#define VISIWEATHER_H

#include <QMainWindow>
#include <QDeclarativeView>
#include <QDeclarativeEngine>
 #include <QDeclarativeContext>
 #include <QDeclarativeComponent>

namespace Ui {
    class Visiweather;
}

class Visiweather : public QMainWindow
{
    Q_OBJECT

public:
    explicit Visiweather(QWidget *parent = 0);
    ~Visiweather();
    QString get_concat();

public slots :
void ville_choisie();
void fonctionner_en_hors_connex();

private:
    Ui::Visiweather *ui;
    QString new_label;
};

#endif // VISIWEATHER_H
