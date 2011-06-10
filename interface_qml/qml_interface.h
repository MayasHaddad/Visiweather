#ifndef QML_INTERFACE_H
#define QML_INTERFACE_H

#include <QtGui/QMainWindow>
#include <QDeclarativeView>
#include <iostream>
#include "receiver.h"

class qml_interface : public QMainWindow
{
    Q_OBJECT

public:
    qml_interface(QString place, QWidget *parent = 0);
    void fetchForecast(QString place = 0);
    Forecast getCurrentForecast(QDateTime); // Retourne la structure forecast correspondant a l'instant present
    ~qml_interface();
private:
    QDeclarativeView *view;
    QList<Forecast> forecasts;
    float dureJour;
    QDateTime leveSoleil;
    QDateTime coucheSoleil;
};

#endif // QML_INTERFACE_H
