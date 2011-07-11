#ifndef QML_INTERFACE_H
#define QML_INTERFACE_H

#include <QtGui>
#include <QtNetwork>
#include <QDeclarativeView>
#include <iostream>
#include "receiver.h"
#define NewConnection 1
#define LastConnection 0

class qml_interface : public QMainWindow
{
    Q_OBJECT

public:
    qml_interface(QString place, QWidget *parent = 0);
    Forecast getCurrentForecast(QDateTime time=QDateTime::currentDateTime().addDays(1)); // Retourne la structure forecast correspondant a l'instant present
    void affiche();
    void forecastAleatoire();
    Q_INVOKABLE QString getWindSpeed();
    Q_INVOKABLE QString getWindDirection();
    Q_INVOKABLE QString getTemperature();
    Q_INVOKABLE QString getTime();
    Q_INVOKABLE QString depsurx();
    Q_INVOKABLE QString arvsurx();
    Q_INVOKABLE QString depsury();
    Q_INVOKABLE QString arvsury();
    Q_INVOKABLE QString depsurz();
    Q_INVOKABLE QString arvsurz();
    Q_INVOKABLE QString getNextUpdate();
    Q_INVOKABLE QString getFrequence();
    Q_INVOKABLE QString getSymbol();
    Q_INVOKABLE void ItFogs();
    Q_INVOKABLE int getPositionCiel();
    Q_INVOKABLE void setSymbol();
    Q_INVOKABLE QString getRandomInteger();
    Q_INVOKABLE QString getDe();
    Q_INVOKABLE QString getA();
    Q_INVOKABLE QString getLocalisation();
    Q_INVOKABLE QString getCountry();
    Q_INVOKABLE void thunderEmetor();
    Q_INVOKABLE void setNightOrDay();
    void thunders();
    bool positionCielChange();
    QList<Forecast> forecasts;
    QDateTime nextUpdate;
    QString localisation;
    QString country;
    ~qml_interface();
private:
    QDeclarativeView *view;
    int mode;
    int positionCouranteCiel;
    QMessageBox *noDataAvaible;
signals:
    void itFogz();
    void destroyAll();
    void fair();
    void pCloudy();
    void cloudy();
    void rain();
    void thunder();
    void snow();
    void day();
    void night();
    void cloudyNight();
public slots :
    void updateSlot();
};

#endif // QML_INTERFACE_H
