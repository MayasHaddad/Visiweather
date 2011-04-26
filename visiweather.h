#ifndef VISIWEATHER_H
#define VISIWEATHER_H

#include <QMainWindow>
#include <QDeclarativeView>
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
void fermer_qml_view();
private:
    Ui::Visiweather *ui;
    QString new_label;
    QDeclarativeView* view;
};

#endif // VISIWEATHER_H
