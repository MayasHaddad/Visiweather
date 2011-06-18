#ifndef QML_INTERFACE_H
#define QML_INTERFACE_H

#include <QtGui/QMainWindow>
#include <QtNetwork>
#include <QDeclarativeView>
#include <iostream>
#include "receiver.h"
#define NewConnection 1
#define LastConnection 0

class qml_interface : public QMainWindow
{
    Q_OBJECT

    Q_PROPERTY(Forecast getCurrentForecast READ getCurrentForecast NOTIFY ItFogz)
public:
    qml_interface(QString place, QWidget *parent = 0);
    void fetchForecast(QString place = 0, int connexion = NewConnection);
    Forecast getCurrentForecast(QDateTime time=QDateTime::currentDateTime().addDays(1)); // Retourne la structure forecast correspondant a l'instant present
    void affiche();
    Q_INVOKABLE QString getWindSpeed();
    Q_INVOKABLE QString getWindDirection();
    Q_INVOKABLE QString getSymbol();
    Q_INVOKABLE QString getTemperature();
    Q_INVOKABLE QString getTime();
    Q_INVOKABLE QString depsurx();
    Q_INVOKABLE QString arvsurx();
    Q_INVOKABLE QString depsury();
    Q_INVOKABLE QString arvsury();
    Q_INVOKABLE QString depsurz();
    Q_INVOKABLE QString arvsurz();
    Q_INVOKABLE QString getNextUpdate();
    Q_INVOKABLE void ItFogs();
    Q_INVOKABLE int getPositionCiel();
    ~qml_interface();
private:
    QDeclarativeView *view;
    QList<Forecast> forecasts;
    float dureJour;
    QDateTime leveSoleil;
    QDateTime coucheSoleil;
    QDateTime nextUpdate;
    QString localisation;
signals:
    int ItFogz();
    int ItRains();

public slots :
    void updateSlot();
    void replyFinished(QNetworkReply*);
};

#endif // QML_INTERFACE_H
