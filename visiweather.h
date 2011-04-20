#ifndef VISIWEATHER_H
#define VISIWEATHER_H

#include <QMainWindow>

namespace Ui {
    class Visiweather;
}

class Visiweather : public QMainWindow
{
    Q_OBJECT

public:
    explicit Visiweather(QWidget *parent = 0);
    ~Visiweather();

private:
    Ui::Visiweather *ui;

private slots:
    void on_Quit_clicked();
};

#endif // VISIWEATHER_H
