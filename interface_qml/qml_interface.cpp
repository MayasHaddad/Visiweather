#include "qml_interface.h"
#include <QFile>
#include <QtGui>
#include <QXmlQuery>
#include <QDeclarativeProperty>
#include <QDeclarativeContext>
#include <QtNetwork>
#include "receiver.h"
#define MaRequete "declare variable $url external;\n" \
    "\n"\
    "doc($url)//nextupdate,\n" \
    "\n" \
    "doc($url)//sun,\n"\
    "for $time in doc($url)//tabular/time\n"\
    "    return <time>\n"\
    "       { $time/@from }\n"\
    "       { $time/@to }\n"\
    "        <symbol>\n"\
    " { $time/symbol/@number, $time/symbol/@name } \n"\
    "        </symbol>\n"\
    "        <windDirection>\n"\
    " { $time/windDirection/@code } \n"\
    "        </windDirection>\n"\
    "        <windSpeed>\n"\
    " { $time/windSpeed/@mps } \n"\
    "        </windSpeed>\n"\
    "       <temperature>\n"\
    "           { $time/temperature/@value, $time/temperature/@unit }\n"\
    "       </temperature>\n"\
    "       </time>"

qml_interface::qml_interface(QString place, QWidget *parent)
    : QMainWindow(parent)
{
    localisation=place;
    QNetworkAccessManager *acces = new QNetworkAccessManager(this);
    if (acces->networkAccessible()== QNetworkAccessManager::Accessible)
    {
        QMessageBox *hh=new QMessageBox();
        hh->aboutQt(this);
    }
    this->fetchForecast(localisation,0);
    view= new QDeclarativeView();
    view->rootContext()->setContextProperty("interfce",this);
    view->setSource(QUrl::fromLocalFile("InterfaceAnime.qml"));
   // QObject *objet= view->rootObject();
//    objet->setProperty("width",10);
    QObject::connect(view->rootObject(), SIGNAL(update()),
                          this, SLOT(updateSlot()));

}

void qml_interface::fetchForecast(QString place, int connexion)
{
   QString url;
   if (connexion == NewConnection)
   {
       url = QString("http://www.yr.no/place/%1/forecast.xml").arg(place);
       QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));
        manager->get(QNetworkRequest(url));
   }
       else // Traiter le fichier local
   {
        QDir *nomfichier = new QDir();
        url= nomfichier->absoluteFilePath("forecast.xml");
   }
   QXmlQuery query;
    query.bindVariable("url", QXmlItem(QVariant(url)));
    query.setQuery(MaRequete);
    Receiver receiver(query.namePool());
    if (query.isValid()) {
        if (query.evaluateTo(&receiver)) {
            leveSoleil=QDateTime::fromString(receiver.sun["rise"]);
            coucheSoleil=QDateTime::fromString(receiver.sun["set"]);
            nextUpdate=QDateTime::fromString(receiver.nextUpdate);
        }
            this->forecasts=receiver.forecasts;
        }
}


void qml_interface::affiche()
{
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

QString qml_interface::getSymbol()
{
    QString Symbol =getCurrentForecast().symbol["name"];
    if (Symbol == "Fog") emit ItFogz();
    return Symbol;
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
               return 360;
           if((mois>=3 && mois<6) ||( mois>=9 && mois<=11))
               return 370;
           if(mois>=6 && mois<=8)
               return 365;
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
    emit ItFogz();
}

QString qml_interface::getNextUpdate()
{
    return nextUpdate.toString();
}

void qml_interface::updateSlot()
{
    if(nextUpdate < QDateTime::currentDateTime())
    {
        fetchForecast(localisation,NewConnection);
    }
}

void qml_interface::replyFinished(QNetworkReply* reponse)
{
    QByteArray xml=reponse->readAll();
    QFile myfile("forecast.xml");
    myfile.open(QIODevice::WriteOnly);
    myfile.write(xml);
    myfile.close();
}
qml_interface::~qml_interface()
{

}
