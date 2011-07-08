#include "qml_interface.h"
#include <QFile>
#include <QtGui>
#include <QXmlQuery>
#include <QDeclarativeProperty>
#include <QDeclarativeContext>
#include <QtNetwork>
#include "receiver.h"
#include "dataloader.h"

qml_interface::qml_interface(QString place, QWidget *parent)
    : QMainWindow(parent)
{
    localisation=place;
    if (localisation == "none") // Fonctionner à defaut de localisation (hors connexion)
    {
       this->mode=0;
       forecastAleatoire();
    }
    else
    {
        QNetworkAccessManager *acces = new QNetworkAccessManager(this);
        acces->setNetworkAccessible(QNetworkAccessManager::Accessible);
        if (acces->networkAccessible()== QNetworkAccessManager::NotAccessible){
    }
    dataloader *loader = new dataloader();
    loader->fetchForecast(localisation,this);
    }
    QTimer* timer = new QTimer(this);
    timer->setInterval(5000);
    timer->start();
    noDataAvaible = new QMessageBox();
    view= new QDeclarativeView();
    view->rootContext()->setContextProperty("interfce",this);
    view->setSource(QUrl::fromLocalFile("rcs/InterfaceAnime.qml"));
    this->setSymbol();
    QObject::connect(timer, SIGNAL(timeout()),
                          this, SLOT(updateSlot()));
   }

void qml_interface::affiche()
{
    view->setFixedSize(640,480);
    view->show();
}

Forecast qml_interface::getCurrentForecast(QDateTime time)
{
    bool actuelle=false;
    Forecast currentForecast;

    foreach (const Forecast &forecast, this->forecasts)
    {
        if (actuelle==true) break;
        if (time > QDateTime::fromString(forecast.time["from"],"yyyy-MM-ddThh:mm:ss") && time < QDateTime::fromString(forecast.time["to"],"yyyy-MM-ddThh:mm:ss"))
        {

              actuelle=true;
              currentForecast = forecast;
        }
    }
    if (!actuelle)
    {
        noDataAvaible->setText("Données indisponibles pour cette periode");
        noDataAvaible->show();
    }
    return currentForecast;
}

QString qml_interface::getWindSpeed()
{
    return getCurrentForecast().windSpeed["mps"];
}

QString qml_interface::getTemperature()
{
    return getCurrentForecast().temperature["value"];
}

void qml_interface::setSymbol()
{
    QString Symbol =getCurrentForecast().symbol["name"];
    if (Symbol == "Fog") emit itFogz();
    else if((Symbol == "Sun") || (Symbol == "clear sky")) emit destroyAll();
    else if(Symbol == "Fair") emit fair();
    else if(Symbol == "Partly cloudy") emit pCloudy();
    else if(Symbol == "Cloudy") emit cloudy();
    else if(Symbol == "Rain showers") {emit cloudy(); emit rain();}
    else if(Symbol == "Rain showers with thunder") { emit cloudy(); emit rain(); thunders();}
    else if((Symbol == "Sleet showers") || (Symbol == "Sleet")) {emit cloudy(); emit snow(); emit rain();}
    else if(Symbol == "Snow showers") {emit cloudy(); emit snow();}
    else if((Symbol == "Rain") || (Symbol == "Heavy rain")){emit cloudy(); emit rain();}
    else if(Symbol == "Rain and thunder"){emit cloudy(); emit rain(); thunders();}
    else if(Symbol == "Snow"){emit cloudy(); emit snow();}
    else if(Symbol == "Snow and thunder")   {emit cloudy(); emit snow(); thunders();}
}

QString qml_interface::getSymbol()
{
    return getCurrentForecast().symbol["name"];
}

QString qml_interface::getFrequence()
{
    QString Symbol =getCurrentForecast().symbol["name"];
    if(Symbol == "Rain") return "50";
    if(Symbol =="Snow") return "50";
    if(Symbol=="Sleet") return "50";
    else if((Symbol == "Rain showers") || (Symbol== "Snow showers") || (Symbol== "Sleet showers")) return "5";
    else /*if(Symbol == "Heavy rain")*/ return "100";
}

QString qml_interface::getWindDirection()
{
    return getCurrentForecast().windDirection["code"];
}

QString qml_interface::getTime()
{
    return getCurrentForecast().time["from"];
}

QString qml_interface::depsurx()
{
    QString directionVents = getWindDirection();
    QStringList directionsEst,directionsOuest;
    directionsEst << "E" << "NE" << "SE" << "NNE" << "ENE" << "SSE" << "ESE";
    directionsOuest << "W" << "NW" << "SW" << "NNW" << "WNW" << "SSW" << "WSW";
    if (directionsEst.contains(directionVents))
    {
        return "600";
    }
    else if (directionsOuest.contains(directionVents))
    {
        return "-400";
    }
    return "50";
}

QString qml_interface::depsury()
{
    QString directionVents = getWindDirection();
    QStringList directionsNord,directionsSud;
    directionsNord << "N" << "NE" << "NW" << "NNE" << "NNW" << "ENE" << "WNW";
    directionsSud << "S" << "SW" << "SE" << "SSW" << "SSE" << "ESE" << "WSW";
    if (directionsNord.contains(directionVents))
    {
        return "220";
    }
    else if (directionsSud.contains(directionVents))
    {
        return "-200";
    }
        return "50";
}

QString qml_interface::arvsurx()
{
    QString directionVents = getWindDirection();
    QStringList directionsEst,directionsOuest;
    directionsEst << "E" << "NE" << "SE" << "NNE" << "ENE" << "SSE" << "ESE";
    directionsOuest << "W" << "NW" << "SW" << "NNW" << "WNW" << "SSW" << "WSW";
    if (directionsEst.contains(directionVents))
    {
        return "-400";
    }
    else if (directionsOuest.contains(directionVents))
    {
        return "600";
    }
    return "50";
}

QString qml_interface::arvsury()
{
    QString directionVents = getWindDirection();
    QStringList directionsNord,directionsSud;
    directionsNord << "N" << "NE" << "NW" << "NNE" << "NNW" << "ENE" << "WNW";
    directionsSud << "S" << "SW" << "SE" << "SSW" << "SSE" << "ESE" << "WSW";
    if (directionsNord.contains(directionVents))
    {
        return "-200";
    }
    else if (directionsSud.contains(directionVents))
    {
        return "220";
    }
        return "50";
}

QString qml_interface::depsurz()
{
    QString directionVents = getWindDirection();
    QStringList directionsNord,directionsSud;
    directionsNord << "N" << "NE" << "NW" << "NNE" << "NNW" << "ENE" << "WNW";
    directionsSud << "S" << "SW" << "SE" << "SSW" << "SSE" << "ESE" << "WSW";
    if (directionsNord.contains(directionVents))
    {
        return "20";
    }
    else if (directionsSud.contains(directionVents))
    {
        return "400";
    }
        return "200";
}

QString qml_interface::arvsurz()
{
    QString directionVents = getWindDirection();
    QStringList directionsNord,directionsSud;
    directionsNord << "N" << "NE" << "NW" << "NNE" << "NNW" << "ENE" << "WNW";
    directionsSud << "S" << "SW" << "SE" << "SSW" << "SSE" << "ESE" << "WSW";
    if (directionsNord.contains(directionVents))
    {
        return "400";
    }
    else if (directionsSud.contains(directionVents))
    {
        return "20";
    }
        return "200";
}

int qml_interface::getPositionCiel()
{
   QString now = QDateTime::currentDateTime().toString("hh");
   QString nowMonth = QDateTime::currentDateTime().toString("MM");
   int mois=nowMonth.toInt();
   int heure=now.toInt();
   switch (heure){
   case 6:
        {
           if((mois<3 && mois>0) || (mois==12))
               return 420;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 415;
           if(mois>=6 && mois<=8)
               return 410;
        }
   case 7:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 410;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 405;
           if(mois>=6 && mois<=8)
               return 400;
       }
   case 8:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 400;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 395;
           if(mois>=6 && mois<=8)
               return 390;
       }
   case 9:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 390;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 385;
           if(mois>=6 && mois<=8)
               return 380;
       }
   case 10:
        {
           if((mois<3 && mois>0) || (mois==12))
               return 380;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 375;
           if(mois>=6 && mois<=8)
               return 370;
       }
   case 11:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 380;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 375;
           if(mois>=6 && mois<=8)
               return 370;
       }
   case 12:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 355;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 360;
           if(mois>=6 && mois<=8)
               return 370;
       }
   case 13:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 350;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 355;
           if(mois>=6 && mois<=8)
               return 360;
       }
   case 14:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 340;
           if(mois>=6 && mois<=8)
               return 350;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 345;
       }
   case 15:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 330;
           if(mois>=6 && mois<=8)
               return 340;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 335;
       }
   case 16:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 320;
           if(mois>=6 && mois<=8)
               return 330;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 325;
       }
   case 17:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 310;
           if(mois>=6 && mois<=8)
               return 320;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 315;
       }
   case 18:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 300;
           if(mois>=6 && mois<=8)
               return 310;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 305;
       }
   case 19:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 290;
           if(mois>=6 && mois<=8)
               return 300;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 295;
       }
   case 20:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 200;
           if(mois>=6 && mois<=8)
               return 210;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 205;
       }
   case 21:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 190;
           if(mois>=6 && mois<=8)
               return 200;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 195;
       }
   case 22:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 180;
           if(mois>=6 && mois<=8)
               return 190;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 185;
       }
   case 23:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 170;
           if(mois>=6 && mois<=8)
               return 180;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 175;
       }
   case 0:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 185;
           if(mois>=6 && mois<=8)
               return 175;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 180;
       }
   case 1:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 175;
           if(mois>=6 && mois<=8)
               return 165;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 170;
       }
   case 2:
       {
           if((mois<3 && mois>0) || (mois==12))
               return 165;
           if(mois>=6 && mois<=8)
               return 155;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 160;
       }
   case 3:
{
    if((mois<3 && mois>0) || (mois==12))
        return 155;
    if(mois>=6 && mois<=8)
        return 145;
    if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
        return 150;
}
   case 4:
{
    if((mois<3 && mois>0) || (mois==12))
        return 145;
    if(mois>=6 && mois<=8)
        return 135;
    if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
        return 140;
}
   case 5:
       {
         if((mois<3 && mois>0) || (mois==12))
             return 135;
         if(mois>=6 && mois<=8)
             return 125;
         if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
             return 130;
        }
}
}

void qml_interface::ItFogs()
{
    if (getCurrentForecast().symbol["name"]=="Fog")
    emit itFogz();
}

QString qml_interface::getNextUpdate()
{
    return nextUpdate.toString();
}

void qml_interface::updateSlot()
{
    if(nextUpdate < QDateTime::currentDateTime())
    {
        dataloader *loader = new dataloader();
        loader->fetchForecast(localisation,this);
        view->setSource(QUrl::fromLocalFile("rcs/InterfaceAnime.qml"));
        this->setSymbol();
    }
}

QString qml_interface::getRandomInteger()
{
    int i=rand()%100+1;
    return QString::number(i);
}

void qml_interface::forecastAleatoire()
{
    int i;
    Forecast forecast;
    for (i=0;i<10;i++)
    {
     forecast.time["from"]=QDateTime::currentDateTime().addDays(i).toString("yyyy-MM-ddThh:mm:ss");
     forecast.time["to"]=QDateTime::currentDateTime().addDays(i+1).toString("yyyy-MM-ddThh:mm:ss");
     forecast.windSpeed["mps"]="3";
     forecast.windDirection["code"]="NNE";
     forecast.temperature["value"]="20";
     forecast.symbol["name"]="Fair";
     this->forecasts.append(forecast);
    }
}

void qml_interface::thunders()
{
    QTimer* timer = new QTimer(this);
    timer->setInterval(300);
    timer->start();
    QObject::connect(timer, SIGNAL(timeout()),
                     this, SLOT(thunderEmetor()));
}

void qml_interface::thunderEmetor()
{
    emit thunder();
}

qml_interface::~qml_interface()
{

}
